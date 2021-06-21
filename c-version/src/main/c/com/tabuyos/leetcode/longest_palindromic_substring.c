/**
 * @Author: Tabuyos
 * @Created: 2/19/21 4:28 PM
 * @Site: www.tabuyos.com
 * @Email: tabuyos@outlook.com
 * @Description: 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// solution 1
char *longestPalindromeSol1(char *s) {
  int len = (int) strlen(s);
  int max = 0, start = 0;
  for (int i = 0; i < len; ++i) {
    int n = i - 1, m = i + 1;
    while (m < len) {
      if (s[m - 1] == s[m]) {
        m = m + 1;
      } else {
        break;
      }
    }
    while (n >= 0 && m < len) {
      if (s[n] == s[m]) {
        n--, m++;
      } else {
        break;
      }
    }
    n++, m--;
    if ((m - n + 1) > max) {
      max = m - n + 1;
      start = n == -1 ? 0 : n;
    }
  }
  s[start + max] = '\0';
  return s + start;
}

// solution 2
char *longestPalindrome(char *s) {
  if (strlen(s) == 0 || strlen(s) == 1) return s;
  int i, start, left, right, count, len;
  start = len = 0;
  for (i = 0; s[i] != '\0'; i += count) {
    count = 1;
    left = i - 1;
    right = i + 1;
    //处理重复字符串
    while (s[right] != '\0' && s[i] == s[right]) {
      right++;
      count++;
    }
    while (left >= 0 && s[right] != '\0' && s[left] == s[right]) {
      left--;
      right++;
    }
    if (right - left - 1 > len) {
      start = left + 1;
      len = right - left - 1;
    }
  }
  // 原地修改返回
  s[start + len] = '\0';
  return s + start;
}

int main(void) {
  char s[] = "babad";
  printf("hello. %s\n", longestPalindrome(s));
}

