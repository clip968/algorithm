#include<bits/stdc++.h>
using namespace std;

int main(){
    int min_val{0}, max_val{11};
    
    while(true){
        int n;
        string line;

        cin >> n; 
        if(n == 0) {
            break;  
        }
        cin.ignore();
        getline(cin, line);
        
        if (line == "too high" && n < max_val){
            max_val = n;
            
        }
        else if(line == "too low" && n > min_val){
            min_val = n;
            
        }
        else if(line == "right on"){
            if(n >= max_val || n <= min_val) cout << "Stan is dishonest" << "\n";
            else cout << "Stan may be honest" << "\n";
        min_val = 1; max_val = 11;
    }
}
    return 0;
}