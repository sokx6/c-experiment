/*在下面所给的源程序中，函数strcate(t,s)的功能是将字符串s连接到字符串t的尾部；函数strdelc(s,c)的功能是从字符串s中删除所有与给定字符c相同的字符，程序应该能够输出如下结果：
 *Programming Language
 *ProgrammingLanguage Language
 *ProgrmingLnguge
 */
#include <stdio.h>
void strcate(char[], char[]);
void strdelc(char[], char);
int main(void)
{
    char a[] = "Language", b[] = "Programming";
    printf("%s %s\n", b, a);
    strcate(b, a);
    printf("%s %s\n", b, a);
    strdelc(b, 'a');
    printf("%s\n", b);
    return 0;
}
void strcate(char t[], char s[])
{
    int i = 0, j = 0;
    while (t[i] != '\0')
        i++;
    while ((t[i++] = s[j++]) != '\0')
        ;
}
void strdelc(char s[], char c)
{
    int j, k;
    for (j = k = 0; s[j] != '\0'; j++)
        if (s[j] != c)
            s[k++] = s[j];
    s[k] = '\0';
}
