#include <stdio.h>

void print_sp(int i, int n);
void print_num(int n);
int main()
{
    int rows = 6;
    for(int i = 1; i <= rows; i++)
    {
        print_sp(i, rows);
        print_num(i);
    }
    return 0;
}

void print_sp(int i, int n)
{
    for(int j = 1; j <= (n - i); j++){
        printf(" ");
    }
}

void print_num(int n){
    
    for(int i = 0; i < n; i++)
    {
        printf("%d ", n);
    }
    printf("\n");
}
