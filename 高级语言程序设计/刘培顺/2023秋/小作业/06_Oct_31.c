// Author: DurFleck16
#include <stdio.h>
#include <stdlib.h>

// ****************************************************
// *******在此处添加你的宏、自定义函数、结构体或全局变量*******

# define MAX 100 // 定义字符串最大长度

// 密文解密，自己推一下公式。
void decode(char *str) {
    // 为什么循环中的条件是 *str?
    while (*str) {
        if (*str >= 'a' && *str <= 'z') {
            *str = 'z' - (*str - 'a');
        } else if (*str >= 'A' && *str <= 'Z') {
            *str = 'Z' - (*str - 'A');
        }
        str++;
    }
}

// 字符串大小比较，要求不使用strcpy函数。
// 字符串的“大小”，在课本里面有。
int myStrCmp(char *str1, char *str2) {
    while (*str1 && *str2) {
        if (*str1 != *str2) {
            break;
        }
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

// 不用strcpy函数，实现字符串拷贝。
// dest是目标字符串，src是源字符串。
void myStrCpy(char *dest, char *src) {
    // 为什么循环条件是 *src?
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';   // 注意题目要求。
}

// ****************************************************
// ****************************************************
// 输出到终端菜单。
void menu()
{
    // **************************************
    // ******菜单输出，可根据需要调整。********
    char title[] = "P166 12 14 15";  // 标题
    char que_1[] = "解密";   // 题目1，对应函数question1，下同
    char que_2[] = "比较字符串";   // 题目2
    char que_3[] = "拷贝字符串";   // 题目3
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
    char str[MAX];
    printf("请输入字符串：");
    scanf("%s", str);
    decode(str);
    printf("解密后的字符串：%s\n", str);
}

void question_2()
{
    char str1[MAX], str2[MAX];
    printf("请输入字符串1：");
    scanf("%s", str1);
    printf("请输入字符串2：");
    scanf("%s", str2);
    int result = myStrCmp(str1, str2);
    printf("比较结果：%d\n", result);
}

void question_3()
{
    char str1[MAX], str2[MAX];
    printf("请输入字符串1：");
    scanf("%s", str1);
    myStrCpy(str2, str1);
    printf("拷贝后的字符串：%s\n", str2);
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
