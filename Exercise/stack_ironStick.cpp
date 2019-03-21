#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(string arrangement) {
    int answer = 0;

    stack<char> stick;
	char temp;

	for(int i = 0; i < arrangement.size(); i++)
	{
		if(arrangement.at(i) == '(')
		{
			stick.push('(');
			temp = '(';
		}
		else{
			if(temp =='('){
				stick.pop();
				answer += stick.size();
				temp = ')';
			}
			else{
				stick.pop();
				answer += 1;
				temp = ')';
			}
		}
	}

    return answer;
}

int main(){
	string arrangement = "()(((()())(())()))(())";
	int answer = 0;

	answer = solution(arrangement);

	cout << answer << endl;
	return 0;
}