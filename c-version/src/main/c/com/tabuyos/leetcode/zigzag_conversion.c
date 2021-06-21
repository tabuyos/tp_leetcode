/**
 * @Author: Tabuyos
 * @Created: 3/24/21 9:56 PM
 * @Site: www.tabuyos.com
 * @Email: tabuyos@outlook.com
 * @Description: 
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

// solution 1
char *convertByCustom(char *s, int numRows) {
  int len = (int) strlen(s);
  int start = 0;
  int line;
  if (len <= 1) {
    return s;
  }
  if (numRows == 1) {
    return s;
  }
  if (len % (numRows * 2 - 2) == 0) {
    line = len / (numRows * 2 - 2) * 2;
  } else {
    line = len / (numRows * 2 - 2) * 2 + 1;
  }
  char zig[line][numRows];
  printf("%s\n", s);
  for (int i = 0; i < line; ++i) {
    if (i % 2 == 0) {
      for (int j = 0; j < numRows; ++j) {
        zig[i][j] = s[start++];
      }
    } else {
      for (int j = 0; j < numRows; ++j) {
        if (j == 0) {
          zig[i][0] = ' ';
        } else if (j == numRows - 1) {
          zig[i][numRows - 1] = ' ';
        } else {
          zig[i][j] = s[start++];
        }
      }
    }
  }
  start = 0;
  for (int i = 0; i < numRows; ++i) {
    for (int j = 0; j < line; ++j) {
      if (start == len) {
        break;
      }
      if (j % 2 == 0) {
        if (zig[j][i] == '\0') {
          continue;
        }
        s[start++] = zig[j][i];
      } else {
        if (zig[j][numRows - 1 - i] == ' ') {
          continue;
        } else {
          s[start++] = zig[j][numRows - 1 - i];
        }
      }
    }
  }
  return s;
}

char *convert(char *s, int numRows) {
  if (numRows == 1) {
    return s;
  }
  int cr = 0;
  int line = 10;
  int len = (int) strlen(s);
  int size = 10;
  char rows[10][20] = {};
  int isDown = 0;
  for (int i = 0; i < len; ++i) {
    strcat(rows[cr], s[i]);
    if (cr == 0 || cr == numRows - 1) {
      isDown = (isDown + 1) % 2;
    }
    cr += isDown == 1 ? 1 : - 1;
  }
  return rows;
}

int main(void) {
  char s[] = "PAYPALISHIRING";
  int numRows = 4;
  printf("%s\n", convert(s, numRows));
}