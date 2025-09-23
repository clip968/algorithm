#include <bits/stdc++.h>
using namespace std;

bool is_valid(string s) {
    for(int i{1};i<=s.size()/2;++i){
        if(s.substr(s.size()-i) == s.substr(s.size()-2*i,i)) return true;
    }
    return false;
}

void dfs(int index, string s, int n) {
    if(is_valid(s)) return;

    if(index == n) {
        printf("%s\n", s.c_str());
        exit(0);
    }

    for(int i{1};i<=3;++i){
        dfs(index+1,s+to_string(i), n);
    }
}

int main() {
    int n; scanf("%d", &n);
    dfs(0,"",n);
    return 0;
}
