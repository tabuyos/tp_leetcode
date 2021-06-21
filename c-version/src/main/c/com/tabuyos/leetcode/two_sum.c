/**
 * @Author: Tabuyos
 * @Created: 2/16/21 11:58 PM
 * @Site: www.tabuyos.com
 * @Email: tabuyos@outlook.com
 * @Description: 
 */

#include <stdio.h>
#include <stdlib.h>
#include <uthash.h>

// solution 1
struct hashTable {
  int key;
  int val;
  UT_hash_handle hh;
};

struct hashTable *hashtable;

struct hashTable *find(int key) {
  struct hashTable *tmp;
  HASH_FIND_INT(hashtable, &key, tmp);
  return tmp;
}

void insert(int key, int val) {
  struct hashTable *it = find(key);
  if (it == NULL) {
    struct hashTable *tmp = malloc(sizeof(struct hashTable));
    tmp->key = key, tmp->val = val;
    HASH_ADD_INT(hashtable, key, tmp);
  } else {
    it->val = val;
  }
}

int *twoSumHash(const int *nums, int numsSize, int target, int *returnSize) {
  hashtable = NULL;
  for (int i = 0; i < numsSize; ++i) {
    struct hashTable *it = find(target - nums[i]);
    if (it != NULL) {
      int *ret = malloc(sizeof(int) * 2);
      ret[0] = it->val, ret[1] = i;
      *returnSize = 2;
      return ret;
    }
    insert(nums[i], i);
  }
  *returnSize = 0;
  return NULL;
}


// solution 2
int *twoSumBruteForceAttack(const int *nums, int numsSize, int target, int *returnSize) {
  for (int i = 0; i < numsSize; ++i) {
    for (int j = i + 1; j < numsSize; ++j) {
      if (nums[i] + nums[j] == target) {
        int *ret = malloc(sizeof(int) * 2);
        ret[0] = i, ret[1] = j;
        *returnSize = 2;
        return ret;
      }
    }
  }
  *returnSize = 0;
  return NULL;
}

int main(void) {
  int nums[4] = {2, 11, 7, 15}, numsSize = 4, target = 9, returnSize = 0, *result;
  result = twoSumBruteForceAttack(nums, numsSize, target, &returnSize);
  for (int i = 0; i < returnSize; ++i) {
    printf("result[%d] = %d\n", i, result[i]);
  }
}
