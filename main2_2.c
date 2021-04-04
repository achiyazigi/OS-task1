#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

#define STACK_SIZE 10000

char child_stack[STACK_SIZE + 1];

void print(){
    for (int i = 0; i < 10; ++i)
    {
        // printf("still running\n");
        usleep(1000000);
    }
}

int child(void *params)
{
    print();
    
    return 0;
}

int main()
{

    int result = clone(child, child_stack + STACK_SIZE, CLONE_PARENT, 0);
    int result2 = clone(child, child_stack + STACK_SIZE, CLONE_PARENT, 0);
    print();    
    return 0;
}