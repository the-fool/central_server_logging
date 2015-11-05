#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define MSG_BUF 120

int main(int argc, char *argv[])
{
  int fd;
  char msg[MSG_BUF + 1];

  sscanf(argv[1], "%d", &fd);
  
  return EXIT_SUCCESS;
}
