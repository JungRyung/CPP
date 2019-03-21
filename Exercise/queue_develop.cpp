#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> progresses_queue;
    queue<int> speeds_queue;

    //	전달받은 진행도, 진행속도 벡터를 큐에 옮겨담는다.
    for(int i=0; i < progresses.size(); i++)
	{
		progresses_queue.push(progresses.at(i));
		speeds_queue.push(speeds.at(i));
	}
	

	while(progresses_queue.size()>0)
	{
		int temp = 0;
		cout << "[";
		for(int i=0; i < progresses_queue.size(); i++)
		{
			if(i==0)
				cout << progresses_queue.front();
			else
				cout << "," << progresses_queue.front();
			if(progresses_queue.front() + speeds_queue.front() >= 100)
				progresses_queue.push(100);
			else
				progresses_queue.push(progresses_queue.front() + speeds_queue.front());
			speeds_queue.push(speeds_queue.front());
			progresses_queue.pop();
			speeds_queue.pop();
		}
		cout << "]" << endl;
		while(progresses_queue.front() == 100)
		{
			++temp;
			progresses_queue.pop();
			speeds_queue.pop();
		}

		if(temp > 0)
		{
			answer.push_back(temp);
		}
	}

    return answer;
}

int main()
{
	vector<int> progresses;
	vector<int> speeds;
	vector<int> answer;

	// progresses.push_back(93);
	// progresses.push_back(30);
	// progresses.push_back(55);

	// speeds.push_back(1);
	// speeds.push_back(30);
	// speeds.push_back(5);

	// progresses.push_back(40);
	// progresses.push_back(93);
	// progresses.push_back(30);
	// progresses.push_back(55);
	// progresses.push_back(60);
	// progresses.push_back(65);

	// speeds.push_back(60);
	// speeds.push_back(1);
	// speeds.push_back(30);
	// speeds.push_back(5);
	// speeds.push_back(10);
	// speeds.push_back(7);

	progresses.push_back(93);
	progresses.push_back(30);
	progresses.push_back(55);
	progresses.push_back(60);
	progresses.push_back(40);
	progresses.push_back(65);

	speeds.push_back(1);
	speeds.push_back(30);
	speeds.push_back(5);
	speeds.push_back(10);
	speeds.push_back(60);
	speeds.push_back(7);

	answer = solution(progresses, speeds);

	cout << "[";
	for(int i=0; i<answer.size(); i++)
	{
		if(i==0)
			cout << answer[i];
		else
			cout << "," << answer[i];
	}
	cout << "]" << endl;


	return 0;
}