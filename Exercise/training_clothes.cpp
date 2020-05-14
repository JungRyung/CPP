#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> student(n,1);

    for(int i=0; i<lost.size(); i++)
    	student[lost[i]-1]--;

    for(int i=0; i<reserve.size(); i++)
    	student[reserve[i]-1]++;

    bool loop_continue = false;
    while(1){
    	cout << "[";
    	for(int i=0; i<n; i++){
    		if(i==n-1){
    			cout << student[i];
    		}
    		else
    			cout << student[i] << ",";
	    }
	    cout << "]" << endl;
    	//여벌의 체육복을 가지고 있는 학생 중에 양옆의 학생중 한쪽만 체육복이 없는경우 검색
    	for(int i=0; i<n; i++){
    		//여벌의 체육복이 있는 학생일 때
    		if(student[i]==2){
    			//맨 첫번째 학생일 때
    			if(i==0){
    				if(student[i+1]==0){
    					student[i]--;
    					student[i+1]++;
    					loop_continue=true;
    					break;
    				}
    			}
    			//맨 끝번째 학생일 때
    			else if(i==n-1){
    				if(student[i-1]==0){
    					student[i]--;
    					student[i-1]++;
    					loop_continue=true;
    					break;
    				}
    			}
    			//얖뒤로 친구가 있는 학생일 때
    			else{
    				if(student[i-1]==0
    					&& student[i+1]>0){
    					student[i]--;
    					student[i-1]++;
    					loop_continue=true;
    					break;
    				}else if(student[i-1]>0
    					&& student[i+1]==0){
    					student[i]--;
    					student[i+1]++;
    					loop_continue=true;
    					break;
    				}
    			}
    		}
    	}
    	if(loop_continue){
    		loop_continue=false;
    		continue;
    	}

    	//여벌의 체육복을 가지고 있는 학생 중에 양옆의 학생이 모두 체육복이 없는 경우 검색
    	for(int i=0; i<n; i++){
    		//여벌의 체육복이 있는 학생일 때
    		if(student[i]==2){
    			//앞뒤로 친구가 있는 학생일 때
    			if(i!=0 && i!=n-1){
    				//양옆의 학생이 모두 체육복이 없을 때
    				if(student[i-1]==0
    					&& student[i+1]==0){
    					//앞의 친구에게만 빌려준다.
    					student[i]--;
    					student[i-1]++;
    					loop_continue=true;
    					break;
    				}
    			}
    		}
    	}
    	if(loop_continue){
    		loop_continue=false;
    		continue;
    	}

    	break;
    }

 //    cout << "[";
	// for(int i=0; i<n; i++){
	// 	if(i==n-1){
	// 		cout << student[i];
	// 	}
	// 	else
	// 		cout << student[i] << ",";
 //    }
 //    cout << "]" << endl;

    for(int i=0; i<n; i++){
    	if(student[i]>0)
    		answer++;
    }

    return answer;
}

int main(){
	int n;
	vector<int> lost;
	vector<int> reserve;
	int answer;

	n=7;
	lost.push_back(2);
	lost.push_back(4);
	lost.push_back(6);
	reserve.push_back(3);
	reserve.push_back(5);
	reserve.push_back(7);

	answer = solution(n,lost,reserve);

	cout << answer << endl;

	return 0;
}