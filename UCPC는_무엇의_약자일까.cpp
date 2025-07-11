#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    getline(cin, s);
    cin.ignore();

    queue<char> q;
    q.push('U'); q.push('C'); q.push('P'); q.push('C');

    for(int i{};i<s.size();i++){
        if(s[i] == ' ') continue;
        if(!q.empty() && s[i] == q.front()){
            q.pop();
        }
    }

    if(q.empty()) cout << "I love UCPC";
    else cout << "I hate UCPC";
}