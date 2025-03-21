#include<bits/stdc++.h>
using namespace std;

vector<int> findDivisors(int n) {
    vector<int> v;
    for(int i{1};i<=n;++i) {
        if(n%i == 0) {
            v.push_back(i);
        }
    }

    return v;
}

int gcd(int a, int b) {
    if(b == 0) {
        return a;
    }

    return gcd(b, a%b);
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    vector<int> v2(n-1);

    for(int i{0};i<n;++i) {
        scanf("%d", &v[i]);
    }

    for(int i{};i<n-1;++i){
        v2[i] = abs(v[i] - v[i+1]);
    }

    int g = v2[0];
    for(int i{1};i<n-1;++i) {
        g = gcd(g, v2[i]);
    }

    vector<int> divisors = findDivisors(g);
    sort(divisors.begin(), divisors.end());
    
    for(int i{1};i<divisors.size();++i) {
        printf("%d ", divisors[i]);
    }
}