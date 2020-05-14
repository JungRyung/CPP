#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

vector<int> win[101];
vector<int> lose[101];

void winner_list_add(int winner, int loser){
	bool existed = false;
	for(int i=0; i<win[winner].size(); i++){
		if(win[winner][i] == loser)
			existed = true;
	}
	if(!existed)
		win[winner].push_back(loser);

	for(int i=0; i<lose[winner].size(); i++)
		winner_list_add(lose[winner][i],loser);
}

void loser_list_add(int winner, int loser){
	bool existed = false;
	for(int i=0; i<lose[loser].size(); i++){
		if(lose[loser][i] == winner)
			existed = true;
	}
	if(!existed)
		lose[loser].push_back(winner);

	for(int i=0; i<win[loser].size(); i++)
		loser_list_add(winner, win[loser][i]);
}

void dfs(int start, vector<int> graph[],int n){
	bool check [n+1];
	fill(check, check+n+1, false);
	stack<int> s;
	s.push(start);
	check[start] = true;

	while(!s.empty()){
		bool existed = false;
		int current_node = s.top();
		s.pop();
		for(int i=0; i<win[start].size(); i++){
			if(win[start][i] == current_node)
				existed = true;
		}
		if(current_node != start && !existed){
			win[start].push_back(current_node);
			lose[current_node].push_back(start);
		}
		for(int i=0; i<graph[current_node].size(); i++){

			int next_node = graph[current_node][i];

			if(check[next_node]==false){
				check[next_node] = true;
				s.push(current_node);
				s.push(next_node);
				break;
			}
		}
	}

}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<int> graph[n+1];
    vector<int> temp_edge;

    // 그래프 초기화
    while(!results.empty()){
    	temp_edge = results.back();
    	graph[temp_edge[0]].push_back(temp_edge[1]);
    	results.pop_back();
    }

    // 그래프 출력
    for(int i=1; i<n+1; i++){
    	cout << "[" << i << "] : ";
    	for(int j=0; j<graph[i].size(); j++){
    		if(j==0)
    			cout << graph[i][j];
    		else
    			cout << ", " << graph[i][j];
    	}
    	cout << endl;
    }

    // 모든 노드에서 DFS
    for(int i=1; i<n+1; i++){
    	// cout << "debug" << i << endl;
    	dfs(i, graph, n);
    }

    //승자배열 출력
	cout << "========WIN=========" << endl;
	for(int i=1; i<n+1; i++)
	{
		cout << "[" << i << "] : ";
		for(int j=0; j<win[i].size(); j++){
			if(j==0)
				cout << win[i][j];
			else
				cout << ", " << win[i][j];
		}
		cout << endl;
	}

	//패자배열 출력
	cout << "========LOSE=========" << endl;
	for(int i=1; i<n+1; i++)
	{
		cout << "[" << i << "] : ";
		for(int j=0; j<lose[i].size(); j++){
			if(j==0)
				cout << lose[i][j];
			else
				cout << ", " << lose[i][j];
		}
		cout << endl;
	}

    return answer;
}

int solution2(int n, vector<vector<int>> results){
	int answer = 0;

	while(!results.empty()){
		vector<int> temp;
		temp = results.back();
		results.pop_back();

		winner_list_add(temp[0], temp[1]);
		loser_list_add(temp[0], temp[1]);

		// // win과 lose 배열에 각각의 선수를 추가한다.
		// win[temp[0]].push_back(temp[1]);
		// lose[temp[1]].push_back(temp[0]);

		// // 패자의 lose배열에 승자의 lose배열요소들을 넣는다.
		// for(int i=0; i<lose[temp[0]].size(); i++){
		// 	bool existed = false;
		// 	for(int j=0; j<lose[temp[1]].size(); j++){
		// 		//패자의 lose배열에 승자의 lose배열요소가 이미있으면
		// 		if(lose[temp[1]][j] == lose[temp[0]][i]){
		// 			existed = true;
		// 		}
		// 	}
		// 	//중복되는 요소가 없으면 삽입
		// 	if(!existed)
		// 		lose[temp[1]].push_back(lose[temp[0]][i]);
		// }

		// //승자의 win배열에 패자의 win배열요소들을 넣는다.
		// for(int i=0; i<win[temp[1]].size(); i++){
		// 	bool existed = false;
		// 	for(int j=0; j<win[temp[0]].size(); j++){
		// 		if(win[temp[0]][j] == win[temp[1]][i]){
		// 			existed = true;
		// 		}
		// 	}
		// 	if(!existed)
		// 		win[temp[0]].push_back(win[temp[1]][i]);
		// }

		// //패자의 win배열요소들의 lose배열에 승자를 넣는다.
		// for(int i=0; i<win[temp[1]].size(); i++){
		// 	bool existed = false;
		// 	for(int j=0; j<lose[win[temp[1]][i]].size(); j++){
		// 		if(lose[win[temp[1]][i]][j] == temp[0]){
		// 			existed = true;
		// 		}
		// 	}
		// 	if(!existed)
		// 		lose[win[temp[1]][i]].push_back(temp[0]);
		// }

		// //승자의 lose배열요소들의 win배열에 패자를 넣는다.
		// for(int i=0; i<lose[temp[0]].size(); i++){
		// 	bool existed = false;
		// 	for(int j=0; j<win[lose[temp[0]][i]].size(); j++){
		// 		if(win[lose[temp[0]][i]][j] == temp[1]){
		// 			existed = true;
		// 		}
		// 	}
		// 	if(!existed)
		// 		win[lose[temp[0]][i]].push_back(temp[1]);
		// }
	}

	//승자배열 출력
	cout << "========WIN=========" << endl;
	for(int i=1; i<n+1; i++)
	{
		cout << "[" << i << "] : ";
		for(int j=0; j<win[i].size(); j++){
			if(j==0)
				cout << win[i][j];
			else
				cout << ", " << win[i][j];
		}
		cout << endl;
	}

	//패자배열 출력
	cout << "========LOSE=========" << endl;
	for(int i=1; i<n+1; i++)
	{
		cout << "[" << i << "] : ";
		for(int j=0; j<lose[i].size(); j++){
			if(j==0)
				cout << lose[i][j];
			else
				cout << ", " << lose[i][j];
		}
		cout << endl;
	}

	// 순위가 확실한 요소의 개수를 구한다
	for(int i=1; i<n+1; i++){
		if(win[i].size()+lose[i].size() == n-1)
			answer++;
	}

	return answer;
}

int main(){
	int n = 5;
	vector<vector<int>> results{{4,3},{4,2},{3,2},{1,2},{2,5}};
	int answer = 0;

	answer = solution(n, results);

	cout << answer << endl;

	return 0;
}