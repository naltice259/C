#include <stdio.h>
#include <stdlib.h>
#include "q.h"
TCB_t* RunQ = NULL;
void start_thread(void (*function)(void))
{ 
	//allocate a stack (via malloc) of a certain size (choose 8192)
	struct stack *s = malloc(8192);
	//allocate a TCB (via malloc)
	TCB_t* t;
	t = NewItem();
	//call init_TCB with appropriate arguments
	init_TCB (t, (*function), s, 8192);
	//call addQ to add this TCB into the "RunQ" which is a global header pointer
	AddQueue(&RunQ, t);
	return;
}

void run()
{	// real code
	
	ucontext_t parent;	// get a place to store the main context, for faking
	getcontext(&parent);	// magic sauce
	swapcontext(&parent, &(RunQ->context));	// start the first thread
	return;
}

void yield() // similar to run
{
	//rotate the run Q
	RotateQ(&RunQ);
	//swap the context, from previous thread to the thread pointed to by RunQ
	if(RunQ->next != NULL){
		swapcontext(&(RunQ->prev->context), &(RunQ->context));
	}
	return;
}

