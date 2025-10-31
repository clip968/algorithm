#include<bits/stdc++.h>
using namespace std;

int arr[1001][1001];

int main(){
    int n; scanf("%d", &n);
    memset(arr, 0, sizeof(arr));

    priority_queue<pair<int,int>> pq;

    for(int i{};i<n;++i){
        int x, y;
        scanf("%d %d", &x, &y);

        pq.push({y, x});
    }

    while(!pq.empty()){
        int x{pq.top().second};
        int y{pq.top().first};
        pq.pop();

        
    }

}