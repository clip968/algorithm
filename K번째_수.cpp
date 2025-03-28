#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    priority_queue<int, vector<int>, greater<int>> pq;
    int tmp;
    for(int i{};i<n;++i){
        scanf("%d", &tmp);
        pq.push(tmp);
    }

    while(m--){
        tmp = pq.top();
        pq.pop();
    }

    printf("%d", tmp);
}