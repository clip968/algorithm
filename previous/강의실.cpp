#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    // int min_end{};
    int answer{};
    priority_queue<int, vector<int>, greater<int>> pq; // 끝나는 시간 저장
    vector<pair<int, int>> v; // 시작하는 시간 저장 겸 오름차순 정렬
    for(int i{};i<n;++i) {
        int dummy, start, end;
        scanf("%d %d %d", &dummy, &start, &end);
        // min_end = min(min_end, end);
        v.push_back({start, end});
    }

    sort(v.begin(), v.end());

    for(int i{};i<n;++i){
        if(!pq.empty() && pq.top() <= v[i].first){
            pq.pop();
        }

        pq.push(v[i].second);
    }

    printf("%d", pq.size());
}