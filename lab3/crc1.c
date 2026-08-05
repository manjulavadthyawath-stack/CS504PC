#include <stdio.h>

int main()
{
    int data[100], div[30], temp[100];
    int datalen = 0, divlen = 0, i, j;
    char ch;

    printf("Enter the data (binary): ");
    while ((ch = getchar()) != '\n')
    {
        if (ch == '1' || ch == '0')
            data[datalen++] = ch - '0';
    }

    printf("Enter the division (generator polynomial): ");
    while ((ch = getchar()) != '\n')
    {
        if (ch == '1' || ch == '0')
            div[divlen++] = ch - '0';
    }

    for (i = 0; i < datalen; i++)
        temp[i] = data[i];

    for (i = 0; i < divlen - 1; i++)
        temp[datalen + i] = 0;

    int totallen = datalen + divlen - 1;

    for (i = 0; i <= totallen - divlen; i++)
    {
        if (temp[i] == 1)
        {
            for (j = 0; j < divlen; j++)
            {
                temp[i + j] = temp[i + j] ^ div[j];
            }
        }
    }

    printf("(data)+");
    for (i = 0; i < datalen; i++)
        printf("%d", data[i]);

    printf("(crc)\n");

    for (i = datalen; i < totallen; i++)
    {
        printf("%d", temp[i]);
        data[i] = temp[i];
    }

    printf("\nTransmitted data (data + crc): ");

    for (i = 0; i < totallen; i++)
        printf("%d", data[i]);

    return 0;
}
