//
// Created by dmitr on 12/9/2021.
//

#ifndef BICYCLES_BASIC_STRING_H
#define BICYCLES_BASIC_STRING_H
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

char* readLine (){
    char* answer = (char *)realloc(NULL, sizeof(char)*1);
    size_t actualSize_ = 0;
    size_t size_ = 1;
    char* tmp = answer;
    int ch;
    int counter = 0;
    while ((ch=getchar()) != '\n'){

        *tmp = ch; // put char at its position in answer
        printf("answer adress is %p, ch=%c\n", (void*)answer, ch); //debug
        tmp++; // next pos
        actualSize_++; //update size
        if(actualSize_ >= size_) //resize if actual size >= specified size
        {
            size_ *=2;
            answer = (char *)realloc(answer, size_ * sizeof(char));
            tmp = answer+actualSize_; // dont forget to update tmp adress as well if case of resize in different location
            counter++;
        }

    }
    printf("resizes - %i\n", counter);
    answer = (char *)realloc(answer, actualSize_ * sizeof(char)+1); //trim, not forgetting the null
    *(answer+actualSize_+1) = '\0'; //put null at the end
    printf("string length is %i \n"  , strlen(answer));
    return answer;


}
char* mygetstring()
{
    char* outPtr;
    char* ptr;
    int i = 0, SymCode;
    outPtr = (char*)realloc(NULL, sizeof(char));
    SymCode = getchar();
    *outPtr = (char)SymCode;
    ptr = outPtr;
    while ((SymCode = getchar()) != '\n')
    {
        i = i + 1;
        if(!(outPtr = (char*)realloc(outPtr, sizeof(char) * i))){
            printf( "failed to realloc memory");
            return NULL;
        }
        ptr = (outPtr + i - 1);
        *ptr = (char)SymCode;

    }
    return outPtr;
}
#endif //BICYCLES_BASIC_STRING_H
