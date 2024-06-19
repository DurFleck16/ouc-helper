// Author: DurFleck16
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// ****************************************************
// *******在此处添加你的自定义函数、结构体或全局变量*******
double calcIncome_switch(double payment)
{
    const double thousand = 1000;
    const double persentage = 0.01;
    int flag = payment / 100 / thousand;
    double rest;
    switch(flag) {
        case 0:
            // <= 100k
            return payment * 10 * persentage;
        case 1:
            // 100k - 200k
            rest = payment - 100 * thousand;
            return  (100 * thousand) * (10 * persentage) + 
                rest * (7.5 * persentage);
        case 2:
        case 3:
            // 200k - 400k
            rest = payment - 200 * thousand;
            return (100 * thousand) * (10 * persentage) + 
                (100 * thousand) * (7.5 * persentage) + 
                rest * (5 * persentage);
        case 4:
        case 5:
            // 400k - 600k
            rest = payment - 400 * thousand;
            return (100 * thousand) * (10 * persentage) + 
                (100 * thousand) * (7.5 * persentage) + 
                (200 * thousand) * (5 * persentage) + 
                rest * (3 * persentage);
        case 6:
        case 7:
        case 8:
        case 9:
            // 600k - 1000k
            rest = payment - 600 * thousand;
            return (100 * thousand) * (10 * persentage) + 
                (100 * thousand) * (7.5 * persentage) + 
                (200 * thousand) * (5 * persentage) + 
                (200 * thousand) * (3 * persentage) + 
                rest * (1.5 * persentage);
        default:
            // > 1000k
            rest = payment - 1000 * thousand;
            return (100 * thousand) * (10 * persentage) + 
                (100 * thousand) * (7.5 * persentage) + 
                (200 * thousand) * (5 * persentage) + 
                (200 * thousand) * (3 * persentage) + 
                (400 * thousand) * (1.5 * persentage) + 
                rest * (1 * persentage);
    }

}

double calcIncome_if(double payment)
{
    const double thousand = 1000;
    const double persentage = 0.01;
    double rest;
    if (payment <= 100 * thousand)
    {
        return payment * 10 * persentage;
    }
    else if (payment <= 200 * thousand)
    {
        rest = payment - 100 * thousand;
        return (100 * thousand) * (10 * persentage) + 
            rest * (7.5 * persentage);
    }
    else if (payment <= 400 * thousand)
    {
        rest = payment - 200 * thousand;
        return (100 * thousand) * (10 * persentage) + 
            (100 * thousand) * (7.5 * persentage) + 
            rest * (5 * persentage);
    }
    else if (payment <= 600 * thousand)
    {
        rest = payment - 400 * thousand;
        return (100 * thousand) * (10 * persentage) + 
            (100 * thousand) * (7.5 * persentage) + 
            (200 * thousand) * (5 * persentage) + 
            rest * (3 * persentage);
    }
    else if (payment <= 1000 * thousand)
    {
        rest = payment - 600 * thousand;
        return (100 * thousand) * (10 * persentage) + 
            (100 * thousand) * (7.5 * persentage) + 
            (200 * thousand) * (5 * persentage) + 
            (200 * thousand) * (3 * persentage) + 
            rest * (1.5 * persentage);
    }
    else
    {
        rest = payment - 1000 * thousand;
        return (100 * thousand) * (10 * persentage) + 
            (100 * thousand) * (7.5 * persentage) + 
            (200 * thousand) * (5 * persentage) + 
            (200 * thousand) * (3 * persentage) + 
            (400 * thousand) * (1.5 * persentage) + 
            rest * (1 * persentage);
    }
}

// 要是学会排序算法就不用那么写了。
void sort_four_digits(int a, int b, int c, int d) {
    int temp;
    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }
    if (a > c) {
        temp = a;
        a = c;
        c = temp;
    }
    if (a > d) {
        temp = a;
        a = d;
        d = temp;
    }
    if (b > c) {
        temp = b;
        b = c;
        c = temp;
    }
    if (b > d) {
        temp = b;
        b = d;
        d = temp;
    }
    if (c > d) {
        temp = c;
        c = d;
        d = temp;
    }
    printf("排序后：%d %d %d %d\n", a, b, c, d);
}

double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double height(double x, double y) {
    const double
        tower_x1 = 2.0, tower_y1 = 2.0,
        tower_x2 = -2.0, tower_y2 = 2.0,
        tower_x3 = -2.0, tower_y3 = -2.0,
        tower_x4 = 2.0, tower_y4 = -2.0;
    double
        dt1 = distance(x, y, tower_x1, tower_y1),
        dt2 = distance(x, y, tower_x2, tower_y2),
        dt3 = distance(x, y, tower_x3, tower_y3),
        dt4 = distance(x, y, tower_x4, tower_y4);
    if (dt1 < 1 || dt2 < 1 || dt3 < 1 || dt4 < 1)
    {
        return 10.0;
    }
    else
    {
        return 0.0;
    }
}
// ****************************************************
// ****************************************************
// 输出到终端菜单。
void menu()
{
    // **************************************
    // ******题目描述，可根据需要调整。********
    char title[] = "P109 10,11,12";
    char que_1[] = "利润提成-if";
    char que_2[] = "利润提成-switch";
    char que_3[] = "四个数排序";
    char que_4[] = "求高度";
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
    double payment;
    printf("请输入存款金额：");
    scanf("%lf", &payment);
    printf("利润提成为：%.2lf\n", calcIncome_if(payment));
}

void question_2()
{
    double payment;
    printf("请输入存款金额：");
    scanf("%lf", &payment);
    printf("利润提成为：%.2lf\n", calcIncome_switch(payment));
}

void question_3()
{
    int a, b, c, d;
    printf("请输入四个整数：");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    sort_four_digits(a, b, c, d);
}

void question_4()
{
    double x, y;
    printf("请输入坐标：");
    scanf("%lf %lf", &x, &y);
    printf("高度为：%.1lf\n", height(x, y));
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
