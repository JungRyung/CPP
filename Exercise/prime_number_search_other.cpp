#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

bool checkNumber(int i, string numbers);
int solution(string numbers) {
	int answer = 0;
	sort(numbers.begin(), numbers.end(), greater<int>());
	vector<bool> temp(stoi(numbers)+1);
	for (int i = 2; i <= stoi(numbers); i++) {
		//i가 소수이고 numbers의 조합으로 만들 수 있는 숫자면 answer++
		if (temp[i]==false && checkNumber(i,numbers)) {
			answer++;
		}
		//i가 소수이면 i의 배수는 전부 소수가 아니다.
		if (temp[i] == false) {
			for (int j = i; j <= stoi(numbers); j += i) {
				temp[j] = true;
			}
		}
	}
	
	return answer;
}

// checkNumber는 i가 numbers의 조합으로 만들 수 있는 숫자인지 확인
bool checkNumber(int i,string numbers) {
	bool flag = false;
	// visit는 numbers의 길이와 같게, number의 요소에 방문한적 있는지 확인
	vector<bool> visit(numbers.length());
	while (i != 0) {
		flag = false;
		int temp = i % 10;	//가장 아래 자리수를 분리해서 temp에 저장
		for (int j = 0; j <= numbers.length(); j++) {
			// temp가 numbers에 있는 숫자와 일치하고 방문한 적이 없으면
			if (temp == numbers[j]-'0'&&visit[j]==0) {
				flag = true;
				visit[j] = 1;
				break;	// for문 탈출
			}
		}
		// 겹치는 사항이 없으면 false를 반환
		if (flag == false)
			return false;

		i /= 10;	//다음 자리수가 있으면 반복
	}

	return true;
}

int main()
{
	string numbers = "011";
	int answer;

	answer = solution(numbers);

	cout << answer << endl;
	return 0;
}
