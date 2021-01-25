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
	int shmid;
	key_t key;
	char *shm, *s;

	key = 2222;
	fflush(stdin);
	if((shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666)) < 0)
		die("shmget");
	if((shm = shmat(shmid, NULL, 0)) == (char*) -1)
		die("shmat");
	
	
	int num = *shm-'0';
	// printf(num);
	s = shm;
	*s++ = 'r';
	*s++ = 'e';
	*s++ = 'a';
	*s++ = 'd';
	*s++ = 'y';
	
	while(*shm != '*')
		sleep(1);

	for (int i=0;i<10;i++)	
	printf("%d\n",num*i);
	
	exit(0);
}