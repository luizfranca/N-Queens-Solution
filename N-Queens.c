#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;

void printBoard(int n, int board[n]) {
	for (int i = 0; i < n - 1; i++) {
		printf("%c%d, ", (char) (i + 97), board[i]);
	}
	
	printf("%c%d", (char) (n - 1 + 97), board[n - 1]);
	
	printf("\n");
}

void initBoard(int n, int board[n]) {
        for (int i = 0; i < n; i++) {
                board[i] = -1;
        }
}

bool isUnderAttack(int n, int board[n], int index) {
	for (int i = 0; i < index; i++) {
		if (i == index) continue;
		
		if (board[i] == board[index] && board[i] != -1) return true;

		int distance = index - i;

		if (board[index] + distance == board[i] && board[i] != -1) return true;

		if (board[index] - distance == board[i] && board[i] != -1) return true;
	}
	return false;
}

void backtracking(int n, int board[n], int index, int *answers) {
	for (int i = 0; i < n; i++) {
		board[index] = i;
		if (!isUnderAttack(n, board, index)) {
			if (index == n - 1) {
				printf("%d  :  ", *answers);
				*answers += 1;
				printBoard(n, board);
			}			
			else {
				backtracking(n, board, index + 1, answers);
			}
		}
	}
}

int main() {

	printf("Enter the value of n: \n");

	int n;

	scanf("%d", &n);

	int board[n];	
	
	initBoard(n, board);	

	int answers = 1;	

	backtracking(n, board, 0, &answers);
	
	return 0;
}