/*
* SPDX-License-Identifier: ISC
*
* Copyright (c) 2024 Afonso L. Morais <moraisafonso@protonmail.com>
*
* Permission to use, copy, modify, and distribute this software for any
* purpose with or without fee is hereby granted, provided that the above
* copyright notice and this permission notice appear in all copies.
*
* THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
* WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
* MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
* ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
* WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
* ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
* OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
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
