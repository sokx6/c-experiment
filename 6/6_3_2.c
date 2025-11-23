/* 旋转是图像处理的基本操作，编程实现一个将一个图像逆时针旋转90°。提示：计算机中的图像可以用一个矩阵来表示，旋转一个图像就是旋转对应的矩阵。将旋转矩阵的功能定义成函数，通过使用指向数组元素的指针作为参数使该函数能处理任意大小的矩阵。要求在main函数中输入图像矩阵的行数n和列数m，接下来的n行每行输入m个整数，表示输入的图像。输出原始矩阵逆时针旋转90°后的矩阵。
样例输入：
2	3
1	5	3
3	2	4
样例输出：
3	4
5	2
1	3
 */
#include <stdio.h>

int rotateMatrix(int row, int col, int origin[row][col], int result[col][row]);

int main()
{
    int row, col;

    scanf("%d %d", &row, &col);
    int origin[row][col];
    int result[col][row];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &origin[i][j]);
        }
    }
    rotateMatrix(row, col, origin, result);
    return 0;
}

int rotateMatrix(int row, int col, int origin[row][col], int result[col][row])
{
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            result[i][j] = origin[j][col - 1 - i];
        }
    }
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            printf("%d", result[i][j]);
            if (j != row - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}