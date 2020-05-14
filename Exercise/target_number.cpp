#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dfs(vector<int> &numbers, int target, int sum, int depth) {
	int answer = 0;
    if (depth == numbers.size()) {
        if (sum == target)
            answer++;
        return answer;
    }
    
    answer += dfs(numbers, target, sum + numbers[depth], depth + 1);
    answer += dfs(numbers, target, sum - numbers[depth], depth + 1);
    return answer;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    answer += dfs(numbers, target, numbers[0], 1);
    answer += dfs(numbers, target, -numbers[0], 1);

    return answer;
}

int main(){
	vector<int> numbers;
	int target = 3;
	int answer;

	numbers.push_back(1);
	numbers.push_back(1);
	numbers.push_back(1);
	numbers.push_back(1);
	numbers.push_back(1);

	answer = solution(numbers, target);

	cout << answer << endl;
}