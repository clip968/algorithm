#include<bits/stdc++.h>
using namespace std;

struct Compare{
    bool operator()(int a, int b){
        if(abs(a) == abs(b)) return a > b;
        return abs(a) > abs(b);
    }
};

int main(){
    priority_queue<int, vector<int>, Compare> pq;
    int n; scanf("%d", &n);
    while(n--){
        int k; scanf("%d", &k);
        if(k == 0){
            if(pq.empty()) printf("0\n");
            else{
                printf("%d\n", pq.top());
                pq.pop();
            }
        }
        else{
            pq.push(k);
        }
    }
}