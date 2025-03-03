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
  if (queue == NULL) {
    fprintf(stderr, "Queue is NULL\n");
    return;
}
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
  if (queue == NULL) {
    fprintf(stderr, "Queue is NULL\n");
    return 0.0;
} 
  if (queue->size == 0) {
    fprintf(stderr, "Queue is empty\n");
    return 0.0;
  }
  return queue->data[queue->size - 1];
}

void queue_free(Queue *queue)
{
  if (queue == NULL) {
    fprintf(stderr, "Queue is NULL\n");
    return;
}
  free(queue->data);
  free(queue);
}

void another_queue_free(Queue **queue) {
  if (queue == NULL) {
      fprintf(stderr, "queue is NULL\n");
      return;
  }
  if (*queue == NULL) {
      fprintf(stderr, "*queue is NULL\n");
      return;
  }
  free((*queue)->data);
  free(*queue);
  *queue = NULL; 
}

