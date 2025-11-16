/* 实验5-3-3：N皇后问题
 * 在N×N的棋盘上摆放N个皇后，要求任意两个皇后不能在同一行、
 * 同一列、同一对角线上
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 10

int board[MAX_N];      /* board[i]表示第i行皇后所在的列号 */
int solutionCount = 0; /* 解的数量 */

/* 函数声明 */
int isSafe(int row, int col, int n);
void solveNQueens(int row, int n);
void printBoard(int n);

int main(void)
{
    int n;

    scanf("%d", &n);

    solutionCount = 0;
    solveNQueens(0, n);

    if (solutionCount == 0)
    {
        printf("无解\n");
    }
    else
    {
        printf("%d\n", solutionCount);
    }

    return 0;
}

/* 检查在(row, col)位置放置皇后是否安全 */
int isSafe(int row, int col, int n)
{
    int i;

    /* 检查同一列是否有皇后 */
    for (i = 0; i < row; i++)
    {
        if (board[i] == col)
            return 0;
    }

    /* 检查左上对角线是否有皇后 */
    for (i = row - 1; i >= 0; i--)
    {
        if (board[i] == col - (row - i))
            return 0;
    }

    /* 检查右上对角线是否有皇后 */
    for (i = row - 1; i >= 0; i--)
    {
        if (board[i] == col + (row - i))
            return 0;
    }

    return 1;
}

/* 使用回溯法求解N皇后问题 */
void solveNQueens(int row, int n)
{
    int col;

    /* 如果所有行都已放置皇后，找到一个解 */
    if (row == n)
    {
        solutionCount++;
        return;
    }

    /* 尝试在当前行的每一列放置皇后 */
    for (col = 0; col < n; col++)
    {
        if (isSafe(row, col, n))
        {
            board[row] = col;         /* 放置皇后 */
            solveNQueens(row + 1, n); /* 递归处理下一行 */
        }
    }
}
