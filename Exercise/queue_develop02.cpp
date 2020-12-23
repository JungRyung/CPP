#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int index = 0;
    int vec_size = progresses.size();

	while(index<vec_size){
        int tmp=0;
        while(progresses[index]>=100){
            tmp++;
            index++;
            if(index>=vec_size)
                break;
        }
		for(int i=0; i<vec_size; i++){
			progresses[i]+=speeds[i];
		}
        if(tmp>0)
            answer.push_back(tmp);
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