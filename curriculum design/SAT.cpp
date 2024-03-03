#include "SAT.h"
int readin(sta& c, char* s)
{
	c.L = (cnf*)malloc(sizeof(cnf));
	cnf* p = c.L;
	FILE* fp = fopen(s, "r");
	if (fp == NULL) return 0;
	char a[10];//用于跳过一些空格。
	char ch;
	ch = fgetc(fp);
	clause* q = NULL;
	while (ch=='c')
	{
		if (ch == 'c')
			for (; fgetc(fp) != '\n';);
		ch = fgetc(fp);
	}
	fscanf(fp, "%s", a);
	fscanf(fp, "%d%d", &c.variablelength, &c.length);
	int x;
	for(int m = 0; m < c.length; m++)
	{
		p->next = (cnf*)malloc(sizeof(cnf));
		p = p->next;
		p->tag = 0;
		q = &(p->cl);
		q->next=(clause*)malloc(sizeof(clause));
		q = q->next;
		q->tag = 0;
		fscanf(fp, "%d", &q->data);
		q->next = NULL;
		p->next = NULL;
		p->length = 1;
		fscanf(fp, "%d", &x);
		for (; x != 0; fscanf(fp, "%d", &x))
		{
			q->next = (clause*)malloc(sizeof(clause));
			q = q->next;
			q->tag = 0;
			q->data = x;
			q->next = NULL;
			p->length++;
		}
	}
	fclose(fp);
	return 1;
}
int DPLL(sta c, int* a)
{
	int* stack = (int*)malloc(sizeof(int) * c.variablelength);
	int top = 0;
	int v=0;
	int n=1;
	cnf *p = c.L;
	int result;
	while (1)
	{
		result = solve(c, a, n, v);
		if (result == 1) return 1;
		else if (result == 0)
		{
			if (n == 1) return 0;
			else
			{
				back(c, n, a);
				v = -stack[top-1];
				top--;
				n--;
			}
		}
		else
		{
			v = choosev(c);
			stack[top] = v;
			top++;
			n++;
		}
	}
}
int find1(sta c)
{
	cnf *p = c.L->next;
	for (;p != NULL;p=p->next)
		if (p->tag == 0 && p->length == 1)
		{
			for (clause* r = p->cl.next; r != NULL; r = r->next)
				if (r->tag == 0) return r->data;
		}
	return 0;
}
int choosev(sta c)//选择决策
{
	int v;
	double u;
	double* b = (double*)malloc(sizeof(double) * (c.variablelength + 1));
	for (int i = 0; i < c.variablelength + 1; i++) b[i] = 0;
	for (cnf* p = c.L->next; p != NULL; p = p->next)
		if (p->tag == 0)
			for (clause* r = p->cl.next; r != NULL; r = r->next)
			{
				if (r->tag == 0)
					if (r->data > 0)
					{
						b[r->data] += pow(2, -p->length);
					}
					else
					{
						b[-r->data] += pow(2, -p->length);
					}
			}
	v = 0, u = 0;
	for (int i = 1; i < c.variablelength + 1; i++)
	{
		if (u < b[i])
		{
			u = b[i];
			v = i;
		}
	}
	free(b);
	return v;
}
int solve(sta &c,int *a ,int n, int v)
{
	int t;
	cnf* p = c.L;
	if (v == 0) t = find1(c);
	else t = v;
	while (t!=0) {
		if (t > 0) a[t] = n;
		else a[-t] = -n;
		for (p = c.L->next; p != NULL; p = p->next)
		{
			if(p->tag ==0)
			{
				for (clause* r = p->cl.next; r != NULL; r = r->next)
				{
					if (r->data == -t)
					{
						r->tag = n;
						p->length--;
						if (p->length == 0)
						{
							return 0;//出现空子句，退出
						}
					}
					else if (r->data == t)
					{
						p->tag = n;
						c.length--;
						break;
					}
				}
			}
		}
		if (c.length == 0) return 1;
		t = find1(c);
	}
	return 2;
}
void back(sta &c, int n,int *a)
{
	cnf* p;
	for (p = c.L->next; p != NULL; p = p->next)
	{
		if (p->tag == n)
		{
			p->tag = 0;
			c.length++;
		}
		for (clause* r = p->cl.next; r != NULL; r = r->next)
		{
			if (r->tag == n)
			{
				p->length++;
				r->tag = 0;
			}
		}
	}
	for (int i = 0; i < c.variablelength; i++)
	{
		if (a[i] == n||a[i]==-n) a[i] = 0;
	}
}
int check(sta c, int* a)
{
	int x = 0;
	for (cnf* p = c.L->next; p != NULL; p = p->next)
	{
		for (clause *r = p->cl.next; r != NULL; r = r->next)
		{
			if (r->data > 0)
			{
				if (a[r->data] >= 0) x = 1;
			}
			else
			{
				if (a[-r->data] <= 0) x = 1;
			}
		}
		if (x == 0) return 0;
		x = 0;
	}
	return 1;
}
int leadout(int n, int m, int* a, char* s, double t)
{
	int i;
	for ( i = 0; s[i] != '\0'; i++);
	s[i - 1] = 's';
	s[i - 2] = 'e';
	s[i - 3] = 'r';
	FILE* fp = fopen(s, "w");
	fprintf(fp,"s %d\nv ",n);
	if (n != 0)
	{
		for (int i = 0; i < m; i++)
			if (a[i + 1] > 0) fprintf(fp, "%d ", i + 1);
			else fprintf(fp, "%d ", -i - 1);
		fprintf(fp,"\n");
	}
	fprintf(fp,"t %lf",t);
	fclose(fp);
	return 1;
}
void print(sta c)
{
	cnf *p;
	for (p = c.L->next; p != NULL; p = p->next)
	{
		printf("(");
		for (clause* r = p->cl.next; r != NULL; r = r->next)
		{
			printf("%d", r->data);
			if (r->next != NULL) printf("||");
		}
		printf(")");
		if (p->next != NULL) printf("&&");
	}
}