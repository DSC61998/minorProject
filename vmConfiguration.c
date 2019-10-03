#include<stdio.h>
#include <time.h>

//global variable for looping purpose
int i, config;
int count = 0;

//definig properties of the Virtual Machines 
typedef struct Vm
{
	int processId;
	float arrivalTime;
	float burstTime;
	// float core = 1;
	struct Vm *next;
}Vm;

Vm *vm1Head, *vm2Head, *vm3Head, *vm4Head, *vm5Head, *vm6Head; 
Vm *vm1Temp, *vm2Temp, *vm3Temp, *vm4Temp, *vm5Temp, *vm6Temp;

//defining parameters for the task
typedef struct task
{
	int processId;
	float arrivalTime;
	float burstTime;
	//float mip
	struct process *next;
}task;

void delay(int number_of_seconds);						//delay for a seconds
void validate(int, int);
Vm *nodeCreation();										//creating nodes for VM's
void vmCreation(int config);							//creating Virtual machines
task *taskCreation(int numberOfTasks);					//creating a linked list of the task that are going to be scheduled
void displayTasksScheduled(task *head);					//display the tasks that has been entered for scheduling 
void displayTasksVMScheduled(Vm *head);					//display the tasks that have been allocated to a particular VM's
void taskAllocationToVM(task *head);					//allocating the tasks from the linked list to the vm's
void sortFCFS(task *head);								//applying bubble sort to the task queue for sorting in arrival order
void calcualtionForFCFS(task *head);					//allocating arrival time and burst time from task queue to the reequired arrays 


int main()
{
	int numberOfTasks;
	
	//displaying the vm configuration
	printf("Enter the configuration that u want \n");
	printf("1. 3 virtual machines \n");
	printf("2. 6 virtual machines \n");
	printf("3  5 virtual machines \n");
	printf("Enter the VM configuration u want \n");
	scanf("%d", &config);
	
	//Number of process 
	task *taskCreationHead = NULL;
	printf("Enter the number of process u want to schedule \n");
	scanf("%d", &numberOfTasks);

	
	taskCreationHead = taskCreation(numberOfTasks);
	
	vmCreation(config);
	
	system("cls");
	sortFCFS(taskCreationHead);													//Sorting the queue of the tasks on the basis of the arrival time for implementing FCFS
	//calcualtionForFCFS(taskCreationHead);										//Filling the enteries in an array from the linked list for the calculations
	taskAllocationToVM(taskCreationHead);										//Allocating task to the Vm ans 
	
	printf("The process that need to be schedued are \n");
	displayTasksScheduled(taskCreationHead);
	
	if(config == 1)
	{
		printf("The process allocated to vm1 ");
		for (i = 0; i < 5; i++) 
		{ 
        	delay(1); 
        	printf("."); 
    	} 
    	printf("\n");
		displayTasksVMScheduled(vm1Head);
		
		printf("The process allocated to vm2 ");
		for (i = 0; i < 5; i++) 
		{ 
        	delay(1); 
        	printf("."); 
    	} 
    	printf("\n");
		displayTasksVMScheduled(vm2Head);
		
		printf("The process allocated to vm3 ");
		for (i = 0; i < 5; i++) 
		{ 
        	delay(1); 
        	printf("."); 
    	} 
    	printf("\n");
		displayTasksVMScheduled(vm3Head);
	}
	
	if(config == 2)
	{
		printf("The process allocated to vm1 ");
		for (i = 0; i < 5; i++) 
		{ 
        	delay(1); 
        	printf("."); 
    	} 
    	printf("\n");
		displayTasksVMScheduled(vm1Head);
		
		
		printf("The process allocated to vm2 ");
		for (i = 0; i < 5; i++) 
		{ 
        	delay(1); 
        	printf("."); 
    	} 
    	printf("\n");
		displayTasksVMScheduled(vm2Head);
		
		
		printf("The process allocated to vm3 ");
		for (i = 0; i < 5; i++) 
		{ 
        	delay(1); 
        	printf("."); 
    	} 
    	printf("\n");
		displayTasksVMScheduled(vm3Head);
		
		
		printf("The process allocated to vm4 ");
		for (i = 0; i < 5; i++) 
		{ 
        	delay(1); 
        	printf("."); 
    	} 
    	printf("\n");
		displayTasksVMScheduled(vm4Head);
		
		
		printf("The process allocated to vm5 ");
		for (i = 0; i < 5; i++) 
		{ 
        	delay(1); 
        	printf("."); 
    	} 
    	printf("\n");
		displayTasksVMScheduled(vm5Head);
		
		
		printf("The process allocated to vm6 ");
		for (i = 0; i < 5; i++) 
		{ 
        	delay(1); 
        	printf("."); 
    	} 
    	printf("\n");
		displayTasksVMScheduled(vm6Head);
		
	}
	
	if(config == 3)
	{
		printf("The process allocated to vm1 ");
		for (i = 0; i < 5; i++) 
		{ 
        	delay(1); 
        	printf("."); 
    	} 
    	printf("\n");
		displayTasksVMScheduled(vm1Head);
		
		printf("The process allocated to vm2 ");
		for (i = 0; i < 5; i++) 
		{ 
        	delay(1); 
        	printf("."); 
    	} 
    	printf("\n");
		displayTasksVMScheduled(vm2Head);
		
		printf("The process allocated to vm3 ");
		for (i = 0; i < 5; i++) 
		{ 
        	delay(1); 
        	printf("."); 
    	} 
    	printf("\n");
		displayTasksVMScheduled(vm3Head);
		
		printf("The process allocated to vm4 ");
		for (i = 0; i < 5; i++) 
		{ 
        	delay(1); 
        	printf("."); 
    	} 
    	printf("\n");
		displayTasksVMScheduled(vm4Head);
		
		printf("The process allocated to vm5 ");
		for (i = 0; i < 5; i++) 
		{ 
        	delay(1); 
        	printf("."); 
    	} 
    	printf("\n");
		displayTasksVMScheduled(vm5Head);
	}
	return 0;
}


void vmCreation(int config)
{
	// Setting up the virtual machines
	switch(config)
	{
		case 1: 
		{
			vm1Head = vm1Temp = nodeCreation();
			vm2Head = vm2Temp = nodeCreation();
			vm3Head = vm3Temp = nodeCreation();
			printf("3 virtual machines are up now \n");
			break;
		}
		case 2:
		{
			vm1Head = vm1Temp = nodeCreation();
			vm2Head = vm2Temp = nodeCreation();
			vm3Head = vm3Temp = nodeCreation();
			vm4Head = vm4Temp = nodeCreation();
			vm5Head = vm5Temp = nodeCreation();
			vm6Head = vm6Temp = nodeCreation();
			printf("6 virtual machines are up now \n");
			break;
		}
		case 3:
		{
			vm1Head = vm1Temp = nodeCreation();
			vm2Head = vm2Temp = nodeCreation();
			vm3Head = vm3Temp = nodeCreation();
			vm4Head = vm4Temp = nodeCreation();
			vm5Head = vm5Temp = nodeCreation();
			printf("5 virtual machines are up now \n");
			break;
		}
	}
}

task *taskCreation(int numberOfTasks)
{
	task *head = NULL;
	task *temp2;
	task *p;
	
	for(i = 0; i < numberOfTasks; i++)
	{
		temp2 = (task*)malloc(sizeof(task));
		temp2->next = NULL;
		printf("Enter the process id (only integer)\n");
		scanf("%d", &temp2->processId);
		printf("Enter the arrival time of the process (in seconds)\n");
		scanf("%f", &temp2->arrivalTime);
		printf("Enter the burst time of the process (in seconds)\n");
		scanf("%f", &temp2->burstTime);
		if(head == NULL)
		{
			head = temp2;
			p = head;
		}
		else
		{
			p->next = temp2;
			p = p->next;
		}
	}	
	return head;
}


void displayTasksScheduled(task *head)
{
	printf("Process Id  Arrival Time  Burst Time \n");
	while(head != NULL)
	{
		printf("   %d        %2f      %2f \n", head->processId, head->arrivalTime, head->burstTime);
		head = head->next;
	}
}


void displayTasksVMScheduled(Vm *head)
{
	printf("Process Id  Arrival Time  Burst Time \n");
	while(head != NULL)
	{
		printf("   %d        %2f      %2f \n", head->processId, head->arrivalTime, head->burstTime);
		head = head->next;
	}
}


Vm *nodeCreation()
{
	Vm *temp = malloc(sizeof(Vm));
	temp->next = NULL;
	return temp;
}


void sortFCFS(task *head)
{
	task *i, *j;
	for(i = head; i != NULL; i = i->next)
	{
		for(j = i->next; j != NULL; j = j->next)
		{
			if(i->arrivalTime > j->arrivalTime)
			{
				int swap = i->arrivalTime;
				i->arrivalTime = j->arrivalTime;
				j->arrivalTime = swap;
				
				swap = i->burstTime;
				i->burstTime = j->burstTime;
				j->burstTime = swap;
				
				swap = i->processId;
				i->processId = j->processId;
				j->processId = swap;
			}
		}
	}
}


void calcualtionForFCFS(task *head)
{
	int at[100];
	int bt[100];
	int wt[100];
	int tat[100];
	while(head != NULL)
	{
		at[count] = head->arrivalTime;
		bt[count] = head->burstTime;
		count = count + 1;
		head = head->next;
	}
	
	/*
	printf("Arrival time \n");
	for(i = 0; i < count; i++)
	{
		printf("%d ", at[i]);
	}
	printf("\n");
	
	printf("Burst time \n");
	for(i = 0; i < count; i++)
	{
		printf("%d ", bt[i]);
	}
	printf("\n");
	*/
	
	//calculating the waiting Time
	int service_time[100]; 
    service_time[0] = 0; 
    wt[0] = 0; 
   
    for (i = 1; i < count ; i++) 
    { 
        service_time[i] = service_time[i-1] + bt[i-1]; 
        wt[i] = service_time[i] - at[i];  
        if (wt[i] < 0) 
            wt[i] = 0; 
    } 
    
    printf("Service time \n");
	for(i = 1; i <= count; i++)
	{
		printf("%d ", service_time[i]);
	}
	printf("\n");
    
    //calculating turnaround time
    for (i = 0; i < count ; i++) 
        tat[i] = bt[i] + wt[i];
        
    //calulating the average waiting time and turn around time 
    float total_wt = 0, total_tat = 0;
    for (i = 0 ; i < count ; i++) 
    { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
        float compl_time = tat[i] + at[i]; 
		printf("%d \n", compl_time); 
    } 
    printf("Average waiting time = %d \n", total_wt / count);  
    printf("Average turn around time = %d \n", total_tat / count);  
}

void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Stroing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not acheived 
    while (clock() < start_time + milli_seconds) 
        ; 
} 

void taskAllocationToVM(task *head)
{
	int counter = 1;
	int flagConfig1 = 1;
	int flagConfig2 = 1;
	int flagConfig3 = 1;
	int flagConfig4 = 1;
	int flagConfig5 = 1;
	int flagConfig6 = 1;
	
	
	//allocating tasks to vm as configured for 1
	if(config == 1)
	{
		
		while(head != NULL)
		{
			if(counter > 3)
				counter = 1;
			
			if(counter == 1)
			{
				
				if(flagConfig1 == 1)
				{
					if(head == NULL)
						break;
					else
					{
						printf("Allocating process id %d to vm %d.... \n", head->processId, counter);
						vm1Temp->processId = head->processId;
						vm1Temp->arrivalTime = head->arrivalTime;
						vm1Temp->burstTime = head->burstTime;
						head=head->next;
						counter++;
					}
				}
				else
				{
					
					if(head == NULL)
						break;
						
					else
					{
						printf("Allocating process id %d to vm %d.... \n", head->processId, counter);
						vm1Temp->next = nodeCreation();
						vm1Temp = vm1Temp->next;
						vm1Temp->processId = head->processId;
						vm1Temp->arrivalTime = head->arrivalTime;
						vm1Temp->burstTime = head->burstTime;
						head=head->next;
						counter++;
					}
				}
				flagConfig1 = 0;
			}
			
			if(counter == 2)
			{
				
				if(flagConfig2 == 1)
				{
					if(head == NULL)
						break;
					else
					{
						printf("Allocating process id %d to vm %d.... \n", head->processId, counter);	
						vm2Temp->processId = head->processId;
						vm2Temp->arrivalTime = head->arrivalTime;
						vm2Temp->burstTime = head->burstTime;
						head=head->next;
						counter++;
					}
				}
				else
				{
					if(head == NULL)
						break;
					else
					{
						printf("Allocating process id %d to vm %d.... \n", head->processId, counter);		
						vm2Temp->next = nodeCreation();
						vm2Temp = vm2Temp->next;
						vm2Temp->processId = head->processId;
						vm2Temp->arrivalTime = head->arrivalTime;
						vm2Temp->burstTime = head->burstTime;
						head=head->next;
						counter++;
					}	
				}
				flagConfig2 = 0;
			}
			
			if(counter == 3)
			{
				
				if(flagConfig3 == 1)
				{
					if(head == NULL)
						break;
					else
					{
						printf("Allocating process id %d to vm %d.... \n", head->processId, counter);
						vm3Temp->processId = head->processId;
						vm3Temp->arrivalTime = head->arrivalTime;
						vm3Temp->burstTime = head->burstTime;
						head=head->next;
						counter++;
					}
				}
				else
				{
					
					if(head == NULL)
						break;
						
					else
					{
						
						printf("Allocating process id %d to vm %d.... \n", head->processId, counter);
						vm3Temp->next = nodeCreation();
						vm3Temp = vm3Temp->next;
						vm3Temp->processId = head->processId;
						vm3Temp->arrivalTime = head->arrivalTime;
						vm3Temp->burstTime = head->burstTime;
						head=head->next;
						counter++;	
					}
				}
				flagConfig3 = 0;
			}
		}
	}
	
	//allocating tasks to vm as configured for 2
	if(config == 2)
	{
		while(head != NULL)
		{
			if(counter > 6)
				counter = 1;
			
			if(counter == 1)
			{
				
				if(flagConfig1 == 1)
				{
					if(head == NULL)
						break;
					else
					{
						printf("Allocating process id %d to vm %d.... \n", head->processId, counter);
						vm1Temp->processId = head->processId;
						vm1Temp->arrivalTime = head->arrivalTime;
						vm1Temp->burstTime = head->burstTime;
						head=head->next;
						counter++;
					}
				}
				else
				{
					
					if(head == NULL)
						break;
						
					else
					{
						printf("Allocating process id %d to vm %d.... \n", head->processId, counter);
						vm1Temp->next = nodeCreation();
						vm1Temp = vm1Temp->next;
						vm1Temp->processId = head->processId;
						vm1Temp->arrivalTime = head->arrivalTime;
						vm1Temp->burstTime = head->burstTime;
						head=head->next;
						counter++;
					}
				}
				flagConfig1 = 0;
			}
			
			if(counter == 2)
			{
				
				if(flagConfig2 == 1)
				{
					if(head == NULL)
						break;
					else
					{
						printf("Allocating process id %d to vm %d.... \n", head->processId, counter);	
						vm2Temp->processId = head->processId;
						vm2Temp->arrivalTime = head->arrivalTime;
						vm2Temp->burstTime = head->burstTime;
						head=head->next;
						counter++;
					}
				}
				else
				{
					if(head == NULL)
						break;
					else
					{
						printf("Allocating process id %d to vm %d.... \n", head->processId, counter);		
						vm2Temp->next = nodeCreation();
						vm2Temp = vm2Temp->next;
						vm2Temp->processId = head->processId;
						vm2Temp->arrivalTime = head->arrivalTime;
						vm2Temp->burstTime = head->burstTime;
						head=head->next;
						counter++;
					}	
				}
				flagConfig2 = 0;
			}
			
			if(counter == 3)
			{
				
				if(flagConfig3 == 1)
				{
					if(head == NULL)
						break;
					else
					{
						printf("Allocating process id %d to vm %d.... \n", head->processId, counter);
						vm3Temp->processId = head->processId;
						vm3Temp->arrivalTime = head->arrivalTime;
						vm3Temp->burstTime = head->burstTime;
						head=head->next;
						counter++;
					}
				}
				else
				{
					
					if(head == NULL)
						break;
						
					else
					{
						
						printf("Allocating process id %d to vm %d.... \n", head->processId, counter);
						vm3Temp->next = nodeCreation();
						vm3Temp = vm3Temp->next;
						vm3Temp->processId = head->processId;
						vm3Temp->arrivalTime = head->arrivalTime;
						vm3Temp->burstTime = head->burstTime;
						head=head->next;
						counter++;	
					}
				}
				flagConfig3 = 0;
			}
			
			if(counter == 4)
			{
				
				if(flagConfig4 == 1)
				{
					if(head == NULL)
						break;
					else
					{
						printf("Allocating process id %d to vm %d.... \n", head->processId, counter);
						vm4Temp->processId = head->processId;
						vm4Temp->arrivalTime = head->arrivalTime;
						vm4Temp->burstTime = head->burstTime;
						head=head->next;
						counter++;
					}
				}
				else
				{
					
					if(head == NULL)
						break;	
					else
					{
						
						printf("Allocating process id %d to vm %d.... \n", head->processId, counter);
						vm4Temp->next = nodeCreation();
						vm4Temp = vm4Temp->next;
						vm4Temp->processId = head->processId;
						vm4Temp->arrivalTime = head->arrivalTime;
						vm4Temp->burstTime = head->burstTime;
						head=head->next;
						counter++;	
					}
				}
				flagConfig4 = 0;
			}
			
			if(counter == 5)
			{
				
				if(flagConfig5 == 1)
				{
					if(head == NULL)
						break;
					else
					{
						printf("Allocating process id %d to vm %d.... \n", head->processId, counter);
						vm5Temp->processId = head->processId;
						vm5Temp->arrivalTime = head->arrivalTime;
						vm5Temp->burstTime = head->burstTime;
						head=head->next;
						counter++;
					}
				}
				else
				{
					
					if(head == NULL)
						break;	
					else
					{
						
						printf("Allocating process id %d to vm %d.... \n", head->processId, counter);
						vm5Temp->next = nodeCreation();
						vm5Temp = vm5Temp->next;
						vm5Temp->processId = head->processId;
						vm5Temp->arrivalTime = head->arrivalTime;
						vm5Temp->burstTime = head->burstTime;
						head=head->next;
						counter++;	
					}
				}
				flagConfig5 = 0;
			}
			
			if(counter == 6)
			{
				
				if(flagConfig6 == 1)
				{
					if(head == NULL)
						break;
					else
					{
						printf("Allocating process id %d to vm %d.... \n", head->processId, counter);
						vm6Temp->processId = head->processId;
						vm6Temp->arrivalTime = head->arrivalTime;
						vm6Temp->burstTime = head->burstTime;
						head=head->next;
						counter++;
					}
				}
				else
				{
					
					if(head == NULL)
						break;	
					else
					{
						
						printf("Allocating process id %d to vm %d.... \n", head->processId, counter);
						vm6Temp->next = nodeCreation();
						vm6Temp = vm6Temp->next;
						vm6Temp->processId = head->processId;
						vm6Temp->arrivalTime = head->arrivalTime;
						vm6Temp->burstTime = head->burstTime;
						head=head->next;
						counter++;	
					}
				}
				flagConfig6 = 0;
			}
		}
	}
	
	
	if(config == 3)
	{
				while(head != NULL)
		{
			if(counter > 5)
				counter = 1;
			
			if(counter == 1)
			{
				
				if(flagConfig1 == 1)
				{
					if(head == NULL)
						break;
					else
					{
						printf("Allocating process id %d to vm %d.... \n", head->processId, counter);
						vm1Temp->processId = head->processId;
						vm1Temp->arrivalTime = head->arrivalTime;
						vm1Temp->burstTime = head->burstTime;
						head=head->next;
						counter++;
					}
				}
				else
				{
					
					if(head == NULL)
						break;
						
					else
					{
						printf("Allocating process id %d to vm %d.... \n", head->processId, counter);
						vm1Temp->next = nodeCreation();
						vm1Temp = vm1Temp->next;
						vm1Temp->processId = head->processId;
						vm1Temp->arrivalTime = head->arrivalTime;
						vm1Temp->burstTime = head->burstTime;
						head=head->next;
						counter++;
					}
				}
				flagConfig1 = 0;
			}
			
			if(counter == 2)
			{
				
				if(flagConfig2 == 1)
				{
					if(head == NULL)
						break;
					else
					{
						printf("Allocating process id %d to vm %d.... \n", head->processId, counter);	
						vm2Temp->processId = head->processId;
						vm2Temp->arrivalTime = head->arrivalTime;
						vm2Temp->burstTime = head->burstTime;
						head=head->next;
						counter++;
					}
				}
				else
				{
					if(head == NULL)
						break;
					else
					{
						printf("Allocating process id %d to vm %d.... \n", head->processId, counter);		
						vm2Temp->next = nodeCreation();
						vm2Temp = vm2Temp->next;
						vm2Temp->processId = head->processId;
						vm2Temp->arrivalTime = head->arrivalTime;
						vm2Temp->burstTime = head->burstTime;
						head=head->next;
						counter++;
					}	
				}
				flagConfig2 = 0;
			}
			
			if(counter == 3)
			{
				
				if(flagConfig3 == 1)
				{
					if(head == NULL)
						break;
					else
					{
						printf("Allocating process id %d to vm %d.... \n", head->processId, counter);
						vm3Temp->processId = head->processId;
						vm3Temp->arrivalTime = head->arrivalTime;
						vm3Temp->burstTime = head->burstTime;
						head=head->next;
						counter++;
					}
				}
				else
				{
					
					if(head == NULL)
						break;
						
					else
					{
						
						printf("Allocating process id %d to vm %d.... \n", head->processId, counter);
						vm3Temp->next = nodeCreation();
						vm3Temp = vm3Temp->next;
						vm3Temp->processId = head->processId;
						vm3Temp->arrivalTime = head->arrivalTime;
						vm3Temp->burstTime = head->burstTime;
						head=head->next;
						counter++;	
					}
				}
				flagConfig3 = 0;
			}
			
			if(counter == 4)
			{
				
				if(flagConfig4 == 1)
				{
					if(head == NULL)
						break;
					else
					{
						printf("Allocating process id %d to vm %d.... \n", head->processId, counter);
						vm4Temp->processId = head->processId;
						vm4Temp->arrivalTime = head->arrivalTime;
						vm4Temp->burstTime = head->burstTime;
						head=head->next;
						counter++;
					}
				}
				else
				{
					
					if(head == NULL)
						break;	
					else
					{
						
						printf("Allocating process id %d to vm %d.... \n", head->processId, counter);
						vm4Temp->next = nodeCreation();
						vm4Temp = vm4Temp->next;
						vm4Temp->processId = head->processId;
						vm4Temp->arrivalTime = head->arrivalTime;
						vm4Temp->burstTime = head->burstTime;
						head=head->next;
						counter++;	
					}
				}
				flagConfig4 = 0;
			}
			
			if(counter == 5)
			{
				
				if(flagConfig5 == 1)
				{
					if(head == NULL)
						break;
					else
					{
						printf("Allocating process id %d to vm %d.... \n", head->processId, counter);
						vm5Temp->processId = head->processId;
						vm5Temp->arrivalTime = head->arrivalTime;
						vm5Temp->burstTime = head->burstTime;
						head=head->next;
						counter++;
					}
				}
				else
				{
					
					if(head == NULL)
						break;	
					else
					{
						
						printf("Allocating process id %d to vm %d.... \n", head->processId, counter);
						vm5Temp->next = nodeCreation();
						vm5Temp = vm5Temp->next;
						vm5Temp->processId = head->processId;
						vm5Temp->arrivalTime = head->arrivalTime;
						vm5Temp->burstTime = head->burstTime;
						head=head->next;
						counter++;	
					}
				}
				flagConfig5 = 0;
			}
		}
	}
}

/*
void findWaitingTime()  
{    
    waiting_Time[0] = 0;  
    for (i = 1; i < count ; i++ )  
        waiting_Time[i] =  burst_Time[i-1] + waiting_Time[i-1] ;  
} 

void findTurnAroundTime()  
{  
    for (i = 0; i < count ; i++)  
        turn_AroundTime[i] = burst_Time[i] + waiting_Time[i];  
}  

void findavgTime() 
{ 
    findWaitingTime();  
    findTurnAroundTime(); 
    float total_wt = 0, total_tat = 0; 
    for (i = 0 ; i < count ; i++) 
    { 
        total_wt = total_wt + waiting_Time[i]; 
        total_tat = total_tat + turn_AroundTime[i]; 
        int compl_time = turn_AroundTime[i] + arrival_Time[i]; 
        printf("Completion time %d", compl_time); 
    } 
    prinf("Average waiting time =  %d \n",  total_wt / count );
	printf("Average turn around time = %d \n", total_tat / count );
} */

