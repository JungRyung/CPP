#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

// bool compare(vector<int> a, vector<int> b)
// {
// 	return b[1] < a[0];
// }

struct Pred
{
	bool operator()(vector<int> a, vector<int> b) {
		return a[1] > b[1];
	}		
};

int solution(vector<vector<int> > jobs) {
    int answer = 0;
    int idx = 0;
    priority_queue<vector<int> ,vector<vector<int> >, Pred> pri_queue;
    queue<vector<int> > schedule_queue;
    queue<vector<int> > scheduled_queue;

    int time = 0;
    int time_tmp = 0;
    int total_time = 0;
    int cnt = 0;

    // cout << "jobs.size() : " << jobs.size() << endl;
    // for(int i=0; i<jobs.size(); i++)
    // {	
    // 	cout << "debug " << i << endl;
    // 	queue.push(jobs.at(i));
    // }

    // cout << "queue.size() : " << queue.size() << endl;
    // int i = 0;
    // while(!queue.empty())
    // {
    // 	i++;
    // 	cout << "round " << i << endl;
    // 	cout << queue.top().at(0) << ", " << queue.top().at(1) << endl;
    // 	queue.pop();
    // 	cout << "finish round " << i << endl;
    // }
    // time_tmp = jobs.at(0).at(1);
    while(idx <jobs.size())
    {
    	int count=0;
    	for(int i=idx; i<jobs.size(); i++)
    	{
    		if(jobs.at(i).at(0) <= time_tmp)
    		{
    			pri_queue.push(jobs.at(i));
    			idx++;
    			count++;
    		}
    	}
    	if(count==0)
    	{
    		pri_queue.push(jobs.at(idx));
			idx++;			
    	}
    	while(!pri_queue.empty())
    	{
    		schedule_queue.push(pri_queue.top());
    		scheduled_queue.push(pri_queue.top());
    		pri_queue.pop();
    	}
    	time_tmp = schedule_queue.front().at(1);
    	// cout << schedule_queue.front().at(0) << ", " << schedule_queue.front().at(1) << endl;
    	schedule_queue.pop();
    }

    // while(!scheduled_queue.empty())
    // {
    // 	cout << scheduled_queue.front().at(0) << ", " << scheduled_queue.front().at(1) << endl;
    // 	scheduled_queue.pop();
    // }

    while(!scheduled_queue.empty())
    {
    	time += scheduled_queue.front().at(1);
    	total_time += time - scheduled_queue.front().at(0);
    	cnt++;
    	scheduled_queue.pop();
    }

    answer = total_time / cnt;
    // while(1)
    // {
    // 	if(jobs.at(idx).at(0) == time)
    // 	{
    // 		queue.push(jobs.at(idx));
    // 		idx++;
    // 	}
    // 	if(time_tmp<=0)
    // 	{
    // 		time_tmp = queue.top().at(1);
    // 		queue.pop();
    // 		// total_time = 
    // 	}
    	 

    // 	time++;
    // 	time_tmp--;
    // }

    return answer;
}

int main()
{
	vector<vector<int> > jobs{{0,3},{1,9},{2,6}};
	int answer = 0;

	answer = solution(jobs);

	cout << answer << endl;

	// cout << jobs.size() << endl;
	// cout << jobs.at(1).at(1) << endl;
	return 0;
}