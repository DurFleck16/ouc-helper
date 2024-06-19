// Author: DurFleck16
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ****************************************************
// *******在此处添加你的宏、自定义函数、结构体或全局变量*******

int readFirstScore(int *score, int student)
{
    int *point = score + student * 5; // 初始化指针，指向学生的第一门课
    return *point;
}

int findFailedStudent(int *score, int student)
{
    int *point = score + student * 5; // 初始化指针，指向学生的第一门课
    int flag = 0;                     // 记录不及格课程的数量
    for (int i = 0; i < 5; i++)
    {
        if (*point < 60)
        {
            flag++;
        }
        if (flag >= 2)
        {
            return 1; // 该学生有两门及以上不及格
        }
        point++; // 指向下一门课
    }
    return 0;
}

int findExcellentStudent(int *score, int student)
{
    int flag = 1;                     // 判断是否优秀
    int *point = score + student * 5; // 初始化指针，指向学生的第一门课
    int sum = 0;                      // 记录总分
    for (int i = 0; i < 5; i++)
    {
        sum += *point;
        if (*point < 85)
        {
            flag = 0; // 有一门课在85分以下
        }
        point++; // 指向下一门课
    }
    if (sum / 5 > 90)
        flag = 1; // 或者平均分大于90
    return flag;
}

// 稍微瞄了谭某某写的代码，什么鬼东西
int extractIntInStr(char *str, int *arr)
{
    int count = 0;  // 记录提取的整数个数
    int num = 0;    // 记录当前数字
    int length = 0; // 记录数字长度
    while (1)
    {
        if (*str >= '0' && *str <= '9')
        {
            length++;
        }
        else if (length)
        {
            num = *(str - 1) - '0';
            for (int i = 1; i < length; i++)
            {
                int tmp = 1; // 计算10的次方，以确定这个数是在哪一位（个位、十位、百位...）
                for (int j = 0; j < i; j++)
                {
                    tmp *= 10;
                }
                num += (*(str - 1 - i) - '0') * tmp; // 确定位数之后，把这一个数字加到num上
            }
            arr[count] = num;
            count++;
            length = 0;
        }
        if (*str == '\0')
        {
            break;
        }
        str++;
    }
    return count;
}
// ****************************************************
// ****************************************************
// 输出到终端菜单。
void menu()
{
    // **************************************
    // ******菜单输出，可根据需要调整。********
    char title[] = "P292 15,16";       // 标题
    char que_1[] = "计算成绩-2nd";     // 题目1，对应函数question1，下同
    char que_2[] = "字符串中提取整数"; // 题目2
    char que_3[] = "";                 // 题目3
    char que_4[] = "";                 // 题目4
    char que_5[] = "";                 // 题目5
    char que_6[] = "";                 // 题目6
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
    int score[20];
    for (int i = 0; i < 4; i++)
    {
        printf("请输入第%d个学生的5门课成绩，以空格分隔：", i + 1);
        for (int j = 0; j < 5; j++)
        {
            scanf("%d", score + i * 5 + j);
        }
    }
    double sumOfFirst = 0;
    for (int i = 0; i < 4; i++)
    {
        sumOfFirst += readFirstScore(score, i);
    }
    printf("第一门课的平均分为：%.2lf\n", sumOfFirst / 4.0);
    printf("\n");
    for (int i = 0; i < 4; i++)
    {
        if (findFailedStudent(score, i))
        {
            double sum;
            printf("第%d个学生有两门及以上不及格\n", i + 1);
            printf("他的各科成绩为：\n");
            for (int j = 0; j < 5; j++)
            {
                printf("%d ", *(score + i * 5 + j));
                sum += *(score + i * 5 + j);
            }
            printf("\n");
            printf("他的平均分为：%.2lf\n", sum / 5.0);
            printf("\n");
        }
    }
    for (int i = 0; i < 4; i++)
    {
        if (findExcellentStudent(score, i))
        {
            double sum;
            printf("第%d个学生是优秀学生\n", i + 1);
            printf("他的各科成绩为：\n");
            for (int j = 0; j < 5; j++)
            {
                printf("%d ", *(score + i * 5 + j));
                sum += *(score + i * 5 + j);
            }
            printf("\n");
            printf("他的平均分为：%.2lf\n", sum / 5.0);
            printf("\n");
        }
    }
}

void question_2()
{
    char str[100];
    int arr[100];
    printf("请输入一个字符串：");
    while (getchar() != '\n');
    gets(str);
    int count = extractIntInStr(str, arr);
    printf("提取的整数有%d个，分别是：", count);
    for (int i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
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
