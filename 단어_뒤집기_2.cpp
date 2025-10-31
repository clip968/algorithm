#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    getline(cin, s);
    stack<char> st;

    
    for(int i{};i<s.length();++i){
        // <> 예외 처리
        if(s[i] == '<'){
            while(!st.empty()){
                cout << st.top();
                st.pop();
            }
            cout << '<';
            while(s[i] != '>'){
                ++i;
                cout << s[i];
            }
        }
        else if(s[i] == ' '){
            while(!st.empty()){
                cout << st.top();
                st.pop();
            }
            cout << ' ';
        }
        else{
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        cout << st.top();
        st.pop();   
    }
    
    return 0;

}