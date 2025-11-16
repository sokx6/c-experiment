#include <stdio.h>

int is_special(int n){
    int square = n * n;
    if (square % 1000 == n ){
        return 1;
    }
    return 0;
}
int factorial(int n){
    if (n == 0) return 1;
    return n * factorial(n - 1);
}
int main() {
    for (int i = 100; i < 1000; i++) {
        if (is_special(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}