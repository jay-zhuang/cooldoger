#include <stdio.h>

#define ELEM_NUM(a) (sizeof(a) / sizeof(a[0]))

int main(int argc, char** argv)
{
    char array[] = {'E', 'M', 'C'};
    int d;
    for (d = -1; d <= (ELEM_NUM(array) - 2); d++){
        printf("%d", array[d+1]);
    }
    return 0;
}
