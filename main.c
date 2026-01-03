#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
   char *buffer;
   size_t buffer_length;
   ssize_t input_length;
} InputBuffer;

// Function prototypes
InputBuffer *new_input_buffer();
void print_prompt();
void read_input(InputBuffer *input_buffer);
void close_input_buffer(InputBuffer *input_buffer);

int main(int argc, char *argv[])
{
   InputBuffer *input_buffer = new_input_buffer();

   while (true)
   {
      print_prompt();
      read_input(input_buffer);

      if (strcmp(input_buffer->buffer, ".exit") == 0)
      {
         close_input_buffer(input_buffer);
         exit(EXIT_SUCCESS);
      }
      else
      {
         printf("Unrecognized command '%s'.\n", input_buffer->buffer);
      }
   }
}

/**
 * Function: read_input
 * Objective: Read the user input, check if it is a valid command too
 * Arguments: (InputBuffer) *input_buffer
 */
void read_input(InputBuffer *input_buffer)
{
   if (fgets(input_buffer->buffer, input_buffer->buffer_length, stdin) == NULL)
   {
      printf("Error reading input\n");
      exit(EXIT_FAILURE);
   }

   // Compute length of the line read
   input_buffer->input_length = strlen(input_buffer->buffer);

   // remove newline if present
   if (input_buffer->input_length > 0 && input_buffer->buffer[input_buffer->input_length - 1] == '\n')
   {
      input_buffer->buffer[input_buffer->input_length - 1] = '\0';
      input_buffer->input_length--;
   }
}

/**
 * Function: close_input_buffer
 * Objective: Release the memory and close the input buffer
 * Arguments: (InputBuffer) *input_buffer
 */
void close_input_buffer(InputBuffer *input_buffer)
{
   free(input_buffer->buffer);
   free(input_buffer);
}

/**
 * Function: print_prompt
 * Objective: Print the prompt in the terminal, a makeup.
 */
void print_prompt()
{
   printf("db > ");
}

/**
 * Function: new_input_buffer
 * Objective: Initialize and create the structure type InputBuffer
 *             then allocate a memory for it on the heap using malloc().
 *             initializes it fields, and returns a pointer to it.
 * return: input_buffer, which is a pointer.
 */
InputBuffer *new_input_buffer()
{
   InputBuffer *input_buffer = (InputBuffer *)malloc(sizeof(InputBuffer));

   input_buffer->buffer_length = 1024;
   input_buffer->buffer = malloc(input_buffer->buffer_length);
   input_buffer->input_length = 0;

   return input_buffer;
}
