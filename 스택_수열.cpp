#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; scanf("%d", &n);

    vector<int> v(n);
    stack<int> st;
    vector<char> result;

    for(int i{};i<n;++i){
        scanf("%d", &v[i]);
    }

    int num{1};
    bool flag = true;

    for(int i{};i<n;++i){
        int tmp = v[i];
        if(tmp >= num){
            while(tmp >= num){
                st.push(num++);
                result.push_back('+');
            }
            st.pop();
            result.push_back('-');
        }

        else {
            int tmp2 = st.top();
            st.pop();

            if(tmp2 > tmp){
                printf("NO\n");
                flag = false;
                break;
            }
            else{
                result.push_back('-');
            }
        }
    }

    if(flag){
        for(int i{};i<result.size();++i){
            printf("%c\n",result[i]);
        }
    }
}