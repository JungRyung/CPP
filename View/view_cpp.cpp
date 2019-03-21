#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#define MAX_HEIGHTS 255
#define MAX_NUM 1000

using namespace std;

int main()
{	
	string inputDataPath = "input.txt";
	string outputDataPath = "output.txt";
	ifstream inputData(inputDataPath.data());
	ofstream outputData(outputDataPath.data());

	int apartmentNUM;

	if(inputData.is_open() && outputData.is_open())
	{
		string line;
		int count = 1;

		//아파트 개수 입력받음
		while(getline(inputData, line))
		{
			outputData << "#" << count << " ";
			apartmentNUM = stoi(line);
			if(apartmentNUM <= MAX_NUM) //아파트의 개수가 정해진 범위 내 이면
			{
				cout << "apartmentNUM : " << apartmentNUM << endl;
				int apartment[apartmentNUM];

				getline(inputData, line);
				istringstream iss(line);

			    for(int i=0; i < apartmentNUM; ++i) //아파트의 높이를 모두 배열에 옮겨받음
			    {
			        string sub;
			        iss >> sub;
			        apartment[i] = stoi(sub);
			    }

			    for(int i=2; i< apartmentNUM-2; ++i) 
			    {
			    	int temp = 0;
			    	if(apartment[i-2]>temp)
			    		temp = apartment[i-2];
			    	if(apartment[i-1]>temp)
			    		temp = apartment[i-1]; 
			    	if(apartment[i+1]>temp)
			    		temp = apartment[i+1]; 
			    	if(apartment[i+2]>temp)
			    		temp = apartment[i+2];

			    	if(apartment[i]-temp > 0)
			    		outputData << apartment[i]-temp << " ";
			    	else
			    		outputData << "0 ";
			    }
			    outputData << endl;
			}
			else
			{
				cout << "excess MAX_NUM" << endl;
				return 0;
			}
			++count;
		}
		while(getline(inputData, line))
		{
			// cout << line << endl;
		}
	}
	return 0;
}