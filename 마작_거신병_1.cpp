#include<bits/stdc++.h>
using namespace std;

int main(){
    int h, w, c, d;
    scanf("%d %d %d %d", &h, &w, &c, &d);

    vector<int> v(h);
    for(int i{1};i<h;++i){
        v[i] = i;
        if(i > w){
            printf("-1");
            return 0;
        }

        d-=i;
        if(d < 0){
            printf("-1");
            return 0;
        }
    }

    ;
    for(int i{h-1},curr_w = w;i>=0;--i){
        int tmp = min(d, curr_w - v[i]);
        v[i] += tmp;
        d-=tmp;
        --curr_w;
    }
    if(d>0){
        printf("-1");
        return 0;
    }

    for(int i{};i<h;++i){
        for(int j{};j<w;++j){
            if(v[i] > j){
                printf("9 ");
            }
            else printf("1 ");
        }
        printf("\n");
    }
}