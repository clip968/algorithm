#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s, target;
    cin >> s >> target;
    vector<char> t;
    for(int i=0;i<s.size();i++){
        t.push_back(s[i]);

        if(t.size() >= target.size()) {
            bool flag = true;
            for(int i=0;i<target.size();i++){
                if(t[t.size() - target.size() + i] != target[i]) {
                    flag = false;
                }
            }
            if(flag == true) {
                for(int i=0;i<target.size();i++){
                    t.pop_back();
                }
            }
        }
        
    }
    if(t.empty()) cout << "FRULA";
    else {
        for(char k : t) {
            cout << k;
        }
    }
    
}