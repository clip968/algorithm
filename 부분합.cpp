#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, s;
    scanf("%d %d", &n, &s);

    vector<int> arr(n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    
    int start{0}, end{0};
    int sum{arr[0]};
    int ans{INT_MAX};
    while(start < n && end < n) {
        if(sum < s) {
            end++;
            if(end < n) sum += arr[end];
        } else {
            ans = min(ans, end - start + 1);    
            sum -= arr[start];
            start++;
        }
    }
    if(ans == INT_MAX) ans = 0;
    printf("%d\n", ans);
    return 0;
}