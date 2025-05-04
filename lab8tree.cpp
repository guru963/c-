//Binary tree creation 
#include <iostream>
#include <cstdlib>
using namespace std;

class Tree {
    struct Node {
        char data;
        struct Node* left;
        struct Node* right;
    } *root;

public:
    Tree() {
        root = NULL;
    }

    // Function to create a new node
    struct Node* createNode(char val) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    // Function to insert nodes in the binary tree
    struct Node* createTree() {
        char data;
        cout << "Enter a character (-1 to stop): ";
        cin >> data;
        if (data == '-') {
            return NULL;
        }
        struct Node* newNode = createNode(data);
        cout << "Enter the left child of " << data << endl;
        newNode->left = createTree();
        cout << "Enter the right child of " << data << endl;
        newNode->right = createTree();
        return newNode;
    }

    // Build tree function
    void buildTree() {
        root = createTree();
    }

    // Recursive Inorder Traversal
    void inorder(struct Node* root) {
        if (root == NULL) {
            return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    // Recursive Preorder Traversal
    void preorder(struct Node* root) {
        if (root == NULL) {
            return;
        }
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    // Recursive Postorder Traversal
    void postorder(struct Node* root) {
        if (root == NULL) {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

    // Function to search for a character in the tree
    bool search(struct Node* root, char key) {
        if (root == NULL) {
            return false;
        }
        if (root->data == key) {
            return true;
        }
        return search(root->left, key) || search(root->right, key);
    }

    // Wrapper functions for calling traversal and search functions
    void inorderPrint() {
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << endl;
    }

    void preorderPrint() {
        cout << "Preorder Traversal: ";
        preorder(root);
        cout << endl;
    }

    void postorderPrint() {
        cout << "Postorder Traversal: ";
        postorder(root);
        cout << endl;
    }

    void searchElement(char key) {
        if (search(root, key)) {
            cout << "Character '" << key << "' found in the tree." << endl;
        } else {
            cout << "Character '" << key << "' not found in the tree." << endl;
        }
    }
};

// Main function with a menu-driven interface
int main() {
    Tree t;
    int choice;
    char key;

    do {
        cout << "\n--- Binary Tree ADT Menu ---\n";
        cout << "1. Insert (Build Tree)\n";
        cout << "2. Preorder Traversal\n";
        cout << "3. Inorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Search for an Element\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                t.buildTree();
                break;
            case 2:
                t.preorderPrint();
                break;
            case 3:
                t.inorderPrint();
                break;
            case 4:
                t.postorderPrint();
                break;
            case 5:
                cout << "Enter character to search: ";
                cin >> key;
                t.searchElement(key);
                break;
            case 6:
                cout << "Exiting program.\n";
                exit(0);
            default:
                cout << "Invalid choice! Please enter a valid option.\n";
        }
    } while (choice != 6);

    return 0;
}
