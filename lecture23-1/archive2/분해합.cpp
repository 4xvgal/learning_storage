#include<iostream>
using namespace std;
void seperateDigits(int arr[6],int n){
    //seperate each digit
    arr[0] = n / 100000;
    arr[1] = (n % 100000) / 10000;
    arr[2] = (n % 10000) / 1000;
    arr[3] = (n % 1000) / 100;
    arr[4] = (n % 100) / 10;
    arr[5] = (n % 10) / 1;
}
void arrReset(int *arr){ //reseting arr
    for (int i =0;i<6;i++){
        arr[i] =0;
    }
}
int sumOfarray(int *arr) { //return sum of indexes
    int sum = 0;
    for (int i =0; i<6;i++){
        sum+=arr[i];
    }
    return sum;
}
int main(void){
    int n;
    int list[6] = {0,};
    cin >> n;
    int min = 999999;
    for (int i=n; i>0; i--){
        arrReset(list);           //reseting array
        seperateDigits(list , i); //seperate digits for verfying decomposition
        int sum = sumOfarray(list) + i;
        if (sum ==n){
            min = i;
        }  
    }
    if (min != 999999){
        cout << min << endl;
    } else{
        cout << '0'<<endl;
    }
    return 0;   
}
    
