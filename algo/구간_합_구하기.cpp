#include<bits/stdc++.h>
using namespace std;
long long tree[2097152];
vector<long long> v;
void init(int node, int start, int end) {
    if(start == end) {
        tree[node] = v[start];
        return;
    }

    int mid = (start + end) / 2;

    init(node*2, start, mid);
    init(node*2+1, mid+1, end);

    tree[node] = tree[node*2] + tree[node*2+1];
}

long long sum(int node, int start, int end, int left, int right) {
    if(left > end || right < start) {
        return 0;
    }

    if(left <= start && end <= right) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    return sum(node*2, start, mid, left, right) + sum(node*2+1, mid+1, end, left, right);
}

void update(int node, int start, int end, int index, long long val){
    if(index < start || index > end) {
        return;
    }

    if(start == end) {
        tree[node] = val;
        v[index] = val;
        return;
    }

    int mid = (start + end) / 2;
    update(node*2, start, mid, index, val);
    update(node*2+1, mid+1, end, index, val);

    tree[node] = tree[node*2] + tree[node*2+1];
}


int main() {
    int n, m, k;
    
    long long temp;
    int a, first, b;
    scanf("%d %d %d", &n, &m, &k);
    for(int i{};i<n;++i){
        scanf("%lld", &temp);
        v.push_back(temp);
    }

    init(1, 0, n-1);

    for(int i{};i<m+k;++i){
        scanf("%d", &first);
        if(first == 1) {
            scanf("%d %lld", &a, &temp);
            update(1, 0, n-1, a-1, temp);
        }

        else{
            scanf("%d %d", &a, &b);
            long long result = sum(1, 0, n-1, a-1, b-1);
            printf("%lld\n", result);
        }
    }

}