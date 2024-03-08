#pragma once
#include "stdio.h"
#include "string.h"
#define MAX 3
#define LIMIT 1

//to be deleted later just temp
typedef struct player {
	char* username;
	int maxScore;
}p;

void start();

void quit();

void setName(struct player info, char name[MAX]);