/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void reorderList(struct ListNode* head) {
    // Trata casos onde a lista tem 0, 1 ou 2 elementos
    if (!head || !head->next || !head->next->next) return;

    // Aloca espaço para armazenar os valores dos nós
    int* nodeValues = (int*)malloc(50000 * sizeof(int));
    int count = 0;
    struct ListNode* current = head;

    // Armazena todos os valores na array
    while (current) {
        nodeValues[count++] = current->val;
        current = current->next;
    }

    current = head;
    int halfLength = count / 2;

    // Reconstrue a lista com a nova ordem
    for (int i = 0; i < halfLength; i++) {
        current->val = nodeValues[i];
        current->next->val = nodeValues[count - 1 - i];
        current = current->next->next;
    }

    // Se o tamanho for ímpar, mantém o valor do nó central
    if (count % 2) {
        current->val = nodeValues[halfLength];
    }

    free(nodeValues);
}