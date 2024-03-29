#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "stdbool.h"

#define MAX_SIZE 1000
#define RANDOM_NUM_FILE "/home/project/bubble_sort/src/random_numbers.txt"
#define SORTED_NUM_FILE "/home/project/bubble_sort/src/sorted_numbers.txt"

void swap(int *swap, int *replace_with) {
  int temp;
  temp = *swap;
  *swap = *replace_with;
  *replace_with = temp;
}

int main(void) {
  int  array[MAX_SIZE];
  uint32_t index;
  uint32_t max_array_size;
  bool no_file_open;
  FILE *random_file_ptr, *sorted_file_ptr;
  
  // Inform user what this program will accomplish
  printf("This program Bubble Sorts the items in %s file and stores the sorted list in %s\n", RANDOM_NUM_FILE, SORTED_NUM_FILE);
  
  // open file with the random numbers and load them into the array
  random_file_ptr = fopen(RANDOM_NUM_FILE, "r");

  no_file_open = (random_file_ptr == 0) ? true : false;

  if (no_file_open) {
    printf("\nNo File found to open. Aborting Bubble Sort.\n");
    exit(0);
  }

  // load random numbers into array
  index = 0;
  while ((fscanf(random_file_ptr,"%d",&array[index]) == 1) && (index < MAX_SIZE)) {
    index++;
  }
  // close file that contained the random numbers
  fclose(random_file_ptr);
  
  // Print sorting in process
  printf("\nSorting in process ...\n");
  
  // Bubble sort routine
  for (uint32_t i = 0; i < (index - 1); i++) {
    for (uint32_t j = 0; j < (index - i - 1); j++) {
       if (array[j] > array[j+1]) swap(&array[j+1], &array[j]);
    }
  }
    
  // Saving sorted list to file
  printf("\nSaving sorted list to file ...\n");
  
  // open file to save sorted list
  sorted_file_ptr = fopen(SORTED_NUM_FILE, "w");
  // save sorted list of numbers
  for (uint32_t i = 0; i < index; i++) {
    fprintf(sorted_file_ptr, "%d\n", array[i]);
    printf("%d\n",array[i]);
  }
  // close sorted number file
  fclose(sorted_file_ptr);
  
  // notify user that the program that the sorting has completed
  printf("\nSorting has been completed for %d items and saved in the file %s\n", index, SORTED_NUM_FILE);
}
