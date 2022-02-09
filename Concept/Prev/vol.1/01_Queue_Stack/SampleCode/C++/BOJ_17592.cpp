/** 
 * 문제: 과제는 끝나지 않아! (http://boj.kr/17952)
 * Tier: Silver 3 (2021.01.14 기준)
 * Comment: 하다가 새로운 것이 들어오면 이어서 하는 것이 아니라
 * 새로 받은 것 부터 한다고 합니다.
 * 당연히 스택이겠죠?
 */

#include <iostream>
#include <stack>
using namespace std;

int score = 0;
int N;
stack<pair<int, int>> st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        int x, point, minute;
        cin >> x;

        if(x == 1) {
            cin >> point >> minute;
            st.push({point, minute});
        }

        if(!st.empty() && --st.top().second == 0) {
            score += st.top().first;
            st.pop();
        }
    }

    cout << score;
}