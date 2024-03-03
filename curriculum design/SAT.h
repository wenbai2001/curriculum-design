#pragma once
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include<time.h>
typedef struct clause {
	int data;
	int tag;
	struct clause* next;
}clause;//单链表，用于储存每一个子句
typedef struct cnf {
	clause cl;//单链表，用于储存每一个子句
	int tag;
	cnf* next;//指向下一个子句
	int length;//此子句的大小
} cnf;//定义cnf子句
typedef struct sta
{
	cnf* L;//各个子句的头结点
	int length;//公式长度；
	int  variablelength;//变元长度
} sta;//定义CNF——STA公式
int readin(sta& c, char* s);//读取函数
int DPLL(sta c, int* a);
int find1(sta c);//寻找单个子句
int choosev(sta c);
int solve(sta &c, int* a, int n ,int v);
void back(sta &c, int n,int *a);
int check(sta c, int* a);
int leadout(int n, int i, int *a, char* s, double t);//读取函数
void print(sta c);