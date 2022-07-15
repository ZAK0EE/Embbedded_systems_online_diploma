

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* buildArray(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int *ans = malloc(*returnSize * sizeof(int));
    
    for(int i = 0; i < *returnSize; i++)
    {
        ans[i] = nums[nums[i]];
    }
    
    for(int i = 0; i < *returnSize; i++)
    {
        nums[i] = ans[i];
    }
    
    free(ans);
    
    return nums;
}