#include <string>
#include <vector>
#include <iostream>

using namespace std;

int compare_strike(int num1, int num2);
int compare_ball(int num1, int num2);
bool compare_num(int num1, int num2, int strike, int ball);

int solution(vector<vector<int> > baseball) {
    int answer = 0;
    vector<bool> temp(1000,true);

    for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			for(int k=0; k<10; k++){
				if(i==j||j==k||i==k
					||i==0||j==0||k==0)
				{
					temp[i*100+j*10+k] = false;
				}
			}
		}
	}
    for(int num=0; num<baseball.size(); num++)
    {
		for(int i=1; i<10; i++){
			for(int j=1; j<10; j++){
				for(int k=1; k<10; k++){
					if(i!=j && j!=k && i!=k)
					{
						if(compare_num(i*100+j*10+k,baseball[num][0],baseball[num][1],baseball[num][2])
							&&temp[i*100+j*10+k]==true)
						{
							temp[i*100+j*10+k] = true;
						}
						else
							temp[i*100+j*10+k] = false;
					}
					else
						temp[i*100+j*10+k] = false;
				}
			}
		}
    }

    for(int i=0; i<1000; i++)
    {
    	if(temp[i]==true)
    	{
    		answer++;
    	}
    }

    return answer;
}


bool compare_num(int num1, int num2, int strike, int ball)
{
	int temp1[3];
	int temp2[3];
	int strike_tmp = 0;
	int ball_tmp = 0;

	for(int i=2; i>=0; i--)
	{
		temp1[i] = num1%10;
		temp2[i] = num2%10;
		num1/=10;
		num2/=10;
	}

	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			if(i==j && temp1[i]==temp2[j]){
				strike_tmp++;
				break;
			}
			if(i!=j && temp1[i]==temp2[j]){
				ball_tmp++;
				break;
			}
		}
	}

	if(strike==strike_tmp
		&& ball==ball_tmp)
		return true;
	else
		return false;
}

int compare_strike(int num1, int num2)
{

	int temp1[3];
	int temp2[3];
	int strike = 0;

	for(int i=2; i>=0; i--)
	{
		temp1[i] = num1%10;
		temp2[i] = num2%10;
		num1/=10;
		num2/=10;
	}

	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			if(i==j && temp1[i]==temp2[j]){
				strike++;
				break;
			}
		}
	}

	return strike;
}

int compare_ball(int num1, int num2)
{

	int temp1[3];
	int temp2[3];
	int ball = 0;

	for(int i=2; i>=0; i--)
	{
		temp1[i] = num1%10;
		temp2[i] = num2%10;
		num1/=10;
		num2/=10;
	}

	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			if(i!=j && temp1[i]==temp2[j]){
				ball++;
				break;
			}
		}
	}

	return ball;
}
int main(){
	int answer;
	vector<vector<int> > baseball;
	vector<int> vec1;
	vector<int> vec2;
	vector<int> vec3;
	vector<int> vec4;

	vec1.push_back(123);
	vec1.push_back(1);
	vec1.push_back(1);

	vec2.push_back(356);
	vec2.push_back(1);
	vec2.push_back(0);

	vec3.push_back(327);
	vec3.push_back(2);
	vec3.push_back(0);

	vec4.push_back(489);
	vec4.push_back(0);
	vec4.push_back(1);

	baseball.push_back(vec1);
	baseball.push_back(vec2);
	baseball.push_back(vec3);
	baseball.push_back(vec4);

	answer = solution(baseball);

	cout << answer << endl;

	// compare_num(123, 436);

	return 0;
}