#include "ramADT.h"
#include "prcsADT.h"

List * PRCS_InitList(int MaxLen) {
    List * lst = (List*)malloc(sizeof(List));
    if(lst != NULL) {
        lst->data = (Process*)malloc(sizeof(Process) * MaxLen);
        if(lst->data == NULL) {
            PRCS_FreeList(lst);
            lst = NULL;
        }
        lst->elId = (int*)malloc(sizeof(int)*MaxLen);
        if(lst->elId == NULL) {
            PRCS_FreeList(lst);
            lst = NULL;
        }
        for(int i = 0; i < MaxLen; i++) {
            lst->elId[i] = -1;
        }
        lst->size = 0;
        lst->capacity = MaxLen;
    }
    return lst;
}

void PRCS_AddProcess(List * lst, Ram * mem, int size) {
    if (lst->capacity > lst->size) {
        lst->elId[lst->size] = PRCS_InitProcess(&lst->data[lst->size], mem, size);
        lst->size++;
    } else {
        perror("no more room in list\n");
    }
}

int PRCS_InitProcess (Process * prcs, Ram * mem, int size) {
    if(prcs == NULL) return -1;
    int i, n, memLeft = size;
    if(size % mem->pageSize == 0) prcs->numPages = size / mem->pageSize;
    else prcs->numPages = size / mem->pageSize + 1;
    n = 0;
    prcs->id = ++mem->pidCnt;
    prcs->pages = (int*)malloc (sizeof (int) * prcs->numPages);
    while (memLeft > 0) {
        i = RAM_NextFreePage (mem);
        if (i >= 0) {
            if (memLeft - mem->pageSize >= 0) {
                RAM_AddPage(mem, i, mem->pidCnt, mem->pageSize);
                memLeft -= mem->pageSize;
            } else { 
                RAM_AddPage(mem, i, mem->pidCnt, memLeft);
                memLeft = 0;
            }
            prcs->pages[n] = i;
            mem->pages[i].used = '1';
            n++;
        } else {
            perror ("no room");
        }
    }
    return prcs->id;
}

void PRCS_RemoveFromList(int id, List * lst, Ram * mem) {
    int i = PRCS_GetIndexById(id, lst);
    if( i >= 0 && i < lst->size) {
        PRCS_RemoveProcess(&lst->data[i], mem);
        if(i == lst->size - 1) {
            // lst->data[i] = NULL;
            lst->elId[i] = -1;
        } else if (i < lst->size) {
            do {
                lst->data[i] = lst->data[i + 1];
                lst->elId[i] = lst->elId[i + 1];
                i++;
            } while(lst->elId[i + 1] != -1);
        }
        lst->size--;
    } else {
            perror("error removing process\n");
    }
}

void PRCS_RemoveProcess (Process * prcs, Ram * mem) {
    int i, n;
    for (i = 0; i < prcs->numPages; i++) {
        n = prcs->pages[i];
        RAM_RemovePage(mem, n);
        mem->pages[n].used = '0';
    }
    free (prcs->pages);
}

Process * PRCS_GetById(int id, List * lst) {
    int i = PRCS_GetIndexById(id, lst);
    if( i >= 0) return &lst->data[i];
    return NULL;
}

int PRCS_GetIndexById(int id, List * lst) {
    int i = 0;
    while(i < lst->capacity && lst->elId[i] != id) i++;
    if( i < lst->capacity) return i;
    return -1;
}


void PRCS_Print(List * lst) {
Process * prcs;
    printf("Process table:\nPRocess id\t\tFrames");
    int i, j;
    for(i = 0; i < lst->size; i++) {
        prcs = &lst->data[i];
        printf("\n%d\t\t\t%d", prcs->id, prcs->pages[0]);
        for(j = 1; j < prcs->numPages; j++) {
           printf(", %d", prcs->pages[j]); 
        }
    }
    printf("\n---------------------------------------------------------------------------\n");
}

void PRCS_FreeList(List * lst) {
    for(int i = 0; i < lst->size; i++) {
        free(lst->data[i].pages);
    }
    free(lst->data);
    free(lst->elId);
    free(lst);
}