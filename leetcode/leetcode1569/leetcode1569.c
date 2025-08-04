int numOfWays(int* nums, int numsSize) {
    int mid = nums[0];
    int* leftNodes = (int*)malloc(sizeof(int)* numsSize);
    int* rightNodes = (int*)malloc(sizeof(int)* numsSize);
    int countLeft = 0;
    int countRight = 0;


    for(int i = 1; i < numsSize; i++){
        if(nums[i] <= mid){
            leftNodes[countLeft++] = nums[i];
        }
        else{
            rightNodes[countRight++] = nums[i];
            countRight++;
        }
    }
    if(countLeft == 0 || countRight == 0){
        return 0;
    }
    if(numsSize == 3){
        return 1;
    }

    return (countLeft * countRight) + 1;


}