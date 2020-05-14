#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int score[3] = {0,};

    int renouncer1[] = {1,2,3,4,5};
    int renouncer2[] = {2,1,2,3,2,4,2,5};
    int renouncer3[] = {3,3,1,1,2,2,4,4,5,5};

    for(int i = 0; i<answers.size(); i++){
    	if(renouncer1[i%5]==answers.at(i))
    		score[0]++;
    }
    for(int i = 0; i<answers.size(); i++){
    	if(renouncer2[i%8]==answers.at(i))
    		score[1]++;
    }
    for(int i = 0; i<answers.size(); i++){
    	if(renouncer3[i%10]==answers.at(i))
    		score[2]++;
    }

    int max = 0;
    for(int i = 0; i<3; i++){
	    if(max<=score[i])
    		max = score[i];
    }
    for(int i = 0; i<3; i++)
    {
    	if(max==score[i])
    		answer.push_back(i+1);
    }

    return answer;
}

int main()
{
	vector<int> answers;
	vector<int> answer;

	answers.push_back(1);
	answers.push_back(2);
	answers.push_back(3);
	answers.push_back(4);
	answers.push_back(5);

	answer = solution(answers);

	for(int i=0; i<answer.size(); i++)
	{
		cout << answer.at(i) << endl;
	}

	return 0;
}