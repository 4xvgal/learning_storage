//ch8-9.cpp
//비행기 스케줄 예약 프로그램

// AirlineBook 클래스 -> 스케줄 객체 3개 생성, 예약시스템 작동
// Schedule 클래스 -> 하나의 스케쥴을 구현하는 클래스,8개의 Seat객체 생성,
// Seat 객체에 예약,취소,보기등 관리
// Seat 클래스 ->: 하나의 좌석을 구현하는 클래스. 예약자 이름 저장, 좌석에 대한 예약,취소
// 등 보기 관리
// Console 클래스 : 메뉴를 출력하는 함수, 사용자로부터 메뉴 선택, 비행 시간,	사용자 이름
// 좌석 번호등을 입력받는 멤버 함수들을 구현, 멤버들은 static 으로 작성하는것이 좋다.

#include<iostream>
using namespace std;
using ::cin;
using ::cout;

//AirlineBook 클래스에서 메뉴를 담당하는 console 클래스
class console{
public:
	static int sel_menu();
	static int sel_time();
	static int inputSeatNum();
	static string input_name();
};
class Seat{ //하나의 좌석을 구현하는 클래스, 예약자 이름 저장, 좌석에 대한 예약
private:
	string ClientName;
public:
	Seat(){
		ClientName ="NULL";
	}
	void setSeat(string name){
		ClientName = name;
	}
	string getSeat(){
		return ClientName;
	}
	void cancleSeat(string name){ //좌석 취소
		ClientName= "NULL";
	}
};
//Schedule 클래스
class Schedule{	
private:
	string ScheduleTime; // 항공편 시간
	Seat* Seats; //개별 좌석 동적할당
	int seatCount;
public:
	Schedule(string ScheduleTime = "07", int seatCount = 8){ // 비행스케줄 이름, 좌석수
		Seats = new Seat[seatCount];
		this -> ScheduleTime = ScheduleTime;
		this -> seatCount = seatCount;
	}
	~Schedule(){ //소멸자
		delete[] Seats;
	}
	void setSeat(string name, int seatNum);  //좌석 지정(이름, 좌석번호)
	bool getSeat(int seatNum);
	void removeSeat(string name, int seatNum); //좌석 취소(이름, 좌석번호)
	void showSeats();
	void setScheTime(string time);
};

void Schedule::removeSeat(string name, int seatNum){ //좌석 취소(이름, 좌석번호)
	Seats[seatNum-1].cancleSeat(name); 
}
void Schedule::setSeat(string name, int seatNum) { //좌석 지정(이름, 좌석번호)
	Seats[seatNum-1].setSeat(name);
}
void Schedule::showSeats(){ //좌석을 출력한다.
	cout << ScheduleTime << ':';
	cout <<"	";
	for(int i=0;i<seatCount;i++){
		string tmp = Seats[i].getSeat(); //임시 문자열 함수
		if (tmp != "NULL"){ //
			cout << tmp;
			cout <<"	";
		}
		else{
			cout <<"---";
			cout <<"	";
		}
	}
}
//해당좌석이 이미 있는지 유무를 리턴한다. 0 = 없음, 1 = 있음
bool Schedule::getSeat(int seatNum){
	if(Seats[seatNum-1].getSeat() != "NULL"){
		return 0;
	}
	return 1;
}

//항공편 이름(시간을 조정한다.)
void Schedule::setScheTime(string time){
	ScheduleTime = time;
}

//최상위 클래스. 각 스케줄을 생성하고 각 스케줄의 예약과 취소를 관리한다.
class AirlineBook{
private:
	Schedule* Schedules;
	console a;
public:
	//생성자 
	AirlineBook(){ 
		Schedules = new Schedule [3];
		Schedules[0].setScheTime("07");
		Schedules[1].setScheTime("12");
		Schedules[2].setScheTime("17");
	}
	//소멸자
	~AirlineBook(){
		delete[] Schedules;
	}
	//프로그램 시작 함수
	void init();
};
//프로그램  시작 함수
void AirlineBook::init(){
	int menu = 1;
	while(menu){
		menu = console::sel_menu();
		int seat,time;
		string name;
		//메뉴 선택이 예약인 경우
		if (menu == 1) {
			time = console::sel_time();
			//예외가 아닐시 진행
			if (time !=0) {
			Schedules[time-1].showSeats();
			//시트번호, 이름 입력받기
			seat = console::inputSeatNum();
			name = console::input_name();
			//그자리에 이미 있으면  예약을 진행한다.
			if (Schedules[time-1].getSeat(seat) != 0){
				Schedules[time-1].setSeat(name,seat);
				}
			}
		}
		//메뉴가 취소인경우
		else if(menu==2){
			time = console::sel_time();
			//예외아닐시 진행
			if(time!= 0){
				Schedules[time-1].showSeats();
				//시트 번호 , 이름 입력
				seat = console::inputSeatNum();
				name = console::input_name();
				//해당 자리에 이미 예약된 자리가 있어야 진행한다.
				if(Schedules[time-1].getSeat(seat) != 1){
					cout << endl;
					Schedules[time-1].removeSeat(name,seat);
				}
			}
		}
		//메뉴가 보기인 경우
		else if(menu == 3){
			for(int i=0;i<3;i++){
				Schedules[i].showSeats();
				cout << endl;
			}
		}
		else if(menu == 4){
			cout<<"프로그램을 종료합니다"<<endl;
			break;
		}
	}
}



//메뉴 선택
int console::sel_menu(){
	cout << "예약 : 1, 취소: 2, 보기 :3 , 끝내기 4>>  ";
	int menu;
	cin >> menu;
	return menu;
}
//스케줄 선택
int console::sel_time(){
	cout<<"07시: 1, 12시: 2, 17시: 3>> ";
	int time;
	cin >> time;
	//예외처리
	if (time < 0 || time >3){
		return 0;
	}
	return time;
}
//좌석 번호 선택
int console::inputSeatNum(){
	int tmp_num;
	cout << "좌석 번호>>" ;
	cin >> tmp_num;
	if (tmp_num <= 0 || tmp_num > 8) return 0;
	return tmp_num;
}
//이름 입력
string console::input_name(){
	string tmpName;
	cout <<"이름 입력 >>";
	cin >> tmpName;
	return tmpName;
}

int main(){
	AirlineBook* airline;
	airline = new AirlineBook;
	airline -> init();
}