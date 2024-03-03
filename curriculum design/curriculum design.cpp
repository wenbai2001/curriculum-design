// curriculum design.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "SAT.h"
#include"soduko.h"
int main()
{
	int op = 1;
	char s[100];
	sta c;
	int* b, * a, * ans;
	int m;
	while (op) {
		system("cls");	printf("\n\n");
		printf("		菜单 \n");
		printf("-------------------------------------------------\n");
		printf("1、DPLL运算		2、数独游戏，输入0退出\n");
		printf("-------------------------------------------------\n");
		scanf("%d", &op);
		switch (op) {
		case 1:
			printf("请输入要处理的cnf文件：\n");
			scanf("%s", s);
			if(readin(c, s)==0) printf("输入文件不存在\n");
			else
			{
				int *a = (int*)malloc(sizeof(int) * (c.variablelength+1));
				print(c);
				time_t time1 = clock();
				int n=DPLL(c, a);
				time_t time2 = clock();
				leadout(n, c.variablelength,a, s, difftime(time2,time1));
				printf("文件已成功保存至%s中\n", s);
				printf("是否进行检查，是输入1，否输入0\n");
				scanf("%d", &m);
				if (m == 1)
				{
					FILE* fp = fopen(s, "r");
					if (m == 1)
					{
						n = check(c, a);
						if (n == 0) printf("失败");
					    else printf("成功");
					}
					fclose(fp);
				}
				free(a);
			}
			getchar(); getchar(); break;
		case 2:
				printf("\n\n");
				printf("-------------------------------------------------\n");
				printf("输入1开始数独游戏，输入2进行已知数独的求解，输入0返回上一步\n");
				printf("-------------------------------------------------\n");
				scanf("%d", &op);
				switch (op) {
				case 1:
					printf("请输入想要玩的层数：\n");
					scanf("%d", &m);
					a = NULL;
					a = producenew(m);
					ans = (int*)malloc(sizeof(int) * (m * m + 1));
					for (int i = 0; i < m; i++)
					{
						for (int j = 0; j < m; j++)
						{
							if (a[i * m + j + 1 ]>0) printf("1 ");
							else if (a[i * m + j + 1 ]<0) printf("0 ");
							else printf("? ");
						}
						printf("\n");
					}
					while (op != 2) {
						printf("-------------------------------------------------\n");
						printf("输入1输入玩家答案，输入2查看答案并退出\n");
						printf("-------------------------------------------------\n");
						scanf("%d", &op);
						switch (op) {
						case 1:
							for (int i = 0; i < m * m; i++)
							{
								ans[i + 1] = a[i + 1];
							}
							for (int i = 0; i < m; i++)
							{
								for (int j = 0; j < m; j++)
								{
									if (a[i * m + j + 1] == 0)
									{
										printf("请输入第%d行第%d列数据,此时输入2查看答案\n", i + 1, j + 1);
										scanf("%d", &ans[i * m + j + 1]);
										if (ans[i * m + j + 1] == 0) ans[i * m + j + 1] = -1;
										else if (ans[i * m + j + 1] == 1)ans[i * m + j + 1] = 1;
										else goto anser;
										b = NULL;;
										if (solvesoduko(ans, &b, m) == 0)
										{
											ans[i * m + j + 1] = -ans[i * m + j + 1];
											printf("错误,正确答案为%d\n", (ans[i * m + j + 1] + 1) / 2);
										}
										else
										{
											printf("正确\n");
										}
									}
								}
							}
							printf("游戏结束,");
							op = 2;
						case 2:
							anser:
							 b = NULL;
							 time_t t1 = clock();
							solvesoduko(a, &b, m);
							time_t t2 = clock();
							printf("解题耗时为%lfms\n", difftime(t2, t1));
							printf("正确答案为：\n");
							for (int i = 0; i < m; i++)
							{
								for (int j = 0; j < m; j++)
								{
									if (b[i * m + j + 1] > 0) printf("1 ");
									else if (b[i * m + j + 1] < 0) printf("0 ");
									else printf("0 ");
								}
								printf("\n");
							}
						}
					}
					free(ans);
					break;
				case 2:
					int m;
					printf("请输入数独层数\n");
					scanf("%d", &m);
					printf("请输入数独，空用“?”表示\n");
					int i = 0;
					char ch;
					 a = (int*)malloc(sizeof(int) * (m * m + 1));
					while (i != m * m)
					{
						ch = getchar();
						if (ch == '0') a[++i] = -1;
						else if (ch == '1') a[++i] = 1;
						else if (ch == '?') a[++i] = 0;
					}
					int* b = NULL;
					if(solvesoduko(a, &b, m)==0) printf("数独无解\n");
					else
					{
						for (int i = 0; i < m; i++)
						{
							for (int j = 0; j < m; j++)
							{
								if (b[i * m + j + 1] > 0) printf("1 ");
								else if (b[i * m + j + 1] < 0) printf("0 ");
								else printf("0 ");
							}
							printf("\n");
						}
					}
				}
			getchar(); getchar(); break;
		case 0:;
		}
	}
	printf("欢迎下次再使用本系统！\n");
	return 0;
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
