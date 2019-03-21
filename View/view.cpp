#include <stdio.h>
#include <iostream>


#define MAX_HEIGHTS 255
#define MAX_NUM 1000

using namespace std;

int main()
{	
	char* inputDataPath = "input.txt";
	char* outputDataPath = "output.txt";
	FILE* inputData;
	inputData = fopen(inputDataPath,"r");
	FILE* outputData;
	outputData = fopen(outputDataPath,"w");

	int apartmentNUM;

	if(inputData && outputData)
	{
		char line[30];
		int count = 1;

		//아파트 개수 입력받음
		while(fscanf(inputData,"%s",line) != EOF)
		{
			fprintf(outputData, "#%d ",count);
			apartmentNUM = stoi(line);
			if(apartmentNUM <= MAX_NUM) //아파트의 개수가 정해진 범위 내 이면
			{
				cout << "apartmentNUM : " << apartmentNUM << endl;
				int apartment[apartmentNUM];
				int viewNUM=0;

			    for(int i=0; i < apartmentNUM; ++i) //아파트의 높이를 모두 배열에 옮겨받음
			    {
			    	fscanf(inputData,"%s",line);
			        apartment[i] = stoi(line);
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
			    		viewNUM += apartment[i]-temp;
			    }
			    fprintf(outputData, "%d\n", viewNUM);
			}
			else
			{
				cout << "excess MAX_NUM" << endl;
				return 0;
			}
			++count;
		}
	}
	return 0;
}