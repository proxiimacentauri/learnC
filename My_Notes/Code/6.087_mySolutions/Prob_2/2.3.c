/////////////////////////////////////////////////////
//  Consider int val=0xCAFE
//      Write expressions using bitwise operators that do the following:
//      - test if atleast three of last four bits (LSB) are on
//      - reverse the byte order (i.e., produce val=0xFECA)
//      - rotate fourbits (i.e., produce val=0xECAF)
//
/////////////////////////////////////////////////////

#include <stdio.h>

int main(void)
{
    int val = 0xCAFE;  // 1100 1010 1111 1110

    printf("\n-------- Test 1 --------\n");
    int flag = 0, tmp = 0;
    if(val & 1) flag += 1;
    if(val & (1 << 1)) flag += 1;
    if(val & (1 << 2)) flag += 1;
    if(val & (1 << 3)) flag += 1;

    if (flag >= 3)
        printf("\n Atleast 3 of the 4 bits in LSB are ON\n");
    else
        printf("\n Less than 3 of the 4 bits in LSB are ON\n");

    printf("\n-------- Test 2 --------\n");
    printf("\n Original Value --> %x\n", val);
    int l = 0, r = 0;
    l = (val >> 8) & 0xFF;
    printf("\n Capture Left: %x\n", l);
    r = (val & 0xFF) << 8;
    printf("\n Capture Right: %x\n", r);
    printf("\n Reversed Value --> %x\n", r | l);

    printf("\n-------- Test 3 --------\n");
    printf("\n Original Value --> %x\n", val);
    int last = 0, rest = 0;
    last = (val & 0xF) << 12;
    printf("\n Capture Last: %x\n", last);
    rest = (val >> 4);
    printf("\n Capture Rest: %x\n", rest);
    printf("\n Rotated Value --> %x\n", rest | last);
}

/*      Learnings       */
/*
    Another way to check if last 3 bits of the last 4 bits are  ON

        int last4bits = val & 0xF;
        if (last4bits == 0x7 || last4bits == 0xB || last4bits == 0xD)
            printf("\n Atleast 3 of the 4 bits in LSB are ON\n");
        else
            printf("\n Less than 3 of the 4 bits in LSB are ON\n");

    Reverse Shortcut: revVal = ((0xFF & val) << 8 | (val >> 8));

    Rotate Shortcut: revVal = ((val >> 4) | ((val & 0xF) < 12));
*/