#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    long result{};
    cin >> n >> m;
    vector<long> arr(n, 0);
    vector<long> arr2(m, 0);
    cin >> arr[0];

    for (int i=1;i<n;i++){
        int num{};
        cin >> num;
        arr[i] = arr[i-1] + num;   
    }
    
    for(int i=0;i<n;i++){
        int temp = arr[i] % m;
        if (temp == 0){
            result += 1;
        }
        arr2[temp] += 1;
    }

    for(int i=0;i<m;i++){
        if(arr2[i] > 1){
            result = result + (arr2[i] * (arr2[i] - 1) / 2);
        }
    }

    cout << result << "\n";





}