#include<bits/stdc++.h>
using namespace std;
int length[1001];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<vector<pair<int, int>>> v(n+1);
    for(int t{};t<m;t++){
        int from, to, weight;
        scanf("%d%d%d", &from, &to, &weight);
        v[from].push_back({weight, to});
    }

    int start, end;
    scanf("%d%d", &start, &end);
    fill(length, length+n+1, INT_MAX);

    length[start] = 0;
    pq.push({0, start});

    while(!pq.empty()){
        int current_length = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();

         if(current_length > length[current_node]) continue;
         
        for(auto k : v[current_node]){
            int next_node = k.second;
            int next_length = k.first;

            if(length[next_node] > length[current_node] + next_length){
                length[next_node] = length[current_node] + next_length;
                pq.push({length[next_node], next_node});
            }
        }
    }
    printf("%d", length[end]);

}