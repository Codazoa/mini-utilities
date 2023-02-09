#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

int main(int argc, char const *argv[]){

    for (int i = 1; i < argc; i++){
        FILE *file_ptr; 
        file_ptr = fopen(argv[i], "r");

        // initialize line variables
        char *line1 = NULL;
        char *line2 = NULL;
        size_t len1 = 0;
        size_t len2 = 0;
        size_t read1;
        size_t read2;

        // read 2 lines at a time
        while ((read1 = getline(&line1, &len1, file_ptr)) != -1){
            read2 = getline(&line2, &len2, file_ptr);
            if (!line1 || !line2){
                // memory allocation failed
                if(line1) free(line1);
                if(line2) free(line2);
                fclose(file_ptr);
                perror("Memory allocation failed");
                exit(1);
            }
            
            // reached the end of the file
            if (read2 == -1) {
                printf("Here: %s", line1);
                break;
            }

            // lines are different
            if (strcmp(line1, line2) != 0){ 
                // print the line and seek back to grab next line
                printf("%s", line1);
                fseek(file_ptr, -read2, SEEK_CUR);
            } else { // lines are same
                // print the line and skip the next line
                printf("%s", line1);
            }
            
        }
        free(line1);
        free(line2);

        fclose(file_ptr);
    }

    return 0;
}