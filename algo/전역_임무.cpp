#include<bits/stdc++.h>
using namespace std;

int main() {
    int answer = 0;
    int n, m;
    long long curr_point;
    scanf("%d %d %lld", &n, &m, &curr_point);
    vector<int> floor(m);

    while(n--){
        int flag = 0;

        for(int i=0;i<m;++i){
            scanf("%d", &floor[i]);
        }

        sort(floor.begin(), floor.end());
        
        for(int i=0;i<m;++i) {
            if(floor[i] == -1) {
                flag++;
                continue;
            }
            else if(curr_point >= floor[i]) {
                curr_point += floor[i];
            } 

            else if(curr_point < floor[i] && flag > 0) {
                do {
                    curr_point *= 2;
                    flag--;
                } while(curr_point < floor[i] && flag > 0);

                if(curr_point < floor[i]) {
                    printf("0");    
                    return 0;
                }

                curr_point += floor[i];
            }
            else {
                printf("0");
                return 0;
            }
        }
        

        while(flag--) {
            curr_point *= 2;
        }
    }

    printf("1");

    return 0;
}