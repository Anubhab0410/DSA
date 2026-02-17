#include <stdio.h>
int main(){
    int Arr[10],int key 
    for(int i=0;i<10;i++){
        printf("Enter a number");
        scanf("%d",&Arr[i]);
    }
printf("Enter the key");
scanf("%d",&key);
search(Arr,10,key);
if(result==1){
    printf("Element Found");
    else{
        printf("Element not found");
    }
}
int search(int A[],int size,int key)
{
    for(int i=0;i<size;i++)
    {
        if (A[i]==key)
        break;}
        if (i==size)
        return(0);
        else 
        return(1);
    }
}