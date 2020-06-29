//
// Created by student on 14/06/2020.
//
#include "encapsulation_defs.h"
extern const char* const DEF_MSG;
extern const char* message;
static Box largeBox;
static Box box99;
static Box box88;
static bool init_box99=0;
static bool init_box88=0;


void thisFunc()
{
    printf("\n--- thisFunc() ---\n\n");
    if(!init_box99){
        box_ctor(&box99,99,99,99);
        init_box99=1;
    }
    operator_mult_eq(&box99,10);


}

void thatFunc()
{
    printf("\n--- thatFunc() ---\n\n");
    if(!init_box88++){
        box_ctor(&box88,88,88,88);

    }
    operator_mult_eq(&box88,10);

}
void do_boxes(){

    Box b1,b2,b3,b4;
    printf("\n--- Start doBoxes() ---\n\n");

    box_ctor_dim(&b1,3);

    box_ctor(&b2,4,5,6);

    printf("b1 volume: %f\n", b1.height*b1.width*b1.length);
    printf("b2 volume: %f\n", b2.height*b2.width*b2.length);

    operator_mult_eq(&b1,1.5);
    operator_mult_eq(&b2,0.5);

    printf("b1 volume: %f\n", b1.height*b1.width*b1.length);
    printf("b2 volume: %f\n", b2.height*b2.width*b2.length);

    b3=b2;
    b4=b2;
    operator_mult_eq(&b4,3);

    printf("b3 %s b4\n",b3.height==b4.height&&b3.length==b4.length&&b3.width==b4.width ? "equals" : "does not equal");

    operator_mult_eq(&b3,1.5);
    operator_mult_eq(&b4,0.5);

    printf("Now, b3 %s b4\n", b3.height==b4.height&&b3.length==b4.length&&b3.width==b4.width ? "equals" : "does not equal");



    printf("\n--- End doBoxes() ---\n\n");

    box_dtor(&b4);
    box_dtor(&b3);
    box_dtor(&b2);
    box_dtor(&b1);


}
void doShelves(){
    printf("\n--- start doShelves() ---\n\n");

    Box aBox,b1,b2,b3,box,box1;
    Shelf aShelf;

    box_ctor_dim(&aBox,5);


    box_ctor_def(&b1);
    set_box(&aShelf,0,&b1);

    box_ctor_def(&b2);
    set_box(&aShelf,1,&b2);

    box_ctor_def(&b3);
    set_box(&aShelf,2,&b3);

    shelf_print(&aShelf);

    set_box(&aShelf,1,&largeBox);
    set_box(&aShelf,0,&aBox);

    shelf_print(&aShelf);

    message="This is the total volume on the shelf:";

    shelf_print(&aShelf);

    message= "Shelf's volume:";
    shelf_print(&aShelf);

    box_ctor(&box,2,4,6);
    set_box(&aShelf,1,&box);
    box_dtor(&box);

    box_ctor_dim(&box1,2);
    set_box(&aShelf,2,&box1);
    box_dtor(&box1);
    shelf_print(&aShelf);


    printf("\n--- end doShelves() ---\n\n");

    for (int i =NUM_BOXES-1 ; i >=0 ; i--) {
        box_dtor(&aShelf.boxes[i]);
    }
    box_dtor(&aBox);


}

int main(){

    box_ctor(&largeBox,10,20,30);
    printf("\n--- Start main() ---\n\n");
    do_boxes();

    thisFunc();
    thisFunc();
    thisFunc();
    thatFunc();
    thatFunc();


    doShelves();
    printf("\n--- End main() ---\n\n");
    if(init_box88)
        box_dtor(&box88);
    if(init_box99)
        box_dtor(&box99);
    box_dtor(&largeBox);


    return 0;
}
