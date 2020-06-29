#include <stdio.h>
#include "inheritance_defs.h"




void do_materials()
{
    Materials mat;
    Material_t mat1;
    Material_t mat2;
    const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
    printf("\n--- Start doMaterials() ---\n\n");


    printf("Size of Materials: %lu\n",sizeof(Materials));
    printf("Size of mat: %lu\n",sizeof(mat));
    printf("Size of Materials::Types: %lu\n", sizeof(Types));
    printf("Size of Material_t: %lu\n", sizeof(Material_t));

    struct MatTest { Materials mat; Material_t mat_t; }MatTest;
    printf("Size of Materials + Material_t: %lu\n", sizeof(MatTest.mat_t)+sizeof(MatTest.mat_t));


    mat1.material=OTHER;
    printf("Material created, set to %s\n",names[mat1.material]);


    mat2.material=METAL;
    printf("Material created, set to %s\n",names[mat2.material] );

    printf("\n--- End doMaterials() ---\n\n");

}
void do_physicalBox()
{
    printf("\n--- Start doPhysicalBox() ---\n\n");

    PhysicalBox pb1;
    PhysicalBox pb2;
    PhysicalBox pb3;
    PhysicalBox pb4;

    physical_box_ctor_with_type(&pb1,8,6,4,PLASTIC);
    physical_box_ctor_only_type(&pb2,WOOD);
    physical_box_ctor_without_type(&pb3,7,7,7);

    printf("\npb4 is copy-constructed from pb1\n");

    pb4=pb1;
    physical_print(&pb4);
    physical_print(&pb1);
    printf("pb4 %s pb1\n", pb4.base_box.length== pb1.base_box.length&&pb4.base_box.width==pb1.base_box.width
    &&pb4.base_box.height==pb1.base_box.height&&pb4.material.material==pb1.material.material? "equals" : "does not equal");

    printf("\npb4 is copy-assigned from pb3\n");
    pb4 = pb3;
    physical_print(&pb4);
    physical_print(&pb3);
    printf("pb4 %s pb3\n",pb4.base_box.length== pb3.base_box.length&&pb4.base_box.width==pb3.base_box.width
                          &&pb4.base_box.height==pb3.base_box.height&&pb4.material.material==pb3.material.material ? "equals" : "does not equal");

    printf("\n--- End doPhysicalBox() ---\n\n");
    physical_box_dtor(&pb4);
    physical_box_dtor(&pb3);
    physical_box_dtor(&pb2);
    physical_box_dtor(&pb1);



}
void do_weightBox() {
    printf("\n--- Start doWeightBox() ---\n\n");

    WeightBox pw1;
    WeightBox pw2;
    WeightBox pw3;
    WeightBox pw4;

    weight_box_ctor(&pw1,8,6,4,25);
    weight_box_ctor_def(&pw2,1,2,3);
    weight_box_ctor(&pw3,10,20,30,15);
    printf("\npw4 is copy-constructed from pw1\n");
    weight_box_copy_ctor(&pw4,&pw1);

    weight_box_print(&pw4);
    weight_box_print(&pw1);

    printf("pw4 %s pw1\n", pw4.base_box.height== pw1.base_box.height&&pw4.base_box.length== pw1.base_box.length&&
    pw4.base_box.width== pw1.base_box.width&&pw4.weight==pw1.weight? "equals" : "does not equal");

    printf("\npw4 is copy-assigned from pw3\n");
    weight_box_operator_eq(&pw4,&pw3);
    weight_box_print(&pw4);
    weight_box_print(&pw3);

    printf("pw4 %s pw1\n", pw4.base_box.height== pw3.base_box.height&&pw4.base_box.length== pw3.base_box.length&&
                           pw4.base_box.width== pw3.base_box.width&&pw4.weight==pw3.weight? "equals" : "does not equal");

    printf("\n--- End doWeightBox() ---\n\n");

    weight_box_dtor(&pw4);
    weight_box_dtor(&pw3);
    weight_box_dtor(&pw2);
    weight_box_dtor(&pw1);

}





int main()
{
    printf("\n--- Start main() ---\n\n");

    do_materials();

    do_physicalBox();
    do_weightBox();
    printf("\n--- End main() ---\n\n");

}
