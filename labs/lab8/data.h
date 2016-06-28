#ifndef DATA_H
#define DATA_H

#include "city.h"

typedef struct data{
	City *city;
} Data;

Data * initData(City * );
void * deleteData(Data *);

#endif
