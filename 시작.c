#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//player:이름,최고기록
typedef struct {
	char name[20];
	int bestscore;
} player;

//gamestate:답,범위,횟수제한
typedef struct {
	int answer;
	int maxnum;
	int maxatt;
	int att;
} gamestate;

//rand의 씨드를 시간베이스로
void seed() {
	srand((unsigned)time(NULL));
}

//정답(난수)리턴
int gen_answer(int maxnum) {
	return (rand() % maxnum) + 1;
}

//점수계산>gameplay
int score(int att, int maxatt, int bonus, int lev) {
	int base = 100 * lev;
	int n = (att-1) * (base / maxatt);
	int score = base - n + bonus;
	return score;
}

//입력값과 답 비교, score불러오기
int gameplay(gamestate* g, int lev) {
	int guess, bonus = 0;
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

	//score함수에 gamestate의 정보 넣고 실행
	int sc = score(g->att, g->maxatt, bonus, lev);
	printf("%d점", sc);
	return sc;
}

//플레이어 카운트
int read(player p[], int max) {
	FILE* fp = fopen("player.txt", "r");
	if (!fp) return 0;

	int count = 0;
	while (fscanf(fp, "%s %d\n", p[count].name, &p[count].bestscore) != EOF) {
		count++;
		if (count >= max) break;
	}
	fclose(fp);
	return count;

}

//플레이어 저장
void save(player p[], int count) {
	FILE* fp = fopen("player.txt", "w");
	for (int i = 0; i < count; i++) {
		fprintf(fp, "%s %d\n", p[i].name, p[i].bestscore);
	}
	fclose(fp);
}

int find(player p[], int count, char* name) {
	FILE* fp = fopen("player.txt", "w");
	if (!fp) return 0;

	for (int i = 0; i < count; i++) {

		if () {
			return i;
		}
	}
	

	return -1;
	//신규인지 판별>-1
}

void game() {
	int lev, pcount=1;
	char name[20];
	player players[100];

	gamestate g = { 0 };

	printf("업다운게임\n난이도 선택(1~3): ");
	scanf_s("%d", &lev);

	switch (lev) {
	case 1:
		g.maxnum = 30;
		g.maxatt = 15;
		break;
	case 2:
		g.maxnum = 500;
		g.maxatt = 10;
		break;
	case 3:
		g.maxnum = 100;
		g.maxatt = 10;
		break;
	}

	printf("사용자 이름: ");
	scanf_s("%s", name, 20);

	int idx = find(players, pcount, &name);

	


	g.answer = gen_answer(g.maxnum);
	gameplay(&g, lev);

	if (idx == -1) {

	}
	else {
		if (gameplay(&g, lev) > players[idx].bestscore) {

		}
	}
	
}

int main(void) {
	seed();
	game();
}
