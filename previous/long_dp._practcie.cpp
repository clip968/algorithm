#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int, string>>> v(101, vector<pair<int, string>>(101));
string a, b;
pair<int, string> dp(int m, int n){
    for(int i{1};i<=m;i++){
        for(int j{1};j<=n;j++){
            if(a[i-1] == b[j-1]) {
                v[i][j] = {v[i-1][j-1].first + 1, v[i-1][j-1].second};
                v[i][j].second += a[i-1];
            }
            else if(a[i-1] != b[j-1]){
                if(v[i-1][j].first > v[i][j-1].first){
                    v[i][j] = v[i-1][j];
                }
                else{
                    v[i][j] = v[i][j-1];
                }
            }
        }
    }
    return v[m][n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--){
        cin >> a >> b;
        for(int i{};i<=a.size();i++){
            for(int j{}; j<=b.size(); j++){
                v[i][j] = {0, ""};
            }
        }

        pair<int, string> result;
        result = dp(a.size(), b.size());

        cout << result.first << " " << result.second << "\n";

    }
}