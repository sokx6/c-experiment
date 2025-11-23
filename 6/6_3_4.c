/*  编写8个任务函数，一个scheduler调度函数和一个execute执行函数。仅在main函数中调用scheduler函数，scheduler函数要求用最快的方式调度执行用户指定的任务函数。
①先设计task0, task1, task2, task3, task4, task5, task6, task7共8个任务函数，每个任务函数的任务就是输出该任务被调用的字符串。例如，第0个任务函数输出“task0 is called!”，第1个任务函数输出“task1 is called!”，以此类推。
②scheduler函数根据键盘输入的数字字符的先后顺序，一次调度选择对应的任务函数。例如，输入：1350并回车，则scheduler函数一次调度选择task1, task3, taks5, task0，然后以函数指针数组和任务个数为参数将调度选择结果传递给execute函数并调用execute函数。
③execute函数根据scheduler函数传递的指针数组和任务个数为参数，按照指定的先后顺序依此调用执行选定的任务函数。
例如，当输入13607122并回车，程序运行结果如下：
task1 is called!
task3 is called!
task6 is called!
task0 is called!
task7 is called!
task1 is called!
task2 is called!
task2 is called!
*/

#include <stdio.h>
void task0()
{
    printf("task0 is called!\n");
}
void task1()
{
    printf("task1 is called!\n");
}
void task2()
{
    printf("task2 is called!\n");
}
void task3()
{
    printf("task3 is called!\n");
}
void task4()
{
    printf("task4 is called!\n");
}
void task5()
{
    printf("task5 is called!\n");
}
void task6()
{
    printf("task6 is called!\n");
}
void task7()
{
    printf("task7 is called!\n");
}
void execute(void (*tasks[])(), int task_count)
{
    for (int i = 0; i < task_count; i++)
    {
        tasks[i]();
    }
}
void scheduler()
{
    void (*task_funcs[8])() = {task0, task1, task2, task3, task4, task5, task6, task7};
    void (*scheduled_tasks[100])();
    int task_count = 0;
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        if (ch >= '0' && ch <= '7')
        {
            scheduled_tasks[task_count++] = task_funcs[ch - '0'];
        }
    }
    execute(scheduled_tasks, task_count);
}
int main()
{
    scheduler();
    return 0;
}