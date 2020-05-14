#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;

int solution(string name) {
    int answer = 0;
    int tmp = 0;
    vector<bool> tmp_status(name.length(), true);
    int cnt = 0;

    //현재상황
    // string name_tmp = "";
    for(int i=0; i<name.length(); i++){
    	// name_tmp.push_back('A');
    	if(name[i]!='A'){
    		tmp_status[i] = false;
    		cnt++;
    	}
    }

    while(cnt>0){
    	//해당 자리의 알파벳을 바꿔야 하는 경우
    	if(!tmp_status[tmp]){
    		if(abs('A'-name[tmp])>(26-abs('A'-name[tmp]))){
    			answer += 26-abs('A'-name[tmp]);
    			tmp_status[tmp] = true;
    			cnt--;
    		}else{
    			answer += abs('A'-name[tmp]);
    			tmp_status[tmp] = true;
    			cnt--;
    		}
    	}
    	//해당 자리의 알파벳을 바꿀 필요 없는 경우
    	else{
    		//뒤로탐색
    		int right_cnt=1;
    		while(1){
    			if(tmp+right_cnt<name.length()){
    				if(tmp_status[tmp+right_cnt]){
    					right_cnt++;
    				}
    				else
    					break;
    			}else{
    				if(tmp_status[tmp+right_cnt-name.length()]){
    					right_cnt++;
    				}
    				else
    					break;
    			}
    		}
    		//앞으로탐색
    		int left_cnt=1;
    		while(1){
    			if(tmp-left_cnt>=0){
    				if(tmp_status[tmp-left_cnt]){
    					left_cnt++;
    				}
    				else
    					break;
    			}else{
    				if(tmp_status[tmp-left_cnt+name.length()]){
    					left_cnt++;
    				}
    				else
    					break;
    			}
    		}
    		//뒤로 탐색이 더 짧거나 길이가 같은 경우
    		if(right_cnt<=left_cnt){
    			if(tmp+right_cnt<name.length()){
    				tmp += right_cnt;
    				cout << tmp << endl;
    				answer += right_cnt;
    			}
    			else{
    				tmp = tmp+right_cnt-name.length();
    				cout << tmp << endl;
    				answer += right_cnt;
    			}
    		}
    		//앞으로 탐색이 더 짧은 경우
    		else{
    			if(tmp-left_cnt>=0){
    				tmp -= left_cnt;
    				cout << tmp << endl;
    				answer += left_cnt;
    			}
    			else{
    				tmp = tmp-left_cnt+name.length();
    				cout << tmp << endl;
    				answer += left_cnt;
    			}
    		}

    	}
    }
    return answer;
}

int main(){
	string name = "BBAABB";
	int answer;

	answer = solution(name);

	cout << answer << endl;

	return 0;
}