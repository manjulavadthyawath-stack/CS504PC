#include <stdio.h>
#include <string.h>

void main() {
    int i = 0, j = 0, n;
    char b[100], a[20];

    printf("enter the stuffed string:\n");
    scanf("%s", b);
    n = strlen(b);

    // Skip the header framing pattern "diestx" (first 6 characters)
    i = 6;

    // Loop until reaching the trailer framing pattern "dieetx" (last 6 characters)
    while (i < n - 6) {
        // Case 1: Check for inserted stuffed sequence "die" + <ch> + "die"
        // Total pattern length = 3 ('die') + 1 (character) + 3 ('die') = 7
        if (b[i] == 'd' && b[i+1] == 'i' && b[i+2] == 'e' && 
            b[i+4] == 'd' && b[i+5] == 'i' && b[i+6] == 'e') {
            
            // Skip the entire 7-character stuffed block ("die" + ch + "die")
            i += 7;
        }
        // Case 2: Check for escaped "die" pattern inside original data
        else if (b[i] == 'd' && b[i+1] == 'i' && b[i+2] == 'e' && 
                 b[i+3] == 'd' && b[i+4] == 'i' && b[i+5] == 'e') {
            
            // Skip the first "die" escape prefix and copy the actual "die"
            i += 3;
            a[j++] = b[i++];
            a[j++] = b[i++];
            a[j++] = b[i++];
        }
        // Case 3: Normal character
        else {
            a[j++] = b[i++];
        }
    }

    a[j] = '\0'; // Null-terminate the recovered original string

    printf("\nstring after de-stuffing:\n%s\n", a);
}
