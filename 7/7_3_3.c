
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
int sort_by_average(struct Student *head);
int print_info_with_total_and_average(struct Student *head);
int sort_by_average_pointer(struct Student **headp);
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
            print_info(head);
            break;
        }
        case 4:
        {
            calculate_average(head);
            break;
        }
        case 5:
        {
            print_info_with_total_and_average(head);
            break;
        }
        case 6:
        {
            sort_by_average(head);
            break;
        }
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

int sort_by_average(struct Student *head)
{
    if (head == NULL)
        return -1; // Empty list

    struct Student *i, *j;
    for (i = head; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            double avg_i = (i->english + i->math + i->physics + i->c_programming) / 4.0;
            double avg_j = (j->english + j->math + j->physics + j->c_programming) / 4.0;
            if (avg_i > avg_j)
            {
                // Swap data fields
                int temp_id = i->id;
                char temp_name[20];
                strcpy(temp_name, i->name);
                int temp_english = i->english;
                int temp_math = i->math;
                int temp_physics = i->physics;
                int temp_c_programming = i->c_programming;

                i->id = j->id;
                strcpy(i->name, j->name);
                i->english = j->english;
                i->math = j->math;
                i->physics = j->physics;
                i->c_programming = j->c_programming;

                j->id = temp_id;
                strcpy(j->name, temp_name);
                j->english = temp_english;
                j->math = temp_math;
                j->physics = temp_physics;
                j->c_programming = temp_c_programming;
            }
        }
    }
    for (struct Student *p = head; p != NULL; p = p->next)
    {
        double average = (p->english + p->math + p->physics + p->c_programming) / 4.0;
        printf("%d %s %.2f\n", p->id, p->name, average);
    }
    return 0;
}

int sort_by_average_pointer(struct Student **headp)
{
    struct Student *sorted = NULL;

    while (*headp != NULL)
    {
        struct Student *current = *headp;
        *headp = (*headp)->next;

        if (sorted == NULL || ((current->english + current->math + current->physics + current->c_programming) / 4.0) < ((sorted->english + sorted->math + sorted->physics + sorted->c_programming) / 4.0))
        {
            current->next = sorted;
            sorted = current;
        }
        else
        {
            struct Student *s = sorted;
            while (s->next != NULL && ((s->next->english + s->next->math + s->next->physics + s->next->c_programming) / 4.0) < ((current->english + current->math + current->physics + current->c_programming) / 4.0))
            {
                s = s->next;
            }
            current->next = s->next;
            s->next = current;
        }
    }
    *headp = sorted;

    struct Student *p = *headp;
    while (p != NULL)
    {
        double average = (p->english + p->math + p->physics + p->c_programming) / 4.0;
        printf("%d %s %.2f\n", p->id, p->name, average);
        p = p->next;
    }
    return 0;
}
