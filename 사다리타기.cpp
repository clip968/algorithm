#include<bits/stdc++.h>
using namespace std;
bool arr[201][201];
int n, m, d;
int calculate(int x){
    for(int i{m-1};i>=0;--i){
        if(x > 0 && arr[i][x-1] == 1){
            x -= 2;
            // printf("%d\n",curr);
        }
        else if(x < n*2-2 && arr[i][x+1] == 1){
            x += 2;
            // printf("%d\n",curr);
        } 
    }
    // printf("============\n%d\n", curr/2);
    return (x+2)/2;
} 

int main(){
    int t; scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &n, &m, &d);
        memset(arr, 0, sizeof(arr));
        string temp;
        cin.ignore();
        for(int i{};i<m;++i){
            
            getline(cin, temp);
            for(int j{};j<temp.length();j++){
                if(temp[j] == '+') {
                    arr[i][j] = true;
                }
                else{
                    arr[i][j] = false;
                }
                
            }
        }
        int result = calculate((d-1)*2);
        printf("%d\n", result);
        
    }
}