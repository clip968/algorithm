#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
    if(n <= 1){
        return 1;
    }
    else{
        int curr = n * factorial(n - 1);
        while(curr % 10 == 0){
            curr = curr / 10;
        }
        
        return curr % 100000;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int num;
        scanf("%d", &num);
        int result = factorial(num);
        cout << result % 1000 << "\n";
    }
}