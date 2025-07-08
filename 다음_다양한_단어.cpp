#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    string ans;
    ans = s;

    int alpha[26];
    char a[26];
    memset(alpha, -1, sizeof(alpha));

    for(int i{};i<s.length();++i){
        a[i] = s[i];
        alpha[a[i]-'a'] = i;
    }

    if(s.length() == 26){
        if(next_permutation(a, a+27)==true) cout << a << "\n";
        else cout << -1 << "\n";
    }
    else{
        for(int i{};i<26;++i){
            if(alpha[i] == -1){
                char temp = i + 'a';
                ans = ans+temp;
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}