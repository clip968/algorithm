#include<bits/stdc++.h>
using namespace std;

vector<string> split(string input, char d){
    vector<string> v;
    stringstream mystream(input);
    string token;

    while(getline(mystream, token, d)){
        v.push_back(token);
    };

    return v;
}

int func(string a){
    int result{};
    vector<string> temp = split(a, '+');

    for(int i{};i<temp.size();++i){
        result += stoi(temp[i]);
    }

    return result;
}

int main(){
    string s;
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    vector<string> v = split(s, '-');
    int result{};

    for(int i{};i<v.size();++i){
        int tmp = func(v[i]);
        if(i == 0) {
            result += tmp;
        }
        else{
            result -= tmp;
        }
    }

    cout << result << "\n";
}