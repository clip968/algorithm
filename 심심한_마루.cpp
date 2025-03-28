#include<bits/stdc++.h>
using namespace std;
vector<bool> sensor(360, false);
int main(){
    int n; scanf("%d", &n);

    for(int i{};i<n;++i){
        int a, b;
        scanf("%d %d", &a, &b);
        int start = (a - b + 360) % 360;
        int end = (a + b) % 360;

        if(start <= end) {
            for(int j{start};j<=end;++j){
                sensor[j] = true;
            }
        }
        else{
            for(int j{start};j<360;++j){
                sensor[j] = true;
            }
            for(int j{0};j<=end;++j){
                sensor[j] = true;
            }
        }
    }

    int cnt{};
    for(auto k : sensor){
        if(k == true){
            cnt++;
        }
    }

    printf("%d", cnt);

}