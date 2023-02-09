#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

int main(int argc, char const *argv[]){
    printf("main\n");

    for (int i = 1; i < argc; i++){
        FILE *file_ptr; 
        file_ptr = fopen(argv[i], "r");

        // get a line
        char *line1 = NULL;
        char *line2 = NULL;
        size_t len1 = 0;
        size_t len2 = 0;
        size_t read1;
        size_t read2;

        while ((read1 = getline(&line1, &len1, file_ptr)) != -1){
            read2 = getline(&line2, &len2, file_ptr);
            if (!line1 || !line2){
                // memory allocation failed
                fclose(file_ptr);
                perror("Memory allocation failed");
                exit(1);
            }
            
            if (read2 == -1) {
                printf("%s", line1);
                break;
            }

            if (strcmp(line1, line2) != 0){ // lines are different
                printf("%s", line1);
                fseek(file_ptr, -len1, SEEK_CUR);
            }
            
            free(line1);
            free(line2);
        }

        fclose(file_ptr);
    }



    
    // for (int i = 1; i < argc; i++){         //Go through each argument, which all should be files

    //     printf("Initialize Variables\n");   
    //     FILE *file_ptr;                     //Initialize variable to hold file
    //     char* line = "";                  //Initialize variable to hold read line
    //     char* lastline = "";              //Initialize variable to hold last line
    //     size_t length = 0;                  //Initialize variable to hold the length
    //     int ignore = 0;                     //Flag to only print once
        
    //     printf("Try and open file\n");
    //     file_ptr = fopen(argv[i], "r");  //Attempt to open file given by user

    //     printf("Check to see if file opened\n");
    //     // check if the file was opened
    //     if(file_ptr == NULL){               //If the file didn't open, error out and exit
    //         perror("my-uniq: cannot open file\n");
    //         exit(1); 
    //     }


    //     //Go through each line
    //     printf("start while loop\n");
    //     while ((getline(&line, &length, file_ptr)) != EOF){

    //         printf("Check to see if we allocated memory\n");
    //         if (!line){
    //             // memory allocation failed
    //             fclose(file_ptr);
    //             perror("Memory allocation failed\n");
    //             exit(1);
    //         }
            
    //         printf("check to see if we arent the same as the last one\n");
    //         //Reset out ignore flag if the last one didn't match
    //         if (strcmp(line, lastline) != 0 ){
    //             ignore = 0;
    //         }

    //         printf("Check to see if we should print\n");
    //         //Check to see if we matched the last line and we haven't printed already
    //         if ((strcmp(line, lastline ) == 0) && (ignore == 0)){
    //             ignore = 1;             //Set our flag so we don't print again
    //             printf("%s", line);     //print
    //         }

    //         //Copy the current line into last line for the next loop
    //         strcpy(lastline, line);

    //     }


    // }
    // printf("End\n");


    
    //iterate through argv with argc as count
        //for each one, go through the file and detect repeated lines
            //Store line
            
            //if line != lastline
                //ignore = 0
            
            //if line == lastline and ignore==0
                //ignore = 1
                //print(line)
            
            
            //lastline = line

    return 0;
}