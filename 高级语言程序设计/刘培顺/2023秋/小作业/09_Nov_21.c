// Author: DurFleck16
#include <stdio.h>
#include <stdlib.h>

// ****************************************************
// *******在此处添加你的宏、自定义函数、结构体或全局变量*******
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 将数组最后m个数移到数组前面，前面的数移到后面
void moveArray(int* arr, int n, int m)
{
    // 交换m个数m次
    for (int i = 0; i < m; i++)
    {
        // 每次交换一个数
        for (int j = n - 1; j > 0; j--)
        {
            swap(&arr[j], &arr[j - 1]);
        }
    }
}

// 退圈问题，又叫约瑟夫问题
// n个人围成一圈，从第一个人开始报数，报到m的人出圈，然后从出圈的下一个人开始重新报数，返回最后一个出圈的人
int lastOne(int* id, int n, int m)
{
    int count = 0;  // 出圈的人数
    int i = 0;  // 当前报数的人的索引
    int j = 0;  // 当前报数的数
    while (count < n - 1)
    {
        if (id[i] != 0)
        {
            j++;
            // 报到m的人出圈
            if (j == m)
            {
                id[i] = 0;
                j = 0;
                count++;
            }
        }
        i++;
        // 到达数组末尾，重新开始
        if (i == n)
        {
            i = 0;
        }
    }

    // 返回最后一个出圈的人
    for (int i = 0; i < n; i++)
    {
        if (id[i] != 0)
        {
            return id[i];
        }
    }
	
    return -1;
}


// ****************************************************
// ****************************************************
// 输出到终端菜单。
void menu()
{
    // **************************************
    // ******菜单输出，可根据需要调整。********
    char title[] = "P291 4,5";  // 标题
    char que_1[] = "后移数组";   // 题目1，对应函数question1，下同
    char que_2[] = "退圈";   // 题目2
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
    int arr[50];
    int n, m;
    printf("请输入数组长度：");
    scanf("%d", &n);
    printf("请输入后移的个数：");
    scanf("%d", &m);
    printf("请输入数组：");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    moveArray(arr, n, m);
    printf("后移后的数组：");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void question_2()
{
    const int m = 3;
    int id[50];
    int n;
    printf("请输入人数：");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        id[i] = i + 1;
    }
    int last = lastOne(id, n, m);
    printf("最后一个出圈的人是：%d\n", last);
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
