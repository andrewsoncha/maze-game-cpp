#include<stdio.h>
#define MX 100
int paths[MX][MX];
int N;
int player1Start, player2Start;
int player1Pos, player2Pos;
int player1Delay, player2Delay;
int main() {
	int M;
	int i, j;
	int turnN = 0;
	scanf("%d %d", &N,&M);
	for (i = 0; i < M; i++) {
		int tmp1, tmp2, length;
		scanf("%d %d %d", &tmp1, &tmp2,&length);
		paths[tmp1-1][tmp2-1] = length;
		paths[tmp2-1][tmp1-1] = length;
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("%d ", paths[i][j]);
		}
		printf("\n");
	}
	scanf("%d %d", &player1Start, &player2Start);
	player1Pos = player1Start;
	player2Pos = player2Start;
	printf("______________________________\n");
	for (turnN = 0;;turnN++) {
		int input;
		if (player1Delay <= 0) {
			printf("current position %d. player 1 where to go?\n",player1Pos);
			for (i = 0; i < N; i++) {
				if (paths[player1Pos][i] > 0) {
					printf("path %d: %d\n", i, paths[player1Pos][i]);
				}
			}
			printf("stay here: input -1\n");
			while (1)
			{
				scanf("%d", &input);
				if (input == -1) {
					player1Pos = player1Pos;
					player1Delay = 0;
					break;
				}
				else if (paths[player1Pos][input] > 0) {
					player1Pos = input;
					player1Delay = paths[player1Pos][input];
					break;
				}
				else {
					printf("please select a valid destination\n");
				}
			}
		}
		else {
			printf("remaining delay:%d\n", player1Delay);
			player1Delay--;
		}

		if (player2Delay <= 0) {
			printf("current position %d. player 2 where to go?\n",player2Pos);
			for (i = 0; i < N; i++) {
				if (paths[player1Pos][i] > 0) {
					printf("path %d: %d\n", i, paths[player2Pos][i]);
				}
			}
			printf("stay here: input -1\n");
			while (1)
			{
				scanf("%d", &input);
				if (input == -1) {
					player2Pos = player2Pos;
					player2Delay = 0;
					break;
				}
				else if (paths[player2Pos][input] > 0) {
					player2Pos = input;
					player2Delay = paths[player2Pos][input];
					break;
				}
				else {
					printf("please select a valid destination\n");
				}
			}
		}
		else {
			printf("player 2 delay:%d\n", player2Delay);
			player2Delay--;
		}
	}
	return 0;
}