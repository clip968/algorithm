#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; 
    scanf("%d", &n);
    vector<int> v;
    
    for(int i = 0; i < n; ++i){
        int temp;
        scanf("%d", &temp);
        temp *= -1;
        auto k = lower_bound(v.begin(), v.end(), temp);
        if(k == v.end()) {
            v.push_back(temp);
        } else {
            *k = temp;
        }
    }
    printf("%d", v.size());
    return 0;
}