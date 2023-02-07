#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    // get a filepointer for reading
    FILE *file_ptr;
    file_ptr = fopen(argv[1], "r");

    // TODO: loop through files

    // check if the file was opened
    if(file_ptr == NULL){
        perror("my-cat: cannot open file\n");
        exit(1); 
    }

    // allocate a buffer for reading from file
    char buf[256];
    while(fgets(buf, sizeof(buf), file_ptr) != NULL){
        // keep reading and printing from the fill until EOF
        printf("%s", buf);
    }

    // print final newline character
    printf("\n");
    return 0;
}