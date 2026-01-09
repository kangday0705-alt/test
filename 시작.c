#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
	char name[20];
	int bestscore;
} player;

typedef struct {
	int answer;
	int maxnum;
	int maxatt;
	int att;
} gamestate;


void seed() {
	srand((unsigned)time(NULL));
}

int gen_answer(int maxnum) {
	return (rand() % maxnum) + 1;
}

int score(int att, int maxatt, int bonus) {
	int base = 100;
	int n = att * (100 / maxatt);
	int score = base - n + bonus;
	return score;
}

int gameplay(gamestate *g) {
	int guess, bonus=0;
	g->att = 0;
	while (1) {
		printf("입력: ");
		scanf_s("%d", &guess);
		g->att++;
		if (g->att > g->maxatt) {
			printf("최대시도횟수 초과\n");
			break;
		}
		else if (guess < g->answer) {
			printf("UP\n");
		}
		else if (guess > g->answer) {
			printf("DOWN\n");
		}
		else {
			printf("정답! %d번 시도\n", g->att);
			break;
		}
	}

	int sc = score(g->att, g->maxatt, bonus);
	printf("%d점", sc);
	return sc;
 }

//void save() {
//	FILE* fp = fopen("player.txt", "w");
//	fprintf;
//}
//
//void read() {
//
//}

void game() {
	int lev;
	char arr[20];
	gamestate g = { 0 };

	printf("업다운게임\n난이도 선택(1~3): ");
	scanf_s("%d", &lev);

	switch(lev) {
	case 1 :
		g.maxnum = 30;
		g.maxatt = 10;
		break;
	case 2:
		g.maxnum = 500;
		g.maxatt = 10;
		break;
	case 3:
		g.maxnum = 100;
		g.maxatt = 5;
		break;
	}

	printf("사용자 이름: ");
	scanf_s("%s", arr);

	g.answer = gen_answer(g.maxnum);
	gameplay(&g);

	//난이도정하고 게임실행, 종료, 기록출력
}

int main(void) {
	seed();
	game();
}
