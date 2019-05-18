/**
 * Process ADT.
 * Define the Process struct and a List to manage currently running processes.
**/
#ifndef PRCS
#define PRCS

#include<stdio.h>
#include<stdlib.h>

#include "ramADT.h"

// Process structure. Stores its id, size, the number of pages its using and a list of pages it is using.
typedef struct processType {
    int id;
    int size;
    int numPages;
    int * pages;
} Process;

// A list of processes that keeps track of all the currently running processes.
typedef struct listType {
    Process * data;
    int * elId;
    int size;
    int capacity;
} List;

/**
 * Utility function that initializes the process list struct. Allocates memory to the 
 * maximum number of processes that could run simultaniously.
 * 
 * The maximum number of proccesses that could be run simultaniously is passed as a parameter.
 * 
 * Returns a pointer to the list.
**/ 
List * PRCS_InitList (int MaxLen);

/**
 * Utiity function that adds a processes. It adds it to the list, defines it, and stores it 
 * in the RAN.
 * 
 * Takes a pointer to the list, a pointer to the Ram and the sixe of the new process as a 
 * parameter.
 * 
 * Nothing is returned.
**/
void PRCS_AddProcess (List * lst, Ram * mem, int size);

/**
 * Utility function that sets all the variables to the new page, as well as stores it in the
 * Ram memory.
 * 
 * Take a pointer to the new process, a pointer to the Ram memory and its size.
 * 
 * Returns its process ID.
**/
int PRCS_InitProcess (Process * prcs, Ram * mem, int size);

/**
 * Utility function that removes a process from the simulation. Removes it from the list as
 * well as from the Ram memory.
 * 
 * Take a process id, a pointer to the list and a pointer to the Ram memory as parameters.
 * 
 * Nothing is returned.
**/
void PRCS_RemoveFromList (int id, List * lst, Ram * mem);

/**
 * Utility function that deallocates the process from memory.
 * 
 * Takes a pointer to the process and to Ram memory as parameters.
 * 
 * Nothing is returned.
**/
void PRCS_RemoveProcess (Process * prcs, Ram * mem);

/**
 * Utility function that locates a procecss by its process ID.
 * 
 * Takes a process id and a pointer to the List as parameters.
 * 
 * Returns a pointer to the process.
**/
Process * PRCS_GetById (int id, List * lst);

/**
 * Utility function that identifies the process location in the list based on its
 * process id,
 * 
 * Takes a process id and a pointer to the list as parameters.
 * 
 * returns the index of the process in the list.
**/
int PRCS_GetIndexById (int id, List * lst);

/**
 * Utility function that prints each currently running process id as well as the pages 
 * it is occupying.
 * 
 * Takes a pointer to the process list as  a parameter.
 * 
 * Nothing is returned.
**/
void PRCS_Print (List * lst);

/**
 * Frees all teh spaces allocated for the process struct and the process list structs.
 * 
 * Takes a pointer to the process list as a parameter.
 * 
 * Nothing is returned.
**/
void PRCS_FreeList (List * lst);

#endif