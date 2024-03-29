#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
 
int
main(int argc, char *argv[])
{
  char buf[512];
  int fd, dfd, r;
  char *src;
  char *dest;
 
  if(argc != 3){
    printf(2, "Usage: cp src dest\n");
    exit();
  }
 
  src = argv[1];
  dest = argv[2];
 
  if ((fd = open(src, O_RDONLY)) < 0) {
    printf(2, "cp: cannot open source %s\n", src);
    exit();
  }
 
  struct stat st;
    fstat(fd, &st);
    if (st.type == T_DIR)
    {
        printf(1, "cp: cannot copy a directory %s\n", src);
        exit();
    }
 
 
  if ((dfd = open(dest, O_CREATE|O_WRONLY)) < 0) {
    printf(2, "cp: cannot open destination %s\n", dest);
    exit();
  }
   
  while ((r = read(fd, buf, sizeof(buf))) > 0) {
    write(dfd, buf, r);
  }
   
 
  close(fd);
  close(dfd);
 
  exit();
}