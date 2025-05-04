#include "lab6stack.h"

int main() {
    stack st;
    string expression;
    int choice;

    do {
        cout << "\n===== Parenthesis Checker =====" << endl;
        cout << "1. Check Parentheses" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the expression: ";
                cin >> expression;
                if (st.parenthesis(expression)) {
                    cout << "The parentheses are balanced" << endl;
                } else {
                    cout << "The parentheses are NOT balanced" << endl;
                }
                break;
            case 2:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 2);

    return 0;
}
