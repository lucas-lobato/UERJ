#include <stdio.h>

int main()
{
    printf("O tamanhdo de um (char) e' %ld", sizeof(char));
    printf("\nO tamanhdo de um (short) e' %li", sizeof(short int));
    printf("\nO tamanhdo de um (int) e' %li",sizeof(int));
    printf("\nO tamanhdo de um (long) e' %li", sizeof(long int));
    printf("\nO tamanhdo de um (long long) e' %li", sizeof(long long));
    printf("\nO tamanhdo de um (float) e' %ld", sizeof(float));
    printf("\nO tamanhdo de um (double) e' %ld", sizeof (double));
    printf("\nO tamanhdo de um (long double) e' %ld",sizeof(long double));
    return 0;    
}