// Author: DurFleck16
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// ****************************************************
// *******在此处添加你的宏、自定义函数、结构体或全局变量*******
#define MAX_EMPLOYEES 10

// 定义员工结构体
typedef struct {
    int id;
    char name[50];
} Employee;

Employee employees[MAX_EMPLOYEES];

void initEmployees()
{
    for (int i = 0; i < MAX_EMPLOYEES; i++)
    {
        employees[i].id = 0;
    }
}

void addEmployee(int id, char* name) {
    for (int i = 0; i < MAX_EMPLOYEES; i++)
    {
        if (employees[i].id == 0)
        {
            employees[i].id = id;
            strcpy(employees[i].name, name);
            break;
        }
    }
}

// 使用冒泡排序
void sortEmployees() {
    for (int i = 0; i < MAX_EMPLOYEES; i++)
    {
        for (int j = i + 1; j < MAX_EMPLOYEES; j++)
        {
            if (employees[i].id > employees[j].id)
            {
                Employee temp = employees[i];
                employees[i] = employees[j];
                employees[j] = temp;
            }
        }
    }
}

void printEmployees() {
    for (int i = 0; i < MAX_EMPLOYEES; i++)
    {
        if (employees[i].id != 0)
        {
            printf("职工号：%d, 姓名：%s\n", employees[i].id, employees[i].name);
        }
    }
}

// 以折半查找方式查找员工
int findEmployee(int id) {
    int left = 0;
    int right = MAX_EMPLOYEES - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (employees[mid].id == id) {
            return mid;
        } else if (employees[mid].id < id) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}


int calcHowManyDays(int year, int month, int day)
{
    int days = 0;
    int monthDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        monthDays[1] = 29;
    }
    for (int i = 0; i < month - 1; i++)
    {
        days += monthDays[i];
    }
    days += day;
    return days;
}

// ****************************************************
// ****************************************************
// 输出到终端菜单。
void menu()
{
    // **************************************
    // ******菜单输出，可根据需要调整。********
    char title[] = "P216 15,18";  // 标题
    char que_1[] = "职工信息";   // 题目1，对应函数question1，下同
    char que_2[] = "计算该年第几天";   // 题目2
    char que_3[] = "";   // 题目3
    char que_4[] = "";   // 题目4
    char que_5[] = "";   // 题目5
    char que_6[] = "";   // 题目6
    // 题目可以留空，对应题目的函数留空即可。
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
    initEmployees();
    // 添加员工
    for (int i = 0; i < MAX_EMPLOYEES; i++) {
        int tempId;
        char tempName[50];
        printf("请输入第%d个员工的职工号：", i + 1);
        scanf("%d", &tempId);
        printf("请输入第%d个员工的姓名：", i + 1);
        scanf("%s", tempName);
        addEmployee(tempId, tempName);
    }
    // 排序
    sortEmployees();
    // 输出
    printf("\n排序后的员工信息：\n");
    printEmployees();
    printf("\n");
    // 查找
    int id;
    int choice = 1;
    while (choice == 1) {
        printf("请输入要查找的员工职工号：");
        scanf("%d", &id);
        int index = findEmployee(id);
        if (index != -1) {
            printf("职工号：%d, 姓名：%s\n", employees[index].id, employees[index].name);
        } else {
            printf("未找到该职工\n");
        }
        
        while (getchar() != '\n'); // 清空输入缓冲区
        printf("是否继续查找？(Y/N):");
        char c = getchar();
        if (c == 'Y' || c == 'y') {
            choice = 1;
        } else {
            choice = 0;
        }
    }
}

void question_2()
{
    int year, month, day;
    printf("请输入年月日(yyyy-mm-dd)：");
    scanf("%d-%d-%d", &year, &month, &day);
    printf("这是%d年的第%d天\n", year, calcHowManyDays(year, month, day));
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
