#include<bits/stdc++.h>
using namespace std;
unordered_set<int> v;

int bfs(int start, int end) {
    if(start == end) return 0;
    unordered_set<int> visited; //현재 채널, 이동 횟수
    queue<pair<int, int>> q;

    q.push({start, 0});
    visited.insert(start);

    while(!q.empty()){
        int curr_spot = q.front().first;
        int curr_temp = q.front().second;
        q.pop();

        for(int i{};i<=9;++i){
            if(v.find(i) != v.end()) continue;

            int temp = curr_spot + i;
            if(temp == end) return curr_temp + 1;

            if(visited.find(temp) == visited.end()) {
                visited.insert(temp);
                q.push({temp, curr_temp + 1});
            }
            temp = curr_spot - i;
            if(temp >= 0){
                if(temp == end) return curr_temp + 1;

                if(visited.find(temp) == visited.end()){
                    visited.insert(temp);
                    q.push({temp, curr_temp + 1});
                }
            }
            
        }
    }
}

int main(){
    int end;
    scanf("%d", &end);
    int k; scanf("%d", &k);
    for(int i{};i<k;++i){
        int temp;
        scanf("%d", &temp);
        v.insert(temp);
    }

    printf("%d", bfs(100, end));
}