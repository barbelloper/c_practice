#include <ex1.h>

static int callback(EventType type)
{
    int ret = 0;
    switch (type)
    {
    case kStart:
        printf("Start!!!\n");
        break;
    case kPause:
        printf("Pause!!!\n");
        break;
    case kEnd:
        printf("End!!!\n");
        break;
    default:
        ret = -1;
        printf("Unkown\n");
        break;
    }
    return ret;
}

int main(void)
{
    IntData int_data = {1,2,3,4};
    handle h = constructor();
    setCallback(h, &callback);
    SetIntData(h, &int_data);
    action(h);
    destructor(h);
    return 0;
}
