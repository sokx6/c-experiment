/* 输入n行文本，每行不超过80个字符，用字符指针数组指向键盘输入的n行文本（n不作为输入，可理解为循环输入多行，以CTRL+Z结束），删除每一行中的前置空格（' '）和水平制表符（'\t'）。

要求：将删除一行文本中前置空格和水平制表符的功能定义成函数，在main函数中输出删除前置空格符的各行。（并在最后输出换行符。） */
#include <stdio.h>

void removeSpace(char *line, int n)
{
    char *p = line;
    char *dst = p;

    while (*p == ' ' || *p == '\t')
    {
        p++;
    }
    while (*p)
    {
        if (*p != '\t')
        {
            *dst++ = *p;
        }
        p++;
    }
    *dst = '\0';
}

int main()
{
    char *lines[100];
    int max = 80;
    char buffer[100][80];
    int n = 0;
    while (fgets(buffer[n], max, stdin) != NULL)
    {
        lines[n] = buffer[n];
        n++;
    }

    for (int i = 0; i < n; i++)
    {
        removeSpace(lines[i], max);
        printf("%s", lines[i]);
    }
    return 0;
}