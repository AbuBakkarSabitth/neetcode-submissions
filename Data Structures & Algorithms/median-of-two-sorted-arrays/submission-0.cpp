#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& num1, vector<int>& num2) {

        // Always binary search on smaller array
        if (num1.size() > num2.size()) {
            swap(num1, num2);
        }

        int x = num1.size();
        int y = num2.size();

        int low = 0;
        int high = x;

        while (low <= high) {

            int partitionX = (low + high) / 2;
            int partitionY = (x + y + 1) / 2 - partitionX;

            int maxLeftX =
                (partitionX == 0)
                ? INT_MIN
                : num1[partitionX - 1];

            int minRightX =
                (partitionX == x)
                ? INT_MAX
                : num1[partitionX];

            int maxLeftY =
                (partitionY == 0)
                ? INT_MIN
                : num2[partitionY - 1];

            int minRightY =
                (partitionY == y)
                ? INT_MAX
                : num2[partitionY];

            // Correct partition found
            if (maxLeftX <= minRightY &&
                maxLeftY <= minRightX) {

                // Even total elements
                if ((x + y) % 2 == 0) {

                    return (
                        max(maxLeftX, maxLeftY) +
                        min(minRightX, minRightY)
                    ) / 2.0;
                }
                else {
                    // Odd total elements
                    return max(maxLeftX, maxLeftY);
                }
            }

            // Move left
            else if (maxLeftX > minRightY) {
                high = partitionX - 1;
            }

            // Move right
            else {
                low = partitionX + 1;
            }
        }

        return 0.0;
    }
};