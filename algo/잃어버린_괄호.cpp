#include<bits/stdc++.h>
using namespace std;

int func(string s) {
    int result = 0;
    string temp = "";
    for(auto k : s) {
        if(k == '+'){
            result += stoi(temp);
            temp = "";
        }
        else temp += k;
    }

    result += stoi(temp);
    return result;
}

int main(){
    string s;
    vector<string> v;
    cin >> s;
    string temp = "";
    for(auto k : s) {
        if(k == '-') {
            v.push_back(temp);
            temp = "";
        }
        else temp += k;
    }

    v.push_back(temp);

    int answer = func(v[0]);
    for(int i=1;i<v.size();++i){
        answer -= func(v[i]);
    }

    cout << answer << "\n";

}