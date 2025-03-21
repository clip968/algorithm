#include<bits/stdc++.h>
using namespace std;

string wb[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};

string bw[8] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};
string board[50];
int chk_wb(int x, int y) {
    int result{};
    for(int i{};i<8;++i){
        for(int j{};j<8;++j){
            if(board[x+i][y+j] != wb[i][j]){
                result++;
            }
        }
    }
    return result;
}

int chk_bw(int x, int y) {
    int result{};
    for(int i{};i<8;++i){
        for(int j{};j<8;++j){
            if(board[x+i][y+j] != bw[i][j]){
                result++;
            }
        }
    }
    return result;
}
    
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x, y;
    cin >> x >> y;

    for(int i{};i<x;++i){
        cin >> board[i];
    }
    int temp;
    int answer{100000};
    for(int i{};i+8<=x;++i){
        for(int j{};j+8<=y;++j){
            int res_bw = chk_bw(i, j);
            int res_wb = chk_wb(i, j);
            temp = min(res_bw, res_wb);
            answer = min(answer, temp);
        }

        
    }

    printf("%d", answer);

}