#include <stdio.h>
#include "./wiringPi.h"
#include "./wiringSerial.h"
#include <string.h>
int main(){

    int fd=serialOpen("/dev/ttyAMA0",9600);
    char send[100];
    char respone[100];
    int i=0;
    while(1)
    {

        for(i=0;i<100;i++)
            respone[i]='\0';
        scanf("%s",send);
        write(fd,send,strlen(send));
        printf("%s:%d\n",send,strlen(send));
        if(strcmp(send,"exit")==0)
            break;


        read(fd,respone,100);
        printf("%s\n",respone);

        for(i=0;i<100;i++)
            send[i]='\0';
    }

    serialClose(fd);

}
