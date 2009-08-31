#include <stdio.h>

int main(int argc, char** argv)
{
    int x = 1, y = 0;
    y = sizeof(x++);
    printf("x = %d, y = %d", x, y);
    return 0;
}
