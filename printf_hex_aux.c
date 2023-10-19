#include "main.h"

/**
<<<<<<< HEAD
 * printf_HEX_aux - prints an hexgecimal number.
 * @num: number to print.
 * Return: counter.
 */
int printf_HEX_aux(unsigned int num)
{
	int i;
	int *array;
	int counter = 0;
	unsigned int temp = num;
=======
 * printf_hex_aux - prints an hexgecimal number.
 * @num: arguments.
 * Return: counter.
 */
int printf_hex_aux(unsigned long int num)
{
	long int i;
	long int *array;
	long int counter = 0;
	unsigned long int temp = num;
>>>>>>> 0d40c577c7e9fa37eec9cfb451f18f3c1cd12762

	while (num / 16 != 0)
	{
		num /= 16;
		counter++;
	}
	counter++;
<<<<<<< HEAD
	array = malloc(counter * sizeof(int));
=======
	array = malloc(counter * sizeof(long int));
>>>>>>> 0d40c577c7e9fa37eec9cfb451f18f3c1cd12762

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
