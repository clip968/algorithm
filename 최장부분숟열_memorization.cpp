#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> arr(101);
string a;
string b;

int LCS(int m, int n){
    if(arr[m][n] != -1){
        return arr[m][n];
    }
    if (m == 0 || n == 0){
        return 0;
    }
    else if(a[m-1] == b[n-1]){
        arr[m][n] = LCS(m - 1, n - 1) + 1;
    }
    else if(a[m-1] != b[n-1]){
        arr[m][n] = max(LCS(m - 1, n), LCS(m, n-1));
    }
    return arr[m][n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t; cin >> t;
    while(t--){
        arr = vector<vector<int>>(101, vector<int>(101, -1));
        cin >> a >> b;

        int result = LCS(a.size(), b.size());
        
        cout << result << "\n";
    }
}