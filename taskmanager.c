#include<stdio.h>
#include<string.h>
#include"processes.h"

extern int processesCount;
extern  Processes processes[5];

int main(){
  int flag=1;
  while(flag==1){
    int op;do{
    printf("1.Create a process\n");
    printf("2.List current processes\n");
    printf("3.Stop a process\n");
    printf("4.Exit program\n");
    scanf("%d",&op);
      }while(op>4||op<1);
    switch(op){
      case 1:{
        char name[30];
        printf("What is the name of your process?:\n");
        scanf("%s",name);
        int currentProcess=CreateNewProcess(*name);
        if(currentProcess==0){
          printf("Creation is not successful!");
        }else{
          printf("A process was created on %d position.",currentProcess);
        }
          break;
      }
      case 2:{
        for(int i=0;i<processesCount;i++){
          printf("%d %s\n",processes[i].ID,processes[i].name);
        }
        break;
      }
      case 3:{
        int processNumber;
        printf("Which process do you want to stop(position)?:\n");
        scanf("%d",&processNumber);
        StopProcess(processNumber);
        break;
      }
      case 4:{
        flag=0;
        break;
      }
        
        
    }
  }
  return 0;
}