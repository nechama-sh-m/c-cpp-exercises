//
// Created by student on 18/06/2020.
//
#include "polymorphism_defs.h"
#include <malloc.h>
void do_pre_post_fixer(){
    PrePostFixer angleBrackets;
    printf("\n--- start doPrePostFixer() ---\n\n");
    PrePostFixer_ctor(&angleBrackets,"<<< ", " >>>");
    PrePostFixer_print(&angleBrackets,"Hello World!");
    PrePostFixer_print_long(&angleBrackets,-777,'\0');
    PrePostFixer_print_long(&angleBrackets,350,'#');
    PrePostFixer_print_long(&angleBrackets,(3.14),'\0');

    printf("\n--- end doPrePostFixer() ---\n\n");
    PrePostFixer_dtor(&angleBrackets);


}
void doPrePostDollarFixer()
{
    PrePostDollarFixer asterisks;
    printf("\n--- start doPrePostDollarFixer() ---\n\n");
    PrePostDollarFixer_ctor(&asterisks,"***** ", " *****");
    PrePostDollarFixer_print_int(&asterisks,-777,'$');
    PrePostDollarFixer_print_int(&asterisks,350, '#');
    PrePostDollarFixer_print_double(&asterisks,3.14,'$');

    printf("\n--- end doPrePostDollarFixer() ---\n\n");

   PrePostDollarFixer_dtor(&asterisks);

}
void doPrePostFloatDollarFixer()
{
    PrePostFloatDollarFixer hashes;
    PrePostDollarFixer hashes2;
    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");

    PrePostFloatDollarFixer_ctor(&hashes,"### ", " ###");
    PrePostFloatDollarFixer_print(&hashes,-777);
    PrePostFloatDollarFixer_print_with_char(&hashes,350, '#');
    PrePostFloatDollarFixer_print(&hashes,3.14f);


    PrePostDollarFixer_copy_ctor(&hashes2,(PrePostDollarFixer*)&hashes);
    PrePostDollarFixer_print_double(&hashes2,7.5,'$');
    PrePostDollarFixer_print_int(&hashes2,100,'$');


    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");

    PrePostDollarFixer_dtor(&hashes2);
    PrePostFloatDollarFixer_dtor(&hashes);



}

void doPrePostChecker() {
    PrePostChecker check;
    printf("\n--- start doPrePostChecker() ---\n\n");
    PrePostChecker_ctor(&check);
    printThisSymbolUsingFunc(&check) ;
    printThisSymbolDirectly(&check) ;
    printDollarSymbolByCastDirectly(&check);
    printDollarSymbolByScopeDirectly(&check);
    printDollarSymbolByCastUsingFunc(&check);
    printDollarSymbolByScopeUsingFunc(&check);

    printf("\n--- end doPrePostChecker() ---\n\n");
    PrePostChecker_dtor(&check);

}
void runAsPrePostFixerRef(const PrePostFixer* pp){

    printf("\n--- start runAsPrePostFixerRef() ---\n\n");
    pp->default_text_formatter_base.text_formatter_base.vptr[3]((PrePostFixer*)pp,123,'\0');
    printf("\n--- end runAsPrePostFixerRef() ---\n\n");
}

void runAsPrePostDollarFixerRef(const PrePostDollarFixer* pp)
{
    printf("\n--- start runAsPrePostDollarFixerRef() ---\n\n");
    PrePostDollarFixer_print_int((PrePostDollarFixer*)pp,123,'$');
    //pp->pre_post_fixer_base.default_text_formatter_base.text_formatter_base.vptr[3]();

    printf("\n--- end runAsPrePostDollarFixerRef() ---\n\n");
}
void runAsPrePostDollarFixerObj(const PrePostDollarFixer pp)
{
    printf("\n--- start runAsPrePostDollarFixerObj() ---\n\n");
    PrePostDollarFixer_print_int(&pp,123,'$');
    printf("\n--- end runAsPrePostDollarFixerObj() ---\n\n");
}
void runAsPrePostHashFixerRef(const PrePostHashFixer* pp)
{
    printf("\n--- start runAsPrePostHashFixerRef() ---\n\n");
    PrePostHashFixer_print_int(pp,123,'#');
    printf("\n--- end runAsPrePostHashFixerRef() ---\n\n");
}
extern funcptr multiplier_table[];
void doMultiplier()
{
    Multiplier m1;
    Multiplier m2;
    Multiplier m3;
    Multiplier m4;
    printf("\n--- start doMultiplier() ---\n\n");
    DefaultTextFormatter_ctor((DefaultTextFormatter*)&m1);
    m1.default_text_formatter.text_formatter_base.vptr=multiplier_table;
    m1.times=3;
    printf("--- Multiplier CTOR: times = %d\n", m1.times);
    //Multiplier m2 = 5;
    DefaultTextFormatter_ctor((DefaultTextFormatter*)&m2);
    m2.default_text_formatter.text_formatter_base.vptr=multiplier_table;
    m2.times=5;
    printf("--- Multiplier CTOR: times = %d\n", m2.times);
   // Multiplier m3 = m1;
    //DefaultTextFormatter_ctor((DefaultTextFormatter*)&m1);
    DefaultTextFormatter_copy_ctor((DefaultTextFormatter*)&m3,(DefaultTextFormatter*)&m1);
    m3=m1;
    //Multiplier m4(m2);
    DefaultTextFormatter_copy_ctor((DefaultTextFormatter*)&m4,(DefaultTextFormatter*)&m2);
    m4.default_text_formatter.text_formatter_base.vptr=m2.default_text_formatter.text_formatter_base.vptr;
    m4.times=m2.times;

    m1.default_text_formatter.text_formatter_base.vptr[1](&m1,"abc ");
    m2.default_text_formatter.text_formatter_base.vptr[1](&m2,"abc ");
    m3.default_text_formatter.text_formatter_base.vptr[1](&m3,"abc ");
    m4.default_text_formatter.text_formatter_base.vptr[1](&m4,"abc ");


    printf("\n--- start doMultiplier() ---\n\n");

    Multiplier_dtor(&m4);
    Multiplier_dtor(&m3);
    Multiplier_dtor(&m2);
    Multiplier_dtor(&m1);


}
void doFormatterArray()
{
    PrePostDollarFixer ppd;
    Multiplier m;
    PrePostChecker ppc;
    DefaultTextFormatter formatters[3] ;
    printf("\n--- start doFormatterArray() ---\n\n");

    PrePostDollarFixer_ctor(&ppd,"!!! ", " !!!");
    DefaultTextFormatter_copy_ctor(&formatters[0],(DefaultTextFormatter*)&ppd) ;
    PrePostDollarFixer_dtor(&ppd);

    DefaultTextFormatter_copy_ctor(&formatters[1],(DefaultTextFormatter*)&m) ;
    DefaultTextFormatter_ctor((DefaultTextFormatter*)&m);
    m.default_text_formatter.text_formatter_base.vptr=multiplier_table;
    m.times=4;
    printf("--- Multiplier CTOR: times = %d\n", m.times);
    Multiplier_dtor(&m);

    PrePostChecker_ctor(&ppc);
    DefaultTextFormatter_copy_ctor(&formatters[2],(DefaultTextFormatter*)&ppc) ;
    PrePostChecker_dtor(&ppc);

    for (int i = 0; i < 3; ++i)
        DefaultTextFormatter_print(&formatters[i],"Hello World!");


    printf("\n--- end doFormatterArray() ---\n\n");
    for (int i = 2; i >= 0; --i)
        DefaultTextFormatter_dtor(&formatters[i]);


}
void doFormatterPtrs()
{

    DefaultTextFormatter* pfmt[3] ;
    printf("\n--- start doFormatterPtrs() ---\n\n");


    pfmt[0]=malloc(sizeof( PrePostDollarFixer));
    PrePostDollarFixer_ctor(( PrePostDollarFixer*)pfmt[0],"!!! ", " !!!");

    pfmt[1]=malloc(sizeof( Multiplier));
    DefaultTextFormatter_ctor(pfmt[1]);
    ((Multiplier*)pfmt[1])->default_text_formatter.text_formatter_base.vptr=multiplier_table;
    ((Multiplier*)pfmt[1])->times=4;
    printf("--- Multiplier CTOR: times = %d\n", ((Multiplier*)pfmt[1])->times);

    pfmt[2]=malloc(sizeof(PrePostChecker));
    PrePostChecker_ctor((PrePostChecker*)pfmt[2]);


    for (int i = 0; i < 3; ++i)
        pfmt[i]->text_formatter_base.vptr[1](pfmt[i],"Hello World!");

    for (int i = 2; i >=0; --i)
        pfmt[i]->text_formatter_base.vptr[0](pfmt[i]);

    printf("\n--- end doFormatterPtrs() ---\n\n");
}
void doFormatterDynamicArray()
{
    printf("\n--- start doFormatterDynamicArray() ---\n\n");

    DefaultTextFormatter* formatters = generateFormatterArray();
    DefaultTextFormatter_ctor(&formatters[0]);
    DefaultTextFormatter_ctor(&formatters[1]);
    DefaultTextFormatter_ctor(&formatters[2]);

    for (int i = 0; i < 3; ++i)
        formatters[i].text_formatter_base.vptr[1](&formatters[i],"Hello World!");


    //delete[] formatters;
    DefaultTextFormatter_dtor(&formatters[2]);
    DefaultTextFormatter_dtor(&formatters[1]);
    DefaultTextFormatter_dtor(&formatters[0]);




    printf("\n--- start doFormatterDynamicArray() ---\n\n");
    free(formatters);
}

int main() {
    PrePostHashFixer hfix;
    PrePostDollarFixer tmp;
    printf("\n--- Start main() ---\n\n");
   do_pre_post_fixer();
    doPrePostDollarFixer();
    doPrePostFloatDollarFixer();

    doPrePostChecker();
    PrePostHashFixer_ctor(&hfix,4);
    runAsPrePostFixerRef((PrePostFixer*)&hfix);
    runAsPrePostDollarFixerRef((PrePostDollarFixer*)&hfix);
    PrePostDollarFixer_copy_ctor(&tmp,(PrePostDollarFixer*)&hfix);
    runAsPrePostDollarFixerObj(tmp);
    PrePostDollarFixer_dtor(&tmp);
    runAsPrePostHashFixerRef(&hfix);
    doMultiplier();
    doFormatterArray();

    doFormatterPtrs();

    doFormatterDynamicArray();
    printf("\n--- End main() ---\n\n");
    PrePostHashFixer_dtor(&hfix);

    return 1;
}
