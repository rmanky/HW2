#include "View.h"

void run(int iterations, int rows, int cols) {
	int startValue = 1;

	int* board = makeBoard(rows, cols);
	board[0] = startValue;
	Point firstPoint = addPoint(0,0,startValue);
	LLNode points;
	points.next = 0;
	points.prev = 0;
	points.point = firstPoint;

	for(int i = 0; i < iterations - 1; i++) {
		board = nextStep(board, &points, rows, cols);
	}


	printBoard(board, rows, cols);
}

void printBoard(int* board, int rows, int cols) {
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++) {
			printf(" %i |", board[i * cols + j]);
		}
		printf("\n");
		for(int j = 0; j < cols; j++) {
			printf("--- ");
		}
		printf("\n");
	}
}

void delay(int ms)
{
	clock_t start_time = clock();

	while (clock() < start_time + ms);
}
