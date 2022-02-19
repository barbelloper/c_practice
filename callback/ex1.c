#include <stdlib.h>
#include "ex1.h"

typedef struct Data
{
	eventCallback event;
	IntData data;
} PrivateData;

static int defaultCallback(EventType type)
{
    printf("plz call setCallback() API to set your callback function\n");
}

handle constructor()
{
    PrivateData *data = (PrivateData *)malloc(sizeof(PrivateData));
    return (handle)data;
}

void destructor(handle h)
{
    free(h);
}

int setCallback(handle h, eventCallback *cb_func)
{
    PrivateData *data = (PrivateData *)h;
    int ret = 0;
    if (data == NULL)
    {
        ret = -1;
    }
    else
    {
        data->event = cb_func;
    }
    return ret;
}

int SetIntData(handle h, IntData *int_data)
{
    PrivateData *data = (PrivateData *)h;
    int ret = 0;
    if (data != NULL)
    {
        data->data = *int_data;
    }
    else
    {
        ret = -1;
    }
    return ret;
}

int action(handle h)
{
    PrivateData *data = (PrivateData *)h;
    printf("data1 : %d\n", data->data.data1);
    printf("data2 : %d\n", data->data.data2);
    printf("data3 : %d\n", data->data.data3);
    printf("data4 : %d\n", data->data.data4);
    printf("finish\n");
    if (data->event == NULL)
    {
        data->event = defaultCallback;
    }
    data->event(kEnd);
    return 0;
}