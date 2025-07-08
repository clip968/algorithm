#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i{};i<n;++i){
        int tmp; scanf("%d", &tmp);
        pq.push(tmp);
    }
    int result{};

    while(pq.size() > 1){
        int d1 = pq.top();
        pq.pop();
        int d2 = pq.top();
        pq.pop();
        result += d1 + d2;
        pq.push(d1 + d2);
    }

    printf("%d\n", result);
}