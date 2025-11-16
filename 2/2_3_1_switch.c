#include <stdio.h>
/*  */
int main(){
    int money, tax;
    printf("请输入工资金额：");
    scanf("%d", &money);

    switch (money / 1000){
        case 0:
            tax = 0;
            break;
        case 1:
            tax = (money - 1000) * 0.05;
            break;
        case 2:
            tax = (money - 2000) * 0.1 + 50;
            break;
        case 3:
            tax = (money - 3000) * 0.15 + 150;
            break;
        case 4:
            tax = (money - 4000) * 0.2 + 300;
            break;
        default:
            tax = (money - 5000) * 0.25 + 500;
            break;
    }

    printf("工资税金：%d\n", tax);
    return 0;
}