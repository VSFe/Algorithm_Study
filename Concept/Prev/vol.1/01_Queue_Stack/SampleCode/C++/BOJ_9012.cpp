/** 
 * 문제: 괄호 (http://boj.kr/9012)
 * Tier: Silver 4 (2021.01.14 기준)
 * Comment: 스택 하면 떠올릴 수 있는 가장 유명한 문제입니다.
 * 그런데, 어차피 괄호 종류는 하나인데 굳이 스택을 써야 할까요?
 */

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;

    for(int i = 0; i < N; i++) {
        string str; cin >> str;
        int cnt = 0;
        for(char c: str) {
            if(c == '(') cnt++;
            else if(c == ')' && cnt) cnt--;
            else {
                cnt = -999;
                break;
            }
        }
        if(cnt == 0) cout << "YES\n";
        else cout << "NO\n";
    }
}