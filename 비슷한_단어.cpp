#include<bits/stdc++.h>
using namespace std;

// 두 단어가 비슷하다면 들어간 알파벳이 똑같을 것이다(순서 무관)
bool isvalid(string first, string second){
    // 두 단어의 길이 차이가 2 이상이라면 빠꾸
    if(abs((int)first.length() - (int)second.length()) >= 2) return false;

    vector<int> c(26, 0);
    for(auto& k : first) {
        c[k-'A']++;
    }
    for(auto& k : second){
        c[k-'A']--;
    }
    int diff{};
    for(auto& k : c){
        diff += abs(k);
    }
    
    

    return diff <= 2;
} 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    string first, tmp;
    cin >> first;

    vector<string> v;
    for(int i{1};i<n;++i){
        cin >> tmp;
        v.push_back(tmp);
    }

    int ans{};
    for(auto& second : v){
        if(isvalid(first, second)){
            ans++;
        }
    }

    cout << ans << "\n";
    
}