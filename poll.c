#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <poll.h>
#define FD_MAX (100)
int main(int argc, char **argv)
{
  struct pollfd pollFd[FD_MAX] = {0};
  int ret;
  pollFd[0].fd = 0;
  pollFd[0].events = POLLIN;
  for (;;)
  {
    ret = poll(pollFd, 1, 2000);
    if (ret < 0)
    {
      printf("poll error");
      continue;
    }
    if (ret == 0)
    {
      printf("poll timeout!\n");
      continue;
    }
    if (pollFd[0].revents == POLLIN)
    {
      char buf[1024] = {0};
      read(pollFd[0].fd, buf, sizeof(buf) - 1);
      printf("sdin:%s", buf);
    }
  }
  return 0;
}
