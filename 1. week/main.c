#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[100]={90,70,50,30,10};
    int n=5;
    int item, i, j;

    printf("Eklenecek elemani girin: ");
    scanf("%d",&item);

    i=0;
    while(i<n && arr[i]>item){
        i++;
    }
    for(j=n;j>i;j--){
        arr[j]=arr[j-1];
    }
    arr[i]=item;
    n++;

    printf("Yeni dizi\n");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
