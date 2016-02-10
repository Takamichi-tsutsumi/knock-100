#include <stdio.h>
#include <stdlib.h>

int search_idx(const int a[], int n, int key, int idx[])
{
  int i, l;
  int count = 0;
  int indexes[n];
  i = 0;
  do {
    if (a[i] == key) {
      indexes[count] = i;
      count++;
    }
    i++;
  } while(i<n);

  for (i = 0; i < count; i++) {
    idx[i] = indexes[i];
  }
  printf("%d", idx[0]);
  
  return count;
}

int main(void)
{
  int i, nx, ky, count;
  int *x, *idx;

  puts("線形探索");
  printf("要素数 : ");
  scanf("%d", &nx);
  x = calloc(nx, sizeof(int));
  idx = calloc(nx, sizeof(int));
  
  for (i = 0; i < nx; i++) {
    printf("x[%d] : ", i);
    scanf("%d", &x[i]);
  }
  printf("探す値");
  scanf("%d", &ky);
  
  count = search_idx(x, nx, ky, idx);

  for (i = 0; i < nx; i++) {
    printf("%3d\n", idx[i]);
  }
  if (count == 0)
    puts("探索に失敗しました。");
  else
    printf("%dは%dつあります。\n", ky, count);
  free(x);
  free(idx);

  return 0;
}
