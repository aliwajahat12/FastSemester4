#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 27

void die(char *str) {
	perror(str);
	exit(1);
}

int main(void) {
	char c;
	int shmid;
	key_t keya;
	char *shma, *s;

	keya = 410;
	
	if((shmid = shmget(keya, MAXSIZE, IPC_CREAT | 0666)) < 0)
		die("shmget");
	if((shma = shmat(shmid, NULL, 0)) == (char*) -1)
		die("shmat");
	
	printf(" 0 ");
	*shma='0';

	// sleep(1);
	// putchar(*shma);

	// s = shm;
	// for(c = 'a'; c <= 'z'; c++) 
	// 	*s++ = c;

	while(*shma != '*')
		sleep(1);

	exit(0);
}

