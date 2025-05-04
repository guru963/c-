#include "stacktwo.h"

int main(){
    stack st;
    string expression;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Get Infix Expression\n";
        cout << "2. Convert Infix to Postfix\n";
        cout << "3. Convert Infix to Prefix\n";
        cout << "4. Convert Postfix to Infix\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter Infix Expression: ";
                cin >> expression;
                break;
            case 2:
                cout << "Postfix Expression: ";
                st.infitopost(expression, "");
                cout << endl;
                break;
            case 3:
                cout << "Prefix Expression: ";
                st.infitopre(expression, "");
                cout << endl;
                break;
            case 4:
                cout << "Enter Postfix Expression: ";
                cin >> expression;
                cout << "Infix Expression: ";
                st.posttoinfi(expression);
                cout << endl;
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while(choice != 5);

    return 0;
}
