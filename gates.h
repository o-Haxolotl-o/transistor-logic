//
// Created by archie on 8/23/25.
//

#ifndef GATES_H
#define GATES_H

/*      transistors       */
int npn(int collector, int base);
int pnp(int collector, int base);

/*      level 1 gates       */
int not(int input);
int and(int input0, int input1);
int or(int input0, int input1);

/*      level 2 gates       */
int nand(int input0, int input1);
int nor(int input0, int input1);
int xor(int input0, int input1);
int xnor(int input0, int input1);

/*      non commutative level 2 gates       */
int imply(int input0, int input1);
int nimply(int input0, int input1);

/*      Latches     */
int srnand(int S, int R, int *output0, int *output1); /*
SR NAND latch:
    First two parameters are input, second two are output,
    pass variable memory positions as output arguments
parameters: Set, Reset, Q, notQ
*/

#endif //GATES_H
