#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define MSG_BUF 120

int main(int argc, char *argv[])
{
  int fd, nmsg, slp;
  char msg[MSG_BUF + 1];

  sscanf(argv[1], "%d", &fd);
  sscanf(argv[2], "%d", &nmsg);
  sscanf(argv[3], "%d", &slp);
  
  return EXIT_SUCCESS;
}
