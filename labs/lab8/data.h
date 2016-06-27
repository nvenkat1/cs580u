#ifndef DATA_H
#define DATA_H

typedef struct data{
	int num;
} Data;

Data * initData(int);
void * deleteData(Data *);

#endif
