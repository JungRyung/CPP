#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int limit_sum(vector<int> budgets, int limit);
int solution(vector<int> budgets, int M) {
    int answer = 0;
    long long total_sum = 0;

    sort(budgets.begin(), budgets.end());
    int left = 0, right = 100000;
 	int mid = 50000;
    //예산요청의 총합을 계산
    for(int i=0; i<budgets.size(); i++)
    	total_sum += budgets[i];
    cout << "total_sum : " << total_sum << endl;
    cout << "left : " << left << endl;
    cout << "right : " << right << endl;

    //총합이 예산을 초과하지 않으면 요청 중 가장 큰 값을 return
    if(total_sum<=M)
    	answer = budgets.back();
    //총합이 예산을 초과하면 가장 적합한 상한선을 이분탐색으로 찾음
    else{
    	long long sum;
    	int old_mid;
    	while(1){
    		sum = limit_sum(budgets,mid);
	    	cout << "-----------------------" << endl;
	    	cout << "limit : " << mid << endl;
	    	cout << "sum : " << sum << endl;
	    	if(sum == M){
	    		cout << "debug" << endl;
	    		answer = mid;
	    		break;
	    	}else if(sum<M){
	    		left = mid;
	    		cout << "left : " << left << endl;
	    	}else if(sum>M){
	    		right = mid;
	    		cout << "right : " << right << endl;
 	    	}

 	    	old_mid = mid;
 	    	mid = (left + right) / 2;
	    	if(mid == old_mid){
	    		answer = mid;
	    		break;
	    	}
    	}
    }

    return answer;
}

int limit_sum(vector<int> budgets, int limit){
	long long total_sum = 0;
	for(int i=0; i<budgets.size(); i++){
		if(budgets[i]<=limit)
			total_sum += budgets[i];
		else
			total_sum += limit;
	}

	return total_sum;
}

int main(){
	vector<int> budgets;
	int M = 485;
	int answer;

	budgets.push_back(120);
	budgets.push_back(110);
	budgets.push_back(140);
	budgets.push_back(150);

	answer = solution(budgets, M);

	cout << answer << endl;
	return 0;
}