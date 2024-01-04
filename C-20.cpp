#include <stdio.h>
#include<limits.h>
#include<algorithm> 
using namespace std;
// 辅助函数，用于找出两个有序数组的中位数
double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size) {
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    int low = 0, high = nums1Size;
    int partitionX, partitionY;
    int maxX, maxY, minX, minY;

    while (low <= high) {
        partitionX = (low + high) / 2;
        partitionY = (nums1Size + nums2Size + 1) / 2 - partitionX;

        maxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];

        minX = (partitionX == nums1Size) ? INT_MAX : nums1[partitionX];
        minY = (partitionY == nums2Size) ? INT_MAX : nums2[partitionY];

        if (maxX <= minY && maxY <= minX) {
            if ((nums1Size + nums2Size) % 2 == 0) {
                return (double)(max(maxX, maxY) + min(minX, minY)) / 2;
            } else {
                return (double)max(maxX, maxY);
            }
        } else if (maxX > minY) {
            high = partitionX - 1;
        } else {
            low = partitionX + 1;
        }
    }

    // 如果程序执行到这里，说明输入的数组不是升序的，或者有其他问题
    printf("Input arrays are not sorted!\n");
    return -1;
}

int main() {
    int A[] = {1, 3, 5, 7, 9};
    int B[] = {2, 4, 6, 8, 10};
    int size = sizeof(A) / sizeof(A[0]);

    double median = findMedianSortedArrays(A, size, B, size);
	
    if (median != -1) {
        printf("Median: %.1f\n", median);
    }
    
    int C[] = {11, 13, 15, 17, 19};
    int D[] = {2, 4, 6, 8, 20};
    size = sizeof(C) / sizeof(C[0]);

    median = findMedianSortedArrays(C, size, D, size);
	
    if (median != -1) {
        printf("Median: %.1f\n", median);
    }
    return 0;
}

