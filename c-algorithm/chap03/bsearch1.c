#include <stdio.h>
#include <stdlib.h>

void *seqsearch(
    const void *key, /* 比較する値 */
    const void *base, /* 比較される配列 */
    size_t nmemb, /* *baseのメンバ数 */
    size_t size,  /* *baseの要素のsize */
    int (*compar)(const void *, const void *)) /* 比較関数 */
{
  size_t i;
  for (i = 0; i < nmemb; i++) {
    if (compar(base + i * size, key) == 0) {
      return (void *)(base + i * size);
    }
  }
  return NULL;
}

void *bin_search(
    const void *key,
    const void *base,
    size_t nmemb,
    size_t size,
    int (*compar)(const void *, const void *))
{
  size_t pl = 0;
  size_t pr = nmemb;
  size_t pc;

  while(pl < pr) {

    pc = pl + (pr - pl)/2;
    
    if(compar(key, base + size * pc) == 0) {
      return (void *) (base + size * pc);
    } else if (compar(key, base + size * pc) == 1) {
      pl = pc + 1;
    } else {
      pr = pc;
    }

  }
  
  return NULL;
}

void *bsearchx(
    const void *key,
    const void *base,
    size_t nmemb,
    size_t size,
    int (*compar)(const void *, const void *))
{
  size_t pl = 0;
  size_t pr = nmemb;
  size_t pc;

  while(pl < pr) {

    pc = pl + (pr - pl)/2;

    if(compar(key, base + size * pc) == 0) {

      while (compar(key, base + size * (pc - 1)) == 0) {
        pc--;
      }
      return (void *) (base + size * pc);

    } else if (compar(key, base + size * pc) == 1) {

      pl = pc + 1;

    } else {

      pr = pc;

    }

  }


  return NULL;
}




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

  puts("bin_search関数による探索");
  printf("要素数 : ");
  scanf("%d", &nx);
  x = calloc(nx, sizeof(long));
  
  printf("昇順に入力してください。\n");
  printf("x[0] : ");
  scanf("%ld", &x[0]);

  for (i = 1; i < nx; i++) {

    do {

      printf("x[%d] : ", i);
      scanf("%ld", &x[i]);

    } while ( x[i] < x[i-1] );

  }

  printf("探す値 : ");
  scanf("%ld", &ky);

  p = bsearchx(
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
