#include <stdio.h>

int fun(){
    int x = 2;
    return x == (1 && x);
}

int main(int argc, char** argv)
{
    int y = 0;
    y = fun();
    printf("y = %d", y);
    return 0;
}
