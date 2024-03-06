#include "Manager.h"
#define _CRT_SECURE_NO_WARNINGS
#include <limits.h> 
#define bits CHAR_BIT
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
void suggestKelt(manager* m)
{
	int kod,prokod;
	printf("enterm t.z.\n");
	scanf("%d", &kod);
	int l = 0, r = m->ncus - 1, mid=0;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (m->customers[mid].kod == kod)
			break;
		if (m->customers[mid].kod < kod)
			l = mid + 1;
		else
			r = mid - 1;
	}
	if (m->customers[mid].kod != kod)
	{
		customer c;
		c.kod = kod;
		printf("enter name and visa\n");
		gets(c.name);
		scanf("%d", &(c.visa));
		if (m->customers[mid].kod < kod)
			mid++;
		m->customers = (customer*)realloc(m->customers, ++(m->ncus) * sizeof(customer));
		if (m->customers == NULL)
			exit(1);
		memmove(m->customers + mid + 1,m-> customers + mid, sizeof(m->customers + mid));
		m->customers[mid] = c;
	}
	printf("enter product kod\n");
	scanf("%d", &prokod);
	for (size_t i = 0; i < m->nprod; i++)
	{
		if (m->products[i].kod == prokod)
		{ 
			int price;
			printf("enter suggest price:\n");
				scanf("%d", &price);
				while (price<m->products[i].minprice||price>m->products[i].maxprice)
				{
					printf("enter suggest price:\n");
					scanf("%d", &price);
				}
				m->products[i].suggests = (suggest*)realloc(m->products[i].suggests, ++(m->products[i].nsuggests) * sizeof(suggest));
				if (m->products[i].suggests == NULL)
					exit(1);
				int l = 0, r =m-> products[i].nsuggests - 1, mid = 0;
				while (l <= r)
				{
					int mid = (l + r) / 2;
					if (m->products[i].suggests[mid].price == price)
						break;
					if (m->products[i].suggests[mid].price< price)
						l = mid + 1;
					else
						r = mid - 1;
				}
				if (m->products[i].suggests[mid].price < price)
					mid++;
				memmove(m->products[i].suggests + mid + 1,m->products[i].suggests + mid, sizeof(m->products[i].suggests + mid));
				m->products[i].suggests[mid].customerkod = kod;
				m->products[i].suggests[mid].price = price;
				printf("add!!\n");
		}
	}
}
void init(manager* m)
{
	m->ncus = 0;
	m->customers = 0;
	m->nprod = 0;
	m->products = 0;
}
