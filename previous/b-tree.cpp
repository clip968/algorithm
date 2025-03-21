#include <iostream>
#include <vector>
#include <algorithm>

class BTree {
private:
    // Node structure for B-tree
    struct Node {
        bool leaf;
        std::vector<int> keys;
        std::vector<Node*> children;

        Node(bool isLeaf = true) : leaf(isLeaf) {}
    };

    Node* root;
    int t; // Minimum degree (defines the range for number of keys)

    // Helper function to split a child node
    void splitChild(Node* parent, int index);

    // Helper function to insert a non-full node
    void insertNonFull(Node* node, int key);

    // Helper function to print the tree
    void printTree(Node* node, int depth = 0) const;

    // Helper function to delete a key
    void removeKey(Node* node, int key);

    // Helper function to find the predecessor
    int getPredecessor(Node* node);

    // Helper function to find the successor
    int getSuccessor(Node* node);

    // Helper function to borrow from left sibling
    void borrowFromLeft(Node* parent, int index);

    // Helper function to borrow from right sibling
    void borrowFromRight(Node* parent, int index);

    // Helper function to merge nodes
    void mergeNodes(Node* parent, int index);

public:
    // Constructor
    BTree(int minDegree);

    // Destructor to free memory
    ~BTree();

    // Insert a key
    void insert(int key);

    // Delete a key
    void remove(int key);

    // Search for a key
    bool search(int key) const;

    // Print the tree
    void print() const;

    // Traverse the tree
    void traverse() const;
};

// Constructor
BTree::BTree(int minDegree) : root(nullptr), t(minDegree) {
    if (t < 2) {
        throw std::invalid_argument("Minimum degree must be at least 2");
    }
    root = new Node();
}

// Destructor (recursive deletion of nodes)
BTree::~BTree() {
    // Implement recursive node deletion
    if (root) {
        std::vector<Node*> nodes;
        nodes.push_back(root);
        while (!nodes.empty()) {
            Node* node = nodes.back();
            nodes.pop_back();
            if (!node->leaf) {
                for (auto child : node->children) {
                    nodes.push_back(child);
                }
            }
            delete node;
        }
    }
}

// Insert a key into the B-tree
void BTree::insert(int key) {
    // If root is full, create a new root
    if (root && root->keys.size() == 2 * t - 1) {
        Node* newRoot = new Node(false);
        newRoot->children.push_back(root);
        root = newRoot;
        splitChild(root, 0);
    }

    // If root is null, create a new root
    if (!root) {
        root = new Node();
    }

    insertNonFull(root, key);
}

// Insert into a non-full node
void BTree::insertNonFull(Node* node, int key) {
    int i = node->keys.size() - 1;

    if (node->leaf) {
        // Insert key into the leaf node
        node->keys.push_back(0);
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
    } else {
        // Find the child node to insert into
        while (i >= 0 && key < node->keys[i]) {
            i--;
        }
        i++;

        // If the child is full, split it
        if (node->children[i]->keys.size() == 2 * t - 1) {
            splitChild(node, i);
            if (key > node->keys[i]) {
                i++;
            }
        }

        insertNonFull(node->children[i], key);
    }
}

// Split a child node
void BTree::splitChild(Node* parent, int index) {
    Node* child = parent->children[index];
    Node* newChild = new Node(child->leaf);

    // Move the upper half of keys to the new child
    newChild->keys = std::vector<int>(
        child->keys.begin() + t,
        child->keys.end()
    );
    child->keys.erase(
        child->keys.begin() + t,
        child->keys.end()
    );

    // If not a leaf, move the upper half of children
    if (!child->leaf) {
        newChild->children = std::vector<Node*>(
            child->children.begin() + t,
            child->children.end()
        );
        child->children.erase(
            child->children.begin() + t,
            child->children.end()
        );
    }

    // Insert the middle key into the parent
    parent->keys.insert(
        parent->keys.begin() + index,
        child->keys[t - 1]
    );
    child->keys.erase(child->keys.begin() + (t - 1));

    // Add the new child to the parent's children
    parent->children.insert(
        parent->children.begin() + index + 1,
        newChild
    );
}

// Search for a key
bool BTree::search(int key) const {
    Node* current = root;
    while (current) {
        auto it = std::find(current->keys.begin(), current->keys.end(), key);
        if (it != current->keys.end()) {
            return true;
        }

        if (current->leaf) {
            return false;
        }

        // Find the appropriate child to continue searching
        int i = 0;
        while (i < current->keys.size() && key > current->keys[i]) {
            i++;
        }
        current = current->children[i];
    }
    return false;
}

// Print the tree
void BTree::print() const {
    if (root) {
        printTree(root);
    } else {
        std::cout << "Tree is empty" << std::endl;
    }
}

// Helper function to print the tree
void BTree::printTree(Node* node, int depth) const {
    if (!node) return;

    // Print indentation based on depth
    for (int i = 0; i < depth; i++) {
        std::cout << "  ";
    }

    // Print keys in this node
    for (int key : node->keys) {
        std::cout << key << " ";
    }
    std::cout << std::endl;

    // Recursively print children
    if (!node->leaf) {
        for (Node* child : node->children) {
            printTree(child, depth + 1);
        }
    }
}

// Remove a key from the B-tree
void BTree::remove(int key) {
    if (!root) return;

    removeKey(root, key);

    // If root becomes empty, update root
    if (root->keys.empty() && !root->leaf) {
        Node* oldRoot = root;
        root = root->children[0];
        delete oldRoot;
    }
}

// Helper function to remove a key
void BTree::removeKey(Node* node, int key) {
    int index = 0;
    while (index < node->keys.size() && key > node->keys[index]) {
        index++;
    }

    // Key is in this node
    if (index < node->keys.size() && key == node->keys[index]) {
        if (node->leaf) {
            // Simple case: remove from leaf
            node->keys.erase(node->keys.begin() + index);
        } else {
            // Key is in an internal node
            int predecessor = getPredecessor(node);
            node->keys[index] = predecessor;
            removeKey(node->children[index], predecessor);
        }
    } else {
        // Key might be in a child
        if (node->leaf) {
            // Key not found
            return;
        }

        // Check if child has enough keys
        if (node->children[index]->keys.size() < t) {
            // Borrow from sibling or merge
            if (index > 0 && node->children[index - 1]->keys.size() >= t) {
                borrowFromLeft(node, index);
            } else if (index < node->keys.size() && 
                       node->children[index + 1]->keys.size() >= t) {
                borrowFromRight(node, index);
            } else {
                // Merge nodes
                mergeNodes(node, index);
            }
        }

        removeKey(node->children[index], key);
    }
}

// Get predecessor of a key
int BTree::getPredecessor(Node* node) {
    Node* current = node->children[0];
    while (!current->leaf) {
        current = current->children.back();
    }
    return current->keys.back();
}

// Get successor of a key
int BTree::getSuccessor(Node* node) {
    Node* current = node->children.back();
    while (!current->leaf) {
        current = current->children[0];
    }
    return current->keys[0];
}

// Borrow from left sibling
void BTree::borrowFromLeft(Node* parent, int index) {
    Node* child = parent->children[index];
    Node* leftSibling = parent->children[index - 1];

    // Move parent key to child
    child->keys.insert(child->keys.begin(), parent->keys[index - 1]);
    parent->keys[index - 1] = leftSibling->keys.back();
    leftSibling->keys.pop_back();

    // Move child if not leaf
    if (!child->leaf) {
        child->children.insert(
            child->children.begin(), 
            leftSibling->children.back()
        );
        leftSibling->children.pop_back();
    }
}

// Borrow from right sibling
void BTree::borrowFromRight(Node* parent, int index) {
    Node* child = parent->children[index];
    Node* rightSibling = parent->children[index + 1];

    // Move parent key to child
    child->keys.push_back(parent->keys[index]);
    parent->keys[index] = rightSibling->keys[0];
    rightSibling->keys.erase(rightSibling->keys.begin());

    // Move child if not leaf
    if (!child->leaf) {
        child->children.push_back(rightSibling->children[0]);
        rightSibling->children.erase(rightSibling->children.begin());
    }
}

// Merge nodes
void BTree::mergeNodes(Node* parent, int index) {
    Node* child = parent->children[index];
    Node* rightSibling = parent->children[index + 1];

    // Move parent key to child
    child->keys.push_back(parent->keys[index]);
    
    // Move keys from right sibling
    child->keys.insert(
        child->keys.end(), 
        rightSibling->keys.begin(), 
        rightSibling->keys.end()
    );

    // Move children if not leaf
    if (!child->leaf) {
        child->children.insert(
            child->children.end(),
            rightSibling->children.begin(),
            rightSibling->children.end()
        );
    }

    // Remove parent key and right sibling
    parent->keys.erase(parent->keys.begin() + index);
    parent->children.erase(parent->children.begin() + index + 1);

    // Clean up
    delete rightSibling;
}

// Traverse the tree
void BTree::traverse() const {
    if (root) {
        printTree(root);
    } else {
        std::cout << "Tree is empty" << std::endl;
    }
}

// Example main function to demonstrate B-tree usage
int main() {
    BTree tree(3); // 최소 차수 3으로 B-트리 생성
    // 테스트 케이스 추가
    // 예: 트리에 값 삽입 및 출력
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(6);
    tree.insert(12);
    tree.insert(30);
    tree.insert(7);
    tree.insert(17);

    tree.traverse(); // 트리 순회 출력

    return 0;
}