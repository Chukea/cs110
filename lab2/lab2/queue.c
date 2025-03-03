#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

Queue *queue_create(void)
{
  Queue *queue = malloc(sizeof(Queue));
  if (queue == NULL) {
      fprintf(stderr, "fail for malloc Queue\n");
      return NULL;
  }

  queue->size = 0;
  queue->capacity = QUEUE_INITIAL_CAPACITY;
  queue->data = malloc(sizeof(double) * queue->capacity);
  if (queue->data == NULL) {
      fprintf(stderr, "fail for malloc data\n");
      free(queue);
      return NULL;
  }
  return queue;
}



void push(Queue *queue, double element)
{

  if (queue->size == queue->capacity)
  {
    int capacity = queue->capacity * 2;
    queue->data = realloc(queue->data, sizeof(double) * capacity);
    if (queue->data == NULL) {
        fprintf(stderr, "fail for realloc\n");
        return;
    }
    queue->capacity = capacity;
  }

  int insert_index = queue->size % queue->capacity;
  queue->data[insert_index] = element;
  queue->size++;
}

double back(Queue *queue)
{
  return queue->data[queue->size - 1];
}

void queue_free(Queue *queue)
{

  free(queue->data);
  free(queue);
}

