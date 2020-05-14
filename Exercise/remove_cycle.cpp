#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

class Graph{
private:
	vector<int> graph[5001];
	vector<bool> visit;
	int NumOfNode;
public:
	void set_graph(int node1, int node2){
		this->graph[node1].push_back(node2);
		this->graph[node2].push_back(node1);
	}
	void init_visit(){
		for(int i=0; i<this->NumOfNode+1; i++)
			this->visit.push_back(false);
	}
	void set_visit(int i, bool visited){
		this->visit[i] = visited;
	}
	void reset_visit(){
		fill(this->visit.begin(),this->visit.end(),false);
	}
	void print_graph(){
		for(int i=1; i<this->NumOfNode+1; i++){
	    	cout << "[" << i << "] : ";
	    	for(int j=0; j<this->graph[i].size(); j++){
	    		if(j==0)
	    			cout << this->graph[i][j];
	    		else
	    			cout << ", " << this->graph[i][j];
	    	}
	    	cout << endl;
	    }
	}
	//재귀함수를 사용한 사이클 검출 함수
	bool isDfsCycle_recur(int currentNode, int parentNode, int removedNode){
		visit[currentNode] = true;
		for(int i=0; i<graph[currentNode].size(); i++){
			if(graph[currentNode][i] == removedNode)
				continue;
			if(!visit[graph[currentNode][i]]){
				if(isDfsCycle_recur(graph[currentNode][i], currentNode,removedNode)){
					return true;
				}
			}else if(graph[currentNode][i]!=parentNode){
				return true;
			}
		}
		return false;
	}
	//스택을 사용한 사이클 검출 함수
	bool isDfsCycle_stack(int start, int removedNode){
		stack<int> s;
		s.push(start);
		visit[start] = true;
		printf("%d ",start);

		int printedNode = -1;
		int parentNode = -1;
		while(!s.empty()){

			int current_node = s.top();
			s.pop();
			
			for(int i=0; i<graph[current_node].size(); i++){

				int next_node = graph[current_node][i];
				if(next_node == removedNode)
					continue;
				if(visit[next_node] && next_node!=printedNode && next_node!=parentNode){
					cout << "F" << endl;
					cout << "current_node : " << current_node  << endl;
					cout << "next_node : " << next_node << endl;
					return true;
				}
				if(visit[next_node]==false){
					printf("%d ", next_node);
					visit[next_node] = true;
					printedNode = next_node;
					parentNode = current_node;
					// cout << "printedNode : " << printedNode << endl;
					// cout << "parentNode : " << parentNode << endl;
					// pop()을 했었기 때문에 현재 current_node도 넣어줘야한다.
					s.push(current_node);
					s.push(next_node);
					break;
				}
			}
		}
		return false;
	}

	bool DFS_with_stack(int start, int removedNode){ 
		int nodeInCom = 0, edgeInCom = 0;
		bool haveRemovedNode = false;
		stack<int> s;
		s.push(start);
		visit[start] = true;
		nodeInCom++;
		edgeInCom += graph[start].size();
		printf("%d ",start);

		while(!s.empty()){

			int current_node = s.top();
			s.pop();
			for(int i=0; i<graph[current_node].size(); i++){

				int next_node = graph[current_node][i];
				if(visit[next_node]==false){
					printf("%d ", next_node);
					visit[next_node] = true;
					nodeInCom++;
					edgeInCom += graph[next_node].size();
					if(next_node == removedNode)
						haveRemovedNode = true;
					// pop()을 했었기 때문에 현재 current_node도 넣어줘야한다.
					s.push(current_node);
					s.push(next_node);
					break;
				}
			}
		}
		// cout << endl;
		// cout << "nodeInCom : " << nodeInCom << "\tedgeInCom : " << edgeInCom << endl;
		if(haveRemovedNode){
			nodeInCom--;
			edgeInCom -= (graph[removedNode].size()*2);
		}
		edgeInCom /= 2;
		if(edgeInCom >= nodeInCom)
			return true;
		else
			return false;
	}

	bool BFS(int start, int removedNode){
		int nodeInCom = 0, edgeInCom = 0;
		bool haveRemovedNode = false;
		queue<int>q;
		q.push(start);
		this->visit[start] = true;
		nodeInCom++;
		edgeInCom += this->graph[start].size();

		while(!q.empty()){
			int qSize = q.size();
			for(int i=0; i<qSize; i++){
				int x = q.front();
				q.pop();
				for(int j=0; j<this->graph[x].size(); j++){
					int y = this->graph[x][j];
					if(!this->visit[y]){
						q.push(y);
						this->visit[y] = true;
						nodeInCom++;
						edgeInCom += this->graph[y].size();
						if(y == removedNode)
							haveRemovedNode = true;
						}
				}
			}
		} 
		if(haveRemovedNode){
			nodeInCom--;
			edgeInCom -= (this->graph[removedNode].size()*2);
		}
		edgeInCom /= 2;
		if(edgeInCom >= nodeInCom)
			return true;
		else
			return false;
	}

	bool searchComponent(int removedNode){
		reset_visit();
		int startNode = 0;
		bool isCycle = false;
		while(1){
			startNode = 0;
			//방문하지 않은 노드가 있는지 확인
			for(int i=1; i<=NumOfNode; i++){
				if(i==removedNode)
					continue;
				if(!visit[i]){
					startNode = i;
					break;
				}
			}
			//방문하지 않은 노드가 있으면 그 노드부터 DFS실시
			if(startNode!=0){
				isCycle = BFS(startNode,removedNode);
				if(isCycle)
					return true;
			}
			else	// 방문하지 않은 노드가 없으면 while문 종료
				break;
		}
		return false;
	}

	bool searchComponent_modify(int removedNode){
		this->reset_visit();
		int startNode = 0;
		bool isCycle = false;

		//방문하지 않은 노드가 있는지 확인
		for(int i=1; i<=this->NumOfNode; i++){
			if(i==removedNode)
				continue;
			if(!this->visit[i]){
				cout << "hoo!" << endl;
				//방문하지 않은 노드가 있으면 그 노드부터 BFS실시
				isCycle = this->BFS(i,removedNode);
				if(isCycle){
					cout << "ho?" << endl;
					return true;
				}
			}
		}

		return false;
	}

	Graph(int n){
		this->NumOfNode = n;
		this->init_visit();
	}
};

int solution_using_class(int n, vector<vector<int>> edges){
	Graph g = Graph(n);
	int answer = 0;
    vector<int> graph[n+1];
    vector<int> temp_edge;


    // 그래프 초기화
    while(!edges.empty()){
    	temp_edge = edges.back();
    	g.set_graph(temp_edge[0],temp_edge[1]);
    	edges.pop_back();
    }

    // 그래프 출력
    g.print_graph();

    // 각 노드를 제거하고 사이클 테스트
    bool is_loop;
    for(int i=1; i<n+1; i++){
		for(int j=1; j<n+1; j++){
			g.reset_visit();
			if(j==i)
				continue;
			is_loop = g.isDfsCycle_stack(j,i);
			if(is_loop)
				break;
		}
    	if(!is_loop){
    		answer += i;
    		cout << "answer : " << answer << endl;
    	}
    }
    return answer;
}

int solution(int n, vector<vector<int>> edges){
	Graph g = Graph(n);
	int answer = 0;
    vector<int> graph[n+1];
    vector<int> temp_edge;


    // 그래프 초기화
    while(!edges.empty()){
    	temp_edge = edges.back();
    	g.set_graph(temp_edge[0],temp_edge[1]);
    	edges.pop_back();
    }

    // 그래프 출력
    g.print_graph();

    // // 사이클 테스트
    // bool is_loop;
    // is_loop = g.searchComponent();
    // cout << is_loop << endl;

    // 각 노드를 제거하고 사이클 컴포넌트 테스트
    bool isCycle = false;
    for(int i=1; i<n+1; i++){
    	isCycle = g.searchComponent_modify(i);
    	cout << isCycle << endl;
    	if(!isCycle){
    		answer += i;
    	}
    }
    return answer;
}

int main(){
	int n = 4;
	vector<vector<int>> edges{{1,2},{1,3},{2,3},{2,4},{3,4}};
	int answer = 0;

	answer = solution(n, edges);

	cout << answer << endl;

	return 0;
}