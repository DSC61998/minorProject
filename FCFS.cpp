#include <stdio.h>
#include <malloc.h>

struct process{
  int atime,btime,wtime,ctime,tat,btemp;
  struct process* link;
} *fcfs=NULL;
typedef struct process process;

void initialise(process *temp, process p)
{
    temp->atime = p.atime;
    temp->btime = p.btime;
}

void insert(process p)
{
    if (fcfs == NULL)
     {
         process* temp = (process*)malloc(sizeof(process));
         initialise(temp, p);
         temp->link = NULL;
         fcfs = temp;
         return;
     }

    process* temp = fcfs,*last=NULL;
    process* next = NULL;
    while (temp!=NULL && (temp->atime < p.atime))
    {
        if (temp->link!=NULL && temp->link->atime > p.atime)
        {
         next = temp->link;
         last = temp;
         break;
        }
       last = temp;
       temp = temp->link;
    }
    process* temp2 = (process*)malloc(sizeof(process));
    initialise(temp2, p);
    temp2->link = next;
     if(last == NULL)
     {
      temp2->link = fcfs;
      fcfs = temp2;
     }
     else
      last->link = temp2;

}

void execute()
{
  int t=0;
  process* temp = fcfs;

  while(temp!=NULL)
  {
    if (temp->atime <= t)
    {
     t += temp->btime;
     temp->ctime = t;
     temp->tat = temp->ctime - temp->atime;
     temp->wtime = temp->tat - temp->btime;
    }
    else
    {
     t++;
     continue;
    }

    temp = temp->link;
  }
}

void showResults()
{
    process* temp = fcfs;
    printf("AT   BT   CT   TAT   WT\n");
    while(temp!=NULL)
    {
     printf("%d     %d    %d    %d    %d\n", temp->atime, temp->btime, temp->ctime, temp->tat, temp->wtime);
     temp = temp->link;
    }
}

float avgwtime()
{
    int w = 0,count=0;
    process* temp = fcfs;
    while(temp!=NULL)
    {
        w += temp->wtime;
        temp = temp->link;
        count++;
    }
    return (float)w/count;
}

float avgtat()
{
    int tat = 0,count=0;
    process* temp = fcfs;
    while(temp!=NULL)
    {
        tat += temp->tat;
        temp = temp->link;
        count++;
    }
    return (float)tat/count;
}

int main()
{
int n,i;
printf("Enter the no. of Processes : ");
scanf("%d",&n);
process p;
for(i=0; i<n; i++)
{
 printf("Enter arrival time of Process %d : ", i+1);
 scanf("%d",&p.atime);
 printf("Enter Burst time of Process %d : ", i+1);
 scanf("%d",&p.btime);
 insert(p);
}
execute();
showResults();
printf("Avg. Waiting Time : %.2f\n", avgwtime());
printf("Avg TAT : %.2f\n",avgtat());
return 0;
}

