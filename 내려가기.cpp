#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; scanf("%d", &n);
    
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    
    int dp_min[] = {a, b, c};
    int dp_max[] = {a, b, c};

    for(int i = 1; i < n; ++i){
        scanf("%d %d %d", &a, &b, &c);
        
        int prev0 = dp_min[0];
        int prev1 = dp_min[1];
        int prev2 = dp_min[2];
        dp_min[0] = min(prev0, prev1) + a;
        dp_min[1] = min({prev0, prev1, prev2}) + b;
        dp_min[2] = min(prev1, prev2) + c;
        
        prev0 = dp_max[0];
        prev1 = dp_max[1];
        prev2 = dp_max[2];
        dp_max[0] = max(prev0, prev1) + a;
        dp_max[1] = max({prev0, prev1, prev2}) + b;
        dp_max[2] = max(prev1, prev2) + c;
    }

    printf("%d %d\n", max({dp_max[0], dp_max[1], dp_max[2]}), min({dp_min[0], dp_min[1], dp_min[2]}));
    return 0;
}