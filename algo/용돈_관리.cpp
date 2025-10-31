#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> v(n);
    for(int i=0;i<n;i++){
        scanf("%d", &v[i]);
    }

    int left = *max_element(v.begin(), v.end());
    int right = accumulate(v.begin(), v.end(), 0);
    
    int answer;
    while(left <= right) {
        int cnt{1};
        int mid = (left + right) / 2;
        int curr_money = mid;
        for(int i=0;i<n;i++){
            if(curr_money >= v[i]) {
                curr_money -= v[i];
            }
            else {
                curr_money = mid - v[i];
                cnt++;
            }
        }

        if(cnt <= m){
            right = mid - 1;
            answer = mid;
        }
        else {
            left = mid + 1;
            
        }
    }

    printf("%d",answer);
}