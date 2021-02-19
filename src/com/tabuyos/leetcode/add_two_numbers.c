/**
 * @Author: Tabuyos
 * @Created: 2/17/21 7:01 PM
 * @Site: www.tabuyos.com
 * @Email: tabuyos@outlook.com
 * @Description: 
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node *next;
} ListNode, *LinkList;

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  ListNode *res = NULL, *tmp = NULL;
  res = tmp = malloc(sizeof(ListNode));
  int carrier = 0;
  while (l1 || l2) {
    int add1 = l1 ? l1->val : 0;
    int add2 = l2 ? l2->val : 0;
    int sum = add1 + add2 + carrier;

    tmp->next = malloc(sizeof(ListNode));
    tmp->next->val = sum % 10;
    tmp = tmp->next;
    tmp->next = NULL;

    carrier = sum / 10;
    if (l1) {
      l1 = l1->next;
    }
    if (l2) {
      l2 = l2->next;
    }
  }
  if (carrier > 0) {
    tmp->next = malloc(sizeof(ListNode));
    tmp->next->val = carrier;
    tmp->next->next = NULL;
  }
  return res->next;
}

int main(void) {
  ListNode *s;
  ListNode *l1 = malloc(sizeof(ListNode));
  ListNode *l2 = malloc(sizeof(ListNode));

  l1->next = NULL;
  s = malloc(sizeof(ListNode));
  s->val = 7, s->next = l1->next, l1->next = s;
  s = malloc(sizeof(ListNode));
  s->val = 4, s->next = l1->next, l1->next = s;
  s = malloc(sizeof(ListNode));
  s->val = 2, s->next = l1->next, l1 = s;

  l2->next = NULL;
  s = malloc(sizeof(ListNode));
  s->val = 4, s->next = l2->next, l2->next = s;
  s = malloc(sizeof(ListNode));
  s->val = 6, s->next = l2->next, l2->next = s;
  s = malloc(sizeof(ListNode));
  s->val = 5, s->next = l2->next, l2 = s;

  s = addTwoNumbers(l1, l2);
  while (s) {
    printf("%d\n", s->val);
    s = s->next;
  }
}
