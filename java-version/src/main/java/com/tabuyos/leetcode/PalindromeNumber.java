package com.tabuyos.leetcode;

/** @author tabuyos */
public class PalindromeNumber {

  public static boolean isPalindrome1(int x) {
    if (x < 0) {
      return false;
    }
    int old = x;
    int result = 0;
    while (x != 0) {
      int mod = x % 10;
      x = x / 10;
      if (result > Integer.MAX_VALUE / 10 || (result == Integer.MAX_VALUE / 10 && mod > 7)) {
        return false;
      }
      if (result < Integer.MIN_VALUE / 10) {
        return false;
      }
      result = result * 10 + mod;
    }
    return result == old;
  }

  public static boolean isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) {
      return false;
    }
    int revert = 0;
    while (x > revert) {
      revert = revert * 10 + x % 10;
      x /= 10;
    }
    return revert == x || x == revert / 10;
  }

  public static void main(String[] args) {
    System.out.println(isPalindrome(1221));
  }
}
