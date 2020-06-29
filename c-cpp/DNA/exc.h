//
// Created by student on 01/06/2020.
//

#ifndef DNA_EXC_H
#define DNA_EXC_H


#include <exception>

class InvalidDna: public std::exception{
public:
   /*virtual*/ const char* what()const throw(){return "Invalid DNA error";}

};



#endif //DNA_EXC_H
