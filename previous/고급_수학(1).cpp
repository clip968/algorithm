#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, temp, flag=0; scanf("%d", &n);
    vector<int> v;
    while(n--){
        v.clear();
        flag++;
        for(int i=0;i<3;++i){
            scanf("%d", &temp);
            v.push_back(temp);
        }
        sort(v.begin(), v.end());
        if(v[0]*v[0] + v[1]*v[1] == v[2]*v[2]) {
            printf("Scenario #%d:\nyes\n", flag);
        }
        else{
            printf("Scenario #%d:\nno\n", flag);
        }
        printf("\n");
    }
}