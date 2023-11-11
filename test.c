#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

int main() {
    while (1) {
        // Display prompt
        write(STDOUT_FILENO, "simple_shell> ", 14);

        // Read command from user
        char *command = NULL;
        size_t len = 0;
        ssize_t read = getline(&command, &len, stdin);

        // Handle end of file (Ctrl+D)
        if (read == -1) {
            free(command);
            break;
        }

        // Remove the newline character
        if (command[read - 1] == '\n') {
            command[read - 1] = '\0';
        }

        // Fork to create a new process
        pid_t pid = fork();

        if (pid == -1) {
            perror("Fork error");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {
            // Child process
            char *token = strtok(command, " ");
            execve(token, &token, NULL);

            // If execve fails
            perror("Command not found");
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            int status;
            waitpid(pid, &status, 0);

            // Check for errors in child process
            if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
                write(STDOUT_FILENO, "Error executing command\n", 24);
            }
        }

        // Free allocated memory
        free(command);
    }

    return 0;
}

