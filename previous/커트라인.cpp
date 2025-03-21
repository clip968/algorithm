#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    priority_queue<int, vector<int>> pq;

    for(int i{};i<n;++i){
        int temp;
        scanf("%d", &temp);
        pq.push(temp);
    }

    for(int i{1};i<=k;++i){
        if(i == k) {
            int answer = pq.top();
            printf("%d", answer);
            return 0;
        }
        pq.pop();
    }
}