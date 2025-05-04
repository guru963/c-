#include <stdio.h>
#include <stdlib.h>

// Implementing list as ADT and its operations
class list {
    int *arr;
    int cur;
    int n;

public:
    list() {
        cur = -1;
        n = 5;
        arr = (int *)malloc(n * sizeof(int));
    }

    int insertatbeg(int value);
    int insertatend(int value);
    int insertatpos(int value, int index);
    void display();
    int deleteatpos(int index);
    int deleteatbeg();
    int deleteatend();
    int search(int target);
    int rotate(int k);
};

int main() {
    int choice = 1;
    list l1;

    while (choice) {
        printf("1) Insertion at beginning\n");
        printf("2) Insertion at end\n");
        printf("3) Insertion at position\n");
        printf("4) Deletion at beginning\n");
        printf("5) Deletion at end\n");
        printf("6) Deletion at position\n");
        printf("7) Display\n");
        printf("8) Search\n");
        printf("9) Rotate\n");
        printf("10) Exit\n");

        int choose;
        scanf("%d", &choose);

        if (choose == 1) {
            printf("Enter the value to be added: ");
            int value;
            scanf("%d", &value);
            l1.insertatbeg(value);
            l1.display();
        } else if (choose == 2) {
            printf("Enter the value to be added: ");
            int value;
            scanf("%d", &value);
            l1.insertatend(value);
            l1.display();
        } else if (choose == 3) {
            printf("Enter the value to be added: ");
            int value;
            scanf("%d", &value);
            printf("Enter the position: ");
            int index;
            scanf("%d", &index);
            l1.insertatpos(value, index);
            l1.display();
        } else if (choose == 4) {
            printf("The element deleted is %d\n", l1.deleteatbeg());
            l1.display();
        } else if (choose == 5) {
            printf("The element deleted is %d\n", l1.deleteatend());
            l1.display();
        } else if (choose == 6) {
            printf("Enter the position: ");
            int index;
            scanf("%d", &index);
            printf("The element deleted is %d\n", l1.deleteatpos(index));
            l1.display();
        } else if (choose == 7) {
            l1.display();
        } else if (choose == 8) {
            printf("Enter the target: ");
            int target;
            scanf("%d", &target);
            printf("The searched element is in the index of %d\n", l1.search(target));
        } else if (choose == 9) {
            printf("Enter k: ");
            int k;
            scanf("%d", &k);
            l1.rotate(k);
            l1.display();
        } else if (choose == 10) {
            printf("Exit\n");
            break;
        } else {
            printf("Invalid number\n");
        }

        printf("Do you want to continue? ");
        scanf("%d", &choice);
    }
}

// Inserting at beginning
int list::insertatbeg(int value) {
    if (cur + 1 >= n) {
        printf("Array is full\n");
        return -1;
    }
    int index = 0;
    for (int i = cur + 1; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    cur = cur + 1;
    return 1;
}

// Inserting at end
int list::insertatend(int value) {
    if (cur + 1 >= n) {
        printf("Array is full\n");
        return -1;
    }
    arr[cur + 1] = value;
    cur = cur + 1;
    return 1;
}

// Inserting at a given position
int list::insertatpos(int value, int index) {
    if (index > cur) {
        printf("It is out of index bound\n");
        return -1;
    }
    if (cur + 1 >= n) {
        printf("Array is full\n");
        return -1;
    }
    for (int i = cur + 1; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    cur = cur + 1;
    return 1;
}

// Deleting at a given position
int list::deleteatpos(int index) {
    if (index > cur) {
        printf("It is out of index bound\n");
        return -1;
    }
    if (cur == 0) {
        printf("Array is empty\n");
        return -1;
    }
    int temp = arr[index];
    for (int i = index; i < cur; i++) {
        arr[i] = arr[i + 1];
    }
    cur = cur - 1;
    return temp;
}

// Deleting at the beginning
int list::deleteatbeg() {
    if (cur == 0) {
        printf("Array is empty\n");
        return -1;
    }
    int temp = arr[0];
    for (int i = 0; i < cur; i++) {
        arr[i] = arr[i + 1];
    }
    cur = cur - 1;
    return temp;
}

// Deleting at the end
int list::deleteatend() {
    if (cur == 0) {
        printf("Array is empty\n");
        return -1;
    }
    int temp = arr[cur];
    cur = cur - 1;
    return temp;
}

// Displaying the array
void list::display() {
    for (int i = 0; i <= cur; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Searching the element
int list::search(int target) {
    for (int i = 0; i <= cur; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// Rotating the element k times
int list::rotate(int k) {
    for (int i = 0; i < k; i++) {
        int temp = arr[cur];
        for (int j = cur + 1; j > 0; j--) {
            arr[j] = arr[j - 1];
        }
        arr[0] = temp;
    }
    return 1;
}
