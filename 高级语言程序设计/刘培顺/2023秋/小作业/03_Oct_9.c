// Author: DurFleck16
#include <stdio.h>
#include <stdlib.h>

// ****************************************************
// *******在此处添加你的自定义函数、结构体或全局变量*******

// 求两个数的最大公约数和最小公倍数
void gcd_lcm(int a, int b, int *gcd, int *lcm)
{
    int t;
    *gcd = a;
    *lcm = a * b;
    while (b != 0)
    {
        t = a % b;
        a = b;
        b = t;
    }
    *gcd = a;
    *lcm = *lcm / a;
}

// 阶乘求和
double factorial_sum(int n)
{
    double sum = 0;     // 建议用double型，结果非常大。
    for(int i = 1; i <= n; i++)
    {
        double factorial = 1;
        for(int j = 1; j <= i; j++)
        {
            factorial *= j;
        }
        sum += factorial;
    }
    return sum;
}

// 统计一行字符的英文字母、空格、数字和其他字符的个数
void count(char *str, int *letter, int *space, int *digit, int *other)
{
    *letter = 0;
    *space = 0;
    *digit = 0;
    *other = 0;
    while (*str != '\0')
    {
        if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
        {
            (*letter)++;
        }
        else if (*str == ' ')
        {
            (*space)++;
        }
        else if (*str >= '0' && *str <= '9')
        {
            (*digit)++;
        }
        else
        {
            (*other)++;
        }
        str++;
    }
}

// ****************************************************
// ****************************************************

// 输出到终端菜单。
void menu()
{
    // **************************************
    // ******题目描述，可根据需要调整。********
    char title[] = "P137 3,4,6";
    char que_1[] = "最大公约数和最小公倍数";
    char que_2[] = "统计数目";
    char que_3[] = "阶乘求和";
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
    int m,n,gcd,lcm;
    printf("输入两个正整数，以空格作分隔：");
    scanf("%d %d",&m,&n);
    gcd_lcm(m,n,&gcd,&lcm);
    printf("最大公约数：%d\n",gcd);
    printf("最小公倍数：%d\n",lcm);
}

void question_2()
{
    printf("输入一行字符：");
    char str[100];

    /*
	 * 如果输入被跳过，马上写下这一行，意思是“清空缓冲区”
     * 缓冲区是一个存储输入输出数据的临时存储区，用于临时存放数据，以便程序使用。
     * 在输入数据时，数据并不是直接送到程序中，而是先送到缓冲区中，程序再从缓冲区中取数据。
     * 如果输入被跳过，可能是因为前面代码的输入已经把回车符等字符留在缓冲区了。
     * while空循环的作用是清空缓冲区，每次进行条件判断时，getchar()都会读取缓冲区的内容，直到缓冲区为空。
     * 当缓冲区的内容读完，getchar()函数会等待用户输入，只要用户输入，while循环条件表达式的值就变为false，跳出空循环。
	 * 然后就可以正常接用户输入了。
	 */
    while (getchar() != '\n');

    fgets(str, 100, stdin);  // fgets()比gets()好，后者有安全问题。
    int letter,space,digit,other;
    count(str,&letter,&space,&digit,&other);
    printf("字母：%d\n",letter);
    printf("空格：%d\n",space);
    printf("数字：%d\n",digit);
	// 减1是为了排除换行符，fgets()和gets()函数会在你敲回车之后，读入换行符，然后再跳出函数，完成字符串输入
    printf("其他：%d\n",other - 1);
}

void question_3()
{
    const int n = 20;
    printf("阶乘求和：%.1lf\n",factorial_sum(n));
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
