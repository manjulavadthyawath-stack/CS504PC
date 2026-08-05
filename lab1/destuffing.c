#include <stdio.h>

void main() {
    int ip_frame[200], op_frame[100];
    int i, j = 0, n;
    int count = 0;

    printf("Enter the stuffed frame length: ");
    scanf("%d", &n);

    printf("Enter the stuffed frame (0's and 1's only):\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &ip_frame[i]);
    }

    for (i = 0; i < n; i++) {
        op_frame[j++] = ip_frame[i];

        if (ip_frame[i] == 1) {
            count++;
            // When 5 consecutive 1s are found, skip the next stuffed '0'
            if (count == 5) {
                i++; // Skip the stuffed bit
                count = 0; // Reset counter
            }
        } else {
            count = 0;
        }
    }

    printf("\nAfter bit de-stuffing, the original frame is:\n");
    for (i = 0; i < j; i++) {
        printf("%d", op_frame[i]);
    }
    printf("\n");
}
