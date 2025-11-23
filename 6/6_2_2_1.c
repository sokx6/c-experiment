/* 下面源程序通过函数指针和菜单选择来调用库函数实现字符串操作；串复制strcpy、串连接strcat或串分解strtok。
①请在源程序中的下划线处填写合适的代码来完善该程序，使之能按照要求输出下面结果：
1 copy string.
2 connect string.
3 parse string.
4 exit.
input a number (1-4) please!
2↙ （键盘输入）
input the first string please!
the more you learn,↙ （键盘输入）
input the second string please!
the more you get. ↙ （键盘输入）
the result is the more you learn, the more you get.
 */
#include <stdio.h>
#include <string.h>
int main(void)
{
    char *(*p)(char *, const char *);
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
        switch (choice)
        {
        case 1:
            p = strcpy;
            break;
        case 2:
            p = strcat;
            break;
        case 3:
            p = strtok;
            break;
        case 4:
            goto down;
        }
        getchar();
        printf("input the first string please!\n");
        scanf("%s", a);
        printf("input the second string please!\n");
        scanf("%s", b);
        result = p(a, b);
        printf("the result is %s\n", result);
    }
down:
    return 0;
}
