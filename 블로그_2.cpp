#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    
    int b_cnt{}, r_cnt{};
    string s;
    cin >> s;
    for(int i{};i<n;++i){
        if(s[i] == 'B') {
            if(s[i+1] == 'B'){
                continue;
            }
            else if(s[i+1] != 'B'){
                b_cnt++;
            }
        }
        else if(s[i] == 'R'){
            if(s[i+1] == 'R'){
                continue;
            }
            else if(s[i+1] != 'R'){
                r_cnt++;
            }
        }
    }

    if(b_cnt > r_cnt) {
        printf("%d", r_cnt+1);
    }
    else if(r_cnt > b_cnt){
        printf("%d", b_cnt+1);
    }
    else{
        printf("%d", b_cnt+1);
    }

}