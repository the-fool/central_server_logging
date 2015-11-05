#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#define NUMBER_CLIENTS 4
#define MSG_BUF 120
#define N_MSG 6
#define MAX_SLP 2

char *readline(int fd);

int main(int argc, char *argv[])
{
  int pfd[2], i, ret;
  char msg[MSG_BUF];
  pid_t pid;

  if (argc != 2) {
    fprintf(stderr, "Usage: lab3 <filenam>\n");
    return EXIT_FAILURE;
  }
  
  if (pipe(pfd) != 0) {
    perror("Error creating pipe");
    return EXIT_FAILURE;
  }
  
  for (i = 0; i < NUMBER_CLIENTS; i++) {
    switch (pid = fork()) 
      {
      case -1:
	perror("Error creating child");
	return EXIT_FAILURE;
      case 0: ;
	char fd[3], slp[3], nmsg[3];
	sprintf(fd, "%d", pfd[1]);
	sprintf(slp, "%d", MAX_SLP);
	sprintf(nmsg, "%d", N_MSG);
       
	execl("client", "client", fd, nmsg, slp, (char *)NULL);
	exit(EXIT_FAILURE);
      }
    if (pid == 0) break;
  }
  
  return 0;

}
