#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>

void hanoi(int n, char kaynak, char hedef, char ara)
{
    if (n == 1) {
        printf("Disk 1 %c cubugundan %c çubuguna tasindi.\n", kaynak, hedef);
        return;
    }
    hanoi(n - 1, kaynak, ara, hedef);

    printf("Disk %d %c cubugundan %c çubuguna tasindi.\n", n, kaynak, hedef);

    hanoi(n - 1, ara, hedef, kaynak);
}

int main()
{
    int diskSayisi;
    printf("Disk sayisini giriniz: ");
    scanf("%d", &diskSayisi);

    printf("\nHanoi Kuleleri Cozumu:\n");
    hanoi(diskSayisi, 'A', 'C', 'B');
    return 0;
}
