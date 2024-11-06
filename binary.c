#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char bnr[33]; 

void codec();
int dec(char s[]);

int main() {
    printf("Conversion to decimal\n");
    printf("Enter the 32-bit binary address:\n");
    scanf("%32s", bnr); 

    if (strlen(bnr) != 32) {
        printf("Error: The input should be exactly 32 bits long.\n");
        return 1;
    }

    codec();
    return 0;
}

void codec() {
    int i;
    char segment[9]; 

    for (i = 0; i < 32; i += 8) {
        strncpy(segment, bnr + i, 8); 
        segment[8] = '\0'; 
        int decimalValue = dec(segment);
        printf("%d ", decimalValue);
    }
    printf("\n");
}

int dec(char s[]) {
    int sum = 0;
    int i;
    for (i = 0; i < 8; i++) {
        if (s[i] == '1') {
            sum += (1 << (7 - i)); 
        }
    }
    return sum;
}