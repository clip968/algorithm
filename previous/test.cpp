#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int num;
    cin >> s >> num;
    long long result = 0;
    long long val;
    int n = s.size();
    for(int i=0;i<n;i++){
        if(s[i] >= '0' && s[i] <= '9') {
            val = s[i] - '0';
        } else {
            val = s[i] - 'A' + 10;
        }
        if (result > (LLONG_MAX - val) / num) {
            cout << "overflow" << endl;
            return 0;
        }
        result = result * num + val; 
    }
    cout << result << endl;
    return 0;
}