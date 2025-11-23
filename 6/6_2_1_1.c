/* 下面程序中函数strsort用于对字符串进行升序排序，在主函数中输入N个字符串（字符串长度不超过49）存入通过malloc动态分配的存储空间，然后调用strsort对这N个串按字典序升序排序（提示：使用strcmp函数比较字符（串）大小）。 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 4
/*对指针数组s指向的size个字符串进行升序排序*/
void strsort(char *s[], int size)
{
    char *temp;
    int i, j;
    for (i = 0; i < size - 1; i++)
        for (j = 0; j < size - i - 1; j++)
            if (strcmp(s[j], s[j + 1]) > 0)
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
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
