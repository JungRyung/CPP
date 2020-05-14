#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>

using namespace std;

int bfs_search(vector<int> graph[],int start, int target_number, int graph_size);
int solution(string begin, string target, vector<string> words);


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

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int word_length = begin.length();
    int words_size = words.size();
    vector<int> graph[words.size()+1];
    vector<bool> check(words.size()+1,false);

    int target_number = 0;

    //graph 초기화
    for(int i=0; i<words.size(); i++){
    	int diff = 0;
    	for(int j=0; j<word_length; j++){
    		if(target.compare(words[i])==0)
    			target_number = i+1;
    		if(begin[j]!=words[i][j])
    			diff++;
    	}
    	if(diff==1){
    		graph[0].push_back(i+1);
    		graph[i+1].push_back(0);
    		// cout << i+1 << " ";
    	}
    }
    // cout << endl;

    for(int i=0; i<words.size()-1; i++){
    	for(int j=i+1; j<words.size(); j++){
    		int diff = 0;
    		for(int k=0; k<word_length; k++)
    			if(words[i][k]!=words[j][k])
    				diff++;
			if(diff==1){
				graph[i+1].push_back(j+1);
				graph[j+1].push_back(i+1);
				// cout << j+1 << " ";
			}
    	}
    	// cout << endl;
    }

    // 그래프 출력
    for(int i=0; i<words.size()+1; i++){
    	cout << i << " : ";
    	for(int j=0; j<graph[i].size(); j++)
    		cout << graph[i][j];
    	cout << endl;
    }
    cout <<  "target_number : " << target_number << endl;

    // answer = dfs(graph, check);
    answer = bfs_search(graph, 0,6,words_size);

    return answer;
}

int main(){
	string begin = "hit";
	string target = "cog";
	vector<string> words;
	int answer;

	words.push_back("hot");
	words.push_back("dot");
	words.push_back("dog");
	words.push_back("lot");
	words.push_back("log");
	words.push_back("cog");

	answer = solution(begin, target, words);

	cout << answer << endl;

	return 0;
}