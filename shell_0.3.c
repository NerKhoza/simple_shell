#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

/**
 * main - main function
 *
 * Return: 0
 */

int main(void)
{
	char input[MAX_INPUT_SIZE];
	size_t len;
	pid_t pid;
	char *token;
	int status;
	int i = 0;

	while (1)
	{
		write(STDOUT_FILENO, ":) ", 3);

		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}

		len = strlen(input);
		if (len > 0 && input[len - 1] == '\n')
		{
			input[len - 1] = '\0';
		}

		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			token = strtok(input, " ");
			char *args[MAX_INPUT_SIZE];

			while (token != NULL)
			{
				args[i++] = token;
				token = strtok(NULL, " ");
			}

			args[i] = NULL;

			execvp(args[0], args);

			perror("execvp");
			exit(EXIT_FAILURE);
		}
		else
		{
			if (waitpid(pid, &status, 0) == -1)
			{
				perror("waitpid");
				exit(EXIT_FAILURE);
			}

			if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			{
				write(STDOUT_FILENO, "Command not found\n", 18);
			}
		}
	}
	return (0);
}
