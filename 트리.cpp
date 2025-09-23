#include<bits/stdc++.h>
using namespace std;

int main() {
    int idx{1};
    while(true) {
        int n, m;
        scanf("%d %d", &n, &m);
        if(n == 0 && m == 0) break;
        vector<int> v[n+1];

        for(int i=0; i<m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        int tree_cnt{};
        stack<int> s;
        vector<bool> visited(n+1, false);
        for(int i=1; i<=n; i++) {
            if(visited[i]) continue;
            s.push(i);
            long long V{}, E{};
            int sum_deg{};
            
            visited[i] = true;
            

            while(!s.empty()) {
                int cur = s.top(); s.pop();

                V++;
                sum_deg += v[cur].size();
                
                for(int nxt : v[cur]){
                    if(!visited[nxt]) {
                        visited[nxt] = true;
                        s.push(nxt);
                    }
                }
            }
            E = sum_deg / 2;
            if(E == V - 1) tree_cnt++;
        }
        if(tree_cnt == 0) {
            printf("Case %d: No trees.\n", idx++);
        } else if(tree_cnt == 1) {
            printf("Case %d: There is one tree.\n", idx++);
        } else {
            printf("Case %d: A forest of %d trees.\n", idx++, tree_cnt);
        }
    }
    return 0;
}