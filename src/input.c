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
