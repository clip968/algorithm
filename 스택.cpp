#include<bits/stdc++.h>
using namespace std;


int main(){
    int t; scanf("%d", &t);
    stack<int> s;
    while(t--){
        string str;
        int n;
        cin >> str;
        if(str == "push"){
            scanf("%d", &n);
        }
        
        if(str == "push"){
            s.push(n);
        }
        else if(str == "top"){
            if(s.empty()) printf("-1\n");
            
            else {int k = s.top(); 
            printf("%d\n", k);}
        }
        else if(str == "size"){
            printf("%d\n", s.size());
        }
        else if(str == "pop"){
            if(s.empty()) printf("-1\n");
            else {
                printf("%d\n", s.top());
                s.pop();
            }
        }
        else if(str == "empty"){
            printf("%d\n", s.empty());
        }

    }
    
}