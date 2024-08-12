#include <stdio.h>

void print_combination(int comb[], int r) {
    for (int i = 0; i < r; i++) {
        printf("%d ", comb[i]);
    }
    printf("\n");
}

int next_combination(int comb[], int n, int r) {
    int i = r - 1;
    while (i >= 0 && comb[i] == n - r + i) {
        i--;
    }

    if (i < 0) {
        return 0;
    }

    comb[i]++;
    for (int j = i + 1; j < r; j++) {
        comb[j] = comb[j - 1] + 1;
    }

    return 1;
}

int main() {
    int n = 5;
    int r = 3;
    int comb[r];

    for (int i = 0; i < r; i++) {
        comb[i] = i;
    }

    printf("Combinations:\n");
    do {
        print_combination(comb, r);
    } while (next_combination(comb, n, r));

    return 0;
}

