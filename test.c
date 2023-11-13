#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char *command;
    size_t len = 0;

    while (1) {
        // Display prompt
        write(STDOUT_FILENO, "$ ", 2);

        // Read command from user
        if (getline(&command, &len, stdin) == -1) {
            if (feof(stdin)) {
                // Handle end of file (Ctrl+D)
                write(STDOUT_FILENO, "\n", 1);
                free(command);
                exit(EXIT_SUCCESS);
            } else {
                // Handle other errors
                perror("getline");
                free(command);
                exit(EXIT_FAILURE);
            }
        }

        // Remove newline character from the end
        command[strlen(command) - 1] = '\0';

        // Fork a child process
        pid_t pid = fork();

        if (pid == -1) {
            // Handle fork error
            perror("fork");
            free(command);
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {
            // Child process
            char *argv[] = {command, NULL};

            // Execute the command
            if (execve(command, argv, NULL) == -1) {
                // Handle execution error
                perror("execve");

                // Exit child process
                free(command);
                _exit(EXIT_FAILURE);
            }
        } else {
            // Parent process
            int status;
            waitpid(pid, &status, 0);

            // Check if executable was not found
            if (WIFEXITED(status) && WEXITSTATUS(status) == 127) {
                write(STDERR_FILENO, "Command not found\n", 18);
            }
        }
    }

    return 0;
}

