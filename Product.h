#ifndef PRODUCT_H
#define PRODUCT_H
#include "Suggest.h"
typedef struct {
	
	char name[20];
	int kod;
	int maxprice;
	int minprice;
	int zocim;
	int nsuggests;
	suggest* suggests;
}product;
#endif 
