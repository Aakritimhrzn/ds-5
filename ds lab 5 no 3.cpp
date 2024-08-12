#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

unsigned long long mod_exp(unsigned long long base, unsigned long long exp, unsigned long long mod) {
    unsigned long long result = 1;
    for (; exp > 0; exp--) {
        result = (result * base) % mod;
    }
    return result;
}

bool is_prime(int num, int k) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    
    for (int i = 0; i < k; i++) {
        int a = 2 + rand() % (num - 4);
        if (mod_exp(a, num - 1, num) != 1) {
            return false;
        }
    }
    return true;
}

int main() {
    int num;
    int k = 5;

    printf("Enter a number to check for primality: ");
    scanf("%d", &num);

    if (is_prime(num, k)) {
        printf("%d is probably a prime number.\n", num);
    } else {
        printf("%d is not a prime number.\n", num);
    }

    return 0;
}

