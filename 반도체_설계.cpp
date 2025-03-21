#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; scanf("%d", &n);
    vector<int> v;
    for(int i{};i<n;++i){
        int temp;
        scanf("%d", &temp);
        auto it = upper_bound(v.begin(), v.end(), temp);
        if(it != v.end()) *it = temp;
        else{
            v.push_back(temp);
        }
    }

    printf("%d", v.size());
}