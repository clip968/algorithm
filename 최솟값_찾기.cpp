#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, l;
    scanf("%d %d", &n, &l);

    vector<int> v(n);
    deque<pair<int, int>> dq;

    for(int i{};i<n;++i){
        scanf("%d", &v[i]);

        if(!dq.empty() && dq.front().second <= i - l){
            dq.pop_front();
        }

        while(!dq.empty() && dq.back().first > v[i]){
            dq.pop_back();
        }

        dq.push_back({v[i], i});

        printf("%d ", dq.front().first);
    }
}