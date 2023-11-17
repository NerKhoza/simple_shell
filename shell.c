#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

/**
 * main - main function
 *
 * Return: 0
 */

int main(void)
{
	pid_t pid;
	char *command;
	size_t len;
	int status;

	len = 0;

	while (1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);

		if (getline(&command, &len, stdin) == -1)
		{
			if (feof(stdin))
			{
				write(STDOUT_FILENO, "", 1);
				free(command);
				exit(EXIT_SUCCESS);
			}
			else
			{
				perror("getline");
				free(command);
				exit(EXIT_FAILURE);
			}
		}

		command[strlen(command) - 1] = '\0';

		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			free(command);
			exit(EXIT_FAILURE);
		}

		if (pid == 0)
		{
		char *argv[] = {command, NULL};

			if (execve(command, argv, NULL) == -1)
			{
				perror("./shell");

				free(command);
				_exit(EXIT_FAILURE);
			}
		}
		else
		{
			waitpid(pid, &status, 0);

			if (WIFEXITED(status) && WEXITSTATUS(status) == 127)
			{
				write(STDERR_FILENO, "command not found\n", 18);
			}
		}
	}
	return (0);
}
