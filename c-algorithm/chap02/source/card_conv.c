#include <stdio.h>
#include <stdlib.h>

int card_conv(unsigned x, int n, char d[])
{
    char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int     digits = 0;

    if (x == 0)
        d[digits++] = dchar[x % n];
    else
        while (x) {
            d[digits++] = dchar[x % n];
            x /= n;
        }

    return digits;
}

int main(void)
{
    int    i;
    unsigned no;
    int    cd;
    int    dno;
    char cno[512];
    int    retry;

    puts("10進数を基数変換します。");
    do {
        printf("変換する非負の整数 : ");
        scanf("%u", &no);

        do {
            printf("何進数に変換しますか? (2 - 36) :");
            scanf("%d", &cd);
        } while (cd < 2 || cd > 36);
        dno = card_conv(no, cd, cno);

        for (i = dno - 1; i >= 0; i--)
            printf("%c", cno[i]);
        printf("です\n");


        printf("もう一度実行しますか? (1 ･･･ はい / 0 ･･･いいえ)");
        scanf("%d", &retry);

    } while (retry == 1);


    return 0;
}