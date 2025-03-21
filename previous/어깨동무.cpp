#include<bits/stdc++.h>
using namespace std;
int answer=1000;
bool isvalid(vector<int>& v, int n, int k, int h){
    multiset<int> m;
    int chk_tired = 0;
    int left = 0;

    for(int i=0;i<n;i++){
        m.insert(v[i]);

        if(*m.rbegin() - *m.begin() > h) {
            m.erase(m.find(v[left]));
            left += 1;
            chk_tired += 1;
        }
    }

    return chk_tired <= k;
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    vector<int> v(n);

    for(int i=0;i<n;i++){
        scanf("%d", &v[i]);
    }

    int left = 0, right = 1000;
    

    while(left <= right) {
        int mid = (left + right) / 2;
        if(isvalid(v, n, k, mid)) {
            answer = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    printf("%d", answer);

}