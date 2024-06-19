// Author: DurFleck16
#include <stdio.h>
#include <stdlib.h>

// ****************************************************
// *******在此处添加你的宏、自定义函数、结构体或全局变量*******
#define MAX 100

// 传入一行字符串，将其中最长单词输出
void longestWord(char *str, char *word) {
    int max = 0, start = 0;
    // 遍历字符串，找到最长单词的起始位置和长度
    for (int i = 0, len = 0; str[i]; i++) {
        if (str[i] == ' ') {
            if (len > max) {
                max = len;
                start = i - len;
            }
            len = 0;
        } else {
            len++;
        }
    }
    // 复制最长单词到word
    for (int i = 0; i < max; i++) {
        word[i] = str[start + i];
    }
}

// 计算每个学生的平均分
void calcStudentAvg(int* score, double* avg)
{
    int* p = score;
    for (int i = 0; i < 10; i++)
    {
        int sum = 0;
        for (int j = 0; j < 5; j++)
        {
            sum += *p;
            p++;
        }
        avg[i] = sum / 5.0;
    }
}

// 计算每门课的平均分
void calcCourseAvg(int* score, double* avg)
{
    for (int i = 0; i < 5; i++)
    {
        int* p = score + i;  // 指向第i + 1门课的第一个学生的分数
        int sum = 0;
        for (int j = 0; j < 10; j++)
        {
            sum += *p;
            p += 5;
        }
        avg[i] = sum / 10.0;
    }
}

// 找到最高分，返回最高分，同时将学生和课程编号存入student和course中
int findMaxScore(int* score, int* student, int* course)
{
    int max = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (*(score + i * 5 + j) > max)
            {
                max = *(score + i * 5 + j);
                *student = i + 1;
                *course = j + 1;
            }
        }
    }
    return max;
}

// 计算方差，根据题意，用学生平均分数据
double calcVariance(double* score)
{
    double avg = 0;
    for (int i = 0; i < 10; i++)
    {
        avg += *(score + i);
    }
    avg /= 10;
    double variance = 0;
    for (int i = 0; i < 10; i++)
    {
        variance += (*(score + i) - avg) * (*(score + i) - avg);
    }
    variance /= 10;
    return variance;
}

// ****************************************************
// ****************************************************
// 输出到终端菜单。
void menu()
{
    // **************************************
    // ******菜单输出，可根据需要调整。********
    char title[] = "P216 10,14";  // 标题
    char que_1[] = "最长单词";   // 题目1，对应函数question1，下同
    char que_2[] = "学生成绩";   // 题目2
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
    char str[MAX], word[MAX];
    printf("请输入一行字符串：");
    while (getchar() != '\n');  // 清空输入缓冲区
    gets(str);
    longestWord(str, word);
    printf("最长单词是：%s\n", word);
}

void question_2()
{
    int score[50];
    int* p = score; // 指向分数数组的指针
    double studentAvg[10], courseAvg[5];
    int maxStudent, maxCourse;
    for (int i = 1; i <= 10; i++)
    {
        printf("请输入第%d个学生的5门课成绩：", i);
        for (int j = 1; j <= 5; j++)
        {
            scanf("%d", p);
            p++;
        }
    }
    calcStudentAvg(score, studentAvg);
    calcCourseAvg(score, courseAvg);
    int maxScore = findMaxScore(score, &maxStudent, &maxCourse);
    double variance = calcVariance(studentAvg);
    printf("=====================================\n");
    printf("序号\t课程1\t课程2\t课程3\t课程4\t课程5\t平均分\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%02d\t", i + 1);
        for (int j = 0; j < 5; j++)
        {
            printf("%d\t", score[i * 5 + j]);
        }
        printf("%.2lf\n", studentAvg[i]);
    }
    printf("平均分\t");
    for (int i = 0; i < 5; i++)
    {
        printf("%.2lf\t", courseAvg[i]);
    }
    printf("\n最高分：%d\n", maxScore);
    printf("最高分学生：%d，最高分课程：%d\n", maxStudent, maxCourse);
    printf("10个学生平均分的方差：%.2lf\n", variance);
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
