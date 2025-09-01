#include <stdio.h>
#include "gates.h"
int main(void) {
    int output0, output1, output2, output3, output4, output5, output6, output7;
    output0 = output1 = output2 = output3 = output4 = output5 = output6 = output7 = 0;
    int input0, input1, input2, input3, input4, input5, input6, input7;
    input0 = input1 = input2 = input3 = input4 = input5 = input6 = input7 = 0;
    int wire0 = 1;
    int wire1=0;
    int fin = 0;
    input3=1;
    input4=1;

    shift8(0, &input0, &input1, &input2, &input3, &input4, &input5, &input6, &input7,
                &output0, &output1, &output2, &output3, &output4, &output5, &output6, &output7);

    printf("%i, %i, %i, %i, %i, %i, %i, %i\n",
        output0,output1, output2, output3, output4, output5, output6, output7
    );
    return 0;
}
