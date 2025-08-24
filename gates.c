//
// Created by archie on 8/23/25.
//

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

/*      Latches     */
int srnand(int S, int R, int *Q, int *nQ) {
        *Q = nand(S, *nQ);
        *nQ = nand(R, *Q);
    return *Q;
}