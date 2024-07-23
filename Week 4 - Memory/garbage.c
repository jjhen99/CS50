#include <stdio.h>
#include <stdlib.h>

void swap(int a, int b);
int main(void)
{
    int scores[1024];

    for(int i = 0; i < 1024; i++)
    {
        printf("%i\n", scores[i]);
    }
}

void swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
