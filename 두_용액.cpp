#include<bits/stdc++.h>
using namespace std;
vector<int> v;

int main(){
    int n;
    scanf("%d", &n);

    for(int i{};i<n;i++){
        int t; scanf("%d", &t);
        v.push_back(t);
    }

    sort(v.begin(), v.end());
    int temp{};
    int minn{INT_MAX};
    int lo{}, hi{n-1};
    int ans1{}, ans2{};
    while(lo < hi){
        if(abs(v[lo] + v[hi]) < minn){
            minn = abs(v[lo] + v[hi]);
            ans1 = v[lo];
            ans2 = v[hi];
        }

        if(abs(v[lo + 1] + v[hi]) < abs(v[lo] + v[hi-1])) lo++;
        else hi--;
    }

    printf("%d %d", ans1, ans2);
}