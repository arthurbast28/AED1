int maxChunksToSorted(int* arr, int arrSize) {
    int chunks = 0;
    int max = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (max == i)
            chunks++;
    }
    return chunks;
}
