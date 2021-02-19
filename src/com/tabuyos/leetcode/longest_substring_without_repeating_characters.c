/**
 * @Author: Tabuyos
 * @Created: 2/17/21 10:17 PM
 * @Site: www.tabuyos.com
 * @Email: tabuyos@outlook.com
 * @Description: 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MaxSize 128

typedef struct {
  char data[MaxSize];
  int front, rear;
} Queue;

int init(Queue *queue) {
  queue->front = queue->rear = 0;
  return 1;
}

int full(Queue *queue) {
  if (((queue->rear + 1) % MaxSize) == queue->front) {
    return 1;
  } else {
    return 0;
  }
}

int inQueue(Queue *queue, char ch) {
  if (full(queue)) {
    printf("queue is full.");
    return 0;
  }
  queue->rear = (queue->rear + 1) % MaxSize;
  queue->data[queue->rear] = ch;
  return 1;
}

int empty(Queue *queue) {
  if (queue->rear == queue->front) {
    return 1;
  } else {
    return 0;
  }
}

int outQueue(Queue *queue, char *ch) {
  if (empty(queue)) {
    printf("queue is free.");
    return 0;
  }
  queue->front = (queue->front + 1) % MaxSize;
  *ch = queue->data[queue->front];
  return 1;
}

int check(Queue *queue, char ch) {
  int index = (queue->front + 1) % MaxSize;
  while (index != (queue->rear + 1)) {
    if (queue->data[index] == ch) {
      return 1;
    }
    index = (index + 1) % MaxSize;
  }
  return 0;
}

char *get(Queue *queue) {
  char *string = malloc(sizeof(char) * 128);
  int index = (queue->front + 1) % MaxSize;
  int i = 0;
  while (index != (queue->rear + 1)) {
    string[i++] = queue->data[index];
    index = (index + 1) % MaxSize;
  }
  return string;
}

// solution 1
int lengthOfLongestSubstringOld(char *s) {
  Queue *queue = malloc(sizeof(Queue));
  init(queue);
  int len = (int) strlen(s);
  char ch;
  char *res;
  int max = 0;
  for (int i = 0; i < len; ++i) {
    if (check(queue, s[i])) {
      char *tmp = get(queue);
      max = strlen(tmp) > max ? (int) strlen(tmp) : max;
      outQueue(queue, &ch);
      while (ch != s[i]) {
        outQueue(queue, &ch);
      }
    }
    inQueue(queue, s[i]);
  }
  char *tmp = get(queue);
  max = strlen(tmp) > max ? (int) strlen(tmp) : max;
  return max;
}

// solution 2
int lengthOfLongestSubstring(const char *s) {
  int i, len = (int) strlen(s), count, max = 0, index[128] = {0}, start = 0;
  for (i = 0; i < len; i++) {
    char ch = s[i];
    if (index[ch] > start) {
      count = i - start;
      if (count > max) {
        max = count;
      }
      start = index[ch];
    }
    index[ch] = i + 1;
  }
  count = i - start;
  if (count > max) {
    max = count;
  }
  return max;
}

int main(void) {
  char s[] = "tabauyaos";
  printf("%d\n", lengthOfLongestSubstring(s));
}

