#include<bits/stdc++.h>
using namespace std;

int main(){
    int ans;
    vector<int> v;
    while(true) {
        ans = 0;
        v.clear();
        int temp; scanf("%d", &temp);
        if(temp == -1) break;

        for(int i = 1; i < temp; ++i){
            if(temp % i == 0){
                ans += i;
                v.push_back(i);
            }
        }

        if(ans == temp) {
            printf("%d = ", temp);
            for(int i = 0; i < v.size(); ++i){
                printf("%d", v[i]);
                if(i < v.size() - 1) printf(" + ");
            }
            printf("\n");
        } else {
            printf("%d is NOT perfect.\n", temp);
        }
    }
}