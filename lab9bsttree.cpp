#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Binary Search Tree class
class BST {
public:
    Node* root;
    
    BST() {
        root = nullptr;
    }
    
    // Insert function
    Node* insert(Node* node, int value) {
        if (node == nullptr)
            return new Node(value);
        
        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
        
        return node;
    }
    
    void insert(int value) {
        root = insert(root, value);
    }
    
    // Preorder traversal
    void preorder(Node* node) {
        if (node == nullptr)
            return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
    
    void preorder() {
        preorder(root);
        cout << endl;
    }
    
    // Inorder traversal
    void inorder(Node* node) {
        if (node == nullptr)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
    
    void inorder() {
        inorder(root);
        cout << endl;
    }
    
    // Postorder traversal
    void postorder(Node* node) {
        if (node == nullptr)
            return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
    
    void postorder() {
        postorder(root);
        cout << endl;
    }
    
    // Search function
    bool search(Node* node, int value) {
        if (node == nullptr)
            return false;
        
        if (node->data == value)
            return true;
        
        if (value < node->data)
            return search(node->left, value);
        else
            return search(node->right, value);
    }
    
    bool search(int value) {
        return search(root, value);
    }
};

int main() {
    BST tree;
    int choice, value;
    
    while (true) {
        cout << "\nBinary Search Tree Menu";
        cout << "\n1. Insert";
        cout << "\n2. Preorder Traversal";
        cout << "\n3. Inorder Traversal";
        cout << "\n4. Postorder Traversal";
        cout << "\n5. Search";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                tree.insert(value);
                break;
            case 2:
                cout << "Preorder traversal: ";
                tree.preorder();
                break;
            case 3:
                cout << "Inorder traversal: ";
                tree.inorder();
                break;
            case 4:
                cout << "Postorder traversal: ";
                tree.postorder();
                break;
            case 5:
                cout << "Enter value to search: ";
                cin >> value;
                if (tree.search(value))
                    cout << "Value found in BST." << endl;
                else
                    cout << "Value not found in BST." << endl;
                break;
            case 6:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
}
