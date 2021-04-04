#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <syslog.h>

int main(){
    int pid = fork();
    if(pid == 0){
        chdir("/");
        setsid();
        // printf("start deamon\n");
        fclose(stdout);
        fclose(stdin);
        fclose(stderr);
        openlog("myDeamon", LOG_PID, LOG_DAEMON);
        syslog(LOG_NOTICE, "Deamon started");
        sleep(3);
        syslog(LOG_NOTICE, "doing somthing");
        sleep(3);
        syslog(LOG_NOTICE, "Deamon finished");
        sleep(10);
    }
    else{
        // printf("%d\n", pid);
    }
    exit(0);
}