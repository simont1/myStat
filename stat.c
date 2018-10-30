#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>

void text(){
  char * line = "hello worlds";
  char * file1 = "test.txt";
  int fd = open(file1, O_RDWR|O_CREAT, 0666);
  write(fd, line, sizeof(line));
  close(fd);
}



int main(){
  //text();
  struct stat *data = malloc(sizeof(struct stat));
  stat("test.txt", data);
  char * file1 = "test.txt";
  int fd = open(file1, O_RDWR);
  char str[256];
  int num = read(fd, str, sizeof(str));
  close(fd);

 
  
  // char *place = ctime(&data->st_size);
  printf("File size: %lld\n", data->st_size);
  int perm = data->st_mode;
  printf("File permissions: extra output: %o, ONLY_PERM output: %o\n", perm, perm & (S_IRWXU | S_IRWXG | S_IRWXO));
  printf("File last accessed: %s\n", ctime(&(data->st_atime)));

  
  char test[256];
  printf("Sizes:\n");
  printf("%.1f B\n", sprintf(test, "%s", str)/1.0);
  printf("%.3f KB\n", sprintf(test, "%s", str)/1000.0);
  printf("%.6f MB\n", sprintf(test, "%s", str)/1000000.0);
  printf("%.9f GB\n", sprintf(test, "%s", str)/1000000000.0);

  //printf("Permissions: %o\n", data->st_mode); //sizeof(test));
}
