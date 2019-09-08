#ifndef TRAIL_H_
#define TRAIL_H_

#include <stdlib.h> //for rand, srand
#include <time.h> //for time
#include "Point.h"

typedef struct LLNode
{
	Point point;
	struct LLNode* prev;
	struct LLNode* next;
} LLNode;

LLNode* generateNext(LLNode* );

int modulo(int, int);

#endif
