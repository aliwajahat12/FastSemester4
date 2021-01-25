#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 27

void die(char *str)
{
	perror(str);
	exit(1);
}

int main(void)
{
	int shmid;
	key_t keya, keyb;
	char *shma, *shmb, *s;

	keya = 410;
	keyb = 411;

	fflush(stdin);
	if ((shmid = shmget(keya, MAXSIZE, IPC_CREAT | 0666)) < 0)
		die("shmget");
	if ((shma = shmat(shmid, NULL, 0)) == (char *)-1)
		die("shmat");

	if ((shmid = shmget(keyb, MAXSIZE, IPC_CREAT | 0666)) < 0)
		die("shmget");
	if ((shmb = shmat(shmid, NULL, 0)) == (char *)-1)
		die("shmat");

	int a = *shma - '0';
	int b = *shmb - '0';
	
	printf("%d %d ",a,b);
	
	for (int i = 0; i < 5; i++)
	{
		int a = *shma - '0';
		int b = *shmb - '0';
		int c = a + b;
		printf("%d ", c);
		*shma = *shmb;
		*shmb = c + '0';
	}
	*shma='*';
	*shmb='*';
	printf("\n");
	// for(s = shm; *s != '\0'; s++)
	// 	putchar(*s);

	// *shm = '*';
	// printf("\n");
	exit(0);
}
