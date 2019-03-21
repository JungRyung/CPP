#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int> > commands) {
    vector<int> answer;
    for(int i=0; i<commands.size();i++)
    {
        vector<int> v;
        for(int j=commands[i][0]-1; j<commands[i][1]; j++)
        {
            v.push_back(array[j]);
            cout << array[j];
        }
        cout << endl;
        sort(v.begin(), v.end());
        for(int j=0; j < v.size(); j++)
            cout << v[j];
        cout << endl;
        cout << "commands[" << i << "][2] : "<< commands[i][2] << endl;
        answer.push_back(v[commands[i][2]-1]);
        cout << "answer[" << i<< "] : " << answer[i] <<endl;
    }
    
    return answer;
}

int main(){
    vector<int> answer;
    vector<int> array;
    array.push_back(1);
    array.push_back(5);
    array.push_back(2);
    array.push_back(6);
    array.push_back(3);
    array.push_back(7);
    array.push_back(4);

    vector<vector<int> > commands;
    vector<int> v;
    v.push_back(2);
    v.push_back(5);
    v.push_back(3);
    commands.push_back(v);
    v.clear();
    v.push_back(4);
    v.push_back(4);
    v.push_back(1);
    commands.push_back(v);
    v.clear();
    v.push_back(1);
    v.push_back(7);
    v.push_back(3);
    commands.push_back(v);
    v.clear();

    answer = solution(array, commands);

    cout << "{";

    for(int i=0; i < answer.size(); i++)
        if(i==0)
            cout << answer[i];
        else
            cout << ", " << answer[i];
    cout << "}" << endl;

    return 0;
}