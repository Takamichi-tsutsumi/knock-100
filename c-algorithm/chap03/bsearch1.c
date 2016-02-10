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

int long_cmp(const long *a, const long *b)
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
  int i, nx;
  long ky;
  long *x;
  long *p;

  puts("bsearch関数による探索");
  printf("要素数 : ");
  scanf("%d", &nx);
  x = calloc(nx, sizeof(long));
  
  printf("降順に入力してください。\n");
  printf("x[0] : ");
  scanf("%ld", &x[0]);
  for (i = 1; i < nx; i++) {
    do {
      printf("x[%d] : ", i);
      scanf("%ld", &x[i]);
    } while (x[i] > x[i-1]);
   }

  printf("探す値 : ");
  scanf("%ld", &ky);
  
  p = bsearch(
        &ky, 
        x, 
        nx, 
        sizeof(long), 
        (int (*)(const void *, const void *))long_cmp
      );

  if (p == NULL)
    puts("探索に失敗しました");
  else 
    printf("%ldはx[%ld]にあります。\n", ky, (long)(p - x));
  free(x);

  return 0;
}
