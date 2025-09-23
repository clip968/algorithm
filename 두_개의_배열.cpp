#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, m; scanf("%d %d", &n, &m);
        vector<int> a(n), b(m);
        
        for(int i = 0; i < n; ++i){
            scanf("%d", &a[i]);
        }
        for(int i = 0; i < m; ++i){
            scanf("%d", &b[i]);
        }

        sort(b.begin(), b.end()); 

        long long sum = 0;
        for(int i = 0; i < n; ++i) {
            int pos = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
            
            int best_b = b[0];
            int min_diff = abs(a[i] - b[0]);
            
            if(pos < m) {
                int diff = abs(a[i] - b[pos]);
                if(diff < min_diff || (diff == min_diff && b[pos] < best_b)) {
                    min_diff = diff;
                    best_b = b[pos];
                }
            }
            if(pos > 0) {
                int diff = abs(a[i] - b[pos-1]);
                if(diff < min_diff || (diff == min_diff && b[pos-1] < best_b)) {
                    min_diff = diff;
                    best_b = b[pos-1];
                }
            }
            
            sum += best_b;
        }
        printf("%lld\n", sum);
    }
    return 0;
}