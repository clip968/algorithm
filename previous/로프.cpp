#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; scanf("%d", &n);
    int answer = 0, curr;
    vector<int> v(n);

    for(int i=0;i<n;i++){
        scanf("%d", &v[i]);
    }

    sort(v.begin(), v.end());

    for(int i=0;i<n;i++){
        curr = v[i] * (n - i);
        answer = max(answer, curr);
    }

    printf("%d", answer);
    
}