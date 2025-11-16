#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    
    int prev_row[7] = {0};
    prev_row[0] = 1;
    
    int spaces = 3 * N;
    for (int s = 0; s < spaces; s++) {
        printf(" ");
    }
    printf("1   \n");
    
    if (N >= 1) {
        int curr_row[7] = {0};
        for (int i = 1; i <= N; i++) {
            curr_row[0] = 1;
            for (int j = 1; j < i; j++) {
                curr_row[j] = prev_row[j-1] + prev_row[j];
            }
            curr_row[i] = 1;
            
            spaces = 3 * N - 2 * i;
            for (int s = 0; s < spaces; s++) {
                printf(" ");
            }
            
            for (int j = 0; j <= i; j++) {
                printf("%d", curr_row[j]);
                if (j < i) {
                    if (curr_row[j] < 10) {
                        printf("   ");
                    } else {
                        printf("  ");
                    }
                } else {
                    printf("   \n");
                }
            }
            
            for (int k = 0; k <= i; k++) {
                prev_row[k] = curr_row[k];
            }
        }
    }
    
    return 0;
}