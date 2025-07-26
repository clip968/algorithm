#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; 
    char game;

    cin >> n >> game;

    int tmp;

    set<string> people;
    if(game == 'Y') tmp = 1;
    else if(game == 'F') tmp = 2;
    else tmp = 3;

    for(int i{};i<n;++i){
        string s;
        cin >> s;

        people.insert(s);
    }

    tmp = people.size() / tmp;
    cout << tmp << "\n";
    
}