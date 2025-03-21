#include<bits/stdc++.h>
using namespace std;
vector<int> v;

int main(){
    int result{};
    int n, c;
    scanf("%d%d", &n, &c);
    for(int i{};i<n;i++){
        int temp;
        scanf("%d", &temp);
        v.push_back(temp);
    }
    sort(v.begin(), v.end());

    int left = 1;
    int right = v.back() - v.front();

    while(left <= right) {
        int mid = left + (right - left) / 2;
        int count = 1;
        int installed = v[0];

        for(int i{1};i<n;i++){
            if(v[i] - installed >= mid){
                count++;
                installed = v[i];
                if(count >= c) break;
            }
        }

        if(count >= c) {
            result = mid;
            left = mid + 1;
        }  
        else {
            right = mid - 1;
        }
    }

    printf("%d\n", result);

}