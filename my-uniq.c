#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

int main(int argc, char const *argv[]){
    
    for (int i = 1; i < argc; i++){         //Go through each argument, which all should be files
        
        FILE *file_ptr;                     //Initialize variable to hold file
        char* line = NULL;                  //Initialize variable to hold read line
        char* lastline = NULL;              //Initialize variable to hold last line
        size_t length = 0;                  //Initialize variable to hold the length
        int ignore = 0;                     //Flag to only print once
        
        
        file_ptr = fopen(argv[i], "r");  //Attempt to open file given by user

        // check if the file was opened
        if(file_ptr == NULL){               //If the file didn't open, error out and exit
            perror("my-uniq: cannot open file\n");
            exit(1); 
        }


        //Go through each line
        while ((getline(&line, &length, file_ptr)) != EOF){

            if (!line){
                // memory allocation failed
                fclose(file_ptr);
                perror("Memory allocation failed");
                exit(1);
            }
            
            //Reset out ignore flag if the last one didn't match
            if (strcmp(line, lastline) != 0 ){
                ignore = 0;
            }

            //Check to see if we matched the last line and we haven't printed already
            if ((strcmp(line,lastline ) == 0) && (ignore == 0)){
                ignore = 1;             //Set our flag so we don't print again
                printf("%s", line);     //print
            }

            //Copy the current line into last line for the next loop
            strcpy(lastline, line);

        }


    }


    
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