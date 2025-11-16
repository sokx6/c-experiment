/* 实验5-3-2：学生成绩管理系统
 * 功能：成绩输入、成绩排序、成绩输出、成绩查找（二分查找）
 */
#include <stdio.h>
#include <string.h>

void inputScores(char names[][50], int scores[], int *n);
void sortScores(char names[][50], int scores[], int n);
void outputScores(char names[][50], int scores[], int n);
void searchScore(char names[][50], int scores[], int n);
int binarySearch(int scores[], int n, int target);

int main(void)
{
    char names[100][50]; /* 学生姓名数组 */
    int scores[100];     /* 学生成绩数组 */
    int n = 0;           /* 学生人数 */
    int choice;

    while (1)
    {
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            inputScores(names, scores, &n);
            break;
        case 2:
            sortScores(names, scores, n);
            printf("Reorder finished!\n");
            break;
        case 3:
            outputScores(names, scores, n);
            break;
        case 4:
            searchScore(names, scores, n);
            break;
        case 0:
            return 0;
        }
    }

    return 0;
}

/* 成绩输入函数 */
void inputScores(char names[][50], int scores[], int *n)
{
    int i;
    scanf("%d", n);

    for (i = 0; i < *n; i++)
    {
        scanf("%s %d", names[i], &scores[i]);
    }

    printf("%d records were input!\n", *n);
}

/* 成绩排序函数（从高到低） */
void sortScores(char names[][50], int scores[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = scores[i];
        char keyName[50];
        strcpy(keyName, names[i]);
        int j = i - 1;
        for (; j >= 0 && scores[j] < key; j--)
        {
            scores[j + 1] = scores[j];
            strcpy(names[j + 1], names[j]);
        }
        scores[j + 1] = key;
        strcpy(names[j + 1], keyName);
    }
}

/* 成绩输出函数 */
void outputScores(char names[][50], int scores[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%s %d\n", names[i], scores[i]);
    }
}

/* 成绩查找函数 */
void searchScore(char names[][50], int scores[], int n)
{
    int target, index;

    scanf("%d", &target);

    index = binarySearch(scores, n, target);

    if (index == -1)
    {
        printf("not found!\n");
    }
    else
    {

        printf("%s %d\n", names[index], scores[index]);
    }
}

int binarySearch(int scores[], int n, int target)
{
    int left = 0, right = n - 1, mid;

    while (left <= right)
    {
        mid = (left + right) / 2;

        if (scores[mid] == target)
            return mid;
        else if (scores[mid] > target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}
