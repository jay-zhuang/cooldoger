#include <stdio.h>

#define f(a,b) a##b
#define g(a)   #a
#define h(a)   g(a)

int main(int argc, char** argv)
{
    printf("%s,", h(f(1,2)));
    printf("%s",  g(f(1,2)));
    return 0;
}
