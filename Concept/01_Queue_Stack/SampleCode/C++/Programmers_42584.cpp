/** 
 * 문제: 주식가격 (https://programmers.co.kr/learn/courses/30/lessons/42584)
 * Difficulty: Level 2
 * Comment: 스택을 활용한 문제입니다.
 * 새로 들어오는 값이 스택의 top 보다 작으면 스택의 값을 빼버리고, 얼마나 오래 있었는지 리턴하면 됩니다.
 * 따라서 들어오는 시간을 기록하기 위해 stack의 구조를 pair로 해주셔야 합니다.
*/

#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    stack<pair<int, int>> st;

    for(int i = 0; i < prices.size(); i++) {
        int price = prices[i];
        while(!st.empty() && st.top().second > price) {
            pair<int, int> p = st.top(); st.pop();
            answer[p.first] = i - p.first;
        }
        st.push({i, price});
    }
    
    while(!st.empty()) {
        pair<int, int> p = st.top(); st.pop();
        answer[p.first] = prices.size() - p.first - 1;
    }
    
    return answer;
}

int main() { // Driver
    vector<int> vec = {1, 2, 3, 2, 3};
    vector<int> result = solution(vec);

    for(int i : result) cout << i << ' ';
}