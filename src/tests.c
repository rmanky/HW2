#include "tests.h"

bool tests()
{
	bool ok = true;

	if(testConstantPointCreation() == false) {
		ok = false;
	}

	if(testRandomPointCreation() == false) {
		ok = false;
	}

	if(testBoardCreation() == false) {
		ok = false;
	}

	if(testBoardListDisplay() == false) {
		ok = false;
	}

	return ok;
}

bool testConstantPointCreation() {
	bool answer = false;

	int testX = 2;
	int testY = 9;
	int testValue = 5;

	Point testPoint = addPoint(testX, testY, testValue);

	if(testPoint.x == testX && testPoint.y == testY && testPoint.value == testValue) {
		printf("Point successfully created with coordinates (%i, %i) and a value of %i \n", testPoint.x, testPoint.y, testPoint.value);
		printf("Test 1 Passed! \n");
		answer = true;
	}

	return answer;
}

bool testRandomPointCreation() {
	bool answer = false;
	int startValue = 1;

	Point firstPoint = addPoint(0,0,startValue);
	LLNode points;
	points.next = 0;
	points.prev = 0;
	points.point = firstPoint;
	LLNode* point_P = generateNext(&points);

	LLNode* nextNode = point_P->next;
	Point nextPoint = nextNode->point;


	if(nextPoint.value == startValue + 1)
	{
		printf("New Point created at (%i, %i) with a value of %i \n", nextPoint.x, nextPoint.y, nextPoint.value);
		printf("Test 2 Passed! \n");
		answer = true;
	}

	return answer;
}

bool testBoardCreation() {
	bool answer = true;

	int rows = 3;
	int cols = 3;

	int* board = makeBoard(rows, cols);

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

	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++) {
			if(board[i * cols + j] != 0)
			{
				answer = false;
			}
		}
	}

	if(answer) {
		printf("Test 3 Passed! \n");
	}

	return answer;
}

bool testBoardListDisplay() {
	bool answer = false;

	int startValue = 1;
	int rows = 4;
	int cols = 4;

	int* board = makeBoard(rows, cols);
	board[0] = startValue;
	Point firstPoint = addPoint(0,0,startValue);
	LLNode points;
	points.next = 0;
	points.prev = 0;
	points.point = firstPoint;

	board = nextStep(board, &points, rows, cols);

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

	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++) {
			if(board[i * cols + j] == 2) {
				answer = true;
			}
		}
	}

	if(answer) {
		printf("Test 4 Passed: \n");
		printf("The value '2' was found \n");
	}

	return answer;
}
