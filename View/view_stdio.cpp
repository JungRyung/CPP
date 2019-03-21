#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>

#define MAX_HEIGHTS 255
#define MAX_NUM 1000

using namespace std;

int main()
{
	int apartmentNUM;


	int line;
	int count = 1;

	//아파트 개수 입력받음
	while(count <= 10)
	{
		scanf("%d",&line);
		printf("#%d ",count);

		apartmentNUM = line;
		if(apartmentNUM <= MAX_NUM) //아파트의 개수가 정해진 범위 내 이면
		{
			int apartment[apartmentNUM];
			int viewNUM=0;

		    for(int i=0; i < apartmentNUM; ++i) //아파트의 높이를 모두 배열에 옮겨받음
		    {
		    	scanf("%d",&line);
		        apartment[i] = line;
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
		    printf("%d\n", viewNUM);
		}
		else
		{
			cout << "excess MAX_NUM" << endl;
			return 0;
		}
		++count;
	}
	return 0;
}