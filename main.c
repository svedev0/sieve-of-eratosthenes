#include <stdio.h>
#include <stdlib.h>

void sieve(int n) {
    int *isPrime = malloc((n + 1) * sizeof(int));
    if (isPrime == NULL) {
        printf("malloc failed\n");
        exit(1);
    }

    for (int i = 0; i <= n; i++) {
        isPrime[i] = 1;  // init all as 1 (true)
    }

    // 0 and 1 don't count :)
    isPrime[0] = 0;
    isPrime[1] = 0;

    // sieve
    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p]) {
            // multiples of p are not primes
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = 0;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            printf("%d\n", i);
        }
    }

    free(isPrime);
}

int main() {
    int n;

    printf("Enter a limit: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Limit must be greater than 1.\n", n);
        return 0;
    }

    sieve(n);
    return 0;
}
