#include <stdio.h>
#include "tea.h"

int main() {
    char* key = "1122334455667788";

    uint8_t arr[17] = {0};
    for (int i = 0; i < 16; i++) {
        arr[i] = i;
    }

    TeaEncrypt(arr, 16, (uint8_t*)key);
    for (int i = 0; i < 16; i++) {
        printf("%02x ", arr[i]);
    }
    printf("\n");

    TeaDecrypt(arr, 16, (uint8_t*)key);
    for (int i = 0; i < 16; i++) {
        printf("%02x ", arr[i]);
    }
    printf("\n");

    return 0;
}
