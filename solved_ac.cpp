#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    double result{};
    int divide_ratio{};
    vector<int> arr;
    cin >> n;
    divide_ratio = round(n * 0.15); 
    // cout << divide_ratio << "\n";
    if (n == 0){
        cout << 0 << "\n";
    }
    else{ 
        for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end());

    for(int i=divide_ratio;i<arr.size()-divide_ratio;i++){
        // cout << i <<"\n";
        result += arr[i];
    }
    // cout << result << "\n";
    // cout << (result / (n - divide_ratio * 2)) << "\n";
    result = round(result / (n - divide_ratio * 2));
    cout << result << "\n";


    }
   
}