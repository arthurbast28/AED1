struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode novo;
    struct ListNode* mergedList = &novo;
    novo.next = NULL;

    while(list1 && list2){
        if(list1 -> val <= list2 -> val){
            mergedList-> next = list1;
            list1 = list1 -> next;
        }
        else{
            mergedList -> next = list2;
            list2 = list2 -> next;

        }
        mergedList = mergedList -> next;
    }
    if(list1){
        mergedList -> next = list1;
    }
    else{
        mergedList -> next = list2;
    }
    return novo.next;



}