#include "shell.h"

/**
 * _strdup - copes a string to another
 * @str: the array
 * Return: pointer of sting copied
 */
char *_strdup(char *str)
{
	int i, j;
	char *s = NULL;

	if (str == NULL)
		return (0);
	for (i = 0; str[i]; i++)
		;
	i++;
	s = malloc(i * sizeof(char *));
	if (!s)
		return (NULL);
	for (j = 0; j < i; j++)
	{
		s[j] = str[j];
	}
	return (s);
}



/**
 * _strlen - returns a string
 * @s: integer to be used
 * Return: length of string
 */
int _strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return ((i + 1));
}
