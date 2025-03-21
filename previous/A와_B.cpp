#include<bits/stdc++.h>
using namespace std;

string swapping(string s) {
    string result = "";
    if(s.size() == 1) return s;
    for(int i = s.size()-1;i>=0;i--){
        result += s[i];
    }

    return result;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s, t;

    cin >> s >> t;

    while(s.size() < t.size()){
        if(t[t.size()-1] == 'A') {
            t.pop_back();
        }
        else if(t[t.size()-1] == 'B') {
            t.pop_back();
            t = swapping(t);
        }
    }
    if(s == t) printf("1");
    else printf("0");

}