#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(){
  char buf[256];
  int r,g,b;
  r = 139;
  g = 0;
  b = 139;
  int fd =open("picmaker.ppm",O_CREAT|O_WRONLY,0644);
  write(fd,"P3\n500 500\n139\n", strlen("P3\n500 500\n255\n")); 
  int w = 0, h = 0;
  while(h < 500){
    w=0;
    while(w < 500){
      if(g == 255){
	g = 0;
      }
      else{
	g++;
      }
      sprintf(buf,"%d %d %d\n",r,g,b);
      write(fd,buf,strlen(buf));
      w++;
    }
    h++;
  }
  close(fd);
  return 0;
}

  
  
    
