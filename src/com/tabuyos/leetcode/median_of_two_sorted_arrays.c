/**
 * @Author: Tabuyos
 * @Created: 2/18/21 3:13 PM
 * @Site: www.tabuyos.com
 * @Email: tabuyos@outlook.com
 * @Description: 
 */

#include <stdio.h>
#include <math.h>

// solution 1
double findMedianSortedArraysOld(int *nums1, int nums1Size, int *nums2, int nums2Size) {
  int nums[nums1Size + nums2Size];
  int i = 0, j = 0;

  while (i != nums1Size && j != nums2Size) {
    if (nums1[i] < nums2[j]) {
      nums[i + j] = nums1[i];
      i++;
    } else {
      nums[i + j] = nums2[j];
      j++;
    }
  }
  for (; i < nums1Size; ++i) {
    nums[i + j] = nums1[i];
  }
  for (; j < nums2Size; ++j) {
    nums[i + j] = nums2[j];
  }
  double median;
  if ((nums1Size + nums2Size) % 2) {
    int high = (nums1Size + nums2Size) / 2;
    median = nums[high];
  } else {
    int high = (nums1Size + nums2Size) / 2;
    median = (nums[high - 1] + nums[high]) / 2.0;
  }
  return median;
}

int min(int num1, int num2) {
  return num1 < num2 ? num1 : num2;
}

int max(int num1, int num2) {
  return num1 > num2 ? num1 : num2;
}

int getKth(int *nums1, int nums1Size, int *nums2, int nums2Size, int k) {
  int index1 = 0, index2 = 0;
  while (1) {
    if (index1 == nums1Size) {
      return nums2[index2 + k - 1];
    }
    if (index2 == nums2Size) {
      return nums1[index1 + k - 1];
    }
    if (k == 1) {
      return min(nums1[index1], nums2[index2]);
    }
    int half = k / 2;
    int newIndex1 = min(index1 + half, nums1Size) - 1;
    int newIndex2 = min(index2 + half, nums2Size) - 1;
    int pivot1 = nums1[newIndex1], pivot2 = nums2[newIndex2];
    if (pivot1 <= pivot2) {
      k -= (newIndex1 - index1 + 1);
      index1 = newIndex1 + 1;
    } else {
      k -= (newIndex2 - index2 + 1);
      index2 = newIndex2 + 1;
    }
  }
}

// solution 2
double findMedianSortedArraysSol2(int *nums1, int nums1Size, int *nums2, int nums2Size) {
  int totalLength = nums1Size + nums2Size;
  if (totalLength % 2 == 1) {
    int midIndex = totalLength / 2;
    double median = getKth(nums1, nums1Size, nums2, nums2Size, midIndex + 1);
    return median;
  } else {
    int midIndex1 = totalLength / 2, midIndex2 = totalLength / 2 + 1;
    double median = (getKth(nums1, nums1Size, nums2, nums2Size, midIndex1)
        + getKth(nums1, nums1Size, nums2, nums2Size, midIndex2)) / 2.0;
    return median;
  }
}

#define MAX_INT ((signed) (((unsigned) (-1)) >> 1))
#define MIN_INT (~MAX_INT)

// solution 3
double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size) {
  if (nums1Size > nums2Size) {
    return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
  }
  int m = nums1Size, n = nums2Size;
  int left = 0, right = m;
  int median1 = 0, median2 = 0;
  while (left <= right) {
    int i = (left + right) / 2;
    int j = (m + n + 1) / 2 - i;
    int nums_i_1 = (i == 0 ? MIN_INT : nums1[i - 1]);
    int nums_i = (i == m ? MAX_INT : nums1[i]);
    int nums_j_1 = (j == 0 ? MIN_INT : nums2[j - 1]);
    int nums_j = (j == n ? MAX_INT : nums2[j]);
    if (nums_i_1 <= nums_j) {
      median1 = max(nums_i_1, nums_j_1);
      median2 = min(nums_i, nums_j);
      left = i + 1;
    } else {
      right = i - 1;
    }
  }
  return (m + n) % 2 == 0 ? (median1 + median2) / 2.0 : median1;
}

int main(void) {
  int nums1[] = {3};
  int nums2[] = {-2, -1};
  printf("result = %f", findMedianSortedArrays(nums1, 1, nums2, 2));
}
