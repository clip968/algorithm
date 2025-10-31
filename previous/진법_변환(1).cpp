#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int num;
    cin >> s >> num;
    int result = 0;
    int val;
    int n = s.size();
    int cnt = 0;
    for(int i=n-1;i>=0;i--){
        if(isdigit(s[i])) val = s[i] - '0';
        else{
            val = s[i] - 'A' + 10;
        }
        result = pow(num, cnt) * val + result; 
        cnt++;
    }
    cout << result << "\n";
}