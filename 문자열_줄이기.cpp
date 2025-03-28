#include<bits/stdc++.h>
using namespace std;

int main(){
   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    string s;
    cin >> n >> m;
    cin >> s;
    priority_queue<char, vector<char>, greater<char>> pq;

    for(int i{};i<s.size();++i){
        pq.push(s[i]);
    }
    
    for(int i{};i<m;++i){
        char min_c = pq.top();
        pq.pop();

        auto it = s.find(min_c);
        s.erase(it, 1);
    }
    cout << s;
}   