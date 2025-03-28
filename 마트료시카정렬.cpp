#include<bits/stdc++.h>
using namespace std;
int cnt;
void merge(vector<int>& v, int left, int mid, int right) {
    int left_size = mid - left + 1;
    int right_size = right - mid;

    vector<int> lv(left_size);
    vector<int> rv(right_size);

    for(int i{};i<left_size;++i){
        lv[i] = v[left + i];
    }
    for(int i{};i<right_size;++i){
        rv[i] = v[mid + 1 + i];
    }

    int i{};
    int j{};
    int k{left};

    while(i < left_size && j < right_size){
        if(lv[i] <= rv[j]){
            v[k] = lv[i];
            i++;
        }
        else {
            v[k] = rv[j];
            j++;
            cnt += (left_size - i);
        }
        k++;
    }

    while(i < left_size){
        v[k] = lv[i];
        i++;
        k++;
    }

    while(j < right_size){
        v[k] = rv[j];
        j++;
        k++;
    }
}

void merge_sort(vector<int>& v, int left, int right){
    if(left >= right) return;

    int mid = (left + right) / 2;

    merge_sort(v, left, mid);
    merge_sort(v, mid+1, right);
    merge(v, left, mid, right);
}

int main(){
    int t; scanf("%d", &t);
    while(t--){
        cnt = 0;
        int n; scanf("%d", &n);
        vector<int> v(n);
        for(int i{};i<n;++i){
            scanf("%d", &v[i]);
        }

        merge_sort(v, 0, v.size()-1);

        printf("%d\n", cnt);
        // for(auto k : v){
        //     printf("%d ", k);
        // }
        // printf("\n");
    }
}