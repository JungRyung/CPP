#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> priority; //중요도
    queue<int> seq; //순서 마킹
    for(int i = 0; i < priorities.size(); i++)
    {
    	priority.push(priorities[i]);
    	seq.push(i);
    }

    sort(priorities.begin(),priorities.end());
    while(priority.size()>0)
    {
    	if(priority.front() >= priorities.back())
    	{
    		if(seq.front() == location){
    			++answer;
    			break;
    		}
    		else{
    			++answer;
    			seq.pop();
    			priority.pop();
    			priorities.pop_back();
    		}
    	}
    	else{
       			seq.push(seq.front());
    			priority.push(priority.front());
    			seq.pop();
    			priority.pop();
    	}
    }

    return answer;
}

int main(){
	vector<int> priorities;
	int answer;
	priorities.push_back(1);
	priorities.push_back(1);
	priorities.push_back(9);
	priorities.push_back(1);
	priorities.push_back(1);
	priorities.push_back(1);

	answer = solution(priorities,0);

	cout << answer << endl;

	return 0;
}