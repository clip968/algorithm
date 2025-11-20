#include<bits/stdc++.h>
using namespace std;

int main() {
    int e, s, m; scanf("%d %d %d", &e, &s, &m);

    int year{e};
    
    while(true){
        if((year-s)%28 == 0 && (year-m)%19 ==0){
            printf("%d\n", year);
            break;
        }
        year += 15;
    }
    return 0;
}