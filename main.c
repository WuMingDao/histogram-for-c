#include <stdio.h>
#include <stdlib.h>

#define SAMPLE_COUNT 16
#define ROWS 5
#define COLS 10

int main(void) {
  float data[SAMPLE_COUNT];

  for (size_t i = 0; i < SAMPLE_COUNT; i++) {
    data[i] = (float)random() / RAND_MAX; // random number for 0~1
    
    // debug 
    printf("%.2f ", data[i]);
  }
  puts("");

  // track keep bucket count
  size_t buckets[COLS] = {0};
  
  for (size_t i = 0; i < SAMPLE_COUNT; i++) {
    size_t bucket_index = data[i] * COLS;

    buckets[bucket_index]++;
  }

  // DEBUG buckets
  for (size_t i = 0; i < COLS; i++) {
    printf("%zu ", buckets[i]);
  }
  puts("");

  // Plotting
  for (size_t i = 0; i < ROWS; i++) {
    size_t height = ROWS - 1 - i;
    for (size_t j = 0; j < COLS; j++) {
      if (buckets[j] > height) {
        printf("#");
      } else {
        printf(" ");
      }
    }
    puts("");
  }

  return 0;
}
