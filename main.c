/*
 * My your own X - Simple database in C
 *
 * Mocaccino/InuzDev , File: Main.c
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
   char *buffer;
   size_t buffer_length;
   ssize_t input_length;
} InputBuffer;

typedef enum { META_COMMAND_SUCCESS,
               META_COMMAND_UNRECOGNIZED } MetaCommandResult;

typedef enum { PREPARE_SUCCESS,
               PREPARE_UNRECOGNIZED_STATEMENT } PrepareResult;

typedef enum {
   STATEMENT_INSERT,
   STATEMENT_SELECT
} StatementType;

typedef struct {
   StatementType type;
} Statement;

// Function prototypes
MetaCommandResult do_meta_command(InputBuffer *input_buffer);
InputBuffer *new_input_buffer();
PrepareResult prepare_statement(InputBuffer *input_buffer, Statement *statement);
void print_prompt();
void read_input(InputBuffer *input_buffer);
void close_input_buffer(InputBuffer *input_buffer);
void execute_statement(Statement *statement);

int main(int argc, char *argv[]) {
   InputBuffer *input_buffer = new_input_buffer();
   while (true) {
      print_prompt();
      read_input(input_buffer);

      if (input_buffer->buffer[0] == '.') {
         switch (do_meta_command(input_buffer)) {
         case (META_COMMAND_SUCCESS):
            continue;
         case (META_COMMAND_UNRECOGNIZED):
            printf("Unrecognized command '%s'\n", input_buffer->buffer);
            continue;
         }
      }

      Statement statement;
      switch (prepare_statement(input_buffer, &statement)) {
      case (PREPARE_SUCCESS):
         break;
      case (PREPARE_UNRECOGNIZED_STATEMENT):
         printf("Unrecognized keyword at start of '%s'.\n", input_buffer->buffer);
         continue;
      }

      execute_statement(&statement);
      printf("Executed.\n");
   }
}

/**
 * Function: read_input
 * Objective: Read the user input, check if it is a valid command too
 * Arguments: (InputBuffer) *input_buffer
 */
void read_input(InputBuffer *input_buffer) {
   if (fgets(input_buffer->buffer, input_buffer->buffer_length, stdin) == NULL) {
      printf("Error reading input\n");
      exit(EXIT_FAILURE);
   }
   // Compute length of the line read
   input_buffer->input_length = strlen(input_buffer->buffer);

   // remove newline if present
   if (input_buffer->input_length > 0 && input_buffer->buffer[input_buffer->input_length - 1] == '\n') {
      input_buffer->buffer[input_buffer->input_length - 1] = '\0';
      input_buffer->input_length--;
   }
}

/**
 * Function: close_input_buffer
 * Arguments: (InputBuffer) *input_buffer
 */
void close_input_buffer(InputBuffer *input_buffer) {
   free(input_buffer->buffer);
   free(input_buffer);
}

/**
 * Function: print_prompt
 * Objective: Print the prompt in the terminal, a makeup.
 */
void print_prompt() { printf("db > "); }

/**
 * Function: new_input_buffer
 * Objective: Initialize and create the structure type InputBuffer
 *             then allocate a memory for it on the heap using malloc().
 *             initializes it fields, and returns a pointer to it.
 * return: input_buffer, which is a pointer.
 */
InputBuffer *new_input_buffer() {
   InputBuffer *input_buffer = (InputBuffer *)malloc(sizeof(InputBuffer));

   input_buffer->buffer_length = 1024;
   input_buffer->buffer = malloc(input_buffer->buffer_length);
   input_buffer->input_length = 0;

   return input_buffer;
}

/**
 * Function: do_meta_command
 * Objective: Check if the command exist, if not return unrecognized META command.
 * return: Type MetaCommandResult
 */
MetaCommandResult do_meta_command(InputBuffer *input_buffer) {
   if (strcmp(input_buffer->buffer, ".exit") == 0) {
      exit(EXIT_SUCCESS);
   } else {
      return META_COMMAND_UNRECOGNIZED;
   }
}

/*
 * Function: prepare_statement
 * Objective: Prepare the staement and check if the state is recognized or not.
 * Return: PrepareResult type
 */
PrepareResult prepare_statement(InputBuffer *input_buffer, Statement *statement) {
   if (strncmp(input_buffer->buffer, "insert", 6) == 0) {
      statement->type = STATEMENT_INSERT;
      return PREPARE_SUCCESS;
   }
   if (strcmp(input_buffer->buffer, "select") == 0) {
      statement->type = STATEMENT_SELECT;
      return PREPARE_SUCCESS;
   }

   return PREPARE_UNRECOGNIZED_STATEMENT;
}

void execute_statement(Statement *statement) {
   switch (statement->type) {
   case (STATEMENT_INSERT):
      printf("Insert scenario");
      break;
   case (STATEMENT_SELECT):
      printf("Select scenario");
      break;
   }
}
