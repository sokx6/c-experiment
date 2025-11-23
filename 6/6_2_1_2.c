/* ②数组作为函数参数其本质类型是指针。例如，对于形参char *s[]，编译器将其解释为char **s，两种写法完全等价。请用二级指针形参重写strsort函数，并且在该函数体的任何位置都不允许使用下标引用。 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 4
/*对指针数组s指向的size个字符串进行升序排序*/
void strsort(char *s[], int size)
{
    char *temp;
    int i, j;
    char **p = s;
    char **q;
    for (i = 0; i < size - 1; i++)
    {
        p = s;
        for (j = 0; j < size - i - 1; j++)
        {
            q = p + 1;
            if (strcmp(*p, *q) > 0)
            {
                temp = *p;
                *p = *q;
                *q = temp;
            }
            p++;
        }
    }
}

int main()
{
    int i;
    char *s[N], t[50];
    for (i = 0; i < N; i++)
    {
        gets(t);
        s[i] = (char *)malloc(strlen(t) + 1);
        strcpy(s[i], t);
    }
    strsort(s, N);
    for (i = 0; i < N; i++)
    {
        puts(s[i]);
        free(s[i]);
    }
    return 0;
}
