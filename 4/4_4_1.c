/*
三角形的面积是 ，其中 ，a,b,c为三角形的三边，要求编写程序用带参数的宏来计算三角形的面积。定义两个带参数的宏，一个用来求s，另一个用来求area。
*/
#include <stdio.h>
#include <math.h>
#define S(a, b, c) ((a + b + c) / 2)
#define AREA(a, b, c) (sqrt(S(a, b, c) * (S(a, b, c) - a) * (S(a, b, c) - b) * (S(a, b, c) - c)))
int main(void)
{
    float a, b, c;
    printf("Input three sides of triangle: ");
    scanf("%f %f %f", &a, &b, &c);
    printf("Area of triangle is: %f\n", AREA(a, b, c));
    return 0;
}