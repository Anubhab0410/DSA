#include<stdio.h>
int sum(int n){
    if(n<=1)
{
    return (n);
}
else{
    return n+sum(n-1);
}}
int main()
{
    int n=5;
    printf("the sum of the first %d natural numbers is %d\n",n,sum(n));
    return 0;
}