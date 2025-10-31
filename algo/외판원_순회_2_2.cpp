#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; scanf("%d", &n);
    int flag{};
    int arr[n][n];
    vector<int> cities;
    int result=10000;

    for(int i{};i<n;++i){
        for(int j{};j<n;++j){
            scanf("%d", &arr[i][j]);
        }
    }
    
    for(int i{};i<n;++i){
        cities.push_back(i);
    }
    
    do{
        int temp{};
        for(int i{};i<n-1;++i){
            if(arr[cities[i]][cities[i+1]] == 0) {
                flag = 1;
                break;
            }
            temp += arr[cities[i]][cities[i+1]];
        }
        if(flag == 1){
            flag = 0;
            continue;
        }
        temp += arr[cities.back()][cities.front()];

        result = min(result, temp);
    }while(next_permutation(cities.begin(), cities.end()));

    printf("%d", result);

}