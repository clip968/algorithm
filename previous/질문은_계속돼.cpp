#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<int> v(n+2, 0);
    v[1] = 1;
    
    vector<string> results;
    
    for(int i = 2; i <= n + 1; ++i) {
        int a, x, y;
        scanf("%d %d %d", &a, &x, &y);
        
        bool flag = false;

        if(a == 1){
            int curr_hap = v[y] - v[x-1];
            if(curr_hap == y - x + 1){
                flag = true;
            }
        }
        else if(a == 2){
            int curr_hap = v[y] - v[x-1];
            if(curr_hap == 0){
                flag = true;
            }
        }

        if(flag == true){
           v[i] = v[i-1] + 1;
        }
        else{
            v[i] = v[i-1];
        }

        results.push_back(flag ? "Yes" : "No");
    }
    
    for(const auto& result : results) {
        printf("%s\n", result.c_str());
    }
    
    return 0;
}