#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool is_prime(int number){
	if(number == 2)
		return true;
	if(number == 1)
		return false;
	if(number % 2 == 0)
		return false;// 2를 제외한 소수는 항상 홀수 // 소수는 홀수 이므로 짝수로 나누는 과정을 생략한다. 

	for(int n = 3; n < number; n+=2)
	{
		if(number % n == 0)
		return false;
	} 

	return true;
}

string trim_zero(string number){
	while(number.front()=='0')
	{
		number.erase(0,1);
		trim_zero(number);
	}
	return number;
}

void combination(int idx, char* arr,char* result, bool* visited, vector<int>& prime_num){
	
    if (idx >= 4){
        // for (int i = 0; i < 4; i++){
        //     cout << result[i];
        // }
        // cout << endl;
        // // combination_count++;
        return;
    }
    for (int i = 0; i < 4; i++){
        if (!visited[i]){
        	string result_str = "";
        	int result_int = 0;
            result[idx] = arr[i];

            for(int j = 0; j <= idx; j++)
            {
            	// cout << result[j];
            	result_str += result[j];
            }

            result_str = trim_zero(result_str);
            // cout << result_str << endl;

            if(result_str == "")
            	result_int = 0;
            else
            	result_int = stoi(result_str);
            // cout << result_int<< endl;

            if(is_prime(result_int))
            {
            	for(int k = 0; k<prime_num.size(); k++)
            	{
            		if(result_int == prime_num.at(k))
            			prime_num.push_back(result_int);
            	}
            }

            visited[i] = true;
            combination(idx + 1, arr,result, visited, prime_num);
            visited[i] = false;
        }
    }
}

// void num_combination(char* numbers_arr, int num_length)
// {
// 	int i,j,k,l;

// 	int number = 0;

// 	// 예를 들어 길이가 4인 조합을 전부 찾아보자
// 	for(i = 0; i<num_length; i++)
// 	{
// 		number++;
// 		//길이가 1인 조합 출력
// 		cout << numbers_arr[i]
// 		<< endl;
// 		for(j = 0; j< num_length; j++)
// 		{
// 			if(i!=j)
// 			{
// 				number++;
// 				//길이가 2인 조합 출력
// 				cout << numbers_arr[i]
// 				<< numbers_arr[j]
// 				<< endl;
// 				for(k = 0; k< num_length; k++)
// 				{
// 					if(j!=k && i!=k)
// 					{
// 						number++;
// 						//길이가 3인 조합 출력
// 						cout << numbers_arr[i]
// 						<< numbers_arr[j]
// 						<< numbers_arr[k]
// 						<< endl;
// 						for(l = 0; l< num_length; l++)
// 						{
// 							if(k!=l && j!=l && i!=l)
// 							{
// 								//길이가 4인 조합 출력
// 								number++;
// 								cout << numbers_arr[i]
// 								<< numbers_arr[j]
// 								<< numbers_arr[k]
// 								<< numbers_arr[l]
// 								<< endl;

// 							}
// 						}
// 					}
// 				}
// 			}
// 		}
// 	}
// 	cout << "number = " << number << endl;
// }

// void num_combination_rec(char* numbers_arr, int num_length, bool* visited)
// {
// 	int i,j,k,l;
// 	// 예를 들어 길이가 4인 조합을 전부 찾아보자
// 	for(i = 0; i<num_length; i++)
// 	{
// 		if(!visited[i])
// 		{
// 			for(j=0;j)
// 		}
// 		//길이가 1인 조합 출력
// 		cout << numbers_arr[i]
// 		<< endl;
// 		for(j = 0; j< num_length; j++)
// 		{
// 			if(i!=j)
// 			{
// 				number++;
// 				//길이가 2인 조합 출력
// 				cout << numbers_arr[i]
// 				<< numbers_arr[j]
// 				<< endl;
// 				for(k = 0; k< num_length; k++)
// 				{
// 					if(j!=k && i!=k)
// 					{
// 						number++;
// 						//길이가 3인 조합 출력
// 						cout << numbers_arr[i]
// 						<< numbers_arr[j]
// 						<< numbers_arr[k]
// 						<< endl;
// 						for(l = 0; l< num_length; l++)
// 						{
// 							if(k!=l && j!=l && i!=l)
// 							{
// 								//길이가 4인 조합 출력
// 								number++;
// 								cout << numbers_arr[i]
// 								<< numbers_arr[j]
// 								<< numbers_arr[k]
// 								<< numbers_arr[l]
// 								<< endl;

// 							}
// 						}
// 					}
// 				}
// 			}
// 		}
// 	}
// 	cout << "number = " << number << endl;
// }

int solution(string numbers) {
    int answer = 0;
    int num_length;
    char numbers_arr[numbers.length()];
    char result[numbers.length()];
    bool visited[4] = {false, };

    vector<int> prime_num;

    num_length = numbers.length();

    for(int i = 0; i<numbers.length(); i++)
    {
    	numbers_arr[i] = numbers.at(i);
    }

    // num_combination(numbers_arr, num_length);
    combination(0 ,numbers_arr ,result ,visited, prime_num);

    for(int i = 0; i<prime_num.size(); i++){
    	cout << prime_num.at(i) << endl;
    }
    return answer;
}

int main()
{
	string numbers = "0011";
	int answer = 0;

	answer = solution(numbers);

	// cout << answer << endl;

	return 0;
}

