// Two files: average_case.txt & worst_case.txt
// Supports both command line arguments and choice based inputs

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The size of array has to be changed in accordance with the number of elements in the file
// Otherwise the sorting algorithm takes too long to iterate through unnecessary elements
int numberArray[200000];

int partition(int a[], int p, int r)
{
  int t = a[p];
  int q = p;
  for (int i = p + 1; i <= r; i++)
    if (a[i] < t)
    {
      a[q++] = a[i];
      if (q < i)
        a[i] = a[q];
    }
  a[q] = t;
  return q;
}

void quickSort(int a[], int p, int r)
{
  if (p < r)
  {
    int q = partition(a, p, r);
    quickSort(a, p, q - 1);
    quickSort(a, q + 1, r);
  }
}

void display(int a[], int start, int end, char *msg)
{
  printf("\n%s", msg);
  for (int i = start; i < end; i++)
  {
    if (a[i] != -1)
    {
      printf("%d, ", a[i]);
    }
  }
  printf("....\n\n");
}

// Main
int main(int argc, char *argv[])
{
  // Calculating the length of the array
  int length = sizeof(numberArray) / sizeof(numberArray[0]);

  // To avoid printing leading/trailing zeros if
  // array size and elements in files doesn't match
  for (int x = 0; x < length; x++)
  {
    numberArray[x] = -1;
  }
  int choice;
  char *filename = malloc(30);
  if (argc >= 2) // Case: filename is given as command line argument
  {
    strcpy(filename, argv[1]);
  }
  else // Case: filename not given as command line argument
  {
    printf("1: Average Case Numbers (Random Numbers)\n2: Worst Case Numbers (Sorted Numbers)\nChoice: ");
    scanf("%d", &choice);
    if (choice == 1)
    {
      strcpy(filename, "average_case.txt");
    }
    else
    {
      strcpy(filename, "worst_case.txt");
    }
  }
  // Reading from file
  printf("\nReading from %s\n", filename);
  FILE *file = fopen(filename, "r");
  free(filename);
  int i;
  for (i = 0; i < length; i++)
  {
    fscanf(file, "%d", &numberArray[i]);
  }
  fclose(file);
  printf("Read complete\n");
  printf("\nLength of the array: %d\n", length);

  // Displaying elements of array
  display(numberArray, 0, 15, "Array before sorting: ");

  // Quick Sort
  printf("Sorting started\n");
  quickSort(numberArray, 0, length - 1);
  printf("Sorting complete\n");

  // Displaying elements of array
  display(numberArray, 0, 15, "Array after sorting: ");
  return 0;
}
