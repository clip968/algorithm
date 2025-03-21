#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k; scanf("%d %d", &n, &k);
    unsigned long long temp, answer=0;

    priority_queue<unsigned long long, vector<unsigned long long>, greater<unsigned long long>> pq;

    while(n--){
        scanf("%lld", &temp);
        pq.push(temp);
    }

    for(int i=0;i<k;i++){
        unsigned long long a, b;
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();

        temp = a + b;

        pq.push(temp);
        pq.push(temp);
    }

    while(!pq.empty()){
        temp = pq.top();
        pq.pop();
        answer += temp;
    }

    printf("%lld", answer);
}