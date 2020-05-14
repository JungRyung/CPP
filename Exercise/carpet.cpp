#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;

    int row, column;
    int brown_tmp, red_tmp;

    bool flag = true;

    for(int i=3; flag ;i++)
    {
    	for(int j=3; j<=i; j++)
    	{
    		brown_tmp = 2*i + 2*j - 4;
    		red_tmp = i*j - brown_tmp;

    		if(brown_tmp==brown
    			&& red_tmp==red)
    		{
    			row = i;
    			column = j;
    			flag = false;
    			break;
    		}

    	}
    }

    answer.push_back(row);
    answer.push_back(column);

    return answer;
}

int main(){
	int brown;
	int red;
	vector<int> answer;

	brown = 24;
	red = 24;

	answer = solution(brown,red);

	cout << "[" << answer[0] << ", " << answer[1] << "]" << endl;

	return 0;
}