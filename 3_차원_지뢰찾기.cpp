#include<bits/stdc++.h>
using namespace std;

vector<vector<vector<char>>> v;
vector<vector<vector<char>>> answer;


int main() {
    int row, column, height;
    scanf("%d %d %d", &row, &column, &height);

    v.resize(row, vector<vector<char>>(column, vector<char>(height)));
    answer.resize(row, vector<vector<char>>(column, vector<char>(height)));
    
    for(int f{};f<height;++f){
        for(int i{};i<row;++i){
            for(int j{};j<column;++j){
                scanf(" %c", &v[i][j][f]);
            }
        }
    }

    for(int f{};f<height;++f){
        for(int i{};i<row;++i){
            for(int j{};j<column;++j){
                if(v[i][j][f] == '*') {answer[i][j][f] = '*'; continue;}

                int cnt{};
                for(int df{-1};df <= 1;++df){
                    for(int di{-1};di<=1;++di){
                        for(int dj{-1};dj<=1;++dj){
                            if(df == 0 && di == 0 && dj == 0) continue;

                            int nf{df+f};
                            int ni{di+i};
                            int nj{dj+j};

                            if(ni>=0 && ni<row && nj>=0 && nj<column && nf >= 0 && nf<height){
                                if(v[ni][nj][nf] == '*') {
                                    cnt++;
                                }
                            }
                        }
                    }
                }
                answer[i][j][f] = (cnt % 10) + '0';
            }
        }
    }

    
     for(int f{};f<height;++f){
        for(int i{};i<row;++i){
            for(int j{};j<column;++j){
                printf("%c", answer[i][j][f]);
            }
            printf("\n");
        }
    }   
    
}