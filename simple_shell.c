#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 100

void display_prompt()
{
	write(STDOUT_FILENO, "$ ", 2);
}

void execute_command(char *command)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		char *args[] = {command, NULL};
		execvp(command, args);

		perror("execvp");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);

		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			write(STDOUT_FILENO, "Command not found\n", 18);
		}
	}
}

int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	ssize_t read_bytes;
	char *env;

	while (1)
	{
		display_prompt();
	}

	read_bytes = read(STDIN_FILENO, command, MAX_COMMAND_LENGTH);

	if (read_bytes == 0)
	{
		write(STDOUT_FILENO, "\n", 1);
			break;
	}

	if (command[read_bytes - 1] == '\n')
	{
		command[read_bytes - 1] = '\0';
	}

	if (strcmp(command, "exit") == 0)
	{
			break;
	}

	else if (strcmp(command, "env") == 0)
	{
		env = getenv("PATH");

		if (env != NULL)
		{
			write(STDOUT_FILENO, env, strlen(env));
			write(STDOUT_FILENO, "\n", 1);
		}
		else
		{
			execute_command(command);
		}
	}
	return (0);
}
