#include <stdio.h>
#include <stdlib.h>

int search(const int a[], int n, int key)
{
  int i = 0;
  int l;
/* 1行目 */
  printf("  |  ");
  for(i = 0; i < n; i++) {
    printf("  %d ", i);
  }
  printf("\n");
  for (l = 0; l <= n; l++) {
    printf("----");
  }
  printf("\n");
/* 1行目 終了 */


  for (i = 0; i < n; i++) {

    printf("  |");
    for (l = 0; l <= i; l++) {
      printf("    ");
      if (l == i) {
        printf("*");
      }
    }
    printf("\n");
    printf("%d |  ", i);
    for(l = 0; l < n; l++) {
      printf("  %d ", a[l]);
    }
    printf("\n");

    if (a[i] == key) 
      return i;
  }

  return -1;
}


int main(void)
{
  int i, nx, ky, idx;
  int *x;

  puts("線形探索");
  printf("要素数 : ");
  scanf("%d", &nx);
  x = calloc(nx, sizeof(int));
  
  for (i = 0; i < nx; i++) {
    printf("x[%d] : ", i);
    scanf("%d", &x[i]);
  }
  printf("探す値");
  scanf("%d", &ky);
  
  idx = search(x, nx, ky);

  if (idx == -1)
    puts("探索に失敗しました。");
  else
    printf("%dはx[%d]にあります。\n", ky, idx);
  free(x);

  return 0;
}
