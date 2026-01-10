#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


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
	int n = (att - 1) * (base / maxatt);
	int score = base - n + bonus;
	return score;
}

//입력값과 답 비교, score, 성공여부
int gameplay(gamestate* g, int lev, int* outsc) {
	int guess, bonus = 0;
	g->att = 0;

	int suc = 1;

	printf("범위 <1~%d> 기회는%d번!\n", g->maxnum, g->maxatt);

	while (1) {
		printf("입력: ");
		if (scanf_s("%d", &guess) != 1 ||guess<=0 || guess > g->maxnum) {
			printf("숫자를 올바르게 입력하세요\n");
			while (getchar() != '\n');
			continue;
		}

		g->att++;
		if (g->att > g->maxatt) {
			printf("최대시도횟수 초과...정답<%d>\n**GAME OVER**\n", g->answer);
			suc = 0;
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
		int sc = 0;
	if (suc == 1) {
			sc = score(g->att, g->maxatt, bonus, lev);
			
			*outsc += sc;

			printf("%d점!\n누적<%d점>", sc, *outsc);

		}
	else printf("누적<%d점>", *outsc);
	

	/**outsc += sc;

	printf("%d점!\n누적<%d점>", sc, *outsc);*/

	return suc;
}


void game() {
	int lev, outsc=0;
	char a;

	gamestate g = { 0 };

	printf("업다운게임~\n");

	//원하는만큼 게임 진행
	while (1) {

		while (1) { //매 판마다 난도조절 가능
			printf("난이도 선택(1~3): ");
			scanf_s("%d", &lev);
			if (lev <= 3 && lev >= 1) {
				break;
			}
			printf("1~3중 입력하세요\n");
		}

		//난도에 따라 maxnum, maxatt 에 값 넣기
		switch (lev) {
		case 1:
			g.maxnum = 30;
			g.maxatt = 15;
			break;
		case 2:
			g.maxnum = 50;
			g.maxatt = 10;
			break;
		case 3:
			g.maxnum = 100;
			g.maxatt = 10;
			break;
		}

		g.answer = gen_answer(g.maxnum); //게임 정보에 (정답생성함수)로 답 생성후 넣어주기

		if (gameplay(&g, lev, &outsc) == 0) { //맞추기실패시 진행불가
			break;
		}
		
		printf("계속하시겠습니까? (Y or N) : ");
		scanf_s(" %c", &a, 1);
		if (a == 'N'||a=='n') {
			printf("게임 종료");
			break;
		}

	}

}

int main(void) {
	seed();
	game();
}
