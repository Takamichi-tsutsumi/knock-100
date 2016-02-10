#include <stdio.h>
#include <stdlib.h>

int int_cmp(const int *a, const int *b)
{
  if (*a > *b)
    return 1;
  else if (*a < *b)
    return -1;
  else
    return 0;
}


int main(void)
{
  int i, nx, ky;
  int *x;
  int *p;

  puts("bsearch関数による探索");
  printf("要素数 : ");
  scanf("%d", &nx);
  x = calloc(nx, sizeof(int));
  
  printf("昇順に入力してください。\n");
  printf("x[0] : ");
  scanf("%d", &x[0]);
  for (i = 1; i < nx; i++) {
    do {
      printf("x[%d] : ", i);
      scanf("%d", &x[i]);
    } while (x[i] < x[i-1]);
   }

  printf("探す値 : ");
  scanf("%d", &ky);
  
  p = bsearch(
        &ky, 
        x, 
        nx, 
        sizeof(int), 
        (int (*)(const void *, const void *))int_cmp
      );

  if (p == NULL)
    puts("探索に失敗しました");
  else 
    printf("%dはx[%d]にあります。\n", ky, (int)(p - x));
  free(x);

  return 0;
}
