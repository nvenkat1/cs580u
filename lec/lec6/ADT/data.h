#ifndef DATA_H
#define DATA_H

typedef struct data{
	int num;
	char * str;
	} Data;

//void setName(Data *d, char * name);
Data * initData(char *, int);
void * deleteData(Data *);

#endif
