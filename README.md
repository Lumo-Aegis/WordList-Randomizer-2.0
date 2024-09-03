# WORD LIST RANDOMIZER

This program was originally made to get words randomly from text files to study Japanese. Feel free to use the current program or modify the code as you wish.

This code enables you to choose a file (.txt preferably) from the directory that the program is currently in and get lines from it at random.
The file can contain comments and they wont be in the output of the program.


### Instructions to Run (linux):
1. Run "./WL-Randomizer path/to/file.txt"
2. Press "ENTER" to get a new random word each time
3. To stop the program type '\' and hit ENTER

### Instructions to Run (windows):
1. Open cmd and go to the WL-Randomizer directory
2. run "WL-Randomizer path/to/file.txt"
3. To stop the program type '\' and hit ENTER

### Instructions to customize: 
1. Run "./WL-Randomizer -c" or "./WL-Randomizer --configure"
2. Select what to customize from the available options (This will be saved next time you use the program)

### Instructions to Compile:

#### Linux:
run "make linux"

#### Windows: 
run "make windows"

#### Clean Compilation Files:
run "make clean"


### File structer and type:
The file to display random words from can be any text type like .txt .md doesn't really matter the program will read from it either way.

But for a better expirience make a file with the following format:
```
// This is a comment will be ignored by the program
Apple
Banana // This comment will also be ignored
Orange
```

PS:
If you get the '^H' character when pressing backspace in a unix terminal use this command to fix:
```
stty erase ^H"
```
If you want to add this to the shell so you don't have to constantly type it use this:
```
echo "stty erase ^H" >> ~/.bashrc
```
(Windows SHOULDN'T have this problem).
