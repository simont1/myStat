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

/* char * return_permissions(char * start, char * data_perms){ */
/*   if(start > 0){ */
/*     if(data_perm[3] % 2 == 1){ */
/*       perms[3] = "x"; */
/*     } */
/*     else{ */
/*       if(*(start-1) >= 2){ */
/* 	perms[2] = "w"; */
/*       } */
/*       else{ */
/* 	perms[2] = "-"; */
/*       } */
/*       if(data_perm[3] >= 4){ */
/* 	perms[1] = "r"; */
/*       } */
/*       else{ */
/* 	perms[1] = "-"; */
/*       } */
/*     } */
/*   } */
/*   else{ */
/*     perms[1] = '-'; */
/*     perms[2] = '-'; */
/*     perms[3] = '-'; */
/*   } */
/* } */


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
  printf("%d B\n", sprintf(test, "%s", str));
  printf("%d KB\n", sprintf(test, "%s", str)/1000);
  printf("%d MB\n", sprintf(test, "%s", str)/1000000);
  printf("%d GB\n", sprintf(test, "%s", str)/1000000000);

  //printf("File size (Human Readable): %lu\n", num); //sizeof(test));
  //printf("Permissions: %mode_t\n", data->mode_t); //sizeof(test));
}
