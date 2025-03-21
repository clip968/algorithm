#include<bits/stdc++.h>
using namespace std;

int fastmultiply(int a, int n){
    if (n == 0) return 1;
    else if(n == 1) return a;
    int result = fastmultiply(a, n/2);
    if (n % 2 == 1) {
        return (a * result * result) % 1000;
    }
    else{
        return (result * result) % 1000;
    }
    
}

int main(){
    int t; scanf("%d", &t);

    while(t--){
        int a, result{1};
        long long n;
        scanf("%d %lld", &a, &n);
        result = fastmultiply(a, n);
        cout << result << "\n";
    }
}