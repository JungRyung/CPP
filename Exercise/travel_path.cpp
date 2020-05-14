#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

bool is_searched = false;

void DFS(string start, vector<vector<string>>& tickets, vector<bool>& visit, vector<string>& answer, vector<string>& temp, int cnt){
	temp.push_back(start);

	if(cnt == visit.size() && !is_searched){
		answer = temp;
		is_searched = true;
	}else{

		for(int i=0; i<tickets.size(); i++){
			if(start == tickets[i][0] && !visit[i]){
				visit[i] = true;
				DFS(tickets[i][1], tickets, visit, answer, temp, cnt+1);
				visit[i] = false;
			}
		}
	}

	temp.pop_back();
}

vector<string> solution(vector<vector<string> > tickets) {
    vector<string> answer, temp;
    vector<bool> visit(tickets.size(), false);
    stack<string> s;
    string currentAir = "ICN";
    string nextAir;

    sort(tickets.begin(),tickets.end());

    for(int i=0; i<tickets.size(); i++){
    	cout << tickets[i][0] << ", " << tickets[i][1] << endl;
    }

    // s.push(currentAir);
    // for(int i=0; i<tickets.size(); i++){
    // 	if(currentAir == tickets[i][0]){
    // 		visit[i] = true;
    // 		nextAir = tickets[i][1];
    // 		break;
    // 	}
    // }
    // while(1){
    // 	for(int i=0; i<tickets.size(); i++){
    // 		if(departureAir == tickets[i][0] && !visit[i]){
    // 			visit[i] == true;
    // 			s.push(tickets[i][1]);
    // 		}
    // 	}
    // }

    // lower_bound(tickets.begin(),tickets.end(),"ICN")

    DFS(currentAir, tickets, visit, answer,temp,0);

    return answer;
}

int main(){
	vector<vector<string> > tickets{{"ICN","SFO"},{"ICN","ATL"},{"SFO","ATL"}
									,{"ATL","ICN"},{"ATL","SFO"}};
	vector<string> answer;

	answer = solution(tickets);

	for(int i=0; i<answer.size(); i++){
		cout << answer[i] << endl;
	}

	return 0;
}