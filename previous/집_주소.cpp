#include<bits/stdc++.h>
using namespace std;
int result;

int main(){
    string s;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(true) {
        result = 0;
        cin >> s;
        if(s == "0") return 0;
        
        for(auto k : s) {
            if (k == '0') {
                result += 4;
            }
            else if(k == '1') {
                result += 2;
            }
            else {
                result += 3;
            }
        }
        result += s.size() + 1;
        cout << result << "\n" 
    }
}
