# Mini-Utilities
Cody Vernon, Jack Harvison, Drake Farmer

## `./my-cat [file ...]`
Prints the contents of the given file(s) to standard output

my-cat will return 0 if the program exits cleanly \
my-cat will send an error and return 1 if the provided file cannot be opened \
my-cat will continue printing text until it reaches a file it cannot open or the end of the passed files \
my-cat will return 0 if run with no file arguments


## `./my-sed find_term replace_term [file ...]`
Replace the first instance of find_term on each line from each file with replace_term and print the resulting line to standard output

my-sed will return 0 if the program exits cleanly \
my-sed will return 1 in the following cases:
- Invalid Arguments
- Find_term is null
- Unable to open file
- A given line could not fit into memory

## `./my-uniq [file ...]`
Detect duplicate adjacent lines in the file and print contents to standard output

## To Compile:
`make`: compile the 3 executables \
`make clean`: delete all but the source files

