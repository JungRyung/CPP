#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <queue>
#include <algorithm>

using namespace std;

vector<string> split(string str, char delimiter) {
    vector<string> internal;
    stringstream ss(str);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        internal.push_back(temp);
    }
 
    return internal;
}

void print_int_vec(vector<int> int_vec){
    for(int i=0; i<int_vec.size(); i++){
        cout << int_vec[i];
    }
    cout << endl;
}

vector<int> solution(vector<string> operations) {
    vector<int> queue_int;
    vector<int> answer;
    for(int i=0; i<operations.size(); i++){
        vector<string> operators = split(operations[i],' ');
        if(operators[0][0]=='I'){
            queue_int.push_back(stoi(operators[1]));
            sort(queue_int.begin(), queue_int.end());
            print_int_vec(queue_int);
        }else if(operators[1]=="-1"){
            if(queue_int.size()!=0){
                queue_int.erase(queue_int.begin());
            }
            print_int_vec(queue_int);
        }else{
            if(queue_int.size()!=0){
                queue_int.pop_back();
            }
            print_int_vec(queue_int);
        }
    }
    if(queue_int.size()==0){
        answer.push_back(0);
        answer.push_back(0);
        return answer;
    }
    else{
        answer.push_back(queue_int.back());
        answer.push_back(queue_int.front());
        return answer;
    }
}

int main(){
    vector<string> operations;
    //["I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"]
    operations.push_back("I -45");
    operations.push_back("I 653");
    operations.push_back("D 1");
    operations.push_back("I -642");
    operations.push_back("I 45");
    operations.push_back("I 97");
    operations.push_back("D 1");
    operations.push_back("D -1");
    operations.push_back("I 333");

    vector<int> answer;
    answer = solution(operations);

    for(int i=0; i<answer.size(); i++){
        cout << answer[i];
    }
    cout << endl;
    return 0;
}