/* 在下面所给的源程序中，函数strcopy(t, s)的功能是将字符串s复制给字符串t，并且返回串t的首地址。请单步跟踪程序，根据程序运行时出现的现象或观察到的字符串的值，分析并排除源程序的逻辑错误，使之能按照要求输出如下结果：
Input a string:
programming↙ （键盘输入）
programming
Input a string again:
language↙ （键盘输入）
language
 */
#include <stdio.h>
char *strcopy(char *, const char *);
int main(void)
{
    char s1[100], s2[100];
    char *s3;
    printf("Input a string:\n");
    scanf("%s", s2);
    strcopy(s1, s2);
    printf("%s\n", s1);
    printf("Input a string again:\n");
    scanf("%s", s2);
    s3 = strcopy(s1, s2);
    printf("%s\n", s3);
    return 0;
}

/*将字符串s复制给字符串t，并且返回串t的首地址*/
char *strcopy(char *t, const char *s)
{
    char *start = t;
    while (*t++ = *s++)
        ;
    return (start);
}
