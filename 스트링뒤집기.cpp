#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        string words;
        cin >> words;
        for(int i = words.size() - 1;i >= 0;i--){
            cout << words[i];
        }
        cout << "\n";
    }
}