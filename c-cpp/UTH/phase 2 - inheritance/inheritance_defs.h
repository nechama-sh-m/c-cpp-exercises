#ifndef INHERITANCE_DEFS_H__
#define NHERITANCE_DEFS_H__

#include <stdio.h>
#include "encapsulation_defs.h"

typedef enum Types
{
    PLASTIC,
    METAL,
    WOOD,
    PAPER,
    OTHER
}Types;

typedef struct Materials
{
    char tmp;
}Materials;

typedef struct Material_t{
    Types  material;
}Material_t;

typedef struct PhysicalBox{
    Box base_box;
    Material_t material;
}PhysicalBox;

void physical_box_ctor_without_type(PhysicalBox* const this, double l, double w, double h);
void physical_box_ctor_with_type(PhysicalBox*const this,double l, double w, double h, Types t);
void physical_box_ctor_only_type(PhysicalBox*const this,Types t);
void physical_box_dtor(PhysicalBox*const this);
void physical_print(PhysicalBox*const this) ;

typedef struct WeightBox{
    Box base_box;
    double weight;
}WeightBox;
void weight_box_ctor(WeightBox* const this,double l, double w, double h, double wgt);
void weight_box_ctor_def(WeightBox* const this,double l, double w, double h);
void weight_box_copy_ctor(WeightBox* const this,WeightBox* const other);
void weight_box_dtor(WeightBox* const this);

void weight_box_operator_eq(WeightBox* const this,WeightBox* const other);
void weight_box_print(WeightBox* const this);



#endif // INHERITANCE_DEFS_H__


