#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(string a, string b)
{
	return stoi(b+a) < stoi(a+b);
}

string solution(vector<int> numbers) {
    string answer = "";
    
    string strNum[numbers.size()];
    for(int i =0; i<numbers.size(); i++)
    {
        strNum[i] = to_string(numbers.at(i));
        // cout << "strNum[" << i <<"] : " << strNum[i] << endl;
    }

    sort(strNum,strNum+numbers.size(),compare);

    for(int i=0; i<numbers.size(); i++)
    {
    	answer += strNum[i];
    }

    if(strNum[0]=="0")
    	return "0";
    
    return answer;
}

int main()
{
	string answer ="";
	vector<int> numbers;
	// numbers.push_back(6);
	// numbers.push_back(10);
	// numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_back(30);
	numbers.push_back(34);
	numbers.push_back(5);
	numbers.push_back(9);

	answer = solution(numbers);

	cout << answer << endl;
	return 0;
}