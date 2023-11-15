#include <unistd.h>

/**
 * my_putchar - that prints a character
 * @c: function parameter
 */

void my_putchar(char c)
{
	write(1, &c, 1);
}

/**
 * my_puts - function that handles a string
 * @str: function parameter
 */

void my_puts(char *str)
{
	while (*str)
	{
		my_putchar(*str);
		str++;
	}
}

/**
 * main - main function
 */

int main(void)
{
	char message[] = "Hello, Betty!";

	my_puts(message);

	return (0);
}
