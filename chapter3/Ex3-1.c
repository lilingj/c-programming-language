#include "assert.h"
/*
  @link https://leetcode.cn/problems/binary-search/description/
  和书中的例子相比，每次循环少一次比较。如果有 target 在数组中重复，程序会找出最左边的一个，而例子找到后会直接退出
  程序测试直接使用leetcode就行。
*/
int search(int* nums, int numsSize, int target) {
    int l = 0, r = numsSize - 1;
    while(l < r) {
        int m = (l + r) / 2;
        (target <= nums[m]) ? (r = m) : (l = m + 1);
    }
    return target == nums[r] ? r : -1;
}

// unit test
/*
  一点思考：注意这个程序中，l 和 r 在逻辑上并不是对称的，如果把 l 和 r 调换，并且将逻辑反转，结果并不是“找到最右边的target”
    而是死循环。例如，target命中下标 3 的数，而 l = 3，r = 4，逻辑反转后，m 总是等于 (3 + 4) / 2 = 3，而 l 总是被赋值 3
    整个程序死循环。
*/
int main(void) {
  assert(search((int[]){1, 2, 3, 3, 3, 3, 3}, 7, 3) == 2);
  return 0;
}
