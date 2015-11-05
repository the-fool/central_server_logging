#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#define NUMBER_CLIENTS 4
#define MSG_BUF 120

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
      case 0:
	printf("Child %d\n", getpid());
	break;
      }
    if (pid == 0) break;
  }
  
  return 0;

}
