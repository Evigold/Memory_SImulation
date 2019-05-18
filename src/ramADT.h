/**
 * Memory ADT.
 * Defines the Ram and Pages structs, as well as their utility functions.
**/
#ifndef RAM
#define RAM

#include<stdio.h>
#include<stdlib.h>

// Memory Page struct. Stores information about the process currently using it.
typedef struct pageType {
    int num;
    int pid;
    int size;
    int spaceUsed;
    char used;        
} Page;

// Ram struct. Stores and keeps track of the state of all its pages.
typedef struct ramType {
    Page * pages;
    int pageSize;
    int length;
    int numPagesUsed;
    int totalFrag;
    int pidCnt;
} Ram;

/**
 * Utility function to initialize a Ram struct. It allocates memory to store the
 * pages, as well as initiating relavant information about itself.
 * 
 * A pointer to a Ram object is passed, as well as the number of partitions to initialize 
 * and the size of each page.
 * 
 * Nothing returned.
**/
void RAM_InitRam (Ram * mem, int partitions, int PageSize);

/**
 * Utility function to initialize a page. It initializes all of its relevant information.
 * 
 * A pointer to the page is passed, as well as its number (id) and its size.
 * 
 * Noting is returned.
**/
void RAM_InitPage (Page * page, int num, int size);

/**
 * Utility function to add (use) a page. It finds usable space for the process, allocates
 * pages for it, and stores some statistical information.
 * 
 * A pointer to the Ram memory where the processs should be stored in is passed. As well as the 
 * page number to be used, the process id using it and the amount of memory to be used.
 * 
 * Nothing is returned.
**/
void RAM_AddPage(Ram * mem, int pgn, int pid, int memUsed);

/**
 * Utility function to remove (free) a page. It tracks down the used page and resets its information.
 * 
 * A pointer to the Ram memory where the processs should be stored in is passed. As well as the 
 * page number to be used.
 * 
 * Nothing is returned.
**/  
void RAM_RemovePage(Ram * mem, int pgn);

/**
 * Utility helper method to set a given page. Used for both allocating and deallocating it.
 * 
 * A pointer to the page is passed, as well as a process id, and amount of memory to be used.
 * 
 * Nothing is returned.
**/
int RAM_SetPage (Page * page, int pid, int memUsed);

/**
 * Utility function used to find the next avilable page stored in the Ram.
 * 
 * A pointer to the Ram memory is passed.
 * 
 * Returns the index number of the next avilable free page.
**/
int RAM_NextFreePage (Ram * mem);

/**
 * Utility function that prints all relevent information about the Ram memory.
 *  For each page: Partition number, Process ID, Memory Fragmentation and its avilability status.
 * 
 * A pointer to the Ram memory is passed.
 * 
 * Nothing is returned.
**/
void RAM_Print(Ram * mem);

/**
 * Freees all the space allocated for the pages in the Ram.
 * 
 * Takes a pointer to the Ram memory.
 * 
 * Nothing is returned.
**/
void RAM_FreeRam(Ram * mem);

#endif