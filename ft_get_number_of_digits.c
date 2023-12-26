int get_number_of_digits(int n, int baselen)
{
	int i;

	i = 0;
	if (baselen <= 0)
		return (-1);
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
		n /= baselen;
		i++;
	return (i)
}
