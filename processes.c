#include <stdio.h>
#include <strings.h>
#include "processes.h"

Processes processes[5];
int processesCount=0;

static int NextProcessID(Processes CurrentProcess){
    static int NextNumber=1;
    CurrentProcess.ID=NextNumber;
    NextNumber++;

    return CurrentProcess.ID;
}

int CreateNewProcess(char *name){
    Processes NewProcess;
    if(processesCount>=5){
      printf("Stop another process to create a new one!");
      return 0;
    }
    else{
        NewProcess.ID = NextProcessID(NewProcess);
        strcpy(name, NewProcess.name);
        processes[processesCount] = NewProcess;
        processesCount++;
        return processesCount; 
    }

}

void StopProcess(int processNumber){
  if(processesCount<=0){
    printf("There are no processes currently running!");
  }
  else{
   if (processNumber >= processesCount+1)
      printf("Deletion not possible.\n");
   else
   {
      for (int i = processNumber - 1; i < processesCount - 1; i++)
         processes[i] = processes[i+1];

        processesCount--;
     printf("Deletion successful!");
   }
    
    
  }
}