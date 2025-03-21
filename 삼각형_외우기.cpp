#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;
    int temp, sum=0;
    for(int i=0;i<3;++i){
        scanf("%d", &temp);
        v.push_back(temp);
        sum += temp;
    }

    sort(v.begin(), v.end());

    if(sum != 180) {
        printf("Error");
    }
    else if(v[0] == v[2]) printf("Equilateral");
    else if(v[0] == v[1] || v[1] == v[2]) printf("Isosceles");
    else printf("Scalene");

    
}