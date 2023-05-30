//ch6-6.cpp
//실습 6번 문제 
#include<iostream>
using namespace std;

class ArrayUtility2 {
private:
	int* s1, * s2;
	int size;
public:
	//s1과 s2 를 연결한 새로운 배열을 동적 생성하고 포인터 리턴
	static int* concat(int s1[], int s2[], int size);
	//s1 에서 s2에 있는 숫자를 모두 삭제한 새로운 배열을 동적 생성하여 리턴. 리턴하는 배열의 크기는
	//retSize에 전달. retSizr가 0인 경우 NULL 리턴
	static int* remove(int s1[], int s2[], int size, int& retSize);
};
//두개의 배열을 연결하고 리턴
int* ArrayUtility2::concat(int s1[], int s2[], int size) {
	
	int* s3 = new int[size * 2];
	/*
	//첫번째 배열을 s3에 삽입
	for(int i=0;i<size;i++){
		s3[i] = s1[i];
	}
	//두번째 배열을 s3에 삽입
	for(int i=0;i<size;i++){
		s3[i+size] = s2[i];
	}*/
	//한번에 하는 방법?
	for (int i = 0; i < size; i++) {
		s3[i] = s1[i];
		s3[i + size] = s2[i];
	}
	//완성된 배열 s3 리턴
	return s3;
}
//s1 배열에서 s2에 있는 숫자를 모두 삭제한 새로운 배열을 동적생성하여 리턴. 리턴하는 배열의 크기는
//retSize에 전달. retSize가 0인경우 NULL 리턴
int* ArrayUtility2::remove(int s1[], int s2[], int size, int& retSize) {
	//배열에서 동일한 인자가 있으면, s1 배열의 해당 인자를 NULL 로 만들어 삭제시킨다.
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (s1[i] == s2[j]) {
				s1[i] = NULL;
			}
		}
	}
	//s1 배열 에서 NULL이 아닌 인자가 발견되면 동적배열해야할 크기가 증가한다.
	//NULL이 아닐시 retSize 를 증가시킨다.
	for (int i = 0; i < size; i++) {
		if (s1[i] != NULL) retSize++;
	}
	//확정된 retSize만큼 동적할당을한다.
	int* s3 = new int[retSize];

	//동적할당한 배열에 인자를 삽입한다.
	int n = 0; //갯수용 인자
	for (int i = 0; i < size; i++) {
		if (s1[i] != NULL) {
			s3[n] = s1[i];
			n++;
		}
	}
	return s3;
};


int main() {
	ArrayUtility2 au2;
	int x[5], y[5];
	int retsize = 0;
	int size = 5;
	int* z;

	std::cout << "정수 " << size << " 개 입력하라. 배열 x 에 삽입한다. >> ";
	for(int i=0;i<size;i++){
		cin >> x[i];
	}
	std::cout << "정수 " << size << " 개 입력하라. 배열 x 에 삽입한다. >> ";
	for(int i=0;i<size;i++){
		cin >> y[i];
	}
	
 	z = au2.concat(x, y, size);
	std::cout << "합친 정수 배열을 출력한다." << endl;
	for (int i = 0; i < size * 2; i++) std::cout << z[i] << ' ';
	std::cout << endl;
	z = au2.remove(x,y,size,retsize);
	std::cout << "배열 x[] 에서 y[]를 뺀 결과를 출력한다. 개수는 " << retsize << endl;
	for(int i=0;i<retsize;i++){
		cout << z[i] << ' ';
	}
	cout << endl;
}