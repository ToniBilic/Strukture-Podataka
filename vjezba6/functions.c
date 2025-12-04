#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "errors.h"
#include "receipt.h"
#include "item.h"

int printAll(receipt* head) {
    while (head) {
        printf("\nReceipt: %s\n", head->date);
        item* i = head->item;
        while (i) {
            printf("  %s | %d | %.2f\n", i->type, i->q, i->price);
            i = i->next;
        }
        head = head->next;
    }

    return EXIT_SUCCESS;
}