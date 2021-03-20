#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct nu Nu;
typedef struct ch Ch;
typedef struct ch
{
	char c;
	Ch* next;
}Ch;

typedef struct nu
{
	double num;
	Nu* next;
}Nu;

Nu* creat_nu(void);
void nu_push(Nu* N, double num);
void nu_pop(Nu* N, double* num);
double nu_compute(double a, char c, double b);
int isnum(char c);
Ch* creat_ch(void);
void ch_push(Ch* N, char ch);
void ch_pop(Ch* N, char* ch);
int ch_priority(char c);

void computer2(Ch* ch, Nu* nu, char c);
void computer1(Ch* ch, Nu* nu, char* str);
int computer_ch_front = 1;
int computer_ch_next = 0;
int flag = 1;

int main()
{
	Nu* nu;
	double sum = 0;
	Ch* ch;
	char st[50];
	ch = creat_ch();
	nu = creat_nu();
	printf("输入表达式：(例如3+4=)\n");
	gets(st);
	computer1(ch, nu, st);
	nu_pop(nu, &sum);
	printf("%10lf\n", sum);
	return 0;
}

void computer2(Ch* ch, Nu* nu, char c)
{
	char computer_ch;
	double computer_a = 0;
	double computer_b = 0;
	double temp;
	computer_ch_next = ch_priority(c);
	while (computer_ch_next <= computer_ch_front)
	{
		ch_pop(ch, &computer_ch);
		if (computer_ch == '(')
			break;
		ch_push(ch, computer_ch);
		nu_pop(nu, &computer_b);
		nu_pop(nu, &computer_a);
		ch_pop(ch, &computer_ch);
		temp = nu_compute(computer_a, computer_ch, computer_b);
		nu_push(nu, temp);
		if (ch->next == NULL)
			break;
		ch_pop(ch, &computer_ch);
		if (computer_ch == '(')
			break;
		computer_ch_front = ch_priority(computer_ch);
		ch_push(ch, computer_ch);
	}
	if (c != '(')
		computer_ch_front = computer_ch_next;
	else
		computer_ch_front = 1;
	if (c != ')')
		ch_push(ch, c);
}

void computer1(Ch* ch, Nu* nu, char* str)
{
	if (*str != '\0' && *str == '-')
	{
		flag = -flag;
		str++;
	}
	while (*str != '\0')
	{
		double temp = 0;
		if (isnum(*str) || *str == '.')
		{
			while (isnum(*str))
			{
				temp = temp * 10 + *str - '0';
				str++;
			}
			if (*str == '.')
			{
				int n = 1;
				str++;
				while (isnum(*str))
				{
					temp = temp + (*str - 48) * pow(0.1, n);
					n++;
					str++;
				}
			}
			nu_push(nu, flag * temp);
			if (flag < 0)
				flag = -flag;
		}
		else
		{
			computer2(ch, nu, *str);
			str++;
			if (*str == '-')
			{
				flag = -flag;
				str++;
			}
		}
	}
}

Ch* creat_ch()
{
	Ch* q;
	q = (Ch*)malloc(sizeof(Ch));
	q->next = NULL;
	return q;
}

void ch_push(Ch* head, char ch)
{
	Ch* q, * p = head->next;
	q = (Ch*)malloc(sizeof(Ch));
	q->c = ch;
	if (head->next == NULL)
	{
		head->next = q;
		q->next = NULL;
	}
	else
	{
		q->next = p;
		head->next = q;
	}
}

void ch_pop(Ch* head, char* ch)
{
	Ch* q = head->next;
	*ch = q->c;
	head->next = q->next;
}

int ch_priority(char c)
{
	switch (c)
	{
	case'=':
		return 0;
	case')':
		return 1;
	case'+':
	case'-':
		return 2;
	case '*':
	case'/':
	case'%':
		return 3;
	case'(':
		return 4;
	default:
		break;
	}
}

Nu* creat_nu()
{
	Nu* q;
	q = (Nu*)malloc(sizeof(Nu));
	q->next = NULL;
	return q;
}

void nu_push(Nu* N, double num)
{
	Nu* q;
	q = (Nu*)malloc(sizeof(Nu));
	q->num = num;
	q->next = N->next;
	N->next = q;
}

void nu_pop(Nu* N, double* num)
{
	Nu* q = N->next;
	*num = q->num;
	N->next = q->next;
}

double nu_compute(double a, char c, double b)
{
	switch (c)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '%':
		if (a == (int)a && b == (int)b)
			return (int)a % (int)b;
		else
			exit(0);
	case '/':
		if (b == 0)
			exit(0);
		else
			return a / b;
	default:
		break;
	}
}

int isnum(char c)
{
	if (c <= '9' && c >= '0')
		return 1;
	else
		return 0;
}
