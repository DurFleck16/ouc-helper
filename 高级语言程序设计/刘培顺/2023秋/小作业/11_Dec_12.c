// Author: DurFleck16
#include <stdio.h>
#include <stdlib.h>

// ****************************************************
// *******在此处添加你的宏、自定义函数、结构体或全局变量*******
#define N 10

typedef struct node
{
    int data;
    struct node* next;
} Node;

typedef struct student
{
    int id;
    char name[20];
    int score[3];
} Student;

void inputStudentData(Student* students, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("请输入第%d个学生的学号：", i + 1);
        scanf("%d", &students[i].id);
        printf("请输入第%d个学生的姓名：", i + 1);
        scanf("%s", students[i].name);
        printf("请输入第%d个学生的三门课成绩：", i + 1);
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &students[i].score[j]);
        }
    }
}

void printScoreInfo(Student* students, int n)
{
    printf("学号\t姓名\t成绩1\t成绩2\t成绩3\t平均分\n");
    double sumAll;
    for (int i = 0; i < n; i++)
    {
        double sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum += students[i].score[j];    // 计算某一个每一个课程的总分
            sumAll += students[i].score[j]; // 计算所有课程的总分
        }
        printf("%d\t%s\t%d\t%d\t%d\t%.2f\n", 
			students[i].id, 
			students[i].name, 
			students[i].score[0], 
			students[i].score[1], 
			students[i].score[2], 
			sum / 3.0);
    }
    printf("所有输入的分数的平均分：%.2f\n", sumAll / (n * 3.0));
}

int printHighestScore(Student* students, int n)
{
    int max = students[0].score[0];
    int maxIndex = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (students[i].score[j] > max)
            {
                max = students[i].score[j];
                maxIndex = i;
            }
        }
    }
    printf("学号：%d, 姓名：%s, 最高分：%d\n", students[maxIndex].id, students[maxIndex].name, max);
    return maxIndex;
}

// 创建循环链表
Node* createList(int n)
{
    Node* head = (Node*)malloc(sizeof(Node));   // 创建头结点
    // 检查内存是否分配成功
    if (head == NULL)
    {
        fprintf(stderr, "malloc failed\n");
        exit(EXIT_FAILURE);
    }
    // 初始化头结点
    head->data = 1;
    head->next = NULL;
    // 创建链表
    Node* p = head;
    for (int i = 2; i <= n; i++)
    {
        // 创建新结点，temp指向新结点
        Node* temp = (Node*)malloc(sizeof(Node));
        temp->data = i;
        temp->next = NULL;

        p->next = temp; // 将新结点挂到链表上，即将前一个结点的next指向新结点
        p = temp;   // p指向新结点，以便下一次循环
    }
    p->next = head; // 将最后一个结点的next指向头结点，形成循环链表
    return head;
}

// 约瑟夫问题
void josephus(int n, int m)
{
    Node* head = createList(n);
    Node* p = head;
    // 找到链表的最后一个结点
    while (p->next != head)
    {
        p = p->next;
    }
    // 从头结点开始，找到第m个结点
    p = head;
    while (p->next != p)
    {
        // 找到第m-1个结点
        for (int i = 1; i < m - 1; i++)
        {
            p = p->next;
        }
        // 删除第m个结点
        Node* temp = p->next;   // temp指向第m个结点
        p->next = temp->next;   // 将第m-1个结点的next指向第m+1个结点
        printf("出列的人是：%d\n", temp->data);
        free(temp);
        p = p->next;    // p指向原来第m+1个结点，以便下一次循环
    }
    printf("最后剩下的人是：%d\n", p->data);
    free(p);
}

// ****************************************************
// ****************************************************
// 输出到终端菜单。
void menu()
{
    // **************************************
    // ******菜单输出，可根据需要调整。********
    char title[] = "P330 5,6";  // 标题
    char que_1[] = "学生成绩-结构体";   // 题目1，对应函数question1，下同
    char que_2[] = "约瑟夫问题-链表";   // 题目2
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
    Student students[N];
    inputStudentData(students, N);
    printScoreInfo(students, N);
    int maxStudent = printHighestScore(students, N);
    double sum;
    printf("最高学生的3门课程分数：\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", students[maxStudent].score[i]);
        sum += students[maxStudent].score[i];
    }
    printf("\n平均分：%.2f\n", sum / 3.0);
}

void question_2()
{
    const int n = 13, m = 3;
    josephus(n, m);
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
