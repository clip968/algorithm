#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if (b == 0) return a;
    else{
        return gcd(b, a % b);
    }
}

int main(){
    int n;
    scanf("%d", &n);

    while(n--){
        int a, b;
        scanf("%d %d", &a, &b);
        int result = gcd(a, b);
        cout << result << "\n";
        
    }
}