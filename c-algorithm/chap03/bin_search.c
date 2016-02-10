#include <stdio.h>
#include <stdlib.h>

int bin_search(const int a[], int n, int key)
{
  int pl = 0;
  int pr = n - 1;
  int pc;

  do {
    pc = (pl + pr)/2;
    if (key == a[pc])
      return pc;
    else if (key > a[pc])
      pl = pc + 1;
    else
      pr = pc - 1;
  } while(pl <= pr);

  return -1;
}

int main(void)
{
  int i, nx, ky, idx;
  int *x;

  puts("2分探索");
  printf("要素数 : ");
  scanf("%d", &nx);
  x = calloc(nx, sizeof(int));

  printf("昇順に入力してください。");
  printf("x[0] : ");
  scanf("%d", &x[0]);
  for (i=1; i<nx; i++) {
    do {
      printf("x[%d] : ", i);
      scanf("%d", &x[i]);
    } while (x[i] < x[i-1]);
  }

  printf("探す値");
  scanf("%d", &ky);

  idx = bin_search(x, nx, ky);
  if (idx == -1)
    printf("探索に失敗しました。\n");
  else
    printf("%dはx[%d]にあります。\n", ky, idx);

  free(x);
  return 0;
}
