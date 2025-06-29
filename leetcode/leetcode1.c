int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    
    int* indices = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    
    
    int max_num = 2000; 
    int hash[max_num * 2 + 1]; 
    
  
    memset(hash, -1, sizeof(hash));
    

    for (int i = 0; i < numsSize; i++) {
        int complemento = target - nums[i];
        int indice_complemento = hash[complemento + max_num];
        
        if (indice_complemento != -1) {
            indices[0] = indice_complemento;
            indices[1] = i;
            return indices;
        }
        

        hash[nums[i] + max_num] = i;
    }
    

    indices[0] = indices[1] = -1;
    return indices;
}