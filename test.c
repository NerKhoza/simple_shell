#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 100

void display_prompt() {
    write(STDOUT_FILENO, "$ ", 2);
}

void execute_command(char *command) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) { // Child process
        char *args[] = {command, NULL};
        execvp(command, args);

        // If execvp fails
        perror("execvp");
        exit(EXIT_FAILURE);
    } else { // Parent process
        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
            write(STDOUT_FILENO, "Command not found\n", 18);
        }
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        display_prompt();

        // Read command
        ssize_t read_bytes = read(STDIN_FILENO, command, MAX_COMMAND_LENGTH);

        if (read_bytes == 0) { // End of file (Ctrl+D)
            write(STDOUT_FILENO, "\n", 1);
            break;
        }

        // Remove newline character
        if (command[read_bytes - 1] == '\n') {
            command[read_bytes - 1] = '\0';
        }

        // Check for built-in commands
        if (strcmp(command, "exit") == 0) {
            break;
        } else if (strcmp(command, "env") == 0) {
            char *env = getenv("PATH");
            if (env != NULL) {
                write(STDOUT_FILENO, env, strlen(env));
                write(STDOUT_FILENO, "\n", 1);
            }
        } else {
            // Execute the command
            execute_command(command);
        }
    }

    return 0;
}

