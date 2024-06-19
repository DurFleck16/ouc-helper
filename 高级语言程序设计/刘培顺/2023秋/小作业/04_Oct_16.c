// Author: DurFleck16
#include <stdio.h>
#include <stdlib.h>

// ****************************************************
// *******在此处添加你的自定义函数、结构体或全局变量*******

// 猴子吃桃问题。
void eatingPeaches() {
    int totalPeaches = 1;
    for (int day = 9; day >= 1; day--) {
        totalPeaches = (totalPeaches + 1) * 2;  // 递推公式易得。
    }
    printf("猴子第一天摘了 %d 个桃子。\n", totalPeaches);
}

// 二分法求根。
void binarySearchRoot() {
    // a, b 为区间端点，c 为中点。
    double a = -10, b = 10, c;
	/*
     * 1e-5 为精度，即10的-5次方。
     * 在编程中，习惯用这种方法来表示非常大/小的浮点数。
	 */
    while (b - a > 1e-5) {
        c = (a + b) / 2;
        if (2*c*c*c - 4*c*c + 3*c - 6 > 0) {
            b = c;
        } else {
            a = c;
        }
    }
    printf("方程 2x^3 - 4x^2 + 3x - 6 = 0 的根为 %.5f\n", c);
}

// 乒乓球比赛。
// 穷举法，直接枚举所有可能的情况。
void pingpongGame() {
    int A_battle, B_battle, C_battle;
    // 使用字符的 ASCII 码来表示对手，这样也方便进行穷举。（char型和int型可以相互转换）
		
	// 如果A对战的对象从“X”到“Z”
	for (A_battle = 'X'; A_battle <= 'Z'; A_battle++)
	{
		// 如果B对战的对象从“X”到“Z”
		for (B_battle = 'X'; B_battle <= 'Z'; B_battle++)
		{
			// 如果C对战的对象从“X”到“Z”
			for (C_battle = 'X'; C_battle <= 'Z'; C_battle++)
			{
				// 去除限制条件
				if (A_battle == 'X' || C_battle == 'X' || C_battle == 'Z' || 
					B_battle == A_battle || B_battle == C_battle || A_battle == C_battle)
				{
					continue;
				}
				printf("A对%c,B对%c,C对%c", A_battle, B_battle, C_battle);
			}
		}
	}
}

// ****************************************************
// ****************************************************
// 输出到终端菜单。
void menu()
{
    // **************************************
    // ******菜单输出，可根据需要调整。********
    char title[] = "P138 12,15,17";  // 标题
    char que_1[] = "猴子吃桃";   // 题目1，对应函数question1，下同
    char que_2[] = "二分法";   // 题目2
    char que_3[] = "乒乓球";   // 题目3
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
    eatingPeaches();
}

void question_2()
{
    binarySearchRoot();
}

void question_3()
{
    pingpongGame();
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
