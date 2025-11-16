#include <stdio.h>

int main(){
    int money, tax;
    printf("请输入工资金额：");
    scanf("%d", &money);

    if (money < 1000){
        tax = 0;
    }else if (money <2000){
        tax = (money - 1000) * 0.05;
    }else if (money <3000){
        tax = (money - 2000) * 0.1 + 50;
    }else if (money < 4000){
        tax = (money - 3000) * 0.15 + 150;
    }else if (money < 5000){
        tax = (money - 4000) * 0.2 + 300;
    }else{
        tax = (money - 5000) * 0.25 + 500;
    }

    printf("工资税金：%d\n", tax);
    return 0;
}