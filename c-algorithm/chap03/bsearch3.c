#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[10];
  int height;
  int weight;
} Person;

int npcmp(const Person *x, const Person *y)
{
  return strcmp(x->name, y->name);
}

int main(void)
{
  Person x[]= {
    {"ABE",     179,  79},
    {"NANGOH",  172,  63},
    {"SHIBATA", 176,  52},
    {"SUGIYAMA",165,  49},
    {"TAKAOKA", 179,  71},
    {"TSURUMI", 166,  60},
  };

  int nx = sizeof(x) / sizeof(x[0]);
  int retry;
  
  puts("名前による探索を行います。");
  do {
    Person temp, *p;
    printf("名前 : ");
    scanf("%s", temp.name);
    p = bsearch(&temp, x, nx, sizeof(Person),
                  (int (*)(const void *, const void *))npcmp);

    if (p == NULL)
      puts ("探索に失敗しました。");
    else {
      puts ("探索成功。以下の要素を見つけました。");
      printf("x[%d] : %s %dcm %dkg\n", 
          (int)(p - x), p->name, p->height, p->weight);
    } 
    printf("もう一度探索しますか？ はい(1)/いいえ(0)");
    scanf("%d", &retry);
  }while (retry == 1);

  return 0;
}
