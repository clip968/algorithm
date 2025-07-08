#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; scanf("%d", &n);
    vector<pair<int, int>> v(n);

    for(int i{};i<n;++i){
        scanf("%d", &v[i].first);
        v[i].second = i;
    }

    // 중요한 건 오른쪽으로 이동하는 건 많이 이동할 수 있지만
    // 한 번 이동하는 건 한 루프에 딱 한번씩 만 일어남
    // 따라서 이전 index - 이후 index 를 할 때 음수는 빼고(오른쪽으로 이동) 양수만 계산함
    sort(v.begin(), v.end());
    int result{};

    for(int i{};i<n;++i){
        if(result < v[i].second - i){
            result = v[i].second - i;
        }
    }

    // 맨 마지막에 1을 더해주는 이유는 모든 정렬이 끝난 루프가 끝나도 이게 끝난지 안끝났는지 모르기 때문에 무조건 한 번 더
    // 루프 실행할 수 밖에 없음
    printf("%d", result+1);

}