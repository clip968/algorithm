#include<bits/stdc++.h>
using namespace std;
int visited[1001];
vector<vector<int>> v;
vector<int> node_size;
int n, m;

void dfs(int next){
    if(visited[next] == 1) return;
    visited[next] = 1;
    m += 1;
    for(auto it : v[next]){
        if(visited[it] == 1) continue;
        dfs(it);
    }
    
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        m = 1;
        int result = 0;
        fill(visited, visited+n+1, 0);
        node_size.clear();
        v.clear();
        v.resize(n+1);
        for(int i{0};i<n;i++){
            int node, num, to;
            cin >> node >> num;
            if(num != 0){
                for(int j{};j<num;j++){
                    cin >> to;
                    v[node].push_back(to);
                }
            }
            
        }

        for(int i{1};i<=n;i++){
            if(!visited[i]){
                m = 0;
                dfs(i);
                node_size.push_back(m);
                result+=1;
            }
        }
        sort(node_size.begin(), node_size.end());
        cout << result << " ";
        for(auto it : node_size){
            cout << it << " ";
        }

        cout << "\n";
    }
}