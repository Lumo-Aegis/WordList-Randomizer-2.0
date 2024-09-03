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
#include "headers/config.h"
#include "headers/input.h"
#include "headers/clear.h"

Config userconfig;
FILE* configFile;
char line[100];

bool verify_config(){

    if((configFile = fopen("config", "r")) == NULL){
        return false;
    }

    for(int i = 0; i < 3; i++){

        if(fgets(line, sizeof(line), configFile) != NULL){

            size_t length = strlen(line);
            if(length > 0 && line[length - 1] == '\n'){
                line[length - 1] = '\0';
            }

            switch(i){
                case 0: userconfig.repeatLastWord = (strcmp(line, "1") == 0); break;
                case 1: userconfig.wordOutput = atoi(line); break;
                case 2: userconfig.repeatWords = (strcmp(line, "1") == 0); break;
            }
        }
    } 
    
    fclose(configFile);
    return true;
}

void create_config(){
    
    const char* answer;

    do{
        if(!verify_config()){ 
            printf("You don't have a config file yet create a new one? (y/n): ");
        }else{ 
            printf("You already have a config file do you wish to edit it? (y/n): ");
        }
        answer = get_input();
    }while(input_accepted(answer) == -1);

    if(input_accepted(answer) == 0){
        printf("Config editing was aborted!\n");
        exit(1);
    }

    do{
        // Repeat 2 words in a row
        do{
            printf("Do you want to repeat the previous line/word? (y/n): ");
            answer = get_input();
        }while(input_accepted(answer) == -1);

        if(input_accepted(answer) == 1){
            userconfig.repeatLastWord = true;
        }else{
            userconfig.repeatLastWord = false;
        }

        // Amount of outputed lines
        do{
            printf("How many words/lines do you want to output in a row? (1 minimum): ");
            answer = get_input();
        }while(atoi(answer) < 1);

        userconfig.wordOutput = atoi(answer);
        
        // Repeat words
        do{
            printf("Do you want to repeat words/lines from the list? (y/n): ");
            answer = get_input();
        }while(input_accepted(answer) == -1);

        if(input_accepted(answer) == 1){
            userconfig.repeatWords = true;
        }else{
            userconfig.repeatWords = false;
        }

        // output of created config
        system(CLEAR);
        printf("Your config is the following:       \n"
               "************************************\n"
               "Repeat previous word/line:      %s  \n"
               "Words/Lines in a single output: %d  \n"
               "Repeat words/lines:             %s  \n"
               "************************************\n", 
               userconfig.repeatLastWord ? "YES" : "NO", 
               userconfig.wordOutput, 
               userconfig.repeatWords ? "YES" : "NO");

        printf("Save the config? (y/n): ");
        answer = get_input();

    }while(!(input_accepted(answer)));


    if((configFile = fopen("config", "w")) == NULL){
        printf("ERROR 04: Coudn't create/open the config file!\n");
        exit(1);
    }

    if(fprintf(configFile, "%d\n%d\n%d\n", 
       userconfig.repeatLastWord, userconfig.wordOutput, userconfig.repeatWords) == EOF){
        
        printf("ERROR 05: Coudn't save the config file!\n");
        exit(1); 
    }
        
    fclose(configFile);
    printf("Config was saved!\n");
}