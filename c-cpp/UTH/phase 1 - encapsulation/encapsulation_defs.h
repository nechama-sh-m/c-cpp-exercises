//
// Created by student on 14/06/2020.
//

#ifndef UNDER_ENCAPSULATION_DEFS_H
#define UNDER_ENCAPSULATION_DEFS_H

#include <stdio.h>
#include <stdbool.h>

#define NUM_BOXES 3

/*const char* const DEF_MSG;
const char* message;*/
typedef struct Box{
    double length;
    double width;
    double height;

}Box;

void print(const Box* const this);
void box_ctor( Box* const this,double l, double w, double h);
void box_ctor_dim( Box* const this,double dim);
void box_ctor_def(Box* const this);
void box_dtor(const Box* const this);
void operator_mult_eq(Box* const this, double mult);

typedef struct Shelf{
    Box boxes[NUM_BOXES];

}Shelf;

void set_box(Shelf * this ,int index, Box* dims);
const double get_volume(Shelf * this);
const void shelf_print(Shelf * this);
//void self_dtor(const Shelf* const this);


#endif //UNDER_ENCAPSULATION_DEFS_H
