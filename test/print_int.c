#include "shell_libs.h"
/**
 *print_dec - fdsfd
 *@numb: state
 *Return: count
 */
int print_dec(int numb)
{
	long int digits = numb, factor,  i = 0;

	if (digits == 0)
	{
		_put('0');
		i = 1;
	}
	else if (digits < 0)
	{
		_put('-');
		digits *= -1;
		i = 1;
	}
	if (digits > 0)
	{
		factor = 1;
		while (factor <= digits)
		{
			factor *= 10;
		}
		while (factor > 1)
		{
			factor /= 10;
			_put('0' + (digits / factor));
			digits %= factor;
			i++;
		}
	}
	return (i);
}
