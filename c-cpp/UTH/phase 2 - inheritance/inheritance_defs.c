#include <stdio.h>
#include "inheritance_defs.h"

void physical_box_ctor_without_type(PhysicalBox* const this, double l, double w, double h){
   box_ctor((Box*)this,l,  w,  h);
   this->material.material=OTHER;
   printf("Material created, set to %s\n","OTHER" );
   physical_print(this);


}
void physical_box_ctor_with_type(PhysicalBox*const this,double l, double w, double h, Types t){
    box_ctor( (Box*)this,l,  w,  h);
    this->material.material=t;
    const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
    printf("Material created, set to %s\n",names[this->material.material] );
    physical_print(this);

}
void physical_box_ctor_only_type(PhysicalBox*const this,Types t){
    box_ctor_def((Box*)this);
    this->material.material=t;
    const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
    printf("Material created, set to %s\n",names[this->material.material] );
    physical_print(this);
}

void physical_box_dtor(PhysicalBox*const this){
    const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
    printf("PhysicalBox dtor, %f x %f x %f, %s; ", this->base_box.length, this->base_box.width, this->base_box.height, names[this->material.material]);
    box_dtor((Box*)this);
}
void physical_print(PhysicalBox*const this) {
    const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
    printf("PhysicalBox, made of %s; ", names[this->material.material]);
    box_print((Box*)this);
}
void weight_box_ctor(WeightBox* const this,double l, double w, double h, double wgt){
    box_ctor((Box*)this,l,w,h);
    this->weight=wgt;
    weight_box_print(this);
}
void weight_box_ctor_def(WeightBox* const this,double l, double w, double h){
    box_ctor((Box*)this,l,w,h);
    this->weight=0.0;
    weight_box_print(this);
}
void weight_box_copy_ctor(WeightBox* const this,WeightBox* const other){
    this->weight=other->weight;
    box_ctor_def((Box*)this);

    weight_box_print(this);
}
void weight_box_dtor(WeightBox* const this){
    printf("Destructing WeightBox; ");
    weight_box_print(this);
    box_dtor((Box*)this);
}
void weight_box_operator_eq(WeightBox* const this,WeightBox* const other){
    this->weight=other->weight;

}
void weight_box_print(WeightBox* const this){
    printf("WeightBox, weight: %f; ", this->weight);
    box_print((Box*)this);
}



