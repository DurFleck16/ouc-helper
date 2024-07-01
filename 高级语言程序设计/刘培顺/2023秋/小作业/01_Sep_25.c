// Author: DurFleck16
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// ****************************************************
// *******在此处添加你的自定义函数、结构体或全局变量*******

// 计算利息，活期year变量为0
float calculateInterest(float money, int year)
{
    const float rate[6] = {0.0035, 0.015, 0.021, 0.0275, NAN, 0.03}; 
    if (year < 0 || year > 5 || money < 0 || isnan(rate[year]))
    {
        return -1;
    }
    return money * rate[year];
}

float calcMonthLeft(float loan, float monthlyPayment, float rate)
{
    float m;
    m = (log(monthlyPayment) - log(monthlyPayment - loan * rate)) / log(1 + rate);
    return m;
}

// ****************************************************
// ****************************************************
// 输出到终端菜单。
void menu()
{
    // **************************************
    // ******题目描述，可根据需要调整。********
    char title[] = "P80-81 2,3";
    char que_1[] = "计算利息";
    char que_2[] = "还房贷";
    char que_3[] = "";
    char que_4[] = "";
    char que_5[] = "";
    char que_6[] = "";
    // **************************************
    // **************************************
    printf("%s\n", title);
    printf("1. %s\n", que_1);
    printf("2. %s\n", que_2);
    printf("3. %s\n", que_3);
    printf("4. %s\n", que_4);
    printf("5. %s\n", que_5);
    printf("6. %s\n", que_6);
    printf("请选择题目编号(1-6)：");
}
// *************************************************
// **********在下列空函数中填入对应题目的代码**********
void question_1()
{
    printf("请输入存款金额：");
    float money;
    scanf("%f", &money);
    printf("请输入存款年限：（0代表活期，1-5代表定期，4除外）");
    int year;
    scanf("%d", &year);
    float interest = calculateInterest(money, year);
    if (interest != -1)
    {
        printf("利息为：%.2f\n", interest);
    }
    else
    {
        printf("输入错误！");
    }
}

void question_2()
{
    float loan = 300000.0,
    monthlyPayment = 6000.0,
    rate = 0.01;
    float month = calcMonthLeft(loan,monthlyPayment,rate);
    printf("月数：%.2f",month);
}

void question_3()
{
    
}

void question_4()
{
    
}

void question_5()
{

}

void question_6()
{

}
// *****************************************************
// *****************************************************

int main()
{
    // 输出菜单
    menu();

    // 读取用户输入
    int choice;
    scanf("%d", &choice);

    // 根据用户输入，调用相应的函数
    switch (choice)
    {
    case 1:
        question_1();
        break;
    case 2:
        question_2();
        break;
    case 3:
        question_3();
        break;
    case 4:
        question_4();
        break;
    case 5:
        question_5();
        break;
    case 6:
        question_6();
        break;
    default:
        printf("输入错误！\n");
    }

    return 0;
}