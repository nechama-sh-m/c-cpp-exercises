#include "vector.h"
#include "iostream"
int main()
{
    Vector<int> v1;
    Vector<int> v2(10,0);
    Vector<int> v3(v2);
    Vector<int> v4;
    v4=v1;
    std::cout<<"v2 size: "<<v2.size() <<std::endl;
    std::cout<<"v2 max_size: "<<v2.max_size() <<std::endl;
    v4.resize(20);
    std::cout<<"v4 size: "<<v4.size() <<std::endl;

    return 0;
}
