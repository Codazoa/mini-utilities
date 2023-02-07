#include <stdio.h>
#include <stdlib.h>

// returns a string containing the next word in the line
// return -1 if we reach newline
char *next_word(char* line, int start){
    // keep going till a space, save back_index

    // set new word buffer to
    return 0;
}

int main(int argc, char const *argv[]){
    // argc >= 4 (3+ arguments)
    if (argc < 4){
        printf("my-sed: find_term replace_term [file ...]\n");
        exit(1);
    }

    find_term = argv[1];
    replace_term = argv[2];

    // loop to open multiple files for read/write
    for (int i = 3; i < argc; i++){
        FILE *file_ptr; 
        file_ptr = fopen(argv[i], "r");

        // evr thang happn dwn her
        // I do declare, gobless

        // get a line
        char *line = NULL;
        size_t len = 0;
        ssize_t nread;

        while ((read = getline(&line, &len, file_ptr)) != EOF){
            int line_ptr = 0;
            char *word;
            // get the word
            
            // update line_ptr
            // check against find_term
            // if word matches, print the replace_term
            // if word not matches, print the word
        }
    }

    free(line);
    fclose(file_ptr);
    return 0;
}