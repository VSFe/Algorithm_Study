/** 
 * 문제: 요세푸스 문제 0 (http://boj.kr/1158)
 * Tier: Silver 5 (2021.01.12 기준)
 * Comment: 큐를 활용할 수 있는 대표적인 문제입니다.
 * 출력이 조금 특이하기 때문에 출력만 유의해서 풀어주세요.
 */

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int N, M;
    queue<int> q;
    vector<int> answer;

    cin >> N >> M;

    for(int i = 1; i <= N; i++) q.push(i);
    
    while(!q.empty()) {
        for(int i = 1; i < M; i++) { // M - 1번은 데이터를 빼고 다시 넣어 줍니다.
            q.push(q.front());
            q.pop();
        }
        answer.push_back(q.front());
        q.pop();
    }

    cout << '<' << answer[0];
    for(int i = 1; i < answer.size(); i++) cout << ", " << answer[i];
    cout << '>';    
}