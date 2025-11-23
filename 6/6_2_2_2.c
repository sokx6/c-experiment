/* 函数指针的一个用途是用户散转程序，即通过一个转移表（函数指针数组）来实现多分枝函数处理，从而省去了大量的if语句或者switch语句。转移表中存放了各个函数的入口地址（函数名），根据条件的设定来查表选择执行相应的函数。请使用转移表而不是switch语句重写以上程序。 */
#include <stdio.h>
#include <string.h>
int main(void)
{
    char *(*p[])(char *, const char *) = {strcpy, strcat, strtok};
    char a[80], b[80], *result;
    int choice;
    while (1)
    {
        do
        {
            printf("\t\t1 copy string.\n");
            printf("\t\t2 connect string.\n");
            printf("\t\t3 parse string.\n");
            printf("\t\t4 exit.\n");
            printf("\t\tinput a number (1-4) please.\n");
            scanf("%d", &choice);
        } while (choice < 1 || choice > 4);
        if (choice == 4)
            goto down;
        char *(*func)(char *, const char *) = p[choice - 1];
        getchar();
        printf("input the first string please!\n");
        scanf("%s", a);
        printf("input the second string please!\n");
        scanf("%s", b);
        result = func(a, b);
        printf("the result is %s\n", result);
    }
down:
    return 0;
}
