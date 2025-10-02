#include<bits/stdc++.h>
using namespace std;
string year = "2023";
bool chk(int n){
    string s = to_string(n);
    int idx{};
    if(s.size() < 4){
        return false;
    }

    for(auto k : s){
        if(k == year[idx]){
            idx++;
        }
        if(idx == 4){
            return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int answer{};
    for(int i{1};i<=n;++i){
        if(chk(i)){
            answer++;
        }
    }

    cout << answer;

    
}