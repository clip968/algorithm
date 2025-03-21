#include<bits/stdc++.h>
using namespace std;
vector<long long> v;
#define LEAF 262144
pair<int, int> tree[LEAF];
int result_min, result_max;

void init_segment(int node, int start, int end){
    if(start == end) {
        tree[node] = {v[start], v[start]};
        return;
    }

    int mid = (start + end) / 2;
    init_segment(node*2, start, mid);
    init_segment(node*2+1, mid+1, end);
    
    tree[node].first = max(tree[node*2].first, tree[node*2+1].first);
    tree[node].second = min(tree[node*2].second, tree[node*2+1].second);
}

pair<int, int> find_min_max(int node, int start, int end, int left,int right){
    if(left > end || right < start) {
        return{-1e9, 1e9};
    }

    if(left <= start && right >= end) {
        return tree[node];
    }

    int mid = (start + end) / 2;
    pair<int, int> left_result = find_min_max(node*2, start, mid, left, right);
    pair<int, int> right_result = find_min_max(node*2+1, mid+1, end, left, right);
    return {max(left_result.first, right_result.first), min(left_result.second, right_result.second)};
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    v.resize(n);
    for(int i{};i<n;++i){
        scanf("%d", &v[i]);
    }

    init_segment(1, 0, n-1);

    int a, b;
    for(int i{};i<m;++i){
        scanf("%d %d", &a, &b);
        pair<int, int> result = find_min_max(1, 0, n-1, a-1, b-1);
        printf("%d %d\n", result.second, result.first);
    }

    
}