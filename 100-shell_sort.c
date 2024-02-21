#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using the Shell
 *              sort algorithm with the Knuth sequence.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	size_t range = 1, i, k;
	int temp;

	while (range < size / 3)
		range = range * 3 + 1;

	while (range > 0)
	{
		for (i = range; i < size; i++)
		{
			temp = array[i];
			k = i;

			while (k >= range && array[k - range] > temp)
			{
				array[k] = array[k - range];
				k -= range;
			}

			array[k] = temp;
		}

		print_array(array, size);
		range /= 3;
	}
}
