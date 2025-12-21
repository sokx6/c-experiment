/*本关任务：用单向链表建立一张班级成绩单，包括每个学生的学号、姓名、英语、高等数学、普通物理、C语言程序设计四门课程的成绩。用菜单实现下列功能：
① 输入每个学生的各项信息。
② 输出每个学生的各项信息。
③ 修改指定学生的指定数据项的内容。
④ 统计每个同学的平均成绩（保留2位小数）。
⑤ 输出各位同学的学号、姓名、四门课程的总成绩和平均成绩。

编程要求
根据提示，在右侧编辑器补充代码，用单向链表建立班级成绩单。

测试说明
平台会对你编写的代码进行测试：

测试输入1：
1
5
2021001 Jack 90 92 87 95
2021002 Mike 85 70 75 90
2021003 Joe 77 86 90 75
2021004 Andy 95 97 92 95
2021005 Rose 90 87 88 89
预期输出1：
完成了5位同学的成绩输入。

测试输入2：
1
5
2021001 Jack 90 92 87 95
2021002 Mike 85 70 75 90
2021003 Joe 77 86 90 75
2021004 Andy 95 97 92 95
2021005 Rose 90 87 88 89
3
2021003 0 Joan
预期输出2：
完成了5位同学的成绩输入。
2021003 Joan 77 86 90 75

测试输入3：
1
5
2021001 Jack 90 92 87 95
2021002 Mike 85 70 75 90
2021003 Joe 77 86 90 75
2021004 Andy 95 97 92 95
2021005 Rose 90 87 88 89
3
2021003 2 96

预期输出3：
完成了5位同学的成绩输入。
2021003 Joan 77 96 90 75

测试输入4：
1
5
2021001 Jack 90 92 87 95
2021002 Mike 85 70 75 90
2021003 Joe 77 86 90 75
2021004 Andy 95 97 92 95
2021005 Rose 90 87 88 89
4
预期输出4：
完成了5位同学的成绩输入。
2021001 Jack 91.00
2021002 Mike 80.00
2021003 Joan 84.50
2021004 Andy 94.75
2021005 Rose 88.50

测试输入5：
1
5
2021001 Jack 90 92 87 95
2021002 Mike 85 70 75 90
2021003 Joe 77 86 90 75
2021004 Andy 95 97 92 95
2021005 Rose 90 87 88 89
5
预期输出5：
2021001 Jack 364 91.00
2021002 Mike 320 80.00
2021003 Joan 338 84.50
2021004 Andy 379 94.75
2021005 Rose 354 88.50
完成了5位同学的成绩输入。

测试输入6：
0
*/

#include <stdio.h>
#include <stdlib.h>
struct Student
{
    int id;
    char name[20];
    int english;
    int math;
    int physics;
    int c_programming;
    struct Student *next;
};

int input_info(struct Student **headp, int n);
int print_info(struct Student *head);
int modify_info(struct Student *head, int id, int field, char *new_value);
int calculate_average(struct Student *head);
int print_info_with_total_and_average(struct Student *head);
int main()
{
    int option;
    struct Student *head = NULL;
    while (scanf("%d", &option) != EOF)
    {
        switch (option)
        {
        case 1:
        {
            int num = 0;
            scanf("%d", &num);
            input_info(&head, num);
            printf("完成了%d位同学的成绩输入。\n", num);
            break;
        }
        case 2:
        {
            print_info(head);
            break;
        }
        case 3:
        {
            int id, field;
            char new_value[20];
            scanf("%d %d %s", &id, &field, new_value);
            modify_info(head, id, field, new_value);
            break;
        }
        case 4:
        {
            calculate_average(head);
            break;
        }
        case 5:
            print_info_with_total_and_average(head);
            break;
        default:
            break;
        }
    }
    return 0;
}

int input_info(struct Student **headp, int n)
{
    struct Student *loc_head = NULL, *tail;
    loc_head = (struct Student *)malloc(sizeof(struct Student));
    scanf("%d %s %d %d %d %d", &loc_head->id, loc_head->name, &loc_head->english, &loc_head->math, &loc_head->physics, &loc_head->c_programming);
    tail = loc_head;
    for (int i = 0; i < n - 1; i++)
    {
        tail->next = (struct Student *)malloc(sizeof(struct Student));
        tail = tail->next;
        scanf("%d %s %d %d %d %d", &tail->id, tail->name, &tail->english, &tail->math, &tail->physics, &tail->c_programming);
    }
    tail->next = NULL;
    *headp = loc_head;
    return 0;
}
int print_info(struct Student *head)
{
    struct Student *current = head;
    while (current != NULL)
    {
        printf("%d %s %d %d %d %d\n", current->id, current->name, current->english, current->math, current->physics, current->c_programming);
        current = current->next;
    }
    return 0;
}

int modify_info(struct Student *head, int id, int field, char *new_value)
{
    struct Student *current = head;
    while (current != NULL)
    {
        if (current->id == id)
        {
            switch (field)
            {
            case 0:
                sscanf(new_value, "%s", current->name);
                break;
            case 1:
                current->english = atoi(new_value);
                break;
            case 2:
                current->math = atoi(new_value);
                break;
            case 3:
                current->physics = atoi(new_value);
                break;
            case 4:
                current->c_programming = atoi(new_value);
                break;
            default:
                break;
            }
            return 0;
        }
        current = current->next;
    }
    return -1; // Student not found
}

int calculate_average(struct Student *head)
{
    struct Student *current = head;
    while (current != NULL)
    {
        double average = (current->english + current->math + current->physics + current->c_programming) / 4.0;
        printf("%d %s %.2f\n", current->id, current->name, average);
        current = current->next;
    }
    return 0;
}

int print_info_with_total_and_average(struct Student *head)
{
    struct Student *current = head;
    while (current != NULL)
    {
        int total = current->english + current->math + current->physics + current->c_programming;
        double average = total / 4.0;
        printf("%d %s %d %.2f\n", current->id, current->name, total, average);
        current = current->next;
    }
    return 0;
}