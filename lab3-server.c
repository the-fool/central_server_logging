#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#define NUMBER_CLIENTS 4

char *readline(int fd);

int main(int argc, char *argv[])
{
  if (argc != 2) {
    fprintf(stderr, "Usage: lab3 <filenam>\n");
    return EXIT_FAILURE;
  }
  
  int i;
  pid_t pid;
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
