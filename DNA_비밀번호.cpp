#include<bits/stdc++.h>
using namespace std;

#define A 0
#define C 1
#define G 2
#define T 3

int min_dna[4];
int my_dna[4];
int chk{};

void add(char c) {
    switch(c){
        case 'A':
            my_dna[A]++;
            if(my_dna[A] == min_dna[A]) chk++;
            break;
        
        case 'C':
            my_dna[C]++;
            if(my_dna[C] == min_dna[C]) chk++;
            break;
        
        case 'G':
            my_dna[G]++;
            if(my_dna[G] == min_dna[G]) chk++;
            break;
        
        case 'T':
            my_dna[T]++;
            if(my_dna[T] == min_dna[T]) chk++;
            break;
    }
}

void remove(char c) {
    switch(c){
        case 'A':
            if(my_dna[A] == min_dna[A]) chk--;
            my_dna[A]--;
            break;
        
        case 'C':
            if(my_dna[C] == min_dna[C]) chk--;
            my_dna[C]--;
            break;
        
        case 'G':
            if(my_dna[G] == min_dna[G]) chk--;
            my_dna[G]--;
            break;
        
        case 'T':
            if(my_dna[T] == min_dna[T]) chk--;
            my_dna[T]--;
            break;
    }
}

int main(){
    int n, m;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int result{};

    cin >> n >> m;
    string s;
    cin >> s;

    for(int i{};i<4;++i){
        cin >> min_dna[i];

        if(min_dna[i] == 0){
            chk++;
        }
    }

    for(int i{};i<m;++i){
        add(s[i]);
    }

    if(chk == 4) result++;

    for(int i{m};i<n;++i){
        int j{i-m};

        add(s[i]);
        remove(s[j]);

        if(chk == 4) result++;
    }
    cout << result << "\n";    
}