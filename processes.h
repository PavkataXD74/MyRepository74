#ifndef PROCESSES_H
#define PROCESSES_H


typedef struct{
    int ID;
    char name[30];
}Processes;


static int NextProcessID(Processes CurrentProcess);
int CreateNewProcess(char *name);
void StopProcess(int ProcessNumber);

#endif