#include <stdio.h>
#include <stdlib.h>

int aveof(const int a[], int n)
{
    int i;
    int sum = 0;
    for (i = 0; i < n; i++)
        sum += a[i];
    return sum/n;
}

int minof(const int a[], int n)
{
    int i;
    int min = a[0];

    for (i = 0; i < n; i++)
        if (a[i] < min) min = a[i];
    return min;
}

int sumof(const int a[], int n)
{
    int i;
    int sum = 0;

    for (i = 0; i < n; i++)
        sum += a[i];

    return sum;
}

int main(void)
{
    int i;
    int *height;
    int number;

    printf("人数: ");
    scanf("%d", &number);

    height = calloc(number, sizeof(int));

    printf("%d人の身長を入力してください。\n", number);
    for (i = 0; i < number; i++) {
        printf("height[%d] : ", i);
        scanf("%d", &height[i]);
    }

    printf("平均は%dです。\n", aveof(height, number));
    free(height);
    return 0;
}
