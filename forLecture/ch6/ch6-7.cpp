//ch6-7.cpp
#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

class Random {
public:
	//매번 다른 랜덤수를 발생시키기위한 seed를 설정하는 함수
	static void seed() { srand((unsigned)std::time(NULL)); }	//set seed as time
	static int nextInt(int min = 0, int max = 32767); //return integer between min and max
	static char nextAlphabet(); //return random alphabet character (upper,lower both)
	static double nextDouble();	//return random double 0<= x < 1
};

int Random::nextInt(int min, int max) {
	return rand()%(max- min+1) +min;
}

char Random::nextAlphabet() {
	char upper = Random::nextInt(65, 90);
	char lower = Random::nextInt(97, 122);
	int chooser = nextInt(0, 1); //gen integer to choose upper or lowercase
	if (!chooser) {
		return upper;
	}
	return lower;
}

double Random::nextDouble() {
	return (double)(rand()) / ((double)(RAND_MAX / (1 - 0)));
}

int main() {
	//1 to 100
	cout << "1에서 100까지 랜덤한 정수 10개를 출력합니다." << endl;
	Random a1;
	a1.seed();
	for (int i = 0; i < 10; i++) {
		cout <<a1.nextInt(1, 100) <<" ";
		if (i == 9) cout << endl;
	}
	//random 10 alphabet
	cout << "알파벳을 랜덤하게 10개를 출력합니다." << endl;
	for (int i = 0; i < 10; i++) {
		cout << a1.nextAlphabet() <<" ";
		if (i ==9) cout << endl;
	}
	//random 10 double
	cout << "랜덤한 실수를 10개를 출력합니다" << endl;
	for (int i = 0; i < 10; i++) {
		cout << a1.nextDouble() << " ";
		if (i == 9) cout << endl;
	}

}