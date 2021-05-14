/**
 * is_numeric - checks if a string has characters considered
 * to be numeric
 * @s: pointer to a string
 * Return: (0) if non numeric characters encountered otherwise (1)
 */
int is_numeric(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (s[i])
	{
		if (i == 0 && s[i] == '-')
		{
			i++;
			continue;
		}
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
