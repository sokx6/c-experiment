#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 10000

int main(void)
{
    char old_str[100], new_str[100];
    char line[MAX_LINE];
    char result[MAX_LINE];
    FILE *fp;
    int count = 0;

    /* 读取要替换的字符串 */
    scanf("%s %s", old_str, new_str);

    /* 打开源文件 */
    fp = fopen("experiment/src/step8/source.txt", "r");
    if (fp == NULL)
    {
        printf("无法打开文件!\n");
        return -1;
    }

    /* 读取文件内容 */
    if (fgets(line, MAX_LINE, fp) == NULL)
    {
        printf("文件为空!\n");
        fclose(fp);
        return -1;
    }
    fclose(fp);

    /* 替换字符串 */
    char *p = line;
    char *q = result;
    int old_len = strlen(old_str);
    int new_len = strlen(new_str);

    while (*p != '\0')
    {
        /* 检查是否匹配要替换的字符串 */
        if (strncmp(p, old_str, old_len) == 0)
        {
            /* 找到匹配，进行替换 */
            strcpy(q, new_str);
            q += new_len;
            p += old_len;
            count++;
        }
        else
        {
            /* 不匹配，复制当前字符 */
            *q = *p;
            q++;
            p++;
        }
    }
    *q = '\0';

    /* 输出替换次数 */
    printf("%d\n", count);

    /* 输出替换后的字符串 */
    printf("%s", result);

    return 0;
}
