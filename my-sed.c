#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// returns a string of length term_len starting at start_index
// return NULL if word continued past length
char *get_word(char *line, int start_index, size_t term_len){
    // set up string buffer
    char *buf; 
    buf = (char *)calloc(term_len+1, sizeof(char));
    if (buf == NULL){
        return NULL; // to check for memory error
    }

    // check if the word is going to end
    if (line[start_index + term_len] != ' '){
        return buf;
    }

    // check if we are at the start of a word
    if (start_index > 0 && line[start_index - 1] != ' '){
        return buf;
    }

    // step through the word char by char
    for (int i = start_index; i < start_index + term_len; i++){
        buf[i - start_index] = line[i];
    }

    return buf;
}

int main(int argc, char const *argv[]){
    // argc >= 4 (3+ arguments)
    if (argc < 4){
        printf("my-sed: find_term replace_term [file ...]\n");
        exit(1);
    }

    const char *find_term = argv[1];
    const char *replace_term = argv[2];

    // loop to open multiple files for read/write
    for (int i = 3; i < argc; i++){
        FILE *file_ptr; 
        file_ptr = fopen(argv[i], "r");

        // get a line
        char *line = NULL;
        size_t len = 0;
        ssize_t nread;

        while ((nread = getline(&line, &len, file_ptr)) != EOF){
            char *word;
            int line_ptr;
            // get the word
            for(line_ptr = 0; line_ptr < nread; line_ptr++){
                if (line[line_ptr] == find_term[0]){
                    word = get_word(line, line_ptr, strlen(find_term));
                    if (word[0] != '\0'){
                        break;
                    }
                    else{
                        free(word);
                    }
                }
            }
            
            // check against find_term
            // if word matches print up to word, print word, print rest of line
            if (strcmp(word, find_term) == 0){
                printf("%.*s", (int)line_ptr, line);
                printf(replace_term);
                printf(line + line_ptr + (int)strlen(word));
                free(word);
            }
            // if word does not match, print the line
            else{
                printf(line);
            }

        }
        free(line);
        fclose(file_ptr);
    }

    
    return 0;
}