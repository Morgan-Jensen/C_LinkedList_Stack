// Stack Object File
// author: Morgan Jensen

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

stackT *NewStack(void)
{
	stackT * newStack;
	
	// create new stack
	newStack = (stackT *) malloc(sizeof(stackT));
	newStack->head = NULL;
	
	return newStack;
}

void Push(stackT *stack, valueT value)
{
	nodeT * newNode;
	
	// allocate space for a nodeT type in the heap
	newNode = (nodeT *) malloc(sizeof(nodeT));
	
	// set the next field of that new node to point to the head in the stack (null if no head)
	newNode->next = stack->head;
	
	// set the value of the new node
	newNode->value = value;

	// set head field of stack to new node
	stack->head = newNode;
}

valueT Pop(stackT *stack)
{	
	valueT returnValue;
	
	// return space and print error if empty
	if (stack->head == NULL)
	{
		printf("Stack is empty.");
		return ' ';		
	}
	else
	{
		// save old head
		nodeT * cursor = stack->head;
		
		// set returnValue
		returnValue = cursor->value;
		
		// set the head field to point to the next node (to null if the last node)
		stack->head = stack->head->next;

		// free the space associateed with the old node
		free(cursor);	
		
		return returnValue;
	}
}

void EmptyStack(stackT *stack)
{
    // check for non-existant stack
    if (stack == NULL)
    {
        return;
    }

	// pop until the stack is empty
	while (!IsEmpty(stack))
	{
		Pop(stack);	
	}
}

void FreeStack(stackT *stack)
{
	// free the stack if empty
	if (IsEmpty(stack))
	{
		free(stack);
	}
}

bool IsEmpty(stackT *stack)
{
	return ((bool)(stack->head == NULL));
}
