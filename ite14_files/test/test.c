#include <stdio.h>
#include <stdlib.h>

void foo(int ** ptr1 )
{
    printf("ptr1 addr: %p\n", &ptr1);
    printf("ptr1 value: %p\n", ptr1);
    printf("*ptr1: %p\n", *ptr1);
    printf("&(*ptr1): %p\n\n", &(*ptr1));
    goo(ptr1);
    
}

void goo( int * ptr2 )
{
    (*ptr2)++;
}

int main()
{
    int x = 5;

    int * ptr = &x;

    printf("x value: %d\n", x);
    printf("&x : %p\n\n", &x);

    printf("ptr addr: %p\n", &ptr);
    printf("ptr value: %p\n", ptr);
    printf("*ptr: %d\n", *ptr);
    printf("&(*ptr): %p\n\n",&(*ptr));
    foo( &ptr );
    printf("ptr addr: %p\n", &ptr);
    printf("ptr value: %p\n", ptr);
    printf("*ptr: %d\n", *ptr);
    printf("&(*ptr): %p\n\n",&(*ptr));
    int *ptr2 = &(*ptr);

    // printf("ptr2 addr: %p\n", &ptr2);
    // printf("ptr2 value: %p\n", ptr2);
    // printf("*ptr2: %d\n", *ptr2);
    // printf("&(*ptr)2: %p\n\n",&(*ptr2));
    return 0;
}