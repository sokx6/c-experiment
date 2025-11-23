/* 一个长整型变量占4个字节，其中每个字节又分成高4位和低4位。输入一个长整型变量，要求从高字节开始，依次取出每个字节的高4位和低4位并以十六进制数字字符的形式进行显示，通过指针取出每字节。
样例输入：15
样例输出：0000000F
 */
#include <stdio.h>

int main()
{
    long int num;
    char hex_chars[] = "0123456789ABCDEF";
    scanf("%ld", &num);
    char *p = (char *)&num;
    for (int i = 3; i >= 0; i--)
    {
        char byte = p[i];
        char high_nibble = (byte >> 4) & 0x0F;
        char low_nibble = byte & 0x0F;
        printf("%c%c", hex_chars[high_nibble], hex_chars[low_nibble]);
    }

    return 0;
}
