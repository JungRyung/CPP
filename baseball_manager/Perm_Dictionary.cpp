#include <iostream>
#include <algorithm>

using namespace std;

void RotateR(int arr[], int start, int end){
    int last = arr[end];
    for(int i = end; i > start; i--){
    	arr[i] = arr[i-1];
    }
    arr[start] = last;
}
void RotateL(int arr[], int start, int end){
    int first = arr[start];
    for(int i = start; i < end; i++){
    	arr[i] = arr[i+1];
    }
    arr[end] = first;
}
void permutation_dictionary(int arr[], int len, int n, int k){
    int j;
    // 종료조건
    if (len == k){ //깊이가 k가 되면
		for(j=0; j<k; j++) printf("%d", arr[j]); //k개의 원소만 출력해준다.
    	printf("\n");
        return;
    }
    // 분기조건
    for(j=len; j<=n; j++){
        RotateR(arr, len, j); //arr의 원소들을 오른쪽으로 밀어준다.
        permutation_dictionary(arr, len+1, n, k);
        RotateL(arr, len, j); //arr의 원소들을 왼쪽으로 밀어준다.
    }
}

int main()
{
	int set[4] = {41,2,31,4};
	sort(set, set+4);
	permutation_dictionary(set,0,3,3);
}