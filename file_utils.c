#include "file_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

// Used site to learn how to use: fread, fopen, fwrite, fseek and fclose.
//https://www.tutorialspoint.com/c_standard_library/c_function_fread.htm
int read_file(char* filename, char **buffer) {
	//Struct used to find and store the size of the file
	struct stat st;
	stat(filename, &st);
	int size = st.st_size;
	//Allocate block of memory from the system
	*buffer = (char*)malloc(size * sizeof(char));
	//Object type suitable for storing information for a filestream
	FILE* f1;
	//opens the file passed to the function, "r"-opens file for reading.The file must exist.
	f1= fopen(filename,"r");
	//Checks if file that is passed to the function was opened
	//Prints error message if the file was not opened
	if(f1 ==NULL){
		fprintf(stderr, "First File was not read by system\n");
		return -1;
	}
	//Checks if memory was allocated
	if(*buffer == NULL){
		fprintf(stderr, "Problem with memory being allocated by system\n");
		return -2;
	}
	//Reads data from given stream(f1) into the buffer
	size =fread(*buffer, 1,  size, f1);
	//Closes stream, all buffers are flushed
	fclose(f1);
	//returns the size of the file that is passed into the first parameter
	return size;
}

int write_file(char* filename, char *buffer, int size) {
	//Object type suitable for storing information for a filestream
	FILE* f2;
	int newSize;
	//opens the file passed to the function, "w"-creates empty file for writing.
	//If a file with the same name already exists, its content is erased and the file is considered a new empty file.
	f2 = fopen(filename,"w");
	//checks if the file passed to the function was opened
	//Prints error message if the file was not opened
	if(f2==NULL){
		fprintf(stderr, "File was not written by system\n");
		return -3;
	}
	int i;
	//iterates through file in reverse
	//each loop writes a single character to the reverse file(f2) until the whole file has been gone through 
	for(i=size -1; i>=0;i--){
		char *j =i + buffer;
		fwrite(j,1,1,f2);

	}
	free(buffer);
	//Closes stream, all buffers are flushed
	fclose(f2);
	return 1;
}

