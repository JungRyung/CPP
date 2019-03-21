#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for(int i = 0; i < completion.size(); i++){
        if(participant[i] != completion[i])
        {
            answer = participant[i];
            break;
        }
    }
    if(answer.compare("")==0)
        answer = participant.back();
    
    return answer;
}

int main()
{
    string answer = "";


    vector<string> participant(5);
    participant.push_back("marina");
    participant.push_back("josipa");
    participant.push_back("nikola");
    participant.push_back("vinko");
    participant.push_back("filipa");


     vector<string> completion(4);
    completion.push_back("josipa");
    completion.push_back("filipa");
    completion.push_back("marina");
    completion.push_back("nikola");

    answer = solution(participant, completion);

    cout << answer << endl;

    return 0;
}