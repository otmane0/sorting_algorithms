#include "sort.h"

/**
 * selection_sort - func
 * @array: inputs
 * @size: in
*/


void selection_sort(int *array, size_t size)
{
	size_t i, j, k;
	int temp;

	if (!array || !size)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = size - 1; k = i + 1; j--)
		{
			if (array[j] < array[k])
			{
				k = j;
			}
		}

		if (array[j] < array[k])
		{
			temp = array[i];
			array[i] = array[k];
			array[k] = temp;
			print_array(array, size);
		}
	}
}
