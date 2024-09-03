# WORD LIST RANDOMIZER

The Word List Randomizer is a tool designed to randomly select words or lines from a text file, originally created to aid me when studying Japanese. You can freely use or modify this program as needed.

This program allows you to choose a file (preferably .txt) from the directory where the program is located and retrieve lines from it at random. Comments in the file are ignored by the program.

## What's the big change in 2.0
Well the change from this version of WordList-Randomizer is mostly the addition of a config to the program aside some minor changes this is the biggest one and the reason for a version 2.0. The previous code was also super junkie this one should be better in most aspects.


## Instructions
### Running the Program
Linux

1. Open a terminal.
2. Navigate to the directory containing WL-Randomizer.
3. Execute the program with the following command:

```
./WL-Randomizer path/to/file.txt
```

4. Press ENTER to get a new random word or line each time.
5. To stop the program, type \ and hit ENTER.

Windows

1. Open Command Prompt (cmd).
2. Navigate to the directory containing WL-Randomizer.
3. Run the program with:

```
WL-Randomizer path/to/file.txt
```

4. To stop the program, type \ and hit ENTER.

### Customizing the Program

To customize settings, run:

```
./WL-Randomizer -c
```
or

```
./WL-Randomizer --configure
```

Follow the prompts to select and adjust available options. Your settings will be saved for future use.

### Compiling the Program
#### Linux

Run the following command to compile:

```
make linux
```

#### Windows

Run the following command to compile:

```
make windows
```

#### Cleaning Compilation Files

To clean up compilation files, use:

```
make clean
```

## File Structure and Format

The file used by the program can be in any text format (e.g., .txt, .md). For the best experience, format your file as follows:

```
// This is a comment and will be ignored by the program
Apple
Banana // This comment will also be ignored
Orange
```

## Troubleshooting
Backspace Character Issue on Unix

If you encounter the ^H character when pressing backspace in a Unix terminal, resolve it with the following command:

```
stty erase ^H
```

To make this change persistent across terminal sessions, add it to your shell configuration file:

```
echo "stty erase ^H" >> ~/.bashrc
```

(Windows should not experience this issue.)


## License
This project is licensed under the MIT License - see the LICENSE file for details.
Contact

For questions or feedback, please contact me at moraisafonso@protonmail.com.
