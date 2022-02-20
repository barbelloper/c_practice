#ifndef EX_1
#define EX_1

#include <stdio.h>

typedef void* handle;

typedef enum EventType
{
	kStart,
	kPause,
	kEnd,
} EventType;

typedef int (*eventCallback)(EventType);

typedef struct IntData
{
	int data1;
	int data2;
	int data3;
	int data4;
} IntData;

handle constructor();
void destructor(handle h);
int setCallback(handle h, eventCallback *cb_func);
int SetIntData(handle h, IntData *int_data);
int action(handle h);

#endif