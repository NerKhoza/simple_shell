#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

int main() {
    char input[MAX_INPUT_SIZE];

    while (1) {
        // Display prompt
        write(STDOUT_FILENO, "$ ", 2);

        // Read user input
        if (fgets(input, sizeof(input), stdin) == NULL) {
            // Handle end of file (Ctrl+D)
            write(STDOUT_FILENO, "\n", 1);
            break;
        }

        // Remove newline character
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        // Fork a child process
        pid_t pid = fork();

        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process
            // Execute the command using execve

            // Split the command and arguments
            char *token = strtok(input, " ");
            char *args[MAX_INPUT_SIZE];
            int i = 0;

            while (token != NULL) {
                args[i++] = token;
                token = strtok(NULL, " ");
            }

            args[i] = NULL; // Null-terminate the argument list

            // Execute the command
            execvp(args[0], args);

            // If execvp fails, print an error message
            perror("execvp");
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            int status;
            // Wait for the child process to complete
            if (waitpid(pid, &status, 0) == -1) {
                perror("waitpid");
                exit(EXIT_FAILURE);
            }

            // Check if the child process exited successfully
            if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
                // Print an error message if the command was not found
                write(STDOUT_FILENO, "Command not found\n", 18);
            }
        }
    }

    return 0;
}

