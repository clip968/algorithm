#include<bits/stdc++.h>
using namespace std;

map<long long, int> height;

int main(){
    int n; scanf("%d", &n);

    for(int i{};i<n;++i){
        int a, b; 
        scanf("%d %d", &a, &b);

        if(a == 1){
            int max_height{};
            for(int j{};j<4;++j){
                if(height.count(b+j)){
                    max_height = max(max_height, height[b+j]);
                }
            }

            max_height++;
            for(int j{};j<4;++j){
                height[b+j] = max_height;
            }
        }
        else if(a == 2){
            if(height.count(b)){
                height[b] += 4;
            }
            else height[b] = 4;
        }

        else {
            if(height.count(b)) printf("%d\n", height[b]);
            else printf("0\n");
        }
    }

}