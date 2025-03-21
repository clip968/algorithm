#include<bits/stdc++.h>
using namespace std;
bool visited[100005];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, n});
    while(!pq.empty()){
        int curr_spot = pq.top().second;
        int counter = pq.top().first;
        pq.pop();
        visited[curr_spot] = true;

        if(curr_spot == k) {
            printf("%d\n", counter);
            break;
        }

        if(curr_spot-1 >= 0 && visited[curr_spot-1] == false) {
            pq.push({counter+1, curr_spot-1});
        }
        if(curr_spot+1 <= 100000 && visited[curr_spot+1] == false) {
            pq.push({counter+1, curr_spot+1});
        }
        if(curr_spot*2 <= 100000 && visited[curr_spot*2] == false){
            pq.push({counter, curr_spot*2});
        }

    }

    return 0;
}