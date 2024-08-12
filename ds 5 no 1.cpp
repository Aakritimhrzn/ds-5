#include <stdio.h>


void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}


int next_permutation(int arr[], int n) {
    int i = n - 2;

   
    while (i >= 0 && arr[i] >= arr[i + 1]) {
        i--;
    }

    if (i < 0) {
   
        reverse(arr, 0, n - 1);
        return 0; 
    }


    int j = n - 1;
    while (arr[j] <= arr[i]) {
        j--;
    }

    
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

  
    reverse(arr, i + 1, n - 1);

    return 1;
}

int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original permutation: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    if (next_permutation(arr, n)) {
        printf("Next permutation: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        printf("No next permutation. The array is in descending order.\n");
    }

    return 0;
}

