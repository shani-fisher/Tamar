#define _CRT_SECURE_NO_WARNINGS
#include <limits.h> 
#define bits CHAR_BIT
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include "Manager.h"
typedef enum { sq, rec, tri }Shape2;
typedef enum {false,true}boolien;
typedef struct node {
	void* data;
	struct node* next;
}Node, * Pnode;
typedef struct {
	int x; char r;
}t;
#define err(element) if(element==NULL){\
printf("memory allocation");\
exit(1);}
#define p(format,el)printf(#format,el);
void push(Pnode* head, void* new_data, size_t data_size)
{
	Pnode new_node = (Pnode)malloc(sizeof(Node));
	err(new_node);
	new_node->data = malloc(data_size);
	err(new_node->data);
	memcpy((char*)new_node->data, (char*)new_data, data_size);
	new_node->next = *head;

	*head = new_node;
}
void printInt(void* data)
{
	printf("%d\n", *((int*)data));
}
void printDouble(void* data)
{
	printf("%f\n", *((double*)data));
}
void printlist(Pnode head, void(*printdata)(void*))
{
	for (Pnode i = head; i != NULL; i = i->next)
	{
		printdata(i->data);
	}
}
void freelist(Pnode head)
{
	Pnode ptr;
	for (Pnode i = head; i != NULL; i = i->next)
	{
		free(i->data);
		ptr = i->next;
		free(i);
		i = ptr;
	}


}
typedef struct {
	char name[15];
	int age;
	int mark;
}student;
int ByInt(void* arr, int i) {
	return ((int*)arr)[i];
}
int ByMark(void* arr, int i) {
	return (((student*)arr)[i]).mark;
}
int ByString(void* arr, int i) {
	if (isdigit(((char*)arr)[i]))
		return ((char*)arr)[i] - '0'; return 0;
}
int ByAge(void* arr, int i) {
	return (((student*)arr)[i]).age;
}
double avg(void* arr, int n, int(*func)(void*, int)) {
	int sum = 0;
	for (size_t i = 0; i < n; i++)
	{
		sum += func(arr, i);
	}
	return (double)sum / n;
}
typedef struct {
	char c;
	double rib;
}Square, * Psquare;
typedef struct {
	char c;
	double len;
	double width;
}Rectangle, * Prectangle;
typedef struct {
	char c;
	double rib;
	double high;
}Triangular, * Ptriangular;
typedef union {
	Triangular tringular;
	Rectangle rectangle;
	Square square;
}Shape, * Pshape;
typedef struct {
	Shape sh;
	Shape2 kod;
}Shapes, * Pshapes;
//void* memcpy(void* dest,  void* src, int n) {
//	unsigned char* d = (unsigned char*)dest;
//	const unsigned char* s = (const unsigned char*)src;
//
//	for (int i = 0; i < n; i++) {
//		*((char*)(dest)+i) = *((char*)(src)+i);
//	}
//
//	return dest;
//}
void printSq(void* shape)
{
	printf("\n");
	Pshape pshape = (Pshape)shape;
	for (size_t i = 0; i < pshape->square.rib; i++)
	{
		printf("%c", pshape->square.c);
	}
	printf("\n"); for (size_t i = 0; i < pshape->square.rib - 2; i++)
	{
		for (size_t i = 0; i < pshape->square.rib; i++)
		{
			if (i == 0 || i == pshape->square.rib - 1)
				printf("%c", pshape->square.c);
			else printf(" ");
		}
		printf("\n");
	}
	for (size_t i = 0; i < pshape->square.rib; i++)
	{
		printf("%c", pshape->square.c);
	}
}
void printrRec(void* shape)
{
	Pshape pshape = (Pshape)shape;
	printf("\n");
	for (size_t i = 0; i < pshape->rectangle.width; i++)
	{
		printf("%c", pshape->rectangle.c);
	}
	printf("\n");
	for (size_t i = 0; i < pshape->rectangle.len - 2; i++)
	{
		for (size_t i = 0; i < pshape->rectangle.width; i++)
		{
			if (i == 0 || i == pshape->rectangle.width - 1)
				printf("%c", pshape->rectangle.c);
			else printf(" ");
		}
		printf("\n");
	}

	for (size_t i = 0; i < ((Pshape)shape)->rectangle.width; i++)
	{
		printf("%c", pshape->rectangle.c);
	}
}
void printrTri(void* shape)
{
	printf("\n");
	for (size_t i = 0; i < ((Pshape)shape)->tringular.rib; i++)
	{
		for (size_t j = 0; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}
void printFuncs(Pshapes shapes, void (*printFunc[])(void*)) {
	for (size_t i = 0; i < 3; i++)
	{
		(*(printFunc[shapes[i].kod]))(shapes + i);
	}
}
unsigned int bit_1(unsigned int num)
{
	unsigned int temp = 0x5555;
	return num | temp;
}
unsigned char bit_2(unsigned char c)
{
	unsigned char temp = 0xAA;
	return c ^ temp;
}
unsigned int bit_3(unsigned int num)
{
	unsigned int temp = 0;
	temp = (temp | (num >> 8)) << 16;
	return temp >> 16;
}
unsigned int bit_4(unsigned int num)
{
	unsigned int temp = 0x0FF0;
	return num & temp;
}
int bit_5(unsigned char c)
{
	return c >> (bits * sizeof(unsigned char)) & 1;
}
int bit_6(unsigned int num)
{
	return (num & 0xFFFF0000) >> 16 == num & 0x0000FFFF;
}
void bit_2_1(unsigned char arr[], int n)
{
	unsigned char last = arr[n - 1] << 4;
	for (size_t i = 0; i < n * 2 - 1; i++)
	{
		if (!i % 2)
		{
			arr[n - 1 - i / 2];
		}
	}
}
struct d {
	int x; char e;
	char y;
	double t;
	int u;
	int r;
};
#include <stdlib.h>
#include <stdio.h>

void twoArrays(int* arr, int n, int** Ppos, int** neg, int* n1, int* n2) {
	int pos = 0, i, j;
	for (i = 0; i < n; i++) {
		if (arr[i] >= 0)
			pos++;
	}
	*Ppos = (int*)malloc(pos * sizeof(int));
	if (*Ppos == NULL) {
		printf("error!");
		exit(1);
	}
	*neg = (int*)malloc((n - pos) * sizeof(int));
	if (*neg == NULL) {
		printf("error!");
		exit(1);
	}
	for (i = 0, j = 0; (i + j) < n;) { // Changed <= to <
		if (arr[i + j] >= 0) {
			(*Ppos)[i] = arr[i + j]; // Added [i]
			i++;
		}
		else {
			(*neg)[j] = arr[i + j];
			j++;
		}
	}
	*n1 = pos;
	*n2 = n - pos;
}
int** f()
{
	int mat[2][2] = { {0} };
	return mat;

}

void printArray(void* arr, size_t length, size_t elemSize) {

	for (size_t i = 0; i < length; i++)

	{
		void* element = (char*)arr + i * elemSize;

		// Print the element based on its type

		if (elemSize == sizeof(int)) {

			printf("%d ", *(int*)element);

		}
		else if (elemSize == sizeof(double)) {

			printf("%lf ", *(double*)element);

		}
		else if (elemSize == sizeof(char)) {

			printf("%c ", *(char*)element);

		}

		// Add more conditions for other types if needed

		// You can also modify the formatting based on your requirements

	}

	printf("\n");
}
boolien equal(const void* a, const void* b, int size)
{
	for (size_t i = 0; i < size; i++)
	{
     if(*((char*)a)!=*((char*)b))
	return false;
	}
	return true;
}
int search(void* arr, int arrsize, int elementsize, void* value, boolien(*equl)(const void* a, const void* b, int size))
{
	for (size_t i = 0; i < arrsize*elementsize; i+=elementsize)
	{
		if(equal((char*)arr+i,value,elementsize))
			return 1;
	}
	return 0;
}
void ff(char*arr[],int n)
{
	int monim[1023]={0};
	for (size_t i = 0; i < n; i++)
	{
		int mask = 0;
		for (size_t j = 0; j < strlen(arr[i]); j++)
		{
			mask |=  1<<(arr[i][j]-'0');
		}
		monim[mask] ++;
	}
	int count = 0;
	for (int i = 0; i < 1024; i++)
	{
		for (size_t j = i+1; j < 1024; j++)
		{
			if (i & j)
				count += monim[i] * monim[j];
		}
	}
	

	p(% d, count);
}
void fff(unsigned int num)
{
	unsigned int first1 = num & -num;
	unsigned int m=num+ first1;
	int y = m;
	m ^= num;
	m /= first1; m >>= 1;
	int ln = y | m;
	printf("%x", ln);
}
int main() {
	

	manager m;
	init(&m);
	suggestKelt(&m);
}


/*Shapes shapes[3];
int size = 3;
for (size_t i = 0; i < size; i++)
{
	printf("enter kod\n");
	scanf(" %d" ,&(shapes[i].kod));

	switch (shapes[i].kod)
	{
	case sq:	printf("enter char and rib to print\n");
		float rib;
		scanf(" %c %f", &(shapes[i].sh.square.c), &rib);
		shapes[i].sh.square.rib = rib;
		printf("%f", shapes[i].sh.square.rib);
				break;
	case rec:printf("enter char to print enter width and length\n");
		float w, l;
		scanf(" %c %f %f", &shapes[i].sh.rectangle.c,&w,&l);
		shapes[i].sh.rectangle.width = w; shapes[i].sh.rectangle.len = l;
		break;
	case tri:printf("enter char to print enter rib and high\n");
		float ribt;float h;
		scanf(" %c %f %f", &(shapes[i].sh.tringular.c),&ribt,&h);
		shapes[i].sh.tringular.rib = ribt; shapes[i].sh.tringular.high = h;
		break;
	}
}
void (*printFun[])(void*) = { &printSq,&printrRec,&printrTri };
printFuncs(shapes, printFun);*/

/*for (size_t i = 0; i < 3; i++)
{
	switch (shapes[i].kod)
	{
	case sq:
		printSq(&shapes[i].sh.square);
		break;
	case rec:
		printrRec(&shapes[i].sh.rectangle);
		break;
	case tri:
		printrTri(&shapes[i].sh.tringular);
	}
}*/

/*int x = 5, y = 9;
memcpy(&y, &x,sizeof(int));
printf("%d", y);
int arr[] = { 1,2,3,4,5 };
char str[] = "sd357";
student stud[] = { {"shlomo",12,38},{"yakov",15,97},{"shimon",11,88} };
printf("%f\n", avg(arr, 5, ByInt));
printf("%f\n", avg(str, 5, ByString));
printf("%f\n", avg(stud, 3, ByAge));
printf("%f\n", avg(stud, 3, ByMark));*/


