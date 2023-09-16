#include "main.h"
/**
 * main - entry program
 * @argc: numbers of arguments
 * @argv: array of string
 * @env: to get environment
 * Return: always return  int
 */

int main(int argc, char *argv[], char *env[])
{
	int start = 1, err_count = 1, no_exc = 1, current;
	const char *del = " ";
	size_t n_buffer = 0;
	char *sign = "$ ", *buffer = NULL, command[50], *args[20], *only_command;

	signal(SIGINT, handle_sigint);
	if (argc != 1)
		myprintf("%s: 0: Can't open %s\n", argv[0], argv[1]), exit(1);
	if (isatty(STDIN_FILENO) == 0)
		non_interactive(argc, argv, env, &start);
	while (start == 1)
	{
		no_exc = 1;
		write(1, sign, 2);
		fflush(stdout);
		handle_input_command(&buffer, &n_buffer, &no_exc,
				&only_command, current, argc, argv, &err_count);
		if (*buffer && no_exc)
		{
			tok_buf(buffer, args, del, command, env);
			if (access(command, X_OK) == 0)
				child(argc, argv, buffer, args, only_command, &current);
			else
				fprintf(stderr, "%s: %d: %s: not found\n",
						argv[argc - 1], err_count++, only_command), fflush(stdout);
		}
		free(only_command);
	}
	return (0);
}
