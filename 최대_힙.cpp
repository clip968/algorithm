#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; scanf("%d", &n);
    priority_queue<int> pq;
    while(n--){
        int k; scanf("%d", &k);
        if (k == 0){
            if (pq.empty()) printf("0\n");
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