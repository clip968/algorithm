#include<bits/stdc++.h>
using namespace std;

vector<vector<long long>> multiply(vector<vector<long long>>& A, vector<vector<long long>>& B, int n) {
    vector<vector<long long>> result(n, vector<long long>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                result[i][j] += (A[i][k] * B[k][j]) % 1000;
                result[i][j] %= 1000;
            }
        }
    }
    return result;
}

vector<vector<long long>> power(vector<vector<long long>>& A, long long B, int n) {
    if(B == 1) return A;
    
    if(B % 2 == 0) {
        vector<vector<long long>> temp = power(A, B/2, n);
        return multiply(temp, temp, n);
    } else {
        vector<vector<long long>> temp = power(A, B-1, n);
        return multiply(temp, A, n);
    }
}

int main() {
    int n;
    long long b;
    cin >> n >> b;
    
    vector<vector<long long>> A(n, vector<long long>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> A[i][j];
            A[i][j] %= 1000;
        }
    }
    
    vector<vector<long long>> result = power(A, b, n);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}