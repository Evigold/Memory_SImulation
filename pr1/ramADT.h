#ifndef RAM
#define RAM

#include<stdio.h>
#include<stdlib.h>

typedef struct pageType {
    int num;
    int pid;
    int size;
    int spaceUsed;
    char used;        
} Page;

typedef struct ramType {
    Page * pages;
    int pageSize;
    int length;
    int * freePages;
    int pidCnt;
} Ram;

void RAM_InitRam (Ram * mem, int partitions, int PageSize);

void RAM_InitPage (Page * page, int num, int size);

void RAM_SetPage (Page * page, int pid, int memUsed);

int RAM_NextFreePage (Ram * mem);

void RAM_Print(Ram * mem);

#endif