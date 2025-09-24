#include <stdio.h>
#include <stdlib.h>

int main()
{   int a[100][100],t[100][100],i,sutun,enlem,j;
    printf("Dizinin sutun ve enlem sayisini giriniz\n");
    printf("ENLEM = ");scanf("%d",&enlem);
    printf("BOYLAM = ");scanf("%d",&sutun);

    printf("Dizinin elemanlarini giriniz ");
        for(i=0;i<enlem;i++){
            for(j=0;j<sutun;j++){
                scanf("%d",&a[i][j]);
            }
        }

        for (int i = 0; i < enlem; i++) {
        for (int j = 0; j <sutun; j++) {
            t[j][i]=a[i][j];
        }
    }
    printf("\nTranspoze matris:\n");
    for (int i = 0; i < sutun; i++) {
        for (int j = 0; j < enlem; j++)
            printf("%d ", t[i][j]);
        printf("\n");
    }
    return 0;
}
