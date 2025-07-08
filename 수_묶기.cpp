#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; scanf("%d", &n);
    
    priority_queue<int> plus_pq;
    priority_queue<int, vector<int>, greater<int>> minus_pq;

    int one{}, zero{};

    for(int i{};i<n;++i){
        int tmp; scanf("%d", &tmp);
        
        if(tmp > 1) plus_pq.push(tmp);
        else if(tmp == 1) one++;
        else if(tmp == 0) zero++;
        else minus_pq.push(tmp);
    }

    int result{};

    while(plus_pq.size() > 1){
        int d1 = plus_pq.top();
        plus_pq.pop();
        int d2 = plus_pq.top();
        plus_pq.pop();

        result += (d1 * d2);
    }

    while(!plus_pq.empty()) {
        result += plus_pq.top();
        plus_pq.pop();
    }

    while(minus_pq.size() > 1){
        int d1 = minus_pq.top();
        minus_pq.pop();
        int d2 = minus_pq.top();
        minus_pq.pop();

        result += (d1 * d2);
    }

    while(!minus_pq.empty()){
        if(zero > 0){
            minus_pq.pop();
            zero--;
        }
        else{
            result += minus_pq.top();
            minus_pq.pop();
        }
    }

    result += one;

    printf("%d\n", result);
}