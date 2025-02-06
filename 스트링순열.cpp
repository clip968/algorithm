#include <bits/stdc++.h>
using namespace std;

int change(string words){
    int bu = 1;
    int result = 0;
    for(int i = 0;i < words.size();i++){
        result += (words[i] - 'a') * bu;
        bu *= -1;
    }
   
    return result;
}

void permute(string words, vector<int> &arr) {
    sort(words.begin(), words.end());
    do{
        arr.push_back(change(words));
    }
    while(next_permutation(words.begin(), words.end()));
}


int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        vector<int> arr;
        string word;
        int result = 0;
        cin >> word;
        permute(word, arr);

        for(int n : arr) {
            if(n > 0) {
                result += 1;
            }
        }

        cout << result << "\n";
    }
}