#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int YEAR = 365;
int LYEAR = 366;

typedef struct Date
{
	int year;
	int month;
	int day;
}Date;

typedef struct Book
{
	int isbn;
}Book;

typedef struct Student
{
	struct Student* next;
	int id;
	Book book;
	int booknum;
	Date start;
}student;

student* getnode(void)
{
	student* node;
	node = (student*)malloc(sizeof(student));

	return node;
}

void add(student* h, int st_id, int isbn, Date start)
{
	student* p;
	student* newnode = getnode();

	int books = 1;

	newnode->id = st_id;
	newnode->book.isbn = isbn;
	newnode->start.year = start.year;
	newnode->start.month = start.month;
	newnode->start.day = start.day;
	newnode->next = NULL;

	p = h;
	while (p->next != NULL)
	{
		p = p->next;
		if (p->id == st_id)
		{
			if (p->booknum < 3)
			{
				books = p->booknum++;
			}
			else
			{
				printf("Over booking.\n");
				return;
			}
		}
	}
	newnode->booknum = books;
	p->next = newnode;
}

int checkLYear(int year)
{
	int is_leap_year;

	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
	{
		is_leap_year = 1;
	}
	else
	{
		is_leap_year = 0;
	}
	return is_leap_year;
}

int TotalDays(Date date)
{
	int total = 0;
	int is_leap_year = 0;

	for (int y = 0; y < date.year; y++)
	{
		is_leap_year = checkLYear(y);
		if (is_leap_year)
			total += LYEAR;
		else
			total += YEAR;
	}

	for (int m = 0; m < date.month; m++)
	{
		is_leap_year = checkLYear(date.year);
		if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
			total += 31;
		else if (m == 2)
		{
			if (is_leap_year) total += 29;
			else if (is_leap_year == 0) total += 28;
		}
		else total += 30;
	}
	total += date.day;

	return total;
}

void print(student* h, Date start, int id)
{
	student* p;

	int overdue;
	int check = 0;

	p = h;
	while (p->next != NULL)
	{
		p = p->next;
		if (p->id != id) continue;
		overdue = TotalDays(start) - TotalDays(p->start);

		if (overdue > 15)
		{
			if (check == 0)
			{
				printf("%d ", p->id);
			}
			check++;
			printf("%d(%d) ", p->book.isbn, overdue * 100 - 1500);
		}
	}

	if (check == 0)
	{
		printf("%d X", p->id);
	}
	printf("\n");
}


int main()
{
	student* H = NULL;
	H = getnode();
	H->next = NULL;

	char com;
	int st_id;
	Book book;
	Date start;

	int flag = 1;

	while (flag)
	{
		scanf("%c", &com);

		switch (com)
		{
			case 'A':
				scanf("%06d %04d %04d-%02d-%02d", &st_id, &book.isbn, &start.year, &start.month, &start.day);
				getchar();
				add(H, st_id, book.isbn, start);
				break;
			case 'P':
				scanf("%04d-%2d-%02d %d", &start.year, &start.month, &start.day, &st_id);
				getchar();
				print(H, start, st_id);
				break;
			case 'Q':
				flag = 0;
				break;
		}
	}

	free(H);

	return 0;
}
