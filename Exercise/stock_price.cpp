#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    stack<int> tmp_stack;
    stack<int> hist_stack;
    stack<int> result_stack;

    while(prices.size()){
        int time = 0;
        int num = prices.back();
        prices.pop_back();
        int tmp_num;
        while(hist_stack.size()){
            time++;
            tmp_num = hist_stack.top();
            hist_stack.pop();
            tmp_stack.push(tmp_num);
            if(tmp_num<num){
                break;
            }
        }
        //계산이 다 끝나면 스택들을 다시 초기화하고 현재 num을 hist스택에 push한다.
        while(tmp_stack.size()){
            hist_stack.push(tmp_stack.top());
            tmp_stack.pop();
        }
        hist_stack.push(num);
        result_stack.push(time);
    }

    while(result_stack.size()){
        answer.push_back(result_stack.top());
        result_stack.pop();
    }
    

    return answer;
}

int main(){
    vector<int> prices;
    vector<int> answer;

    prices.push_back(1);
    prices.push_back(2);
    prices.push_back(3);
    prices.push_back(2);
    prices.push_back(3);
    
    answer = solution(prices);
    for(int i=0; i<answer.size(); i++){
        cout << "answer[" << i << "] : " << answer[i] << endl;
    }
    
    return 0;
}