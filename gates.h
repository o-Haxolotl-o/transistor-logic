//
// Created by archie on 8/23/25.
//

#ifndef GATES_H
#define GATES_H

/*      transistors       */
int npn(int collector, int base); /*
    C B Result
    0 0 : 0
    1 0 : 0
    0 1 : 0
    1 1 : 1
 */
int pnp(int collector, int base); /*
    C B Result
    0 0 : 0
    1 0 : 1
    0 1 : 0
    1 1 : 0
 */

/*      level 1 gates       */
int not(int input);/*
    A Result
    0 : 1
    1 : 0
 */
int and(int input0, int input1);/*
    A B Result
    0 0 : 0
    1 0 : 0
    0 1 : 0
    1 1 : 1
 */
int or(int input0, int input1);/*
    A B Result
    0 0 : 0
    1 0 : 1
    0 1 : 1
    1 1 : 1
 */

/*      level 2 gates       */
int nand(int input0, int input1);/*
    A B Result
    0 0 : 1
    1 0 : 1
    0 1 : 1
    1 1 : 0
 */
int nor(int input0, int input1);/*
    A B Result
    0 0 : 1
    1 0 : 0
    0 1 : 0
    1 1 : 0
 */
int xor(int input0, int input1);/*
    A B Result
    0 0 : 0
    1 0 : 1
    0 1 : 1
    1 1 : 0
 */
int xnor(int input0, int input1);/*
    A B Result
    0 0 : 1
    1 0 : 0
    0 1 : 0
    1 1 : 1
 */

/*      non commutative level 2 gates       */
int imply(int input0, int input1);/*
    A B Result
    0 0 : 1
    1 0 : 0
    0 1 : 1
    1 1 : 1
 */
int nimply(int input0, int input1);/*
    A B Result
    0 0 : 0
    1 0 : 1
    0 1 : 0
    1 1 : 0
 */

/*      Latches     */
int srnand(int S, int R, int *output0, int *output1); /*
SR NAND latch:
    First two parameters are input, second two are output,
    pass variable memory positions as output arguments

    Q and nQ are both passed as inputs to the opposite NAND gate,
    thereby creating an endless loop persisting them unless they are
    reset.

parameters: Set, Reset, Q, ~Q
*/
int srnor(int S, int R, int *output0, int *output1); /*
SR NOR latch:
    First two parameters are input, second two are output,
    pass variable memory positions as output arguments

    Q and nQ are both passed as inputs to the opposite NOR gate,
    thereby creating an endless loop persisting them unless they are
    reset.

parameters: Set, Reset, Q, ~Q
*/

/*      Math     */
void hadder(int input0, int input1, int *sum, int *carry); /*
Half Adder
*/
int fadder(int num0, int num1, int carryIn, int *sum, int *carryOut); /*
Full Adder
    First parameter is a bit in the first number,
    second parameter is a bit in the second number.

    Always fill the carry-in input of the first adder
    in a chain with a zero.
*/
void hsubtractor(int input0, int input1, int *diff, int *borrow); /*
Half Subtractor
*/
int fsubtractor(int num0, int num1, int bin, int *diff, int *bout); /*
Full Subtractor
    First parameter is a bit in the first number,
    second parameter is a bit in the second number.

    Always fill the carry-in input of the first subtractor
    in a chain with a zero.
*/

#endif //GATES_H
