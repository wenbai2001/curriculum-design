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
}clause;//���������ڴ���ÿһ���Ӿ�
typedef struct cnf {
	clause cl;//���������ڴ���ÿһ���Ӿ�
	int tag;
	cnf* next;//ָ����һ���Ӿ�
	int length;//���Ӿ�Ĵ�С
} cnf;//����cnf�Ӿ�
typedef struct sta
{
	cnf* L;//�����Ӿ��ͷ���
	int length;//��ʽ���ȣ�
	int  variablelength;//��Ԫ����
} sta;//����CNF����STA��ʽ
int readin(sta& c, char* s);//��ȡ����
int DPLL(sta c, int* a);
int find1(sta c);//Ѱ�ҵ����Ӿ�
int choosev(sta c);
int solve(sta &c, int* a, int n ,int v);
void back(sta &c, int n,int *a);
int check(sta c, int* a);
int leadout(int n, int i, int *a, char* s, double t);//��ȡ����
void print(sta c);