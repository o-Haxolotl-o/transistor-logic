#include <stdio.h>
#include "gates.h"
int main(void) {
    int output0, output1, s, r;
    output0 = output1=0;
    s=1; r=0;

    while(1) {
        srnand(s,r, &output0, &output1);
        printf("%i, %i\n",
                output0,output1
        );
        s=1; r=1;
    }
    return 0;
}
