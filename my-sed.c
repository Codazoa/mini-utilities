#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// reads lines from the given file pointer, replaces first instance
// of find_term with replace_term and prints the line to stdout
void readlines(const char *find_term, const char *replace_term, FILE *file_ptr){
    // get a line
    char *line = NULL;
    size_t len = 0;

    while ((getline(&line, &len, file_ptr)) != EOF){
        if (!line){
            // memory allocation failed
            fclose(file_ptr);
            perror("Memory allocation failed");
            exit(1);
        }

        char *res;
        res = strstr(line, find_term);
        
        // if substring exists in the line
        if (res){
            int line_ptr = res - line;
            char *end_of_line = line + line_ptr + (int)strlen(find_term);
            
            printf("%.*s", line_ptr, line); // print up to find_term
            printf("%s", replace_term); // print replacement word
            printf("%s", end_of_line); //print line from end of find_term

        } else {
            printf("%s", line); // just print the line
        }
    }
    free(line);
}

int main(int argc, char const *argv[]){
    // argc >= 4 (3+ arguments)
    if (argc < 3){
        printf("my-sed: find_term replace_term [file ...]\n");
        exit(1);
    }

    const char *find_term = argv[1];
    const char *replace_term = argv[2];

    if (argv[3]){
        // loop to open multiple files for read/write
        for (int i = 3; i < argc; i++){
            FILE *file_ptr; 
            file_ptr = fopen(argv[i], "r");

            if (!file_ptr){ // open file error
                printf("my-sed: cannot open file\n");
                exit(1);
            }

            // read lines from the file
            readlines(find_term, replace_term, file_ptr);

            fclose(file_ptr);
        }
    } else {
        // reading from stdin (no file given)
        readlines(find_term, replace_term, stdin);
    }
    return 0;
}
