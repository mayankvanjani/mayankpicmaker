#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {

  int x = open( "pic.ppm", O_CREAT | O_TRUNC | O_WRONLY, 0644);
  int r, g, b;
  int i, j, z;

  char * header = "P3 500 500 255\n";
  write ( x, header, strlen(header));
  //  for ( z = 0; z < 256; z++) {
  for ( i = 0; i < 500; i++ ) {
    z++;
    for ( j = 0; j < 500; j++ ) {
      char * line = (char *)malloc(6);
      r = (z * z) % 256;
      g = (i * i) % (256);
      b = (j * j) % (256);
      sprintf( line, "%d %d %d\n", r, g, b);
      //      printf("%s\n", line); 
      write ( x, line, strlen(line));
    }
  }
  //}
  return 0;
}
