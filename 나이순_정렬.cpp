#include<bits/stdc++.h>
using namespace std;

struct temp{
    int num;
    string s;
};

int main(){
    int n;
    cin >> n;
    vector<temp> v(n);
    for(int i{};i<n;++i){
        cin >> v[i].num >> v[i].s;
    }

    stable_sort(v.begin(), v.end(), [](const temp& a, const temp& b) {
        return a.num < b.num; });

    for(const auto& k : v){
        cout << k.num << " " << k.s << "\n";
    }
}