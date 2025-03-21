#include <iostream>
using namespace std;

// 트리 노드 구조체 정의
struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// 전위 + 후위 순회 결합 함수
void order(Node* root) {
    if (root == nullptr) { // base case: 노드가 없을 때
        return;
    }
    
    cout << root->data; // 현재 노드 데이터 출력 (전위 순회)
    order(root->left);  // 왼쪽 서브트리 탐색
    order(root->right); // 오른쪽 서브트리 탐색
    cout << root->data; // 현재 노드 데이터 출력 (후위 순회)
}

int main() {
    // 트리 생성 (주어진 트리 구조)
    Node* root = new Node('A');
    root->left = new Node('B');
    root->right = new Node('C');
    root->left->left = new Node('D');
    root->right->left = new Node('E');
    root->right->right = new Node('F');
    root->left->left->left = new Node('G');

    // 순회 결과 출력
    order(root);
    cout << endl;

    // 동적 메모리 해제
    delete root->left->left->left;
    delete root->left->left;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
