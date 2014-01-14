/* declare global variables: */

/* stack areas of the 3 tasks */
OS_STK task1Stk[1024];   // OS_STK has usually the size of a word (e.g. 16 or 32 bits
OS_STK task2Stk[1024];
OS_STK task3Stk[1024];

/*private static variables of tasks that need it*/
structure t2data{         // variables used by several functions called in task2
   char message[20];
NT16U t2counter;
}task2data;

/*events: mutexes, interrupts etc.*/
OS_EVENT mymutex;


 void main (void){  // main is the "system layer" of the project
	INT8U err;      // a variable declared as 8 bit unsigned integer
	OSInit();           // first initialise uCOS/OS-2 general purpose data structures;
					// also creates the idle task(lowest priority) and a task
					// collecting statistical data on CPU usage

	/*initialise uCOS/OS-2 specific data structures used by this project*/
	mymutex = OSMutexCreate(9,&err); 	// first arg is pip (priority inheritance priority:
									// must be higher than prio of all tasks using the mutex)

	OSTaskCreate(task1,    	// pointer to function including code of task
			 (void *)0, 	// pointer to task private data area: none on this case
		 &task1Stk[1023],	// Top of stack (stack assumed to grow downwards)
		 10);      			// prio of task: is also task identifier for uCOS/OS-2

	OSTaskCreate(task2,
			 &task2data,	// pointer to task private data area
		 &task2Stk[1023],
		 15);

	OSTaskCreate(task3,
			 (void *)0,
		 &task3Stk[1023],	// Top of stack (stack assumed to grow downwards)*/
		 20);
	/*More tasks may be created within the tasks themselves, but at least one must have beeen created here*/

	/*start scheduling the tasks*/
	OSStart();
 }


 void task1 (void *pdata){
	INT8U err;
	while (1){
	   /*some code here*/
	   OSMutexPend(mymutex, 	// sleep until I get the mutex
					   0,       // time-out in clock ticks 0(for ever or 1 to 65535)
		   &err);
	   /*access shared resource*/
	   OSMutexPost(mymutex);	// allow next task to use the resource
	   /*more code here */
	}
 }

 /*similar code for tasks 2 and 3*/