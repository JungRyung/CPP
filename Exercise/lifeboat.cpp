#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <stdlib.h>

using namespace std;

// int solution(vector<int> people, int limit) {
//     int answer = 0;
//     sort(people.begin(), people.end());

//     while(!people.empty()){
//     	int weight_sum = 0;
//     	int idx = -1;

//     	answer++;

//     	//배에 첫번째 사람을 태움
//     	weight_sum += people.back();
//     	people.pop_back();

//     	//배에 두번째 사람을 태우려는 시도
//     	if(!people.empty()){
//     		//이진탐색을 사용하는게 빠르다.
//     		// for(int i=0; i<people.size(); i++)
//     		// 	if(weight_sum+people[i] <= limit)
//     		// 		idx=i;
//     		// 	else
//     		// 		break;

//     		if(upper_bound(people.begin(),people.end(),
//     			limit-weight_sum) - people.begin() > 0)
//     			idx = upper_bound(people.begin(),people.end(),
//     			limit-weight_sum) - people.begin() - 1;

//     		if(idx>=0)
//     			people.erase(people.begin()+idx);
//     	}

//     }

//     return answer;
// }

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int lightest_idx = 0, heaviest_idx = people.size()-1;

    while(lightest_idx<heaviest_idx+1){
    	if(people[lightest_idx]+people[heaviest_idx] <= limit)
    		lightest_idx++;
    	heaviest_idx--;
    	answer++;
    }
    return answer;
}

int main(){
	vector<int> people;
	int limit = 100;
	int answer;

	people.push_back(70);
	people.push_back(50);
	people.push_back(80);
	people.push_back(50);

	// sort(people.begin(), people.end());

	// cout << upper_bound(people.begin(), people.end(), 50) - people.begin() << endl;

	answer = solution(people, limit);

	cout << answer << endl;

	return 0;
}