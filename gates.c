//
// Created by archie on 8/23/25.
//

/*          Gates with one output will return its value.                                        */
/*          Gates with multiple outputs will be passed as argument memory positions.            */
/*          Gates with multiple outputs, but one main output will do both.                      */

/*      transistors       */
int npn(int collector, int base) {
    if(collector==0)
        return 0;
    else if(base == 1)
        return 1;
    return 0;
}

int pnp(int collector, int base) {
    if(collector==0)
        return 0;
    else if(base == 0)
        return 1;
    return 0;
}


/*      level 1 gates       */
int not(int input) {
    return  pnp(npn(1,1),
                input);
}

int and(int input0, int input1) {
    return  npn(npn(1,input0),
                input1);
}

int or(int input0, int input1) {
    if(npn(1,input0))
        return 1;
    if(npn(1,input1))
        return 1;
    return 0;
}


/*      level 2 gates       */
int nand(int input0, int input1) {
    return not(and(input0,input1));
}

int nor(int input0, int input1) {
    return not(or(input0,input1));
}

int xor(int input0, int input1) {
    return or(and(not(input0),input1),
                and(input0,not(input1)));
}

int xnor(int input0, int input1) {
    return or(and(input0,input1),
                and(not(input0),not(input1)));
}


/*      non commutative level 2 gates       */
int imply(int input0, int input1) {
    return not(pnp((input0), input1));
}

int nimply(int input0, int input1) {
    return pnp(input0, input1);
}


/*      latches     */
int srnand(int set, int reset, int *Q, int *nQ) {
        *Q = nand(set, *nQ);
        *nQ = nand(reset, *Q);
    return *Q;
}

int srnor(int set, int reset, int *Q, int *nQ) {
    *Q = nor(reset, *nQ);
    *nQ = nor(set, *Q);
    return *Q;
}


/*      adders     */
int hadder(int input0, int input1, int *sum, int *carry) {
    *sum = xor(input0, input1);
    *carry = and(input0, input1);
    return *carry;
}

int fadder(int num0, int num1, int carryIn, int *sum, int *carryOut) {
    int wireSum2B; //wire sum of first adder to B input of second
    int wireCarry2Out0; // wire carry of first adder to final OR gate
    int wireCarry2Out1; // wire carry of second adder to final OR gate

    hadder(num0, num1, &wireSum2B, &wireCarry2Out0);
    hadder(carryIn, wireSum2B, sum, &wireCarry2Out1);
    *carryOut = or(wireCarry2Out0, wireCarry2Out1);
    return *carryOut;
}
