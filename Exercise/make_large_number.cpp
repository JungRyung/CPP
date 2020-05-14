#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int cnt = k;
    int idx = 0;

    while(cnt>0){
    	//number의 남은 숫자개수와 cnt가 같아지는 경우 cnt만큼 숫자 삭제 후 종료
    	if(number.length()-idx==cnt){
    		for(int i=0; i<cnt; i++){
    			number.erase(idx,1);
    			cnt--;
    		}
    		break;
    	}
    	cout << "number : " << number << endl;
    	cout << "cnt : " << cnt << ", idx = " << idx << endl;
    	//앞에서 cnt번째까지의 숫자 중에서 가장 큰 수를 가진 숫자를 선택하고 그 앞의 숫자는 제거
    	int max = -1, tmp_idx = idx;
    	for(int i=idx; i<=idx+cnt; i++){
    		if(number[i]>max){
    			tmp_idx = i;
    			cout << "tmp_idx : " << tmp_idx << endl;
    			max = number[i];
    		}
    	}
    	// if(cnt==1 && idx==tmp_idx){
    	// 	number.erase(idx,1);
    	// 	cnt--;
    	// }
    	for(int i=idx; i<tmp_idx; i++){
    		number.erase(idx,1);
    		cnt--;
    		cout << "erase" << endl;
    	}
    	idx++;
    }
    answer = number;
    return answer;
}

int main(){
	string number = "1010";
	int k = 2;
	string answer = "";

	// number.erase(0,1);
	// cout << number << endl;
	answer = solution(number,k);

	cout << answer << endl;

	return 0;
}