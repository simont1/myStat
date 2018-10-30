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


char * get_permissions(char digit){
  char * num = malloc(sizeof(char)*3);
  num[0] = '-';
  num[1] = '-';
  num[2] = '-';

  int x = digit - '0';
  
  if(x % 2 == 1){
    num[2] = 'x';
    x-=1;
  }

  if(x == 2){
    x-=2;
    num[1] = 'w';
  }

  if(x == 4){
    x-=4;
    num[0] = 'r';
  }
  
  
  x-=2;
  if(x >= 0){
    num[1] = 'w';
  }
  
  x-=4;
  if(x >= 0){
    num[0] = 'r';
  }

  return num;
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

  char permm[7];
  sprintf(permm,"%o", perm);
  char *point = permm;
  point += 3;

  /* char *user_p = get_permissions(*point); */
  /* point++; */
  /* char *group_p = get_permissions(*point); */
  /* point++; */
  /* char *everyone_p = get_permissions(*point); */

  char *user_p = get_permissions('1');
  point++;
  char *group_p = get_permissions('6');
  point++;
  char *everyone_p = get_permissions('7');

  char * res = strcat(user_p, group_p);

  res = strcat(res, everyone_p);

  
  printf("Permissions: %s\n", res); //sizeof(test));
}
