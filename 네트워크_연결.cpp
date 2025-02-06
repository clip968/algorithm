#include<bits/stdc++.h>
using namespace std;
int parent[10001];


int union_find(int x){
    if(parent[x] == x) return x;
    else return union_find(parent[x]);
}

void union_parent(int x, int y){
    x = union_find(x);
    y = union_find(y);

    if (x < y) parent[y] = x;
    else parent[x] = y;
}

int main(){
    int n, m;
    scanf("%d%d", & n, &m);
    int result{};
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for(int i{};i<m;i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        pq.push({c, {a, b}});
    }

    for(int i{};i<n;i++){
        parent[i] = i;
    }

    while(!pq.empty()){
        int weight = pq.top().first;
        int from = pq.top().second.first;
        int to = pq.top().second.second;
        pq.pop();
        if(union_find(to) == union_find(from)){
            continue;
        }
        union_parent(to, from);
        result+=weight;
    }

    printf("%d\n", result);


}