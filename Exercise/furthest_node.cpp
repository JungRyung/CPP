#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int bfs_search(vector<int> graph[],int start, int target_number, int graph_size){
	queue<int> q;
	q.push(start);
	vector<bool> visit(graph_size+1, false);
	visit[start] = true;

	int level = 0;

	while(!q.empty()) {

		cout << "=========== level : " << level << " ===========" << endl;

		int qSize = q.size();

		for(int i=0; i<qSize; i++){
			int x = q.front();
			q.pop();
			cout << x << endl;
			if(x==target_number)
				return level;
			for (int j=0; j<graph[x].size(); j++) {
				int y = graph[x][j];
				if(!visit[y]) {
					q.push(y);
					visit[y] = true;
				}
			}
		}
		level++;
	}
	// cout << "debug" << endl;
	return 0;
}

int BFS(vector<int> graph[], int start, int n){
	int answer = 0;
	queue<int>q;
	q.push(start);
	vector<bool> visit(n+1, false);
	visit[start] = true;

	int level = 0;

	while(!q.empty()){
		answer = 0;
		cout << "=========== level : " << level << " =============" << endl;

		int qSize = q.size();

		for(int i=0; i<qSize; i++){
			answer++;
			int x = q.front();
			q.pop();
			cout << x << endl;
			for(int j=0; j<graph[x].size(); j++){
				int y = graph[x][j];
				if(!visit[y]){
					q.push(y);
					visit[y] = true;
				}
			}
		}
		level++;
	}
	return answer;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<int> graph[n+1];
    vector<int> temp_edge;

    // 그래프 초기화
    while(!edge.empty()){
    	temp_edge = edge.back();
    	graph[temp_edge[0]].push_back(temp_edge[1]);
    	graph[temp_edge[1]].push_back(temp_edge[0]);
    	edge.pop_back();
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

    // BFS
    answer = BFS(graph, 1, n);

    return answer;
}

int main(){
	int n = 6;
	vector<vector<int>> edge{{3,6},{4,3},{3,2},{1,3},{1,2},{2,4},{5,2}};
	int answer = 0;

	answer = solution(n, edge);

	cout<< answer << endl;

	return 0;
}