#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; scanf("%d", &n);
    int cnt = 0;
    int curr = 0;
    vector<int> v;
    
    for(int i{};i<n;i++){
        int temp; scanf("%d", &temp);

        auto k = lower_bound(v.begin(), v.end(), temp);
        if(k == v.end()) {
            v.push_back(temp);
        }
        else{
            *k = temp;
        }
    }

    printf("%d\n", v.size());
    

    
}