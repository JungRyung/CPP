#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;

    sort(citations.begin(),citations.end());
    int left = citations.front();
    int right = citations.back();
    int mid = (left+right) / 2;

    int beforeMid=10001;

    if(left>=citations.size())
    	return citations.size();

    while(left<=right)
    {
    	int hNum = 0;
    	for(int i=0; i<citations.size(); i++)
    	{
    		if(citations.at(i)>=mid)
    			hNum++;
    	}
    	// if(hNum>=citations.back())
    	// 	return citations.back();
    	if(hNum < mid)
    	{
    		right = mid;
    		mid = (left + right)/2;
    	}else
    	{
    		left = mid;
    		mid = (left + right)/2;
    	}
    	if(beforeMid == mid)
    		break;
    	else
    		beforeMid = mid;
    }

    answer = mid;

    return answer;
}

int main()
{
	int answer;

	vector<int> citations;
	citations.push_back(4);
	citations.push_back(3);
	citations.push_back(3);
	citations.push_back(3);

	answer = solution(citations);

	cout << answer << endl;

	return 0;
}