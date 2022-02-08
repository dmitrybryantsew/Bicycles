//
// Created by dmitr on 12/11/2021.
//

#ifndef BICYCLES_STACK_H
#define BICYCLES_STACK_H
#include <stdlib.h>
#include <stdio.h>

struct stack_element {
    int element;
    struct stack_element* prev;
};

typedef struct stack_element *stack;

int top(stack* _stack){
    return (*_stack)->element;
}
int pop(stack* _stack){
    if(NULL == *_stack) {
        printf("\nstack is empty - nothing to pop!\n"); //debug
        return -1;
    }
    int answer = (*_stack)->element;
    printf("\npopping element %i with address %p\n", answer, (void*)(*_stack)); // debug
    struct stack_element* node_to_free = *_stack;
    *_stack = (*_stack)->prev;
    free(node_to_free);
    return answer;
}

int push(stack* _stack, int _element) {
    if(NULL == *_stack)
    {
        printf("stack is empty\n"); //debug
    }
    //printf("in function address is %p\n", (void *)*_stack);
    struct stack_element* stackNode = (struct stack_element*) malloc(sizeof(struct stack_element));
    if(NULL == stackNode){
        printf("failed to allocate memory!");
        return -1;
    }
    stackNode->element = _element;
    stackNode->prev = *_stack;
    if(NULL == stackNode->prev)
    {
        printf("only one element in stack\n"); // debug
    }
    *_stack = stackNode;
    printf("in function address is %p, data is %i\n", (void *)*_stack, (*_stack)->element); //debug
    return 0;
 }

void delete_stack(stack *_stack)
{
    while(NULL != *_stack){
        printf("popping element %i with address %p\n", (*_stack)->element, (void*)(*_stack)); //debug
        struct stack_element* node_to_free = *_stack;
        *_stack = (*_stack)->prev;
        free(node_to_free);
    }

}
#endif //BICYCLES_STACK_H
