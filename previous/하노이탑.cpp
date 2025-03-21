#include<bits/stdc++.h>
using namespace std;
stack<int> arr;

void move(int n, int from, int to){
    // cout << n << " " << from << " " << to << "\n";
    if (to == 3){
        // printf("(%d %d %d)", n, from, to);
        arr.push(n);
        cout << arr.top() << " ";
    }
    else if(from == 3){
        // printf("(%d %d %d)", n, from, to);
        
        arr.pop();
        if(arr.empty()){
            cout << 0 << " ";
        }
        else{
            cout << arr.top() << " ";
        }
    }
}

void hanoi(int n, int from, int use, int to){
    if(n == 1) move(n, from, to);
    else{
        hanoi(n - 1, from, to, use);
        move(n, from, to);
        hanoi(n - 1, use, from, to);
    }

}

int main(){
    
    int t; scanf("%d", &t);

    while(t--){
        int n; scanf("%d", &n);

        hanoi(n, 1, 2, 3);
        cout << "\n";
        while(!arr.empty()){
            arr.pop();
        }
    }
}