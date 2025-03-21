#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int, string>>> arr(101, vector<pair<int, string>>(101));
string a;
string b;

pair<int, string> LCS(int m, int n){
    if(m == 0 || n == 0){
        return {0, ""};
    }

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(a[i-1] == b[j-1]){
                arr[i][j] = {arr[i-1][j-1].first + 1, arr[i-1][j-1].second};
                arr[i][j].second += a[i-1];
            } else {
                if(arr[i-1][j].first > arr[i][j-1].first) {
                    arr[i][j] = arr[i-1][j];
                } else {
                    arr[i][j] = arr[i][j-1];
                }
            }
        }
    }
    return {arr[m][n].first, arr[m][n].second};
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t; 
    cin >> t;
    while(t--){
        cin >> a >> b;

        
        for(int i = 0; i <= a.size(); i++) {
            for(int j = 0; j <= b.size(); j++) {
                arr[i][j] = {0, ""};
            }
        }

        pair<int, string> result = LCS(a.size(), b.size());

        cout << result.first << " " << result.second << "\n";
    }
}
