// Author: DurFleck16
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// ****************************************************
// *******在此处添加你的宏、自定义函数、结构体或全局变量*******
typedef struct employee
{
    int id;
    char name[20];
    char sex;
    int age;
    char address[50];
    double salary;
    char health[20];
    char education[20];
} Employee;

typedef struct simpifyEmployee
{
    char name[20];
    double salary;
} SimplifyEmployee;

// 以二进制形式写入职工数据
void writeEmployeeData()
{
    FILE* fp = fopen("./data/employee.dat", "wb");
    if (fp == NULL)
    {
        perror("文件打开失败！");
        exit(EXIT_FAILURE);
    }
	
	// 职工数据，可以修改
    Employee employees[] = {
        {1001, "张三", 'M', 22, "北京", 3000, "良好", "本科"},
        {1002, "李四", 'F', 23, "上海", 3500, "良好", "本科"},
        {1003, "王五", 'M', 24, "广州", 4000, "良好", "本科"},
        {1004, "赵六", 'F', 25, "深圳", 4500, "良好", "本科"},
        {1005, "孙七", 'M', 26, "杭州", 5000, "良好", "本科"},
    };

    fwrite(employees, sizeof(Employee), 5, fp);
    if (fclose(fp) != 0)
    {
        perror("文件关闭失败！");
        exit(EXIT_FAILURE);
    }
}

// 读取职工数据
void readEmployeeData()
{
    FILE* fp = fopen("./data/employee.dat", "rb");
    if (fp == NULL)
    {
        perror("文件打开失败！");
        exit(EXIT_FAILURE);
    }

    Employee employees[5];
    fread(employees, sizeof(Employee), 5, fp);
    fclose(fp);

    printf("ID\tName\tSex\tAge\tAddress\tSalary\tHealth\tEducation\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t%s\t%c\t%d\t%s\t%.2f\t%s\t%s\n",
            employees[i].id, employees[i].name, employees[i].sex, employees[i].age, employees[i].address,
            employees[i].salary, employees[i].health, employees[i].education);
    }
}

// 从文件中读取职工数据，简化后写入文件
void simplifyEmployeeData()
{
    FILE* fp = fopen("./data/employee.dat", "rb");
    if (fp == NULL)
    {
        perror("文件打开失败！");
        exit(EXIT_FAILURE);
    }

    Employee employees[5];
    fread(employees, sizeof(Employee), 5, fp);
    if (fclose(fp) != 0)
    {
        perror("文件关闭失败！");
        exit(EXIT_FAILURE);
    }

    SimplifyEmployee simplifyEmployees[5];
    for (int i = 0; i < 5; i++)
    {
        strcpy(simplifyEmployees[i].name, employees[i].name);
        simplifyEmployees[i].salary = employees[i].salary;
    }

    FILE* fp2 = fopen("./data/simplifyEmployee.dat", "wb");
    if (fp2 == NULL)
    {
        perror("文件打开失败！");
        exit(EXIT_FAILURE);
    }

    fwrite(simplifyEmployees, sizeof(SimplifyEmployee), 5, fp2);
    if (fclose(fp2) != 0)
    {
        perror("文件关闭失败！");
        exit(EXIT_FAILURE);
    }
}

void readSimplifyEmployeeData()
{
    FILE* fp = fopen("./data/simplifyEmployee.dat", "rb");
    if (fp == NULL)
    {
        perror("文件打开失败！");
        exit(EXIT_FAILURE);
    }

    SimplifyEmployee simplifyEmployees[5];
    fread(simplifyEmployees, sizeof(SimplifyEmployee), 5, fp);
    fclose(fp);

    printf("Name\tSalary\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%s\t%.2f\n", simplifyEmployees[i].name, simplifyEmployees[i].salary);
    }
}

void writeStringToFile(char* str, char* filename)
{
    FILE* fp = fopen(filename, "w");
    if (fp == NULL)
    {
        perror("文件打开失败！");
        exit(EXIT_FAILURE);
    }

    fputs(str, fp);
    if (fclose(fp) != 0)
    {
        perror("文件关闭失败！");
        exit(EXIT_FAILURE);
    }
}

void readStringFromFile(char* str, char* filename)
{
    FILE* fp = fopen(filename, "r");
    if (fp == NULL)
    {
        perror("文件打开失败！");
        exit(EXIT_FAILURE);
    }

    fgets(str, 100, fp);
    fclose(fp);
}

// ****************************************************
// ****************************************************
// 输出到终端菜单。
void menu()
{
    // **************************************
    // ******菜单输出，可根据需要调整。********
    char title[] = "P356 9,11";  // 标题
    char que_1[] = "职工数据";   // 题目1，对应函数question1，下同
    char que_2[] = "输入字符-文件-输出";   // 题目2
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
    printf("写入职工数据...\n");
    writeEmployeeData();
    printf("读取职工数据...\n");
    readEmployeeData();
    printf("简化职工数据...\n");
    simplifyEmployeeData();
    printf("读取简化职工数据...\n");
    readSimplifyEmployeeData();
}

void question_2()
{
    char str_1[100], str_2[100];
    printf("请输入字符串：");

    while (getchar() != '\n');  // 清空输入缓冲区
    fgets(str_1, sizeof(str_1), stdin);
    writeStringToFile(str_1, "./data/string.txt");
    printf("从文件中读取字符串...\n");
    readStringFromFile(str_2, "./data/string.txt");
    puts("读取的字符串为：");
    puts(str_2);
    puts("把字符串中的小写字母转换为大写字母...");
    for (int i = 0; i < strlen(str_2); i++)
    {
        if (islower(str_2[i]))
        {
            str_2[i] = toupper(str_2[i]);
        }
    }
    puts("转换后的字符串为：");
    puts(str_2);
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
