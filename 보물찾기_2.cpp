#include<bits/stdc++.h>
using namespace std;

#define F 0
#define R 1
#define L 2
#define B 3

int dir[4][4] = {
    {F, R, L, B}, 
    {R, B, F, L},
    {L, F, B, R},
    {B, L, R, F}
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<string>> arr(n, vector<string>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> arr[i][j];
            }
        }

        int dx[4] = {1, 0, 0, -1};
        int dy[4] = {0, 1, -1, 0};

        bool visited[51][51][4] = {false}; 

        int cur_x= 0, cur_y = 0;
        int prev = B;
        visited[cur_x][cur_y][prev] = true;
        while(true){ 
            string instr = arr[cur_x][cur_y];
            char letter = instr[0];
            int steps = instr[1] - '0';

            int instrDir;
            if(letter == 'F') instrDir = F;
            else if(letter == 'R') instrDir = R;
            else if(letter == 'L') instrDir = L;
            else if(letter == 'B') instrDir = B;


            int new_dir = dir[prev][instrDir];


            int next_x = cur_x + dx[new_dir] * steps;
            int next_y = cur_y + dy[new_dir] * steps;


            if(visited[next_x][next_y][new_dir]){
                cout << next_x << " " << next_y << "\n";
                break;
            }

            visited[next_x][next_y][new_dir] = true;
            cur_x = next_x;
            cur_y = next_y;
            prev = new_dir;
        }
    }
    return 0;
}