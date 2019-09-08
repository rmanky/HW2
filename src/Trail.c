#include "Trail.h"
#include <stdio.h>

LLNode* generateNext(LLNode* currentList)
{
	LLNode* temp;
	temp = (LLNode*)malloc(sizeof(struct LLNode));
	temp->next = NULL;
	LLNode* p = currentList;
	while(p->next != NULL) {
		p = p->next;
	}

	Point currentPoint;
	currentPoint = p->point;

	int addX = 0;
	int addY = 0;
	while(addX == 0 && addY == 0)
	{
		addX = (rand() % 3) - 1;
		addY = (rand() % 3) - 1;
	}

	int newX = currentPoint.x + addX;
	int newY = currentPoint.y + addY;
	int newValue = currentPoint.value + 1;

	printf("On turn %i, moved from (%i, %i) to (%i, %i) \n", newValue, currentPoint.x, currentPoint.y,
	       newX, newY);

	Point nextPoint = addPoint(newX, newY, newValue);
	temp->point = nextPoint;
	p->next = temp;
	temp->prev = p;

	return currentList;
}


int modulo(int a, int b) {
	int r = a % b;
	if (r < 0)
	{
		r = (b < 0) ? r - b : r + b;
	}
	return r;
}
