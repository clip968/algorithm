#include<bits/stdc++.h>
using namespace std;

int parent[200002]; 
int friendship[200002];

int find(int a){
    if(parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}


int union_find(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b) {
        parent[a] = b;
        friendship[b] += friendship[a];
    }

    return friendship[b];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;

    while(t--){
        int n; cin >> n;

        string a, b;
        map<string, int> m;

        for(int i{};i<n*2;++i) {
            parent[i] = i;
            friendship[i] = 1;
        }
        
        for(int i{};i<n;++i) {
            cin >> a >> b;
            if(m.find(a) == m.end()) m[a] = m.size();
            if(m.find(b) == m.end()) m[b] = m.size();
            cout << union_find(m[a], m[b]) << "\n" ;
        }
    }
}