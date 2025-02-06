#include<bits/stdc++.h>
using namespace std;

int fibo(int n){
    if (n <= 1){
        return n;
    }
    else{
        return fibo(n - 1) + fibo(n - 2);
    }
}

int main(){
    int n;
    scanf("%d", &n);

    while(n--){
        int num;
        scanf("%d", &num);
        int result = fibo(num);
        cout << result << "\n";
    }

}