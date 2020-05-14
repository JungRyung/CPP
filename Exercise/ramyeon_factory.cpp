#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    // int stock_tmp = stock;
    // int today;
    int idx = 0;

    priority_queue<int> queue;
    // queue<int> dates_queue;
    // queue<int> supplies_queue;

    // for(int i=0; i<dates.size(); i++)
    // {
    // 	dates_queue.push(dates.at(i));
    // 	supplies_queue.push(supplies.at(i));
    // }

    while(stock<k){
    	for(int i=idx; i<dates.size(); i++)
    	{
    		if(dates.at(i)<=stock)
    		{
    			queue.push(supplies.at(i));
    			idx++;
    		}
    	}
    	stock += queue.top();
    	queue.pop();
    	answer++;
    }
    // 내 방식
    // for(int i=0; i<k; i++)
    // {
    // 	if(i==dates_queue.front())
    // 	{
    // 		today = dates_queue.front();
    // 		dates_queue.pop();
    // 		if(!dates_queue.empty())
    // 		{
    // 			if(stock_tmp-(dates_queue.front()-today)<0)
    // 			{
    // 				stock_tmp += supplies_queue.front();
    // 				supplies_queue.pop();
    // 				answer++;
    // 			}else
    // 			{
    // 				supplies_queue.pop();
    // 			}
    // 		}else
    // 		{
    // 			if(stock_tmp-(k-today)<0)
    // 			{
    // 				stock_tmp += supplies_queue.front();
    // 				supplies_queue.pop();
    // 				answer++;
    // 			}else
    // 			{
    // 				supplies_queue.pop();
    // 			}
    // 		}
    // 	}
    // 	// cout << i << "일\t:  " << stock_tmp << "톤" << endl;;
    // 	stock_tmp--;
    // }

    return answer;
}

int main()
{
	int answer = 0;

	int stock = 4;
	vector<int> dates;
	vector<int> supplies;
	int k = 30;

	dates.push_back(4);
	dates.push_back(10);
	dates.push_back(15);

	supplies.push_back(20);
	supplies.push_back(5);
	supplies.push_back(10);

	answer = solution(stock, dates, supplies, k);

	cout << answer << endl;

	return 0;
}