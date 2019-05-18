/**
 * Program 1: Memory Simulation
 * TCSS 380 B
 * May 17th, 2019
 * 
 * Eviatar Goldshcmidt
 * SID: 1460232
 * 
 * To be compiled on a cssgate server. 
**/
#include <stdio.h>
#include <stdlib.h>

#include "prcsADT.h"
#include "ramADT.h"

/**
 *  Main method. 
 * No parameters passed. 
 * Nothing returned. 
**/
void main (void) {
    // Declaring int variables to be used throughout the simulation. 
    int ptn, pts, c, newProcessSize, deleteID;
    // Declaring the memory (RAM) structure.
    Ram mem;
    // Declaration of the list of processes used throught the simulation.
    List * lst;
    // Declaration of a process pointer to be used throughout the simulation.
    Process * tempPrcs;
    
    //Initial prompt
    printf ("Enter the number of partitions: ");
    scanf ("%d", &ptn);
    printf ("Enter the size of each partition: ");
    scanf ("%d", &pts);
    
    // Initialization of the memory based on the initial input given.
    RAM_InitRam (&mem, ptn, pts);

    // Initialization of the list of processes used throught the simulation.
    lst = PRCS_InitList (ptn);
    
    // Simulation loop.
    
    // Simulation loop statement. If user entered 4, quits the simulation, otherwise repeats.
    while (c != 4){
        // Simulation reacurring prompt.
        printf ("Do you want to:\nAdd a process? Enter 1\nDelete a process? Enter 2\nPrint values? Enter 3\nQuit? Enter 4\n");
        // Clears input buffer before scanning for new input.
        while (getchar () != '\n');
        scanf ("%d",&c);
        // Simulation action switch.
        switch (c) {
            // Case 1: Adding a new process.
            case 1:
                printf ("Adding - enter process size: ");
                scanf ("%d", &newProcessSize);
                PRCS_AddProcess (lst, &mem, newProcessSize);
                break;
            // Case 2: Deleting a process.
            case 2:
                printf ("Deleting - enter process id " );
                scanf ("%d", &deleteID);
                PRCS_RemoveFromList (deleteID, lst, &mem);
                break;
            // Case 3: Printing information about the current memory usage to console. 
            case 3:
                printf ("Printing –\n---------------------------------------------------------------------------\n");
                PRCS_Print (lst);
                RAM_Print (&mem);
                break;
            // Default case: Exit switch.
            default:
                break;
        }
    }

    // Fress all the allcoated memory in the program.
    PRCS_FreeList(lst);
    RAM_FreeRam(&mem);
}