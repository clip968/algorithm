#define DIV 10000
#include<bits/stdc++.h>
using namespace std;

void calculate_fib(long long arr1[2][2], long long arr2[2][2]){
    long long a = arr1[0][0] * arr2[0][0] + arr1[0][1] * arr2[1][0];
    long long b = arr1[0][0] * arr2[0][1] + arr1[0][1] * arr2[1][1];
    long long c = arr1[1][0] * arr2[0][0] + arr1[1][1] * arr2[1][0];
    long long d = arr1[1][0] * arr2[0][1] + arr1[1][1] * arr2[1][1];

    a %= DIV;
    b %= DIV;
    c %= DIV;
    d %= DIV;

    arr1[0][0] = a;
    arr1[0][1] = b;
    arr1[1][0] = c;
    arr1[1][1] = d;
}

void calculate_matrix(long long arr[2][2], long long n){
    if (n == 0 || n == 1){
        return;
    }
    long long b[2][2] = {{1, 1}, {1, 0}};
    calculate_matrix(arr, n/2);
    calculate_fib(arr, arr);

    if(n % 2 != 0){
        calculate_fib(arr, b);
    } 

}

long long fibo(int n){
    if(n == 0) return 0;

    long long a[2][2] = {{1, 1}, {1, 0}};

    calculate_matrix(a, n-1);

    return a[0][0];

}

int main(){
    int t; scanf("%d", &t);
    while(t--){
        long long n; scanf("%lld", &n);
        
        int result = fibo(n);
        printf("%d\n", result % 1000);
    }
}