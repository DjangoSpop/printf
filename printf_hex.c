#include "main.h"

/**
<<<<<<< HEAD
 * printf_HEX - prints an hexgecimal number.
 * @val: arguments.
 * Return: counter.
 */
int printf_HEX(va_list val)
=======
 * printf_hex - prints an hexgecimal number.
 * @val: arguments.
 * Return: counter.
 */
int printf_hex(va_list val)
>>>>>>> 0d40c577c7e9fa37eec9cfb451f18f3c1cd12762
{
	int i;
	int *array;
	int counter = 0;
	unsigned int num = va_arg(val, unsigned int);
	unsigned int temp = num;

	while (num / 16 != 0)
	{
		num /= 16;
		counter++;
	}
	counter++;
	array = malloc(counter * sizeof(int));

	for (i = 0; i < counter; i++)
	{
		array[i] = temp % 16;
		temp /= 16;
	}
	for (i = counter - 1; i >= 0; i--)
	{
		if (array[i] > 9)
<<<<<<< HEAD
			array[i] = array[i] + 7;
=======
			array[i] = array[i] + 39;
>>>>>>> 0d40c577c7e9fa37eec9cfb451f18f3c1cd12762
		_putchar(array[i] + '0');
	}
	free(array);
	return (counter);
}
