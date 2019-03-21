#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int weight_sum = 0;
    queue<int> bridge;
    queue<int> truck;

    // initializing bridge queue
    for(int i=0; i < bridge_length; i++)
    	bridge.push(0);
  
  	// initializing truck queue
    for(int i=0; i < truck_weights.size(); i++)
    	truck.push(truck_weights[i]);

    while(truck.size() + weight_sum > 0)
    {
    	answer++;
    	weight_sum -= bridge.front();
    	bridge.pop();
    	if(truck.size() > 0)
    	{
	    	if(weight_sum + truck.front() > weight)
	    		bridge.push(0);
	    	else{
	    		bridge.push(truck.front());
	    		weight_sum += truck.front();
	    		truck.pop();
	    	}
   		}else{
   			bridge.push(0);
   		}
    	// cout << "time : " << answer << "\t[";
    	// for(int i = 0; i < bridge.size(); i++)
    	// {
    	// 	if(i==0)
    	// 		cout << bridge.front();
    	// 	else
    	// 		cout << "," << bridge.front();
    	// 	bridge.push(bridge.front());
    	// 	bridge.pop();
    	// }
    	// cout << "]" << endl;
    }
    // while(weight_sum >0){
    // 	answer++;
    // 	weight_sum -= bridge.front();
    // 	bridge.pop();
    // 	bridge.push(0);
    // }

    return answer;
}

int main()
{
	vector<int> truck_weights;
	int answer = 0;
	truck_weights.push_back(7);
	truck_weights.push_back(4);
	truck_weights.push_back(5);
	truck_weights.push_back(6);

	answer = solution(2,10,truck_weights);

	cout << answer << endl;

	return 0;
}