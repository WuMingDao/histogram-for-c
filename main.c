#include <stdio.h>
#include <stdlib.h>

#define SAMPLE_COUNT 1000
#define ROWS 16
#define COLS 120

int main(void) {
  // generate data
  float data[SAMPLE_COUNT];

  for (size_t i = 0; i < SAMPLE_COUNT; i++) {
    data[i] = (float)random() / RAND_MAX; // random number for 0~1
  }
  puts("");

  // track keep bucket count
  size_t buckets[COLS] = {0};
  size_t bucket_max = 0;
  
  for (size_t i = 0; i < SAMPLE_COUNT; i++) {
    size_t bucket_index = data[i] * COLS;

    buckets[bucket_index]++;

    if (buckets[bucket_index] > bucket_max) {
      bucket_max = buckets[bucket_index];
    }
  }

  // scale heights
  for (size_t i = 0; i < COLS; i++) {
    buckets[i] = (buckets[i] * ROWS) / bucket_max;
  }

  // Plotting
  for (size_t i = 0; i < ROWS; i++) {
    size_t height = ROWS - 1 - i;
    for (size_t j = 0; j < COLS; j++) {
      if (buckets[j] > height) {
        printf("\u2588");
      } else {
        printf(" ");
      }
    }
    puts("");
  }

  return 0;
}
