#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gen(lower, upper) {
  return lower + rand() % (upper - lower + 1);
}

int check(guess, answer) {
  int retVal = 1;
  if (guess == answer) {
    printf("정답\n");
    retVal = 0;
  }
  else if (guess < answer) {
    printf("up\n");
  }
  else { printf("down\n"); }
  return retVal;
}

void sks(int *max, int *lower, int *upper) {
  int level;
  printf("난이도 선택(1~3): ");
  scanf_s("%d", &level);
  switch (level) {
  case 1: *max = 10, *lower = 1, *upper = 10;
    break;
  case 2: *max = 10, *lower = 1, *upper = 70;
    break;
  case 3: *max = 10, *lower = 1, *upper = 100;
    break;
  }
}

void stgame() {
  int lower, upper, answer, guess, att, sc2=0;
  int max = 10;
  int r = 0;

  char a = 'y';
  int sc = 100;
  while (a == 'y') {
    sks(&max, &lower, &upper);
    answer = gen(lower, upper);
    r++;
    att = 0;
    printf("ROUND%d\n", r);
    do {
      if (att > max) {
        printf("횟수초과");
        break;
      }
      printf("guess: ");
      scanf_s("%d", &guess);
      att++;
    } while (check(guess, answer) != 0);
    
    sc = 100;
    sc -= (100 / max) * (att-1);
    
    printf("%d번 시도!\n", att);
    printf("총점: %d\n", sc);
    printf("다시하시겠습니까? y or n: ");
    scanf_s("  %c", &a, 1);
    sc2 += sc;
  }
  printf("합산:%d, 평균:%.2f", sc2, (float)sc2 / r);
}

int main() {
  srand(time(0));
  stgame();
}