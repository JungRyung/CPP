#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<int> temp;
    for(int i=0; i < numbers.size(); i++)
    return answer;
}

int mul(int num){
	if(num>0)
		for(int i=0; i<num; i++)
			mul(num-1);
	else
		return ;
}

int main(){
	vector<int> numbers;
	numbers.push_back(6);
	numbers.push_back(10);
	numbers.push_back(2);
}