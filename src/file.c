/*
 * MIT License
 * 
 * Copyright (c) 2024 Afonso L. Morais
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "headers/file.h"
#include "headers/input.h"
#include "headers/config.h"

#define MAX_WORDS 5000
#define MAX_CHAR 300

char words[MAX_WORDS][MAX_CHAR];
int wordCount = 0;

void get_file(const char* fname){

    
    FILE *fp;
    fp = fopen(fname, "r");

    if(fp == NULL){
        
        printf("ERROR 01: Couldn't open the file!\n");
        return;
    }

    retrieve_content(fp);
   
    printf("PRESS [ENTER] TO GET RANDOM WORDS. YOU CAN TYPE '\\' AND PRESS [ENTER] TO EXIT!\n");
    wait_forinput();

    get_randword();

    fclose(fp);
}

void retrieve_content(FILE *fp){

    char line[300];

    while(fgets(line, sizeof(line), fp) != NULL){
       
        if(strcmp(line, "\n") || strcmp(line, "\0")){

            strcpy(words[wordCount++], line);
        }
    }
}


void get_randword() {
    srand(time(NULL));

    int r = 0;
    int lr = -1;     
    int usedWords[MAX_WORDS] = {0};      
    int usedCount = 0;

    while(1) {
        
        for(int i = 0; i < userconfig.wordOutput; i++) {
            
                do {
                    r = rand() % wordCount;
                    if(userconfig.repeatLastWord) break;
                } while((r == lr) || (!userconfig.repeatWords && usedWords[r]) ||
                         (!strncmp(words[r], "//", 2)) || (!strcmp(words[r], "\0")) ||
                          (!strcmp(words[r], "\n")) );

                if(!userconfig.repeatWords) {
                    usedWords[r] = 1;
                    usedCount++;
                }

                lr = r;  
                
                //Remove comments if needed
                char *comment_pos = strstr(words[r], "//");
                if (comment_pos != NULL) {
                    *comment_pos = '\0';
                }

                //Remove '\n' from each
                comment_pos = strstr(words[r], "\n");
                if(comment_pos != NULL){
                    *comment_pos = '\0';
                }

                printf("RANDOM WORD/LINE: %s\n", words[r]);

                if (usedCount == wordCount) {
                    printf("End of word list! Exiting the program...\n");
                    exit(1);
                }
        }

        wait_forinput();  
    }
}
