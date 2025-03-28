#include<bits/stdc++.h>
using namespace std;
int answer{};

int main(){
    int r, g, b;
    scanf("%d %d %d", &r, &g, &b);
    if(r>0 && g>0 && b>0){
        int tmp = min(r, min(g, b));
        answer+=tmp;
        r-=tmp;
        g-=tmp;
        b-=tmp;
    }

    if(r >= 3) {
        answer += (r / 3); r %= 3;
    } 
    if(g >= 3) {
        answer += (g / 3); g %= 3;
    }
    if(b >= 3) {
        answer += (b / 3); b %= 3;
    }
    
    if(r == 2){
        answer++;
        r -= 2;
    }
    if(g == 2){
        answer++;
        g -= 2;
    }
    if(b == 2){
        answer++;
        b -= 2;
    }
    
    if(r>0 && g>0) {answer++; r--; g--;}
    else if(r>0 && b>0) {answer++; r--; b--;}
    else if(g>0 && b>0) {answer++; g--;b--;}

    if(r>0) answer++;
    if(g>0) answer++;
    if(b>0) answer++;
    
    // chkallOk(r, g, b);
    printf("%d", answer);

    
}