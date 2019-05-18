#ifndef PRCS
#define PRCS

#include<stdio.h>
#include<stdlib.h>

#include "ramADT.h"

typedef struct processType {
    int id;
    int size;
    int numPages;
    int * pages;
} Process;

typedef struct listType {
    Process * data;
    int * elId;
    int size;
    int capacity;
}List;

List * PRCS_InitList(int MaxLen);

void PRCS_AddProcess(List * lst, Ram * mem, int size);

int PRCS_InitProcess (Process * prcs, Ram * mem, int size);

void PRCS_RemoveFromList(int id, List * lst, Ram * mem);

void PRCS_RemoveProcess (Process * prcs, Ram * mem);

Process * PRCS_GetById(int id, List * lst);

int PRCS_GetIndexById(int id, List * lst);

void PRCS_Print(List * lst);

void PRCS_FreeList(List * lst);

#endif