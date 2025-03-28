#include<bits/stdc++.h>
using namespace std;

bool chk(const string& s, int tmp){
    if(s[tmp] == 'A' || s[tmp] == 'E' || s[tmp] == 'I' || s[tmp] == 'O' || s[tmp] == 'U'){
        return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string s; cin >> s;

    int cnt{};
    
        for(int i{};i<n-m;++i){
            if(chk(s, s.size()-1)){ // 맨 끝이 모음일경우 빼버림
                s.pop_back();
            }
            else{ //맨 끝이 모음이 아닐 경우
                if(s.size() >=2 && s[s.size()-2] != 'A') {
                    s.erase(s.size()-2, 1);
                    
                }
                else if(s.size() >=3 && s[s.size()-3] != 'A') {
                    s.erase(s.size()-3, 1);
                    
                }
                else{
                    s.erase(0, 1);
                }
            }
        }
    
        if(s.size()>=3 && !chk(s, s.size()-1) && s[s.size()-2] == 'A' && s[s.size()-3] == 'A'){
            printf("YES\n");
            for(int i = s.size()-m;i<s.size();++i){
                printf("%c", s[i]);
            }
        }
        else{
            printf("NO");
        }
        return 0;
    }
    
