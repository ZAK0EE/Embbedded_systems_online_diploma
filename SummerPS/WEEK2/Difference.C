

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findDifference(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize, int** returnColumnSizes){
    
    *returnSize = 2;
    int **ans = malloc(sizeof(int*) * (*returnSize));
    ans[0] = malloc(sizeof(int) * nums1Size);
    ans[1] = malloc(sizeof(int) * nums2Size);
    
    int ans0Size, ans1Size;
    ans0Size= ans1Size= 0;
    
    int freq1[2001] = {0};
    int freq2[2001] = {0};
    
    for(int i = 0; i < nums1Size; i++)
    {
        freq1[nums1[i] + 1000] = 1;
    }
    
    for(int i = 0; i < nums2Size; i++)
    {
        freq2[nums2[i] + 1000] = 1;
    }
    
    for(int i = 0; i < 2001; i++)
    {
        if(freq1[i] != 0 && freq1[i] != freq2[i])
        {
            ans[0][ans0Size++] = i - 1000;
        }
        else if(freq2[i] != 0 && freq2[i] != freq1[i])
        {
           ans[1][ans1Size++] = i - 1000; 
        }
    } 
    
    *returnColumnSizes = malloc(sizeof(int) * (*returnSize));
    (*returnColumnSizes)[0] = ans0Size;
    (*returnColumnSizes)[1] = ans1Size;

    return ans;
    
    

}