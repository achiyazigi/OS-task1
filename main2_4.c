#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int pid = fork();
    if(pid == 0){
        execl("./main2_1", "main2_1", "-c", 0,(char*)0);
    }
    else if(pid > 0){
        pid = fork();
        if(pid == 0){
            execl("./main2_2", "main2_2", "-c", 0,(char*)0);
        }
        else if(pid > 0){
            pid = fork();
            if(pid == 0){
                execl("./main2_3", "main2_3", "-c", 0,(char*)0);
            }
            else{
                sleep(1);
                char pid[10];
                sprintf(pid, "%d", getppid());
                execl("/bin/pstree", "pstree", "-c", pid, (char*)0);
            }
        }
    }
    return 0;
}