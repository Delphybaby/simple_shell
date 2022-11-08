#include "shell.h"

/**
 *str_concat - back a pointer to array
 *@s1: Array one
 *@s2: Array two
 *Return: Always an array dinamic
 */

char *str_concat(char *s1, char *s2)
{
	char *dst;
	unsigned int i, j, size;

	/*If the array is empty*/
	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	/*count size total*/
	size = (_strlen(s1) + _strlen(s2) + 1);

	dst = (char *) malloc(size * sizeof(char));

	if (dst == 0)
	{
		return (NULL);
	}

	/*Concatenate arrays*/
	for (i = 0; *(s1 + i) != '\0'; i++)
		*(dst + i) = *(s1 + i);

	for (j = 0; *(s2 + j) != '\0'; j++)
	{
		*(dst + i) = *(s2 + j);
		i++;
	}
	dst[i] = '\0';

	return (dst);
}
/**
 * _itoa - integer to ascii
 * @num: num
 * @base: base
 * Return: char
 * Reference: https://gist.github.com/narnat/95733cd0ad7bfac0d90697292914c407
 *
 */
char *_itoa(int num, int base)
{
	static char *array = "0123456789abcdef";
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (num < 0)
	{
		n = -num;
		sign = '-';
	}
	ptr = &buffer[49];
	*ptr = '\0';

	do      {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * _strcmp - compare two strings
 * @s1: string one
 * @s2: string two
 * Return: returns an integer less  than,  equal  to,  or
 * greater  than zero if s1 is found, respectively, to be
 * less than, to match, or be greater than s2.
 */
int _strcmp(char *s1, char *s2)
{
	char *p1 = s1;
	char *p2 = s2;

	while (*p1 != '\0' && *p2 != '\0' && *p1 == *p2)
	{
		p1++;
		p2++;
	}
	return (*p1 - *p2);
}

/**
 * sparse_str - devides a string into and array of strings
 * @line: the string to be separated
 * @env: environment variable
 * Return: tokens(array of strings) on succes or EXIT_FAILURE if fails
 */
char **sparse_str(char *line, char **env)
{
	int bufsize = TOK_BUFSIZE, posicion = 0;
	char **tokens;
	char *token;

	if (line == NULL)
	{
		return (0);
	}
	tokens = _calloc(sizeof(char *), bufsize);
	if (!tokens)
	{
		perror("error");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, TOK_DELIM);
	while (token != NULL)
	{
		tokens[posicion] = token;
		posicion++;
		token = strtok(NULL, TOK_DELIM);
	}
	if (tokens[0] == NULL)
		tokens[posicion] = "\n";

	if ((_strcmp(tokens[0], "exit") == 0) && tokens[1] == NULL)
	{
		free(line);
		free(tokens);
		exit(0);
	}
	if ((_strcmp(tokens[0], "env") == 0) && tokens[1] == NULL)
		func_printenv(env);

	return (tokens);
}
