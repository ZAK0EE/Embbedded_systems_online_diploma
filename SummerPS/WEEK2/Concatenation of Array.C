

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize){
    
    *returnSize = numsSize * 2;
    int *ans = malloc(*returnSize * sizeof(int));
    
    memcpy(ans, nums , numsSize * sizeof(int));
    memcpy(&ans[numsSize], nums , numsSize*sizeof(int));

    
    return ans;

}