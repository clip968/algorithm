#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; scanf("%d", &n);
    vector<int> v(n);

    for(int i = 0; i < n; ++i){
        scanf("%d", &v[i]);
    }

    priority_queue<int> pq; 

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(i == j) continue;
            string s = to_string(v[i]) + to_string(v[j]);
            int tmp = stoi(s);
            if(pq.size() < 3) {
                pq.push(tmp);
            } else if(tmp < pq.top()) {
                pq.pop();
                pq.push(tmp);
            }
        }
    }

    printf("%d\n", pq.top());
}