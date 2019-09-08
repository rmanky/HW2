#include "Board.h"

int* nextStep(int* currentBoard, LLNode* currentList, int rows, int cols) {
	currentList = generateNext(currentList);

	LLNode* p = currentList;
	while(p->next != NULL) {
		p = p->next;
	}

	Point nextPoint;
	nextPoint = p->point;

	int vertOffset = modulo(nextPoint.y,cols);
	// Wrap arround
	int horzOffset = modulo(nextPoint.x,cols);

	currentBoard[vertOffset * cols + horzOffset] = nextPoint.value;

	return currentBoard;
}

int* makeBoard(int rows, int cols)
{
	int* boardPointer = (int*) malloc(rows*cols*sizeof(int));
	if(boardPointer==0)
	{
		printf("MALLOC FAILED");
	}

	for (int i = 0; i <  rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			*(boardPointer + i*cols + j) = 0;
		}
	}

	return boardPointer;
}
