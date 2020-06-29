#include "dnaSeq.h"

int main(){
    std::string str="AAAAAAAAAA";
    DnaSeq d(str);
    DnaSeq d2=d;
    std::cout<<d;
    try {
        d[2]='w';
    }
    catch (InvalidDna& e)
    {
        std::cout<<e.what()<<std::endl;
    }


  // std::cout<<d[0];

    return 0;


}



