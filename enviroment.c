#include "main.h"

/**
 * _env - Print environment variables
 * Return: void
 */
void _env(void)
{
	char **env_ptr = environ;

	while (*env_ptr)
	{
		myprintf("%s\n", *env_ptr);
		env_ptr++;
	}
}


/**
 * _envNon - Print environment variables
 * @no_exc: num to handle continue to fork
 * Return: void
 */
void _envNon(int *no_exc)
{
	char **env_ptr = environ;
	*no_exc = 0;
	while (*env_ptr)
	{
		myprintf("%s\n", *env_ptr);
		env_ptr++;
	}
}

