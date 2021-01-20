package main

import (
	"fmt"
	"log"
	"net/http"
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
	getQuery()
	baseURL = baseURLresult
	//totalPages 총 페이지 수
	totalPages := getPages()
	for i := 0; i < totalPages; i++ {
		extractJobs := getPage(i)
		jobs = append(jobs, extractJobs...)
	}
	fmt.Println(jobs)
}

//검색어 입력 함수
func getQuery() {
	var query string
	fmt.Printf("typing query :")
	fmt.Scanln(&query)
	baseURLresult = baseURLhead + query
}

//getPage extract jobs from page
func getPage(page int) []extractedJob {
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
		job := extractJob(card)
		jobs = append(jobs, job)
	})
	return jobs
}

//extractJob is extract job data from cards
func extractJob(card *goquery.Selection) extractedJob {
	id, _ := card.Attr("data-jk")
	title := clearString(card.Find(".title>a").Text())
	location := clearString(card.Find(".sjcl").Text())
	salary := clearString(card.Find(".salaryText").Text())
	summary := clearString(card.Find(".summary").Text())
	return extractedJob{
		id:       id,
		title:    title,
		location: location,
		salary:   salary,
		summary:  summary,
	}
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
