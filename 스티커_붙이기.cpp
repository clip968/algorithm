#include<bits/stdc++.h>
using namespace std;

int n, m, k;

// 90도 회전
void rotate(vector<vector<int>>& sticker){
    int r = sticker.size();
    int c = sticker[0].size();
    vector<vector<int>> temp(c, vector<int>(r));
    for(int i{};i<r;++i){
        for(int j{};j<c;++j){
            temp[j][r-1-i] = sticker[i][j];
        }
    }
    sticker = temp;
}

bool can_attach(vector<vector<int>>& board, vector<vector<int>>& sticker, int start_x, int start_y){
    int r = sticker.size();
    int c = sticker[0].size();
    if(start_x + r > n || start_y + c > m) return false;
    for(int i{};i<r;++i){
        for(int j{};j<c;++j){
            if(sticker[i][j] == 1 && board[start_x + i][start_y + j] == 1){
                return false;
            }
        }
    }
    return true;
}

void attach(vector<vector<int>>& board, vector<vector<int>>& sticker, int start_x, int start_y){
    int r = sticker.size();
    int c = sticker[0].size();
    for(int i{};i<r;++i){
        for(int j{};j<c;++j){
            if(sticker[i][j] == 1){
                board[start_x + i][start_y + j] = 1;
            }
        }
    }
}

int calculate_area(vector<vector<int>>& board){
    int area{};
    for(int i{};i<n;++i){
        for(int j{};j<m;++j){
            if(board[i][j] == 1){
                area++;
            }
        }
    }
    return area;
}

int main(){
    scanf("%d %d %d", &n, &m, &k);
    vector<vector<int>> board(n, vector<int>(m));

    while(k--){
        int R, C;
        scanf("%d %d", &R, &C);

        vector<vector<int>> sticker(R, vector<int>(C));
        for(int i{};i<R;++i){
            for(int j{};j<C;++j){
                scanf("%d", &sticker[i][j]);
            }
        }

        bool attached = false;
        for(int rot{};rot<4;++rot){
            bool flag{false};
            for(int i{};i<=n-R &&!flag;++i){
                for(int j{};j<=m-C;++j){
                    if(can_attach(board, sticker, i, j)){
                        attach(board, sticker, i, j);
                        attached = true;
                        flag = true;
                        break;
                    }
                }
            }
            if(!attached){
                rotate(sticker);
                swap(R, C);
            } else {
                break;
        }
    }
}
    printf("%d\n", calculate_area(board));
    return 0;
}

