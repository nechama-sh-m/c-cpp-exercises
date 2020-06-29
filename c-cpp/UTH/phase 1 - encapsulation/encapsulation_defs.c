//
// Created by student on 14/06/2020.
//

#include "encapsulation_defs.h"

const char* const DEF_MSG = "The total volume held on the shelf is";
const char* message="The total volume held on the shelf is";

void box_ctor( Box* const this,double l, double w, double h){
    this->length=l;
    this->width=w;
    this->height=h;
    print(this);
}
void box_ctor_dim( Box* const this,double dim){
    this->length=dim;
    this->width=dim;
    this->height=dim;
    print(this);
}

void box_ctor_def(Box* const this){
    this->length=1;
    this->width=1;
    this->height=1;
    print(this);
}
void box_dtor(const Box* const this){
    printf("Box destructor, %f x %f x %f\n", this->width, this->height, this->length);
}
void operator_mult_eq(Box* const this, double mult){
    this->length*=mult;
    this->width*=mult;
    this->height*=mult;
}
void print(const Box* const this){
    printf("Box: %f x %f x %f\n", this->length, this->width, this->height);
}

void set_box(Shelf * this ,int index, Box* dims)
{
    this->boxes[index] = *dims;
}
const double get_volume(Shelf * this)
{
    double vol = 0;
    for (size_t i = 0; i < NUM_BOXES; ++i)
        vol += (this->boxes[i].height*this->boxes[i].width*this->boxes[i].length);

    return vol;
}

const void shelf_print(Shelf * this)
{
    printf("%s %f\n", message, get_volume(this));
}
/*void self_dtor(const Shelf* const this){
    for (size_t i = 0; i < NUM_BOXES; ++i)
    {
        box_dtor(&this->boxes[i]);
    }

}*/