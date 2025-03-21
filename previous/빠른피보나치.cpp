#include<bits/stdc++.h>
using namespace std;
#define Div 10000

void multiply_matrix(long long A[2][2], long long B[2][2]){
    long long a = A[0][0] * B[0][0] + A[0][1] * B[1][0];
    long long b = A[0][0] * B[0][1] + A[0][1] * B[1][1];
    long long c = A[1][0] * B[0][0] + A[1][1] * B[1][0];
    long long d = A[1][0] * B[0][1] + A[1][1] * B[1][1];

    a %= Div;
    b %= Div;
    c %= Div;
    d %= Div;

    A[0][0] = a;
    A[0][1] = b;
    A[1][0] = c;
    A[1][1] = d;
}

void matrix_calculate(long long A[2][2], long long n){
    if (n ==0 || n == 1){
        return;
    }

    long long B[2][2] = {{1, 1}, {1, 0}};
    matrix_calculate(A, n/2);
    multiply_matrix(A, A);

    if (n % 2 != 0){
        multiply_matrix(A, B);
    }
}

long long fibonacci(long long n){
    if (n == 0){
        return 0;
    }

    long long A[2][2] = {{1,1}, {1,0}};

    matrix_calculate(A, n - 1);

    return A[0][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        long long n; cin >> n;
        cout << fibonacci(n) % 1000 << "\n";
    }

    
}