#include <bits/stdc++.h>
using namespace std;

// Test function to check if results match expected output
void runTest(vector<vector<int>> input, vector<vector<int>> expected) {
    // Redirect stdout to string stream for testing
    streambuf* oldCout = cout.rdbuf();
    stringstream ss;
    cout.rdbuf(ss.rdbuf());

    int n = input.size();
    int m = input[0].size();
    
    // Reset global variables
    memset(arr, 0, sizeof(arr));
    memset(result, 0, sizeof(result));
    memset(visited, 0, sizeof(visited));
    counter = 0;

    // Fill input array
    int start_i = 0, start_j = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            arr[i][j] = input[i][j];
            if(arr[i][j] == 2) {
                start_i = i;
                start_j = j;
            }
        }
    }

    Point start_node = {start_i, start_j};
    clear(n, m);
    bfs(start_node, n, m);

    // Compare results
    bool passed = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(result[i][j] != expected[i][j]) {
                passed = false;
                break;
            }
        }
    }

    cout.rdbuf(oldCout); // Restore stdout
    cout << (passed ? "PASSED" : "FAILED") << endl;
}

int main() {
    // Test Case 1: Simple 3x3 grid
    runTest(
        {{1,2,1},
         {1,1,1},
         {1,1,1}},
        {{1,0,1},
         {2,1,2},
         {3,2,3}}
    );

    // Test Case 2: Path blocked
    runTest(
        {{1,2,1},
         {0,0,1},
         {1,1,1}},
        {{1,0,1},
         {0,0,2},
         {0,0,3}}
    );

    // Test Case 3: Larger grid
    runTest(
        {{1,1,1,1,1},
         {1,2,1,1,1},
         {1,1,1,1,1},
         {1,1,1,1,1}},
        {{2,1,2,3,4},
         {1,0,1,2,3},
         {2,1,2,3,4},
         {3,2,3,4,5}}
    );

    return 0;
}