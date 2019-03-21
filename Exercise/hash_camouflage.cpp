#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string> > clothes) {
    int answer = 1;

    unordered_map <string, int> attributes;
    for(int i = 0; i < clothes.size(); i++)
        attributes[clothes[i][1]]++;
    for(auto it = attributes.begin(); it != attributes.end(); it++)
        answer *= (it->second+1);
    answer--;

    return answer;
}

int main(){
	vector<vector<string> > clothes;
	vector<string> v;
	int answer;

	v.push_back("yellow_hat");
	v.push_back("headgear");
	clothes.push_back(v);
	v.clear();

	v.push_back("blue_sunglasses");
	v.push_back("eyewear");
	clothes.push_back(v);
	v.clear();

	v.push_back("green_turban");
	v.push_back("headgear");
	clothes.push_back(v);
	v.clear();

	answer = solution(clothes);

	cout << answer << endl;

	return 0;
}