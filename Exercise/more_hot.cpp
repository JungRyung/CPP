#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int first, second;

    priority_queue<int, vector<int>, greater<int> > scoville_queue;

    for(int i=0; i<scoville.size(); i++)
	{
		scoville_queue.push(scoville.at(i));
	}

	while(scoville_queue.size()>1)
	{
		answer++;

		first = scoville_queue.top();
		scoville_queue.pop();
		second = scoville_queue.top();
		scoville_queue.pop();

		scoville_queue.push(first+(second*2));

		if(scoville_queue.top()>=K)
			return answer;
	}

	if(scoville_queue.top()>=K)
		return answer;
	else
		return -1;

	// while(scoville_queue.size()>0)
	// {
	// 	cout << scoville_queue.top();
	// 	scoville_queue.pop();
	// }

    // return answer;
}

int main()
{
	int answer;

	vector<int> scoville;
	scoville.push_back(1);
	scoville.push_back(3);
	scoville.push_back(2);
	scoville.push_back(9);
	scoville.push_back(10);
	scoville.push_back(12);

	answer = solution(scoville, 7);

	cout << answer << endl;

	return 0;
}