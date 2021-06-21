package com.tabuyos.leetcode;

import java.util.ArrayList;
import java.util.List;

/** @author tabuyos */
public class ZigzagConversion {

  public String convert1(String s, int numRows) {
    if (numRows == 1) {
      return s;
    }
    List<StringBuilder> rows = new ArrayList<>();
    for (int i = 0; i < Math.min(numRows, s.length()); i++) {
      rows.add(new StringBuilder());
    }
    int cr = 0;
    boolean isDown = false;
    for (char c : s.toCharArray()) {
      rows.get(cr).append(c);
      if (cr == 0 || cr == numRows - 1) {
        isDown = !isDown;
      }
      cr += isDown ? 1 : -1;
    }
    StringBuilder ret = new StringBuilder();
    for (StringBuilder row : rows) {
      ret.append(row);
    }
    return ret.toString();
  }

  public String convert2(String s, int numRows) {
    if (numRows == 1) {
      return s;
    }
    List<StringBuilder> rows = new ArrayList<>();
    for (int i = 0; i < numRows; i++) {
      rows.add(new StringBuilder());
    }
    int i = 0, flag = -1;
    for (char c : s.toCharArray()) {
      rows.get(i).append(c);
      if (i == 0 || i == numRows - 1) {
        flag = -flag;
      }
      i += flag;
    }
    StringBuilder res = new StringBuilder();
    for (StringBuilder row : rows) {
      res.append(row);
    }
    return res.toString();
  }

  public String convert(String s, int numRows) {

    if (numRows == 1) {
      return s;
    }

    StringBuilder ret = new StringBuilder();
    int n = s.length();
    int cycleLen = 2 * numRows - 2;

    for (int i = 0; i < numRows; i++) {
      for (int j = 0; j + i < n; j += cycleLen) {
        System.out.println("i: " + i + ", j: " + j);
        ret.append(s.charAt(j + i));
        if (i != 0 && i != numRows - 1 && j + cycleLen - i < n) {
          ret.append(s.charAt(j + cycleLen - i));
        }
      }
    }
    return ret.toString();
  }

  public static void main(String[] args) {
    System.out.println(new ZigzagConversion().convert("PAYPALISHIRING", 4));
  }
}
