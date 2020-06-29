//
// Created by student on 18/06/2020.
//

#ifndef CPP2C_POLYMORPHISM_POLYMORPHISM_DEFS_H
#define CPP2C_POLYMORPHISM_POLYMORPHISM_DEFS_H

#include <stdio.h>

typedef void (*funcptr) (void*,...);
// TextFormatter
typedef struct TextFormatter{
   funcptr* vptr;
}TextFormatter;

void TextFormatter_dtor(TextFormatter* const this);
void TextFormatter_print(TextFormatter* const this,const char* text);

// DefaultTextFormatter

typedef struct DefaultTextFormatter{

    TextFormatter text_formatter_base;
    int id;
}DefaultTextFormatter;

void DefaultTextFormatter_ctor(DefaultTextFormatter* const this);
void DefaultTextFormatter_copy_ctor(DefaultTextFormatter* const this,const DefaultTextFormatter* other);
void DefaultTextFormatter_operator_eq(DefaultTextFormatter* const this,const DefaultTextFormatter* other);
void DefaultTextFormatter_dtor(DefaultTextFormatter* const this);
void DefaultTextFormatter_print(const DefaultTextFormatter* const this,const char* text);
DefaultTextFormatter* generateFormatterArray();

// PrePostFixer

typedef struct PrePostFixer{

    DefaultTextFormatter default_text_formatter_base;
    const char* pre;
    const char* post;
}PrePostFixer;

void PrePostFixer_ctor(PrePostFixer* const this,const char* prefix, const char* postfix);
void PrePostFixer_dtor(PrePostFixer* const this);
void PrePostFixer_print(const PrePostFixer* const this,const char* text);
void PrePostFixer_print_long(const PrePostFixer* const this,const long num,const char symbol);
//---void PrePostFixer_print_longfff(const PrePostFixer* const this,const long num);
char PrePostFixer_getDefaultSymbol(const PrePostFixer* const this);

// PrePostDollarFixer

typedef struct PrePostDollarFixer{

    PrePostFixer pre_post_fixer_base;
}PrePostDollarFixer;

void PrePostDollarFixer_ctor(PrePostDollarFixer* const this, const char* prefix, const char* postfix);
void PrePostDollarFixer_copy_ctor(PrePostDollarFixer* const this,const PrePostDollarFixer* other);
void PrePostDollarFixer_dtor(PrePostDollarFixer* const this);
void PrePostDollarFixer_print_int(const PrePostDollarFixer* const this,int num, char symbol);
void PrePostDollarFixer_print_long(const PrePostDollarFixer* const this,long num, char symbol);
void PrePostDollarFixer_print_double(const PrePostDollarFixer* const this,double num, char symbol);
//---void PrePostDollarFixer_print_int_def(const PrePostDollarFixer* const this,int num);
//---void PrePostDollarFixer_print_long_def(const PrePostDollarFixer* const this,long num);
//---void PrePostDollarFixer_print_double_def(const PrePostDollarFixer* const this,double num);
char PrePostDollarFixer_getDefaultSymbol();


// PrePostHashFixer
typedef struct PrePostHashFixer{
    PrePostDollarFixer pre_post_dollar_fixer_base;
    int precision;
}PrePostHashFixer;


void PrePostHashFixer_ctor(PrePostHashFixer* const this ,int prc);
//---void PrePostHashFixer_ctor_def(PrePostHashFixer* const this);
void PrePostHashFixer_dtor(PrePostHashFixer* const this );
void PrePostHashFixer_print_int(const PrePostHashFixer* const this ,int num, char symbol);
void PrePostHashFixer_print_long(const PrePostHashFixer* const this ,long num, char symbol );
//----void PrePostHashFixer_print_double(const PrePostHashFixer* const this ,int num, char symbol);//TODO INLINE
//---void PrePostHashFixer_print_int_def(const PrePostHashFixer* const this ,int num);
//---void PrePostHashFixer_print_long_def(const PrePostHashFixer* const this ,long num);
//---void PrePostHashFixer_print_double_def(const PrePostHashFixer* const this ,int num);
char PrePostHashFixer_getDefaultSymbol();

// PrePostFloatDollarFixer
typedef struct PrePostFloatDollarFixer{
    PrePostDollarFixer pre_post_dollar_fixer_base;
}PrePostFloatDollarFixer;


void PrePostFloatDollarFixer_ctor(PrePostFloatDollarFixer* const this,const char* prefix, const char* postfix);
void PrePostFloatDollarFixer_dtor(PrePostFloatDollarFixer* const this);
void PrePostFloatDollarFixer_print(const PrePostFloatDollarFixer* const this,float num) ;
void PrePostFloatDollarFixer_print_with_char(const PrePostFloatDollarFixer* const this, float num, char symbol) ;
char PrePostFloatDollarFixer_getDefaultSymbol();

// PrePostChecker


typedef struct PrePostChecker{
    PrePostFloatDollarFixer pre_post_float_dollar_fixer_base;
}PrePostChecker;

void PrePostChecker_ctor(PrePostChecker* const this);
void PrePostChecker_dtor(PrePostChecker* const this);

void printThisSymbolUsingFunc(const PrePostChecker* const this) ;
void printThisSymbolDirectly(const PrePostChecker* const this) ;
void printDollarSymbolByCastUsingFunc(const PrePostChecker* const this);
void printDollarSymbolByScopeUsingFunc(const PrePostChecker* const this);
void printDollarSymbolByCastDirectly(const PrePostChecker* const this);
void printDollarSymbolByScopeDirectly(const PrePostChecker* const this);

// Multiplier
typedef struct Multiplier{
    DefaultTextFormatter default_text_formatter;
    int times;
}Multiplier;
void Multiplier_dtor(Multiplier* const this);
void Multiplier_print(const Multiplier* const this,const char* text) ;



#endif //CPP2C_POLYMORPHISM_POLYMORPHISM_DEFS_H
