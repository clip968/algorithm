#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
string a, b;
int LCS(int m, int n){
    if(v[m][n] != -1) return v[m][n];

    else if(m==0||n==0) return 0;

    else if(a[m-1] == b[n-1]) return v[m][n] = LCS(m-1, n-1) + 1;

    else if(a[m-1] != b[n-1]) return v[m][n] = max(LCS(m-1,n), LCS(m, n-1));

    return v[m][n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        cin >> a >> b;
        v = vector<vector<int>>(101, vector<int>(101, -1));
        int result = LCS(a.size(), b.size());

        cout << result << "\n";
    }
}