/** 
 * 문제: 기능개발 (https://programmers.co.kr/learn/courses/30/lessons/42586)
 * Difficulty: Level 2
 * Comment: "뒤에 있는 기능은 앞에 있는 기능이 배포될 때 함께 배포된다." 라는 말에 주목하세요.
 * 즉, 모든 기능이 순차적으로 배포되어야 합니다.
 * 순차적이면 어떤 자료구조를 사용하면 될까요? 큐죠?
*/

#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<pair<int, int>> q;
    int time = 0;

    for(int i = 0; i < progresses.size(); i++) q.push({progresses[i], i});
    while(!q.empty()) {
        int X = q.front().first, Y = speeds[q.front().second];
        int cnt = 1;

        while(X + Y * time < 100) time++;
        q.pop();

        while(!q.empty()) {
            if(q.front().first + speeds[q.front().second] * time >= 100) {
                q.pop();
                cnt++;
            } else break;
        }

        answer.push_back(cnt);
    }
    return answer;
}

int main() { // Driver
    vector<int> progress = {95, 90, 99, 99, 80, 99};
    vector<int> speeds = {1, 1, 1, 1, 1, 1};
    vector<int> result = solution(progress, speeds);

    for(int i : result) cout << i << ' ';
}