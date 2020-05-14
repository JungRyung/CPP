#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long left, mid, right;

    sort(times.begin(),times.end());
    left = 1;
    right = (long long)times.back() * n;
    mid = (left + right) / 2;

    cout << "left : " << left << "  mid : " << mid << "  right : " << right << endl;

    long long old_mid = 0;
    long long peopleSum = 0;
    answer = right;
    while(left<=right){
    	for(int i=0; i<times.size(); i++){
    		peopleSum += mid/(long long)times[i];
    	}
    	cout << "peopleSum : " << peopleSum << endl;
		if(peopleSum < n){
			left = mid + 1;
		}else{
			if(mid <= answer)
				answer = mid;
			right = mid - 1;
		}
		peopleSum = 0;
		mid = (left + right) / 2;
		cout << " mid : " << mid << endl;
    }

    return answer;
}

int main(){
	int n = 6;
	vector<int> times;
	long long answer;

	times.push_back(7);
	times.push_back(10);

	answer = solution(n, times);

	cout << answer << endl;

	return 0;
}