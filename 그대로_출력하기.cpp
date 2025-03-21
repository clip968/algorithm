#include<bits/stdc++.h>
using namespace std;
int num = 100;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    vector<string> v;
    while(num--) {
        getline(cin, s);
        if(s.empty()) break;
        v.push_back(s);
    }

    for(auto k : v) {
        cout << k << "\n";
    }
}