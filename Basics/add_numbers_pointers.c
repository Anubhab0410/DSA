#include<stdio.h>
int main()
{
    int a,b,result;
    int *ptr1,*ptr2,*ptr3;
    ptr1=&a;
    ptr2=&b;
    ptr3=&result;
    printf("Enter the first number\n");
    scanf("%d",ptr1);
    printf("Enter the 2nd number:\n");
    scanf("%d",ptr2);
    *ptr3=*ptr1+*ptr2;
    printf("The sum of %d and %d is %d\n",ptr1,ptr2,ptr3);
}