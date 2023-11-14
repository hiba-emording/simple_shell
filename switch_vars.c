#include "main.h"

/**
 * switch_vars - switches vars in the tokenized string.
 * @args: Array of tokenized command-line args.
 * @last_exit_status: Pointer to the last exit status variable.
 *
 * Return: 1 if replaced, 0 otherwise.
 */
int switch_vars(char **args, int *last_exit_status)
{
	int i = 0;
	char *value;

	for (i = 0; args[i]; i++)
	{
		if (args[i][0] == '$' && args[i][1] != '\0')
		{
			if (args[i][1] == '?')
				_sstr(&(args[i]), _itoa(*last_exit_status, 10, 0));

			else if (args[i][1] == '$')
				_sstr(&(args[i]), _itoa(getpid(), 10, 0));

			else
			{
				value = _getenv(args[i] + 1);

				if (value)
					_sstr(&(args[i]), value);
				else
					_sstr(&(args[i]), _strdup(""));
			}
		}
	}

	return (0);
}
