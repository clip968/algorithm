#include<bits/stdc++.h>
using namespace std;
vector<int> tmp;
int n, k;
int answer{};
vector<int> c;
bool flag = false;
void merge(vector<int>& v,int p, int q, int r) {
    if(answer >= k){
        return;
    }
    int i=p, j=q+1, t=0;
    tmp.resize(r-p+1);
    while(i <= q && j <= r){
        if(v[i] <= v[j]) {
            // answer++;
            tmp[t++] = v[i++];
        }
        else {
            // answer++;
            tmp[t++] = v[j++];
        }
        answer++;
        if(answer == k){
            flag = true;
            c = v;
            for(int d{};d<t;++d){
                c[p + d] = tmp[d];
            }
            return;
        }
    }
    while(i <= q && !flag){
        answer++;
        tmp[t++] = v[i++];
        if(answer == k){
            flag = true;
            c = v;
            for(int d{};d<t;++d){
                c[p + d] = tmp[d];
            }
            return;
        }
    }
    while(j <= r && !flag) {
        answer++;
        tmp[t++] = v[j++];
        if(answer == k){
            flag = true;
            c = v;
            for(int d{};d<t;++d){
                c[p + d] = tmp[d];
            }
            return;
        }
    }
    if(!flag){
        i = p, t = 0;
        while(i <= r){
            v[i++] = tmp[t++];
        }
    }
    
}
// p=0, r=v.size()
void merge_sort(vector<int>& v, int p,int r){
    if(flag){
        return;
    }
    if(p < r) {
        int q = (p + r)/2;
        merge_sort(v, p, q);
        merge_sort(v, q+1, r);
        merge(v, p, q, r);
    }
}


int main(){
    scanf("%d %d", &n, &k);
    vector<int> v(n);
    for(int i{};i<n;++i){
        scanf("%d", &v[i]);
    }
    merge_sort(v, 0, v.size()-1);

    if(k > answer) {
        printf("-1\n");
        return 0;
    }
    for(int i{};i<n;i++){
        printf("%d ", c[i]);
    }
    
}