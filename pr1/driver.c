#include <stdio.h>
#include <stdlib.h>

#include "prcsADT.h"
#include "ramADT.h"

void main(void) {
    int ptn, pts, c, newProcessSize, deleteID;
    Ram mem;
    printf("Enter the number of partitions: ");
    scanf("%d", &ptn);
    printf("Enter the size of each partition: ");
    scanf("%d", &pts);
    RAM_InitRam(&mem, ptn, pts);
    List * lst = PRCS_InitList(ptn);
    Process * tempPrcs;
    
    do {
        printf("Do you want to:\nAdd a process? Enter 1\nDelete a process? Enter 2\nPrint values? Enter 3\nQuit? Enter 4\n");
        while(getchar() != '\n');
        scanf("%d",&c);
        switch (c) {
            case 1:
                printf("Adding - enter process size: ");
                scanf("%d", &newProcessSize);
                PRCS_AddProcess(lst, &mem, newProcessSize);
                break;
            case 2:ls
                printf("Deleting - enter process id " );
                scanf("%d", &deleteID);
                PRCS_RemoveFromList(deleteID, lst, &mem);
                break;
            case 3:
                printf("Printing –\n---------------------------------------------------------------------------\n");
                PRCS_Print(lst);
                RAM_Print(&mem);
                break;
            default:
                break;
        }
    } while(c != 4);
}