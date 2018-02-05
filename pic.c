#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(){
  char buf[256];
  int r,g,b;
  int fd =open("picmaker.ppm",O_CREAT|O_WRONLY,0644);
  write(fd,"P3\n500 500\n255\n", strlen("P3\n500 500\n255\n")); 
  int w, h;
  for (w  = 0; w < 500; w++)
    for (h=0; h < 500; h++) {
      r =  w % 256;
      g = h/2;
      b = w/2;
      sprintf(buf,"%d %d %d ", r, g, b);
      write(fd, buf, strlen(buf));
    }
  close(fd);
  return 0;
}

  
  
    
