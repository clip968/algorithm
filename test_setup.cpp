#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "========================================" << endl;
    cout << "  Cursor + g++ 설정 테스트" << endl;
    cout << "========================================" << endl;
    
    vector<int> v = {1, 2, 3, 4, 5};
    cout << "\n벡터 크기: " << v.size() << endl;
    
    cout << "벡터 내용: ";
    for(int x : v) {
        cout << x << " ";
    }
    cout << endl;
    
    cout << "\n✅ bits/stdc++.h가 정상적으로 작동합니다!" << endl;
    cout << "✅ g++ 컴파일러가 정상적으로 작동합니다!" << endl;
    
    return 0;
}
