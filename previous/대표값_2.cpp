#include<bits/stdc++.h>
using namespace std;

int main() {
    multiset<int> v;
    int ans=0, median=0, temp;
    for(int i=0;i<5;++i) {
        scanf("%d", &temp);
        v.insert(temp);
        ans+=temp;
    }
    auto k = v.begin();
    advance(k, 2);
    printf("%d\n%d", ans/5, *k);
}