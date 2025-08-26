#include <stdio.h>
#include "gates.h"
int main(void) {
    int output0, output1, output2;
    output0 = output1 = output2 = output2 = 0;
    int wire0;
    int wire1;
    int fin = 0;

    fadder(1, 0, 0, &output0, &wire0);
    fadder(1, 1, wire0, &output1, &wire1);
    fadder(0, 0, wire1, &output2, &fin);

    printf("%i, %i, %i\n",
        output0,output1, output2
    );
    return 0;
}
