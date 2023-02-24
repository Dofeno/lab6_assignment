#include <stdio.h>

// Implementing a searching method involving checking median index, and then higher or lower depending on
//      corresponding "value" variable
int search(int numbers[], int low, int high, int value) {
    // Find Index's Median Index
    if (high >= low) {
        // Median Index
        int median = low + (high - low) / 2;
        // Check If Median Value Is Target Value
        if (numbers[median] == value) {
        return median;
        }
        if (numbers[median] > value) {
            return search(numbers, low, median - 1, value);
        }
        else if (numbers[median] < value) {
            return search(numbers, median + 1, high, value);
        }
    }
    // Not Found In Array
	return -1;
}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}