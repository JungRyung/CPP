#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;

    sort(rocks.begin(), rocks.end());

    int left = 0, right = distance;
    int mid;

    while(left<=right){
    	mid = (left + right) / 2;
    	cout << "left : " << left << "  mid : " << mid << "  right : " << right << endl;
    	int num = 0;
    	int last = 0;
    	for(int i=0; i<=rocks.size(); i++){
    		// int gap = i!=rocks.size()?rocks[i]-last:distance-last;
    		int gap = last == 0 ? rocks[i] : 
            i == rocks.size() ? distance - rocks.back() : rocks[i] - last;
    		cout << gap << " ";
    		if(gap < mid)
    			num++;
    		else{
    			last = rocks[i];
    		}
    	}
    	cout << endl;
    	if(num<n){
    		left = mid + 1;
    	}else{
    		answer = mid;
    		right = mid - 1;
    	}
    }

    return answer;
}

int main(){
	int distance = 25;
	vector<int> rocks;
	int n =2;
	int answer;

	rocks.push_back(2);
	rocks.push_back(14);
	rocks.push_back(11);
	rocks.push_back(21);
	rocks.push_back(17);

	answer = solution(distance, rocks, n);

	cout << answer << endl;

	return 0;
}