#include <iostream>
#include <stack>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char val) {
        data = val;
        left = right = nullptr;
    }
};

class BST {
private:
    Node* root;

public:
    BST() { root = nullptr; }
    void insert(int value);
    void preorder();
    void inorder();
    void postorder();
    bool search(int value);
    void constructExpressionTree(string postfix);
    Node* getRoot() { return root; }
};

// Insert a new node in the BST
void BST::insert(int value) {
    Node** curr = &root;
    while (*curr) {
        if (value < (*curr)->data)
            curr = &((*curr)->left);
        else if (value > (*curr)->data)
            curr = &((*curr)->right);
        else
            return;
    }
    *curr = new Node(value);
}

//  Preorder traversal of the BST
void BST::preorder() {
    stack<Node*> s;
    Node* curr = root;
    while (curr || !s.empty()) {
        while (curr) {
            cout << curr->data << " ";
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top()->right;
        s.pop();
    }
    cout << endl;
}

// Inorder traversal of the BST
void BST::inorder() {
    stack<Node*> s;
    Node* curr = root;
    while (curr || !s.empty()) {
        while (curr) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;
}

// Postorder traversal of the BST
void BST::postorder() {
    if (!root) return;
    stack<Node*> s1, s2;
    s1.push(root);
    while (!s1.empty()) {
        Node* node = s1.top();
        s1.pop();
        s2.push(node);
        if (node->left) s1.push(node->left);
        if (node->right) s1.push(node->right);
    }
    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
    cout << endl;
}

// Search for a value in the BST
bool BST::search(int value) {
    Node* curr = root;
    while (curr) {
        if (value == curr->data) return true;
        curr = (value < curr->data) ? curr->left : curr->right;
    }
    return false;
}

// Construct an expression tree from a postfix expression
void BST::constructExpressionTree(string postfix) {
    stack<Node*> s;
    for (char ch : postfix) {
        Node* newNode = new Node(ch);
        if (isalnum(ch)) {
            s.push(newNode);
        } else {
            newNode->right = s.top(); s.pop();
            newNode->left = s.top(); s.pop();
            s.push(newNode);
        }
    }
    root = s.top();
}

int main() {
    BST tree;
    int choice;
    string postfix;
    do {
        cout << "\nExpression Tree Menu";
        cout << "\n1. Postfix Expression";
        cout << "\n2. Construct Expression Tree";
        cout << "\n3. Preorder";
        cout << "\n4. Inorder";
        cout << "\n5. Postorder";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter a valid postfix expression: ";
                cin>>postfix;
                break;
            case 2:
                tree.constructExpressionTree(postfix);
                cout << "Expression Tree Constructed!\n";
                break;
            case 3:
                cout << "Preorder Traversal: ";
                tree.preorder();
                break;
            case 4:
                cout << "Inorder Traversal: ";
                tree.inorder();
                break;
            case 5:
                cout << "Postorder Traversal: ";
                tree.postorder();
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice, try again.\n";
        }
    } while (choice != 6);
    return 0;
}

/*
Insert : O(n)
preorder : O(n)
Inorder : O(n)
postorder : O(n)
search : O(n)*/