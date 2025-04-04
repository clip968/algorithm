#include<bits/stdc++.h>
using namespace std;

struct Pos{
    long long x, y;
};
int ans{};
vector<Pos> v;
vector<Pos> temp;

long long dist(Pos a, Pos b){
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    return dx * dx + dy * dy;
}

bool is_triangle(long long a, long long b, long long c){
    if(a > c) swap(a, c);
    if(b > c) swap(b, c);
    
    return a + b == c;
}

int main(){
    int n; scanf("%d", &n);
    for(int i{};i<n;++i){
        long long a, b;
        scanf("%lld %lld", &a, &b);
        v.push_back({a, b});
    }

    vector<vector<long long>> distance(n, vector<long long>(n));
    for(int i{};i<n;++i){
        for(int j{i+1};j<n;++j){
            distance[i][j] = distance[j][i] = dist(v[i], v[j]);
         }
    }

    for(int i{};i<n;++i){
        for(int j{i+1};j<n;++j){
            for(int k{j+1};k<n;++k){
                long long d1 = distance[i][j];
                long long d2 = distance[j][k];
                long long d3 = distance[i][k];

                if(is_triangle(d1, d2, d3)){
                    ans++;
                }
            }
        }
    }
    printf("%d", ans);
}