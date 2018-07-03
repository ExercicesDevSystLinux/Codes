/********************************
 * Fichier famille_wait3.c
 * Livre "Exercices corrigés de développement système sous Linux"
 *
 * (c) 2018 P. Alain, J. Chevelu, V. Thion
 *
 ********************************/
#include <stdio.h>		/* stderr, stdout, fprintf, perror */
#include <unistd.h>		/* fork */
#include <sys/wait.h>		/* wait */
#include <stdlib.h>		/* exit */

int main(void)
{
	pid_t pid_fils1 = -1;
	pid_t pid_fils2 = -1;

	printf("(pid:%d, ppid:%d) Do you do you Saint-Tropez (%d) (%d)\n", getpid(), getppid(),
	       pid_fils1, pid_fils2);

	pid_fils1 = fork();

	if (pid_fils1 == 0) {
		pid_fils2 = fork();

		wait(NULL);
		printf("(pid:%d, ppid:%d) Do you do you Saint-Tropez (%d) (%d)\n", getpid(),
		       getppid(), pid_fils1, pid_fils2);
		exit(EXIT_SUCCESS);
	}

	exit(EXIT_SUCCESS);
}
