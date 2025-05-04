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
    


}

