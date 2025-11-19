#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct
{
   char *buffer;
   size_t buffer_length;
   ssize_t input_lenth;
} InputBuffer;

// Function prototypes
InputBuffer *new_input_buffer();
void print_prompt();
void read_input(InputBuffer *input_buffer);

int main(int argc, char *argv[])
{
   InputBuffer *input_buffer = new_input_buffer();

   while (TRUE)
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

void read_input(InputBuffer *input_buffer)
{
   ssize_t bytes_read = getline(&(input_buffer->buffer), &(input_buffer->buffer_length), stdin);

   if (bytes_read <= 0)
   {
      printf("Error reading input\n");
      exit(EXIT_FAILURE);
   }

   // Ignore trailing newline
   input_buffer->input_lenth = bytes_read - 1;
   input_buffer->buffer[bytes_read - 1] = 0;
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

   input_buffer->buffer = NULL;
   input_buffer->buffer_length = 0;
   input_buffer->input_lenth = 0;

   return input_buffer;
}