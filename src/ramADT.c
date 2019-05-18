#include "ramADT.h"
#include "prcsADT.h"

void RAM_InitRam (Ram * mem, int partitions, int PageSize) {
    int i;
    mem->pages = (Page*)malloc (sizeof (Page) * partitions);
    mem->length = partitions;
    mem->pageSize = PageSize;
    mem->numPagesUsed = 0;
    mem->totalFrag = 0;
    mem->pidCnt = 0;
    for (i = 0; i < partitions; i++) {
        RAM_InitPage(&mem->pages[i],i, PageSize);
    }
}

void RAM_InitPage (Page * page, int num, int size) {
    page->num = num;
    page->pid = -1;
    page->size = size;
    page->spaceUsed = 0;
    page->used = '0';
}


void RAM_AddPage(Ram * mem, int pgn, int pid, int memUsed) {
    mem->totalFrag += RAM_SetPage(&mem->pages[pgn], pid, memUsed);
    mem->numPagesUsed++;
}

void RAM_RemovePage(Ram * mem, int pgn) {
    mem->totalFrag += RAM_SetPage(&mem->pages[pgn], -1, 0);
    mem->numPagesUsed--;
}

int RAM_SetPage (Page * page, int pid, int memUsed) {
    page->pid = pid;
    page->spaceUsed = memUsed;
    if (pid == -1) page->used = '0';
    else page->used = '1';
    return page->size - memUsed;
}

int RAM_NextFreePage (Ram * mem) {
    int i;
    for (i = 0; i < mem->length; i++) {
        if (mem->pages[i].used == '0') return i;
    }
    return -1;
}

void RAM_Print(Ram * mem) {
    Page * pg;
    printf("Partition table:\nPartition number\tProcess id\tFrag\tAvailability");
    int i, j;
    for(i = 0; i < mem->length; i++) {
        pg = &mem->pages[i];
        if(pg->used == '1') {
            int frg = pg->size - pg->spaceUsed;
            printf("\n%d\t\t\t%d\t\t%d\t\tN",pg->num, pg->pid, frg) ;    
        } else {
            printf("\n%d\t\t\t?\t\t?\t\ty",pg->num);    
        }
    }
    printf("\n---------------------------------------------------------------------------\n");
}

void RAM_FreeRam(Ram * mem) {
    free(mem->pages);
}