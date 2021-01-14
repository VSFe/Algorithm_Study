/** 
 * 문제: 제로 (http://boj.kr/10773)
 * Tier: Silver 4 (2021.01.14 기준)
 * Comment: 0이 나올때 가장 최근의 값을 뺍니다.
 * 즉, FIFO 구조를 띄고 있고, 자연스럽게 스택을 사용하시면 됩니다.
 */

#include <iostream>
#include <stack>
using namespace std;

int N;
stack<int> st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        if(tmp == 0) st.pop();
        else st.push(tmp);
    }

    long long result = 0;
    while(!st.empty()) {
        result += st.top();
        st.pop();
    }

    cout << result;
}