package main

import (
	"encoding/csv"
	"fmt"
	"log"
	"net/http"
	"os"
	"strconv"
	"strings"

	"github.com/PuerkitoBio/goquery"
)

//baseURL is base url of the program
var baseURL string = "https://kr.indeed.com/jobs?q=python&limit=50"
var baseURLhead string = "https://kr.indeed.com/jobs?q="
var baseURLresult string

type extractedJob struct {
	id       string
	title    string
	location string
	salary   string
	summary  string
}

func main() {
	var jobs []extractedJob
	c := make(chan []extractedJob)

	getQuery()
	baseURL = baseURLresult
	//totalPages 총 페이지 수
	totalPages := getPages()

	for i := 0; i < totalPages; i++ {
		go getPage(i, c)
	}
	for i := 0; i < totalPages; i++ {
		extractedJobs := <-c
		jobs = append(jobs, extractedJobs...)
	}
	writeJobs(jobs)
	fmt.Println("Done, extracted", len(jobs))
}

//getPages is return how many pages in the URL
func getPages() int {
	pages := 0
	res, err := http.Get(baseURL)
	checkErr(err)
	checkCode(res)

	defer res.Body.Close()

	doc, err := goquery.NewDocumentFromReader(res.Body)
	checkErr(err)

	doc.Find(".pagination").Each(
		func(i int, s *goquery.Selection) {
			pages = s.Find("a").Length()
		},
	)
	return pages
}

//getPage extract jobs from each card
func getPage(page int, mainC chan<- []extractedJob) {
	c := make(chan extractedJob)
	var jobs []extractedJob
	pageURL := baseURL + "&start=" + strconv.Itoa(page*50)
	fmt.Println("Requesting", pageURL)
	res, err := http.Get(pageURL)
	checkErr(err)
	checkCode(res)

	defer res.Body.Close()

	doc, err := goquery.NewDocumentFromReader(res.Body)
	checkErr(err)

	searchCards := doc.Find(".jobsearch-SerpJobCard")
	searchCards.Each(func(i int, card *goquery.Selection) {
		go extractJob(card, c)
	})
	//fmt.Println("length", searchCards.Length())
	for i := 0; i < searchCards.Length(); i++ {
		job := <-c
		jobs = append(jobs, job)
	}
	mainC <- jobs
}

//extractJob is extract job data from cards
func extractJob(card *goquery.Selection, c chan<- extractedJob) {
	id, _ := card.Attr("data-jk")
	title := clearString(card.Find(".title>a").Text())
	location := clearString(card.Find(".sjcl").Text())
	salary := clearString(card.Find(".salaryText").Text())
	summary := clearString(card.Find(".summary").Text())
	c <- extractedJob{
		id:       id,
		title:    title,
		location: location,
		salary:   salary,
		summary:  summary,
	}
}

//wrtieJobs is writing extractedJob into csv
func writeJobs(jobs []extractedJob) {
	file, err := os.Create("jobs.csv")
	checkErr(err)

	utf8bom := []byte{0xEF, 0xBB, 0xBF}
	file.Write(utf8bom)
	w := csv.NewWriter(file)
	defer w.Flush()
	headers := []string{"LINK", "Title", "Location", "Salary", "Summary"}

	wErr := w.Write(headers)
	checkErr(wErr)

	for _, job := range jobs {
		jobSlice := []string{"https://kr.indeed.com/viewjob?jk=" + job.id, job.title, job.location, job.salary, job.summary}
		jwErr := w.Write(jobSlice)
		checkErr(jwErr)
	}
}

//검색어 입력 함수
func getQuery() {
	var query string
	fmt.Printf("typing query :")
	fmt.Scanln(&query)
	baseURLresult = baseURLhead + query
}

//clearString is clearing the strings (clean & seperate)
func clearString(str string) string {
	return strings.Join(strings.Fields(strings.TrimSpace(str)), " ")
}

//checkErr is checking err
func checkErr(err error) {
	if err != nil {
		log.Fatalln(err)
	}
}

//checkCode is checking the http statuscode
func checkCode(res *http.Response) {
	if res.StatusCode != 200 {
		log.Fatalln("Request failed with Status:", res.StatusCode)
	}
}
