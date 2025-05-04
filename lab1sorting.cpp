#include<stdio.h>

void selection(int arr[], int n) {
    for (int i = 0; i <= n - 2; i++) {
        int min = arr[i];
        int min_index = i;
        for (int j = i; j <= n - 1; j++) {
            if (arr[j] < min) {
                min = arr[j];
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = min;
        arr[min_index] = temp;
    }

    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }
}

void bubble(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }
}

void insertion(int arr[], int n) {
    for (int i = 1; i < n - 1; i++) {
        int j = i;
        while (j >= 0 && arr[j] > arr[j + 1]) {
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
            j--;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }


}


 

int main() {
    puts("No of elements");
    int no;
    scanf("%d", &no);

    int arr[no];
    for (int i = 0; i < no; i++) {
        scanf("%d", &arr[i]);
    }

    int choice = 1;
    while (choice) {
        puts("Enter the number for sorting: 1) Bubble sort 2) Selection Sort 3) Insertion sort 4) Exit");
        int n;
        scanf("%d", &n);

        if (n == 1) {
            bubble(arr, no);
        } else if (n == 2) {
            selection(arr, no);
        } else if (n == 3) {
            insertion(arr, no);
        } else if(n==4) {
            printf("Code Exit\n");
            break;
        }else{
            printf("Error");
        }
    }

    return 0;
}

