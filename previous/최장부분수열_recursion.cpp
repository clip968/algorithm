#include<bits/stdc++.h>
using namespace std;
string a;
string b;
int LCS(int m, int n){
    if (m == 0 || n == 0){
        return 0;
    }
    else if(a[m-1] == b[n-1]){
        return LCS(m - 1, n - 1) + 1;
    }
    else if(a[m-1] != b[n-1]){
        return max(LCS(m - 1, n), LCS(m, n-1));
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        
        cin >> a >> b;

        int result = LCS(a.size(), b.size());

        cout << result << "\n";
    }
}