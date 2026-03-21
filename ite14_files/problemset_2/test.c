#include <stdio.h>

int main()
{
    char test[10];
    scanf("%[^\n]", test);
    printf("%s\n", test);
}