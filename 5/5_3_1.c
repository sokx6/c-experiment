/* 实验5-3-1：输入一个整数，将它在内存中二进制表示的每一位
 * 转化成对应的数字字符并且存放到一个字符数组中，然后输出该整数的二进制表示
 */
#include <stdio.h>
#include <string.h>

void intToBinary(int num, char binary[]);

int main(void)
{
    int num;
    char binary[33];

    printf("请输入一个整数: ");
    scanf("%d", &num);

    intToBinary(num, binary);

    printf("该整数的二进制表示为: %s\n", binary);

    return 0;
}

void intToBinary(int num, char binary[])
{
    int i;
    unsigned int n = (unsigned int)num;

    for (i = 0; i < 32; i++)
    {
        if (n & 0b10000000000000000000000000000000)
            binary[i] = '1';
        else
            binary[i] = '0';

        n <<= 1;
    }

    binary[32] = '\0';
}
