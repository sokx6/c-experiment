#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char ch;
    char filename[100];

    printf("请输入要读取的文件名: ");
    scanf("%s", filename);

    if (freopen(filename, "r", stdin) == NULL)
    {
        printf("Can't open %s file!\n", filename);
        exit(-1);
    }

    while ((ch = getchar()) != EOF) /* 从重定向的stdin中读字符 */
        putchar(ch);                /* 向显示器中写字符 */

    fclose(stdin); /* 关闭文件 */
    return 0;
}
