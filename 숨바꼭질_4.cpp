#include<bits/stdc++.h>
using namespace std;

bool visited[100005];
int history[100005];

vector<int> returning_path(int begin, int end){
    vector<int> v;
    int node = end;
    while(node != begin) {
        v.push_back(node);
        node = history[node];
    }
    v.push_back(begin);
    reverse(v.begin(), v.end());
    return v;
}

int main(){
    int n, k;
    scanf("%d%d", &n, &k);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    

    pq.push({0, n});

    while(!pq.empty()) {
        int counter = pq.top().first;
        int curr_spot = pq.top().second;
        pq.pop();


        if(curr_spot == k) {
            printf("%d\n", counter);
            vector<int> v = returning_path(n, k);
            for(auto i : v) {
                printf("%d ", i);
            }
            break;
        }

        if(curr_spot-1 >= 0 && visited[curr_spot-1] == false) {
            history[curr_spot-1] = curr_spot;
            visited[curr_spot-1] = true;
            pq.push({counter+1, curr_spot-1});
        }
        if(curr_spot+1 <= 100000 && visited[curr_spot+1] == false) {
            history[curr_spot+1] = curr_spot;
            visited[curr_spot+1] = true;
            pq.push({counter+1, curr_spot+1});
        }
        if(curr_spot*2 <= 100000 && visited[curr_spot*2] == false) {
            history[curr_spot*2] = curr_spot;
            visited[curr_spot*2] = true;
            pq.push({counter+1, curr_spot*2});
        }
    }

}