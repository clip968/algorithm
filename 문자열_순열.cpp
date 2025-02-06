#include<bits/stdc++.h>
using namespace std;

int f(string s){
    int flag=1;
    int result=0;
    for(char c : s){
        int temp = c-'a';
        result += temp * flag;
        flag *= -1;
    }
    
    return result;
}

int main(){
    int t; scanf("%d", &t);
    while(t--){
        int count=0;
        string s; 
        vector<string> arr;
        cin >> s;
        do{
            arr.push_back(s);
        } while(next_permutation(s.begin(), s.end()));
    
    for(string q : arr){
        int curr = f(q);
        if (curr > 0) count += 1;
    }
    
    printf("%d\n", count);
        
    }
}