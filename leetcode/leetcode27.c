int removeElement(int* nums, int numsSize, int val) {

    int index_clean = 0;
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[index_clean] = nums[i];
            index_clean++;
        }
    }

    return index_clean;
}