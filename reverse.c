#include "file_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
int size;
char* buffer;
char* f1;
char* f2;
 f1= argv[1];
 f2= argv[2];
//used to read a file, size of file is returned.
size=read_file(f1, &buffer);
//used to write a file in reverse
write_file(f2, buffer, size);
//returns allocated memory
free(buffer);
return 0;
}
