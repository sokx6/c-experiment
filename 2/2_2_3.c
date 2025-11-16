/* 实验2-1改错题程序：合数判断器*/
#include <stdio.h>
int removeOnes(int n) {
    int ones = n%10;
    int removedn = (n-ones)/10;
    return removedn;
}

int isComposite(int n) {
    int i, k;
    for(i=2, k=n>>1; i<=k; i++) {
        if (n % i == 0) {
            return 1;
        }
    }
    return 0;
}

int main( ){ 
    for (int i=100; i<=999; i++) {
        if (isComposite(i) && 
            isComposite(removeOnes(i)) && 
            isComposite(removeOnes(removeOnes(i)))) {
            printf("%d\n", i);
        }
    }
}
