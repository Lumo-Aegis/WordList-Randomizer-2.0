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
#include <ctype.h>
#include <string.h>
#include "headers/input.h"

char* input;

const char* get_input(){

    char* tempInput;
    int index = 0;
    int c;

    if((input = (char*)malloc(1 * sizeof(char))) == NULL){
        printf("ERROR 01: Try restarting the program\n");
    }

    while((c = getchar()) != '\n' && c != EOF){
        
        if(index > 1){
            
            if((tempInput = (char*)realloc(input, (index + 1) * sizeof(char))) == NULL){
                printf("ERROR 02: Try restarting the program\n");
                free(input);
                exit(EXIT_FAILURE);
            }
        }

        input[index++] = (char)c;
    }
    input[index] = '\0';

    for(int i = 0; i < index; i++) input[i] = tolower(input[i]);

    return input; 
}

int input_accepted(const char* input){

    if(strcmp(input, "y") == 0 || strcmp(input, "yes") == 0){
        return 1;
    }else if(strcmp(input, "n") == 0 || strcmp(input, "no") == 0){
        return 0;
    }
   
    return -1;
}

void wait_forinput(){

    int c;
    printf("\n");
    
    while((c = getchar()) != '\n' && c != '\\' && c != EOF);
    
    if(c == '\\'){
        printf("PROGRAM CLOSED!\n");
        exit(1);
    }
}
