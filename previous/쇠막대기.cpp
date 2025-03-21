#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int answer = 0;
    string s;
    cin >> s;

    stack<char> st;

    for(int i=0;i<s.size();i++){
        if(i < s.size()-1 && s[i] == '(' && s[i+1] == ')') {
            answer += st.size();
            i++;
        }

        else if(s[i] == ')') {
            answer++;
            st.pop();
        }
        else if(s[i] == '(') {
            st.push(s[i]);
        }
    }

    cout << answer;
}