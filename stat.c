#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>

void text(){
  char * line = "hello world";
  char * file1 = "test.txt";
  int fd = open(file1, O_RDWR|O_CREAT, 0666);
  write(fd, line, sizeof(line));
  close(fd);
}

int main(){
  text();
  struct stat *data = malloc(sizeof(struct stat));
  stat("test.txt", data);
  // char *place = ctime(&data->st_size);
  printf("File size: %lld\n", data->st_size);
  printf("File permissions: %o\n", data->st_mode);
  printf("File last accessed: %s\n", ctime(&(data->st_atime)));
}
