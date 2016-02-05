#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {

  int x = open( "pic.ppm", O_CREAT | O_TRUNC | O_WRONLY, 0644);
  int r, g, b, i, j;

  char * header = "P3 500 500 255\n";
  write ( x, header, strlen(header));
  //  system("cat pic.ppm");
  for ( i = 0; i < 256; i++ ) {
    for ( j = 0; j < 256; j++ ) {
      char * line = (char *)malloc(6);
      r = 255;
      g = i % 256;
      b = j % 256;
      sprintf( line, "%d %d %d\n", r, g, b); 
      //      printf("%s\n", line);
      write ( x, line, strlen(line));
    }
  }
  close( x );
  
  return 0;
}
