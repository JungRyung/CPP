#include <iostream>
using namespace std;

int facto(int n){
	if(n == 1)
		return 1;
	return n * facto(n-1);
}

int fibo(int n){
	if(n==1|| n==2)
		return 1;
	return fibo(n-1) + fibo(n-2);
}

int main(){
	cout << facto(5) << endl;
	for(int i=1; i<21; i++){
		if(i==20)
			cout << fibo(i) << endl;
		else
			cout << fibo(i) << " ";
	}
	return 0;
}