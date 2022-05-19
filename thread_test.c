//Nicholas Altice
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "threads.h"

int global = 0; 
int e;
int f;
int id = 1;

void function();

int main()
{
	int a = 0;
	int b = 0;
    char c[12];
    int d = 1;
    fgets(c, 12, stdin); //get input
    
    int i = 0;
    while(c[i] >= 48 && c[i] <= 57 && i < 12){
    	a = (a * 10) + (c[i] - '0'); //get thread number
    	i++;
	}
	i++;
	while(c[i] >= 48 && c[i] <= 57 && i < 12){
    	b = (b * 10) + (c[i] - '0'); //get execution number
    	i++;
	}
    if(a == 0) //check for no threads
    {
    	printf("No Threads\n"); 
	} else if(b != 0) //check for no executions
    {	
		while(d <= a)
		{
			start_thread(function); //create threads
			d++;
		}
		e = b;
		f = a;
		run();
	}
	
    
    return 0;
}

void function()
{
	int local = 0;
	while(local < e)
	{
		global += id;
		local++;
		printf("\n This is %d th execution of thread %d with global var value %d \n", local, id, global);
		if(id == f){
			id = 1;
		}else{
			id++;
		}
		yield();
	}
	return;
}
