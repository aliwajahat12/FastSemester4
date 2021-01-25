#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>

int main(){
    long int s= syscall(335);
    printf("System Call .: sys_helloworld :. returned %1d \n",s);
    return 0;
}