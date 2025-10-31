//
// Created by clip968 on 25. 1. 18.
//
#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int result{};
    scanf("%d",&n);
    vector<int> v;
    for(int i=0;i<n;i++) {
        int temp;
        scanf("%d",&temp);
        v.push_back(temp);
    }
    int x; scanf("%d",&x);
    sort(v.begin(),v.end());
    int low = 0; int high = v.size()-1;
    while(low<high) {
        if (v[low]+v[high]==x) {
            result++;
        }
        else if(v[low]+v[high]<x) {
            low++;
        }
        else {
            high--;
        }
    }

    printf("%d",result);
    return 0;
}
