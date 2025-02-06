#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;
    int size;
    int bf;  // balance factor
    
    Node(int k) {
        key = k;
        left = nullptr;
        right = nullptr;
        height = 1;  // 새 노드의 높이는 1
        size = 1;    // 새 노드의 크기는 1
        bf = 0;      // 새 노드의 균형 인수는 0
    }
};

// 높이 계산 함수
int getHeight(Node* node) {
    if (node == nullptr) return 0;
    return node->height;
}

// 크기 계산 함수
int getSize(Node* node) {
    if (node == nullptr) return 0;
    return node->size;
}

// 노드의 정보 업데이트 함수
void updateNode(Node* node) {
    if (node == nullptr) return;
    
    // height 업데이트
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    
    // size 업데이트
    node->size = 1 + getSize(node->left) + getSize(node->right);
    
    // balance factor 업데이트
    node->bf = getHeight(node->left) - getHeight(node->right);
}

// 우회전
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    // 순서 중요: y를 먼저 업데이트한 후 x를 업데이트
    updateNode(y);
    updateNode(x);

    return x;
}

// 좌회전
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    // 순서 중요: x를 먼저 업데이트한 후 y를 업데이트
    updateNode(x);
    updateNode(y);

    return y;
}

// AVL 트리 삽입
Node* insert(Node* root, int key) {
    // 1. 일반적인 BST 삽입 수행
    if (root == nullptr)
        return new Node(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else // 중복 키는 허용하지 않음
        return root;

    // 2. 노드 정보 업데이트
    updateNode(root);

    // 3. 불균형 체크 및 회전 수행
    if (root->bf > 1) {
        if (key < root->left->key) // LL case
            return rotateRight(root);
        else { // LR case
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
    }
    if (root->bf < -1) {
        if (key > root->right->key) // RR case
            return rotateLeft(root);
        else { // RL case
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
    }

    return root;
}

// 최소값 노드 찾기
Node* findMin(Node* node) {
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

// AVL 트리 삭제
Node* remove(Node* root, int key) {
    if (root == nullptr)
        return root;

    // 1. 일반적인 BST 삭제 수행
    if (key < root->key)
        root->left = remove(root->left, key);
    else if (key > root->key)
        root->right = remove(root->right, key);
    else {
        // 자식이 하나이거나 없는 경우
        if (root->left == nullptr || root->right == nullptr) {
            Node* temp = root->left ? root->left : root->right;
            if (temp == nullptr) { // 자식이 없는 경우
                temp = root;
                root = nullptr;
            } else // 자식이 하나인 경우
                *root = *temp; // 내용 복사
            delete temp;
        } else {
            // 자식이 둘인 경우
            Node* temp = findMin(root->right);
            root->key = temp->key;
            root->right = remove(root->right, temp->key);
        }
    }

    // 삭제 후 빈 트리가 된 경우
    if (root == nullptr)
        return root;

    // 2. 노드 정보 업데이트
    updateNode(root);

    // 3. 불균형 체크 및 회전 수행
    if (root->bf > 1) {
        if (getHeight(root->left->left) >= getHeight(root->left->right)) // LL case
            return rotateRight(root);
        else { // LR case
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
    }
    if (root->bf < -1) {
        if (getHeight(root->right->right) >= getHeight(root->right->left)) // RR case
            return rotateLeft(root);
        else { // RL case
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
    }

    return root;
}

// 중위 순회 출력
void inorder(Node* root) {
    if (root == nullptr) return;
    
    cout << "<";
    inorder(root->left);
    cout << " " << root->key << " ";
    inorder(root->right);
    cout << ">";
}

// 트리 메모리 해제
void clear(Node* root) {
    if (root == nullptr) return;
    clear(root->left);
    clear(root->right);
    delete root;
}

int main() {
    Node* root = nullptr;
    char cmd;
    int key;

    while (cin >> cmd >> key) {
        if (cmd == 'i') {
            Node* temp = root;
            root = insert(root, key);
            if (temp == root)
                cout << "i " << key << ": The key already exists" << endl;
            else
                inorder(root);
        }
        else if (cmd == 'd') {
            Node* temp = root;
            root = remove(root, key);
            if (temp == root)
                cout << "d " << key << ": The key does not exist" << endl;
            else
                inorder(root);
        }
        if (cmd != 'i' && cmd != 'd')
            cout << "Invalid command" << endl;
        
        if ((cmd == 'i' && temp != root) || (cmd == 'd' && temp != root))
            cout << endl;
    }

    clear(root);
    return 0;
}