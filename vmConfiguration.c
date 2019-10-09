#include<stdio.h>
#include<stdlib.h>
#include <time.h>

#define CPS 2.5
#define CPI 6
//global variable for looping purpose
int i, config;
int count = 0;
int numberOfTasks;

// calculating MIPS for the processor
float ps = (CPS/CPI)*(10000);// 10^10/10^6=10^4

//definig properties of the Virtual Machines 
typedef struct Vm
{
	int processId;
	float arrivalTime;
	//float burstTime;
	float instruction;
	struct Vm *next;
}Vm;

Vm *vm1Head = NULL, *vm2Head = NULL, *vm3Head = NULL, *vm4Head = NULL, *vm5Head = NULL, *vm6Head = NULL; 
Vm *vm1Temp = NULL, *vm2Temp = NULL, *vm3Temp = NULL, *vm4Temp = NULL, *vm5Temp = NULL, *vm6Temp = NULL;

//defining parameters for the task
typedef struct task
{
	int processId;
	float arrivalTime;
	//float burstTime;
    float instruction;
	struct task *next;
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
void CalculateCPUTime(task * head);						//to calcute the CPU execution time 
void CalculateCPUTimeVM(Vm * head);                     // To calcute the CPU execution on individual VM 
int main()
{

	
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
	sortFCFS(taskCreationHead);				//Sorting the queue of the tasks on the basis of the arrival time for implementing FCFS
	CalculateCPUTime(taskCreationHead);									
	//calcualtionForFCFS(taskCreationHead);										//Filling the enteries in an array from the linked list for the calculations
	taskAllocationToVM(taskCreationHead);										//Allocating task to the Vm ans 
	
	printf("The process that need to be schedued are \n");
	displayTasksScheduled(taskCreationHead);
	
	if(config == 1)
	{
		printf("The process allocated to vm1 ");
		for (i = 0; i < 3; i++) 
		{ 
        	delay(1); 
        	printf("."); 
    	} 
    	printf("\n");
		displayTasksVMScheduled(vm1Head);
		CalculateCPUTimeVM(vm1Head);	
		
		printf("The process allocated to vm2 ");
		for (i = 0; i < 3; i++) 
		{ 
        	delay(1); 
        	printf("."); 
    	} 
    	printf("\n");
		displayTasksVMScheduled(vm2Head);
		CalculateCPUTimeVM(vm2Head);
		
		printf("The process allocated to vm3 ");
		for (i = 0; i < 3; i++) 
		{ 
        	delay(1); 
        	printf("."); 
    	} 
    	printf("\n");
		displayTasksVMScheduled(vm3Head);
		CalculateCPUTimeVM(vm3Head);
	}
	
	if(config == 2)
	{
		printf("The process allocated to vm1 ");
		for (i = 0; i < 3; i++) 
		{ 
        	delay(1); 
        	printf("."); 
    	} 
    	printf("\n");
		displayTasksVMScheduled(vm1Head);
		
		
		printf("The process allocated to vm2 ");
		for (i = 0; i < 3; i++) 
		{ 
        	delay(1); 
        	printf("."); 
    	} 
    	printf("\n");
		displayTasksVMScheduled(vm2Head);
		
		
		printf("The process allocated to vm3 ");
		for (i = 0; i < 3; i++) 
		{ 
        	delay(1); 
        	printf("."); 
    	} 
    	printf("\n");
		displayTasksVMScheduled(vm3Head);
		
		
		printf("The process allocated to vm4 ");
		for (i = 0; i < 3; i++) 
		{ 
        	delay(1); 
        	printf("."); 
    	} 
    	printf("\n");
		displayTasksVMScheduled(vm4Head);
		
		
		printf("The process allocated to vm5 ");
		for (i = 0; i < 3; i++) 
		{ 
        	delay(1); 
        	printf("."); 
    	} 
    	printf("\n");
		displayTasksVMScheduled(vm5Head);
		
		
		printf("The process allocated to vm6 ");
		for (i = 0; i < 3; i++) 
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
		for (i = 0; i < 3; i++) 
		{ 
        	delay(1); 
        	printf("."); 
    	} 
    	printf("\n");
		displayTasksVMScheduled(vm1Head);
		
		printf("The process allocated to vm2 ");
		for (i = 0; i < 3; i++) 
		{ 
        	delay(1); 
        	printf("."); 
    	} 
    	printf("\n");
		displayTasksVMScheduled(vm2Head);
		
		printf("The process allocated to vm3 ");
		for (i = 0; i < 3; i++) 
		{ 
        	delay(1); 
        	printf("."); 
    	} 
    	printf("\n");
		displayTasksVMScheduled(vm3Head);
		
		printf("The process allocated to vm4 ");
		for (i = 0; i < 3; i++) 
		{ 
        	delay(1); 
        	printf("."); 
    	} 
    	printf("\n");
		displayTasksVMScheduled(vm4Head);
		
		printf("The process allocated to vm5 ");
		for (i = 0; i < 3; i++) 
		{ 
        	delay(1); 
        	printf("."); 
    	} 
    	printf("\n");
		displayTasksVMScheduled(vm5Head);
	}
	return 0;
}

// to calcuate CPU Time 
void CalculateCPUTime(task * head)
{
	float CPU_Time_sum=0;
	float CPU_Time=0;
	int i =1;
	task * temp = head;
	//printf("Task Allocated to VM i\n");
	if(temp == NULL )
	{
		
	}
	else
	{
		while(temp!=NULL)
		{
			CPU_Time = temp->instruction/ps;
			CPU_Time_sum+=CPU_Time;
			printf("%0.3f sec for task %d\n",CPU_Time,i);
			++i;
			temp=temp->next;
		}
		printf("%0.3f sec for completion of all tasks.\n",CPU_Time_sum);
	}
}

// to compute CPU time of individual VM
void CalculateCPUTimeVM(Vm * head)
{
    float CPU_Time_sum=0;
	float CPU_Time=0;
	int i =1;
	Vm * temp = head;
	//printf("Task Allocated to VM \n");
	if(temp == NULL )
	{
		
	}
	else
	{
		while(temp!=NULL)
		{
			CPU_Time = temp->instruction/ps;
			CPU_Time_sum+=CPU_Time;
			printf("%0.3f sec for task %d\n",CPU_Time,i);
			++i;
			temp=temp->next;
		}
		printf("%0.3f sec for completion \n",CPU_Time_sum);
	}
	
}

void vmCreation(int config)
{
	// Setting up the virtual machines
	switch(config)
	{
		case 1: 
		{
			if(numberOfTasks == 1)
			{
				printf("1 virtual machines are up now \n");
				vm1Head = vm1Temp = nodeCreation();
			}
			else if(numberOfTasks == 2)
			{
				printf("2 virtual machines are up now \n");
				vm1Head = vm1Temp = nodeCreation();
				vm2Head = vm2Temp = nodeCreation();
			}
			else
			{
				vm1Head = vm1Temp = nodeCreation();
				vm2Head = vm2Temp = nodeCreation();
				vm3Head = vm3Temp = nodeCreation();
				printf("3 virtual machines are up now \n");
			}
			break;
		}
		case 2:
		{
			if(numberOfTasks == 1)
			{
				printf("1 virtual machines are up now \n");
				vm1Head = vm1Temp = nodeCreation();
			}
			else if(numberOfTasks == 2)
			{
				printf("2 virtual machines are up now \n");
				vm1Head = vm1Temp = nodeCreation();
				vm2Head = vm2Temp = nodeCreation();
			}
			else if(numberOfTasks == 3)
			{
				printf("3 virtual machines are up now \n");
				vm1Head = vm1Temp = nodeCreation();
				vm2Head = vm2Temp = nodeCreation();
				vm3Head = vm3Temp = nodeCreation();	
			}
			else if(numberOfTasks == 4)
			{
				printf("4 virtual machines are up now \n");
				vm1Head = vm1Temp = nodeCreation();
				vm2Head = vm2Temp = nodeCreation();
				vm3Head = vm3Temp = nodeCreation();
				vm4Head = vm4Temp = nodeCreation();
			}
			else if(numberOfTasks == 5)
			{
				printf("5 virtual machines are up now \n");
				vm1Head = vm1Temp = nodeCreation();
				vm2Head = vm2Temp = nodeCreation();
				vm3Head = vm3Temp = nodeCreation();
				vm4Head = vm4Temp = nodeCreation();
				vm5Head = vm5Temp = nodeCreation();
			}
			else
			{
				printf("6 virtual machines are up now \n");
				vm1Head = vm1Temp = nodeCreation();
				vm2Head = vm2Temp = nodeCreation();
				vm3Head = vm3Temp = nodeCreation();				
				vm4Head = vm4Temp = nodeCreation();
				vm5Head = vm5Temp = nodeCreation();
				vm6Head = vm6Temp = nodeCreation();

			}
			break;
		}
		case 3:
		{
			if(numberOfTasks == 1)
			{
				printf("1 virtual machines are up now \n");
				vm1Head = vm1Temp = nodeCreation();
			}
			else if(numberOfTasks == 2)
			{
				printf("2 virtual machines are up now \n");
				vm1Head = vm1Temp = nodeCreation();
				vm2Head = vm2Temp = nodeCreation();
			}
			else if(numberOfTasks == 3)
			{
				printf("3 virtual machines are up now \n");
				vm1Head = vm1Temp = nodeCreation();
				vm2Head = vm2Temp = nodeCreation();
				vm3Head = vm3Temp = nodeCreation();	
			}
			else if(numberOfTasks == 4)
			{
				printf("4 virtual machines are up now \n");
				vm1Head = vm1Temp = nodeCreation();
				vm2Head = vm2Temp = nodeCreation();
				vm3Head = vm3Temp = nodeCreation();
				vm4Head = vm4Temp = nodeCreation();
			}
			else
			{
				printf("5 virtual machines are up now \n");
				vm1Head = vm1Temp = nodeCreation();
				vm2Head = vm2Temp = nodeCreation();
				vm3Head = vm3Temp = nodeCreation();
				vm4Head = vm4Temp = nodeCreation();
				vm5Head = vm5Temp = nodeCreation();
			}
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
		printf("Enter the instructions (in MI)\n");
		scanf("%f", &temp2->instruction);
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
	if(head == NULL)
	{
		printf("No task allocated \n");
	}
	else
	{
		printf("Process Id  Arrival Time \n");
		while(head != NULL)
		{
			printf("   %d        %2f     \n", head->processId, head->arrivalTime);
			head = head->next;
		}
	}
}


void displayTasksVMScheduled(Vm *head)
{
	if(head == NULL)
	{
		printf("No task allocated \n");
	}
	else
	{
		printf("Process Id  Arrival Time  \n");
		while(head != NULL)
		{
			printf("   %d        %2f      \n", head->processId, head->arrivalTime);
			head = head->next;
		}
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
				
				swap = i->processId;
				i->processId = j->processId;
				j->processId = swap;
			}
		}
	}
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
						//vm1Temp->burstTime = head->burstTime;
						vm1Temp->instruction = head->instruction;
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
						//vm1Temp->burstTime = head->burstTime;
						vm1Temp->instruction = head->instruction;
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
					//	vm2Temp->burstTime = head->burstTime;
						vm2Temp->instruction = head->instruction;
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
					//	vm2Temp->burstTime = head->burstTime;
						vm2Temp->instruction = head->instruction;
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
					//	vm3Temp->burstTime = head->burstTime;
						vm3Temp->instruction = head->instruction;
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
					//	vm3Temp->burstTime = head->burstTime;
						vm3Temp->instruction = head->instruction;
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
					//	vm1Temp->burstTime = head->burstTime;
						vm1Temp->instruction = head->instruction;
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
					//	vm1Temp->burstTime = head->burstTime;
						vm1Temp->instruction = head->instruction;
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
					//	vm2Temp->burstTime = head->burstTime;
						vm2Temp->instruction = head->instruction;
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
					//	vm2Temp->burstTime = head->burstTime;
						vm2Temp->instruction = head->instruction;
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
					//	vm3Temp->burstTime = head->burstTime;
						vm3Temp->instruction = head->instruction;
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
					//	vm3Temp->burstTime = head->burstTime;
						vm3Temp->instruction = head->instruction;
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
					//	vm4Temp->burstTime = head->burstTime;
						vm4Temp->instruction = head->instruction;
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
					//	vm4Temp->burstTime = head->burstTime;
						vm4Temp->instruction = head->instruction;
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
					//	vm5Temp->burstTime = head->burstTime;
						vm5Temp->instruction = head->instruction;
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
					//	vm5Temp->burstTime = head->burstTime;
						vm5Temp->instruction = head->instruction;
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
					//	vm6Temp->burstTime = head->burstTime;
						vm6Temp->instruction = head->instruction;
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
					//	vm6Temp->burstTime = head->burstTime;
						vm6Temp->instruction = head->instruction;
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
					//	vm1Temp->burstTime = head->burstTime;
						vm1Temp->instruction = head->instruction;
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
					//	vm1Temp->burstTime = head->burstTime;
						vm1Temp->instruction = head->instruction;
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
					//	vm2Temp->burstTime = head->burstTime;
						vm2Temp->instruction = head->instruction;
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
					//	vm2Temp->burstTime = head->burstTime;
						vm2Temp->instruction = head->instruction;
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
					//	vm3Temp->burstTime = head->burstTime;
						vm3Temp->instruction = head->instruction;
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
					//	vm3Temp->burstTime = head->burstTime;
						vm3Temp->instruction = head->instruction;
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
					//	vm4Temp->burstTime = head->burstTime;
						vm4Temp->instruction = head->instruction;
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
					//	vm4Temp->burstTime = head->burstTime;
						vm4Temp->instruction = head->instruction;
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
					//	vm5Temp->burstTime = head->burstTime;
						vm5Temp->instruction = head->instruction;
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
					//	vm5Temp->burstTime = head->burstTime;
						vm5Temp->instruction = head->instruction;
						head=head->next;
						counter++;	
					}
				}
				flagConfig5 = 0;
			}
		}
	}
}


