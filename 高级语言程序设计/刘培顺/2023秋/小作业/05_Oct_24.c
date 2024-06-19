// Author: DurFleck16
#include <stdio.h>
#include <stdlib.h>

// ****************************************************
// *******在此处添加你的自定义函数、结构体或全局变量*******

#define MAX 50	// 定义静态数组的边界

// 杨辉三角。
// 用笔和纸画一下课本里展示的杨辉三角来找规律。
void pascalTriangle(int n) {
    int arr[MAX][MAX];

    for (int line = 0; line < n; line++) {
        for (int i = 0; i <= line; i++) {
            if (line == i || i == 0)    // 第一列和对角线的元素都是1
                arr[line][i] = 1;
            else
				// 其他元素等于上一行的两个元素之和（左上的和顶头上的）
                arr[line][i] = arr[line - 1][i - 1] + arr[line - 1][i];
            printf("%d ", arr[line][i]);
        }
        printf("\n");
    }
}

// 魔方阵。只实现奇数阶的魔方阵。
void magicSquare(int n) {
	if (n % 2 == 0) {
		printf("只实现奇数阶的魔方阵！\n");
		return; // 直接跳出函数
	}
	
	int arr[MAX][MAX];
	// 初始化数组
	for (int i = 0; i <= n; i++)
		for (int j = 1; j <= n; j++)
			arr[i][j] = 0;
	
	// 初始化行、列、数字，直接忽略0行0列
	int row = 1, col = n / 2 + 1, num = 1;
	arr[row][col] = num;    // 第一个数字1放在第1行的中间
	for (num = 2; num <= n * n; num++) {
		row--;  // 行减1
		col++;  // 列加1
		if(row < 1 && col > n) {    // 如果行小于1且列大于n，说明越界，需要调整
			row += 2;
			col--;
		}
		else {
			if (row < 1)    // 如果行小于1，说明在第0行，需要调整到最后一行
				row = n;
			if (col > n)    // 如果列大于n，说明在第n+1列，需要调整到第1列
				col = 1;
		}
		
		if (arr[row][col] == 0) // 如果该位置没有数字，直接放入
			arr[row][col] = num;
		else {  // 如果该位置有数字，需要调整
			row += 2;
			col--;
			arr[row][col] = num;
		}
	}
	
	// 输出魔方阵
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}

// 鞍点。
// m,n分别为输入矩阵的行数和列数。
void saddlePoint(int* arr, int m, int n) {
    int flag = 0;   // 标志变量，判断是否有鞍点。
    for (int i = 0; i < m; i++) {
        // max和col分别初始化为第一列的最大值和列号
        // arr[i][j] = *(arr + i * n + j)
        // ANSI C不支持变长二维数组，只能用一维数组模拟（C99支持）
        int max = *(arr + i * n);   
        int col = 0;

        // 找到行的最大值和列号
        for (int j = 1; j < n; j++) {
            if (*(arr + i * n + j) > max) {
                max = *(arr + i * n + j);
                col = j;
            }
        }
        // min初始化为第0行的第col列的值
        int min = *(arr + col);

        // 找到列的最小值
        for (int k = 1; k < m; k++) {
            if (*(arr + k * n + col) < min)
                min = *(arr + k * n + col);
        }
        
        // 如果鞍点的行最大值等于列最小值，说明是鞍点。
        if (max == min) {
            printf("鞍点为：%d\n", *(arr + i * n + col));
            printf("坐标为：(%d, %d)\n", i, col);
            flag = 1;   // 有鞍点
        }
    }
    // 如果没有鞍点，输出提示信息。
    if (flag == 0)
        printf("无鞍点！\n");
}

// ****************************************************
// ****************************************************
// 输出到终端菜单。
void menu()
{
    // **************************************
    // ******菜单输出，可根据需要调整。********
    char title[] = "P165 6,7,8";  // 标题
    char que_1[] = "杨辉三角";   // 题目1，对应函数question1，下同
    char que_2[] = "魔方阵";   // 题目2
    char que_3[] = "鞍点";   // 题目3
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
    const int n = 10;
    pascalTriangle(n);
}

void question_2()
{
    printf("请输入奇数阶魔方阵的阶数：");
    int n;
    scanf("%d", &n);
    magicSquare(n);
}

void question_3()
{
    int m, n;
    printf("请输入矩阵的行数和列数：");
    scanf("%d %d", &m, &n);
    int* arr = (int*)malloc(m * n * sizeof(int));

    printf("请输入一个%d行%d列的矩阵：\n", m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", arr + i * n + j);
    
    saddlePoint(arr, m, n);
    free(arr);
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
