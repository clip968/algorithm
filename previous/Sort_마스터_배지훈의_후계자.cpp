#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> arr(n, 0);

    for(int i{};i<n;i++){
        scanf("%d", &arr[i]);
    }

    sort(arr.begin(), arr.end());

    for(int i{};i<m;i++){
        int temp; scanf("%d", &temp);
        auto it = lower_bound(arr.begin(), arr.end(), temp);
        
        if(it != arr.end() && *it == temp){
            int index = distance(arr.begin(), it);
            printf("%d\n", index);
        }
        else printf("-1\n");
    }
}