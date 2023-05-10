#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

class Random {
	//매번 다른 랜덤수를 발생시키기위한 seed를 설정하는 함수
	static void seed() { srand((unsigned)time(0)); }	//씨드 설정
	static int nextInt(int min = 0, int max = 32767); //return integer between min and max
	static char nextAlphabet(); //return random alphabet character
	static double nextDouble();	//return random double 0<= x < 1
};

int Random::nextInt(int min, int max) {
	seed();
	return rand() % max + min;
}

char Random::nextAlphabet() {
	seed();
	return rand() % 132 + 101;
}

double Random::nextDouble() {
	seed();
	return (double)(rand()) / ((double)(RAND_MAX / (1 - 0)));
}

int main() {
	
}