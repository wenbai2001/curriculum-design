#include "soduko.h"
sta* producestafrom0(sta &c,int m)
{
	c.L = (cnf*)malloc(sizeof(cnf));
	cnf* p=c.L;
	p->next = NULL;
	clause* r;
	c.length = 0;
	//对约束一进行处理
	for (int i = 0; i < m; i++)
	{	
		for (int j = 0; j < m - 2; j++)
		{
			p->next = (cnf*)malloc(sizeof(cnf));
			p = p->next;
			p->tag = 0;
			p->length = 3;
			r = &p->cl;
			for (int k = 0; k < 3; k++)
			{
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = i * m + j + k + 1;
				r->next = NULL;
			}
			c.length++;
			p->next = (cnf*)malloc(sizeof(cnf));
			p = p->next;
			p->tag = 0;
			p->length = 3;
			r = &p->cl;
			for (int k = 0; k < 3; k++)
			{
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = -(i * m + j + k + 1);
				r->next = NULL;
			}
			c.length++;
			p->next = NULL;
			p->next = (cnf*)malloc(sizeof(cnf));
			p = p->next;
			p->tag = 0;
			p->length = 3;
			r = &p->cl;
			for (int k = 0; k < 3; k++)
			{
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = i  + j * m + k * m + 1;
				r->next = NULL;
			}
			c.length++;
			p->next = (cnf*)malloc(sizeof(cnf));
			p = p->next;
			p->tag = 0;
			p->length = 3;
			r = &p->cl;
			for (int k = 0; k < 3; k++)
			{
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = -(i + j * m + k * m + 1);
				r->next = NULL;
			}
			c.length++;
			p->next = NULL;
		}
	}
	//对约束二进行处理
	int* a=(int*)malloc(sizeof(int)*(m/2+1));
	combination(c, p, m, 0, a);
	free(a);
	for (; p->next != NULL; p = p->next);
	c.variablelength = m * m;
	int s = 0;
	//对约束三进行处理
	for (int x = 0; x < m; x++)
	{
		for (int y = x + 1; y < m; y++)
		{
			for (int i = 1; i < m + 1; i++)
			{
				//行处理
				//添加clause1且clause2语句
				p->next = (cnf*)malloc(sizeof(cnf));
				p = p->next;
				p->tag = 0;
				p->length = 2;
				r = &p->cl;
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = x * m + i;
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = -(m * m + (y - x + s - 1) * (3 * m + 1) + i);
				r->next = NULL;
				c.length++;
				p->next = NULL;

				p->next = (cnf*)malloc(sizeof(cnf));
				p = p->next;
				p->tag = 0;
				p->length = 2;
				r = &p->cl;
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = y * m + i;
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = -(m * m + (y - x + s - 1) * (3 * m + 1) + i);
				r->next = NULL;
				c.length++;
				p->next = NULL;
				p->next = (cnf*)malloc(sizeof(cnf));

				p = p->next;
				p->tag = 0;
				p->length = 3;
				r = &p->cl;
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = -(y * m + i);
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = -(x * m + i);
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = m * m + (y - x + s - 1) * (3 * m + 1) + i;
				r->next = NULL;
				c.length++;
				p->next = NULL;

				//添加非clause1且非clause2语句
				p->next = (cnf*)malloc(sizeof(cnf));
				p = p->next;
				p->tag = 0;
				p->length = 2;
				r = &p->cl;
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = -(x * m + i);
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = -(m * m + (y - x + s - 1) * (3 * m + 1) + i + m);
				r->next = NULL;
				c.length++;
				p->next = NULL;

				p->next = (cnf*)malloc(sizeof(cnf));
				p = p->next;
				p->tag = 0;
				p->length = 2;
				r = &p->cl;
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = -(y * m + i);
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = -(m * m + (y - x + s - 1) * (3 * m + 1) + i + m);
				r->next = NULL;
				c.length++;
				p->next = NULL;

				p->next = (cnf*)malloc(sizeof(cnf));
				p = p->next;
				p->tag = 0;
				p->length = 3;
				r = &p->cl;
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = y * m + i;
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = x * m + i;
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = m * m + (y - x + s - 1) * (3 * m + 1) + i + m;
				r->next = NULL;
				c.length++;
				p->next = NULL;

				//处理类似于1571= 15711∨15710的语句
				p->next = (cnf*)malloc(sizeof(cnf));
				p = p->next;
				p->tag = 0;
				p->length = 2;
				r = &p->cl;
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = -(m * m + (y - x + s - 1) * (3 * m + 1) + i + m);
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = m * m + (y - x + s - 1) * (3 * m + 1) + i + m * 2;
				r->next = NULL;
				c.length++;
				p->next = NULL;

				p->next = (cnf*)malloc(sizeof(cnf));
				p = p->next;
				p->tag = 0;
				p->length = 2;
				r = &p->cl;
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = -(m * m + (y - x + s - 1) * (3 * m + 1) + i );
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = m * m + (y - x + s - 1) * (3 * m + 1) + i + m * 2;
				r->next = NULL;
				c.length++;
				p->next = NULL;

				p->next = (cnf*)malloc(sizeof(cnf));
				p = p->next;
				p->tag = 0;
				p->length = 3;
				r = &p->cl;
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = m * m + (y - x + s - 1) * (3 * m + 1) + i ;
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = m * m + (y - x + s - 1) * (3 * m + 1) + i + m;
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = -(m * m + (y - x + s - 1) * (3 * m + 1) + i + m * 2);
				r->next = NULL;
				c.length++;
				p->next = NULL;

				//处理157= ¬[1571∧1572∧…∧1578]
				p->next = (cnf*)malloc(sizeof(cnf));
				p = p->next;
				p->tag = 0;
				p->length = 2;
				r = &p->cl;
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = m * m + (y - x + s - 1) * (3 * m + 1) + m * 3 + 1;
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = m * m + (y - x + s - 1) * (3 * m + 1) + i + m * 2;
				r->next = NULL;
				c.length++;
				p->next = NULL;

				//列处理
				//添加clause1且clause2语句
				p->next = (cnf*)malloc(sizeof(cnf));
				p = p->next;
				p->tag = 0;
				p->length = 2;
				r = &p->cl;
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = (i - 1) * m + x + 1;
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = -(m * m + (3 * m + 1) * m * (m - 1) / 2 + (y - x + s - 1) * (3 * m + 1) + i);
				r->next = NULL;
				c.length++;
				p->next = NULL;

				p->next = (cnf*)malloc(sizeof(cnf));
				p = p->next;
				p->tag = 0;
				p->length = 2;
				r = &p->cl;
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = (i - 1) * m + y + 1;
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = -(m * m + (y - x + s - 1) * (3 * m + 1) + i + (3 * m + 1) * m * (m - 1) / 2);
				r->next = NULL;
				c.length++;
				p->next = NULL;
				p->next = (cnf*)malloc(sizeof(cnf));

				p = p->next;
				p->tag = 0;
				p->length = 3;
				r = &p->cl;
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = -((i - 1) * m + y + 1);
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = -((i - 1) * m + x + 1);
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = m * m + (y - x + s - 1) * (3 * m + 1) + i + (3 * m + 1) * m * (m - 1) / 2;
				r->next = NULL;
				c.length++;
				p->next = NULL;

				//添加非clause1且非clause2语句
				p->next = (cnf*)malloc(sizeof(cnf));
				p = p->next;
				p->tag = 0;
				p->length = 2;
				r = &p->cl;
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = -((i - 1) * m + x + 1);
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = -(m * m + (y - x + s - 1) * (3 * m + 1) + i + m + (3 * m + 1) * m * (m - 1) / 2);
				r->next = NULL;
				c.length++;
				p->next = NULL;

				p->next = (cnf*)malloc(sizeof(cnf));
				p = p->next;
				p->tag = 0;
				p->length = 2;
				r = &p->cl;
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = -((i-1) * m + y + 1);
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = -(m * m + (y - x + s - 1) * (3 * m + 1) + i + m + (3 * m + 1) * m * (m - 1) / 2);
				r->next = NULL;
				c.length++;
				p->next = NULL;

				p->next = (cnf*)malloc(sizeof(cnf));
				p = p->next;
				p->tag = 0;
				p->length = 3;
				r = &p->cl;
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = (i - 1) * m + x + 1;
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = (i - 1) * m + y + 1;
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = m * m + (y - x + s - 1) * (3 * m + 1) + i + m + (3 * m + 1) * m * (m - 1) / 2;
				r->next = NULL;
				c.length++;
				p->next = NULL;

				//处理类似于1571= 15711∨15710的语句
				p->next = (cnf*)malloc(sizeof(cnf));
				p = p->next;
				p->tag = 0;
				p->length = 2;
				r = &p->cl;
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = -(m * m + (y - x + s - 1) * (3 * m + 1) + i + m + (3 * m + 1) * m * (m - 1) / 2);
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = m * m + (y - x + s - 1) * (3 * m + 1) + i + m * 2 + (3 * m + 1) * m * (m - 1) / 2;
				r->next = NULL;
				c.length++;
				p->next = NULL;

				p->next = (cnf*)malloc(sizeof(cnf));
				p = p->next;
				p->tag = 0;
				p->length = 2;
				r = &p->cl;
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = -(m * m + (y - x + s - 1) * (3 * m + 1) + i + (3 * m + 1) * m * (m - 1) / 2);
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = m * m + (y - x + s - 1) * (3 * m + 1) + i + m * 2 + (3 * m + 1) * m * (m - 1) / 2;
				r->next = NULL;
				c.length++;
				p->next = NULL;

				p->next = (cnf*)malloc(sizeof(cnf));
				p = p->next;
				p->tag = 0;
				p->length = 3;
				r = &p->cl;
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = m * m + (y - x + s - 1) * (3 * m + 1) + i + (3 * m + 1) * m * (m - 1) / 2;
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = m * m + (y - x + s - 1) * (3 * m + 1) + i + m + (3 * m + 1) * m * (m - 1) / 2;
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = -(m * m + (y - x + s - 1) * (3 * m + 1) + i + m * 2 + (3 * m + 1) * m * (m - 1) / 2);
				r->next = NULL;
				c.length++;
				p->next = NULL;

				//处理157= ¬[1571∧1572∧…∧1578]
				p->next = (cnf*)malloc(sizeof(cnf));
				p = p->next;
				p->tag = 0;
				p->length = 2;
				r = &p->cl;
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = m * m + (y - x + s - 1) * (3 * m + 1) + m * 3 + 1 + (3 * m + 1) * m * (m - 1) / 2;
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = m * m + (y - x + s - 1) * (3 * m + 1) + i + m * 2 + (3 * m + 1) * m * (m - 1) / 2;
				r->next = NULL;
				c.length++;
				p->next = NULL;
			}
			//行约束3补充
			p->next = (cnf*)malloc(sizeof(cnf));
			p = p->next;
			p->tag = 0;
			p->length = m + 1;
			r = &p->cl;
			r->next = (clause*)malloc(sizeof(clause));
			r = r->next;
			r->tag = 0;
			r->data = -(m * m + (y - x + s - 1) * (3 * m + 1) + m * 3 + 1);
			for (int i = 1; i < m + 1; i++)
			{
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = -(m * m + (y - x + s - 1) * (3 * m + 1) + i + m * 2);
				r->next = NULL;
			}
			c.length++;
			p->next = NULL;

			p->next = (cnf*)malloc(sizeof(cnf));
			p = p->next;
			p->tag = 0;
			p->length =  1;
			r = &p->cl;
			r->next = (clause*)malloc(sizeof(clause));
			r = r->next;
			r->tag = 0;
			r->data = m * m + (y - x + s - 1) * (3 * m + 1) + m * 3 + 1;
			r->next = NULL;
			c.length++;
			p->next = NULL;

			//列约束3补充
			p->next = (cnf*)malloc(sizeof(cnf));
			p = p->next;
			p->tag = 0;
			p->length = m + 1;
			r = &p->cl;
			r->next = (clause*)malloc(sizeof(clause));
			r = r->next;
			r->tag = 0;
			r->data = -(m * m + (y - x + s - 1) * (3 * m + 1) + m * 3 + 1 + (3 * m + 1) * m * (m - 1) / 2);
			for (int i = 1; i < m + 1; i++)
			{
				r->next = (clause*)malloc(sizeof(clause));
				r = r->next;
				r->tag = 0;
				r->data = -(m * m + (y - x + s - 1) * (3 * m + 1) + i + m * 2 + (3 * m + 1) * m * (m - 1) / 2);
				r->next = NULL;
			}
			c.length++;
			p->next = NULL;

			p->next = (cnf*)malloc(sizeof(cnf));
			p = p->next;
			p->tag = 0;
			p->length = 1;
			r = &p->cl;
			r->next = (clause*)malloc(sizeof(clause));
			r = r->next;
			r->tag = 0;
			r->data = m * m + (y - x + s - 1) * (3 * m + 1) + m * 3 + 1 + (3 * m + 1) * m * (m - 1) / 2;
			r->next = NULL;
			c.length++;
			p->next = NULL;
		}
		s += m - x - 1;
	}
	c.variablelength = m * m + (3 * m + 1) * m * (m - 1);
	return &c;
}
void  combination(sta &c, cnf* p, int m, int n, int* a)
{
	if (n == 0) a[n] = 0;
	else a[n] = a[n - 1] + 1;
	if (n < m / 2)
	{
		for (; a[n] < m / 2 + n; a[n]++)
		{
			for (; p->next != NULL; p = p->next);
			combination(c, p, m, n + 1, a);
		}
	}
	else
	{
		clause *r;
		for (; a[n] < m / 2 + n; a[n]++)
		{
			for (int i = 0; i < m; i++)
			{
				p->next = (cnf*)malloc(sizeof(cnf));
				p = p->next;
				p->tag = 0;
				p->length = m / 2 + 1;
				r = &p->cl;
				for (int k = 0; k < m / 2 + 1; k++)
				{
					r->next = (clause*)malloc(sizeof(clause));
					r = r->next;
					r->tag = 0;
					r->data = i * m + a[k] + 1;
					r->next = NULL;
				}
				c.length++;
				p->next = NULL;
				p->next = (cnf*)malloc(sizeof(cnf));
				p = p->next;
				p->tag = 0;
				p->length = m / 2 + 1;
				r = &p->cl;
				for (int k = 0; k < m / 2 + 1; k++)
				{
					r->next = (clause*)malloc(sizeof(clause));
					r = r->next;
					r->tag = 0;
					r->data = a[k] * m + i + 1;
					r->next = NULL;
				}
				c.length++;
				p->next = NULL;
				p->next = (cnf*)malloc(sizeof(cnf));
				p = p->next;
				p->tag = 0;
				p->length = m / 2 + 1;
				r = &p->cl;
				for (int k = 0; k < m / 2 + 1; k++)
				{
					r->next = (clause*)malloc(sizeof(clause));
					r = r->next;
					r->tag = 0;
					r->data = -(i * m + a[k] + 1);
					r->next = NULL;
				}
				c.length++;
				p->next = NULL;
				p->next = (cnf*)malloc(sizeof(cnf));
				p = p->next;
				p->tag = 0;
				p->length = m / 2 + 1;
				r = &p->cl;
				for (int k = 0; k < m / 2 + 1; k++)
				{
					r->next = (clause*)malloc(sizeof(clause));
					r = r->next;
					r->tag = 0;
					r->data = -(a[k] * m + i + 1);
					r->next = NULL;
				}
				c.length++;
				p->next = NULL;
			}
		}
	}
}
int solvesoduko(int* a, int **b, int m)
{
	sta c;
	producestafrom0(c, m);
	cnf *p;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
		{
			if (a[i * m + j + 1] != 0) //a中1，和-1表示对应的数，0表示无数据，2，-2表示确定不能更改的数据
			{
				c.length++;
				p = (cnf*)malloc(sizeof(cnf));
				p->next = c.L->next;
				c.L->next = p;
				p->tag = 0;
				p->cl.next = (clause*)malloc(sizeof(clause));
				p->length = 1;
				p->cl.next->next = NULL;
				p->cl.next->tag = 0;
				if (a[i * m + j + 1] > 0) p->cl.next->data = i * m + j + 1;
				else if (a[i * m + j + 1] < 0) p->cl.next->data = -(i * m + j + 1);
			}
		}
	*b = (int*)malloc(sizeof(int) * c.variablelength);
	int n = DPLL(c,* b);
	cnf* q;
	clause *s;
	for (cnf* p = c.L; p->next != NULL; )
	{
		for (clause* r = &p->next->cl; r->next != NULL; )
		{
			s = r->next; 
			r->next = s->next;
			free(s);
		}
		q = p->next;
		p->next = q->next;
		free(q);
	}
	free(c.L);
	return n;
}
int* producenew(int m)
{
	sta c;
	producestafrom0(c,m);
	int* a = (int*)malloc(sizeof(int) * (c.variablelength + 1));
	DPLL(c, a);
	for (int i = 1; i < m * m + 1; i++)
	{
		if (a[i] >= 0) a[i] = 1;
		else a[i] = -1;
	}
	srand(time(NULL));
	deletedata(a, m, m*m);
	return a;
}
void deletedata(int* a, int m, int n)
{
	if (n == 0) return;
	int* b=NULL;
	int x = rand() % (n) + 1;
	int j=0;
	for (int i = 1; i < m*m; i++)
	{
		if (a[i] == 1||a[i] == -1)
		{
			j++;
			if (j == x) break;
		}
	}
	a[j] = -a[j];
	if (solvesoduko(a, &b, m) == 1)
	{
		a[j] = -a[j] * 2;
	}
	else
	{
		a[j] = 0;
	}
	deletedata(a, m, n - 1);
}