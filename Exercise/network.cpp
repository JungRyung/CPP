#include <string>
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>

using namespace std;

int dfs(vector<vector<int> > graph){
	int answer = 0;
	vector<bool> check(graph.size(),false);
	for(int tmp = 0; tmp<graph.size(); tmp++){
		if(check[tmp]==false){
			stack<int> s;
			s.push(tmp);
			check[tmp] = true;
			// printf("%d ",tmp);

			while(!s.empty()){

				int current_node = s.top();
				s.pop();
				for(int i=0; i<graph[current_node].size(); i++){
					if(i!=current_node && graph[current_node][i]==1){
						int next_node = i;

						if(check[next_node]==false){
							// printf("%d ", next_node);
							check[next_node] = true;
							// pop()을 했었기 때문에 현재 current_node도 넣어줘야한다.
							s.push(current_node);
							s.push(next_node);
							break;
						}
					}
				}
			}
			answer++;
			cout << "debug" << endl;
		}
	}
	return answer;	
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    answer = dfs(computers);
    return answer;
}

int main(){
	int n = 3;
	vector<vector<int> > computers{{1, 1, 0}, {1, 1, 1}, {0, 1, 1}};
	int answer;

	answer = solution(n, computers);

	cout << answer << endl;

	return 0;
}