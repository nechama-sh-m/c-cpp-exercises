//
// Created by student on 09/06/2020.
//

#ifndef FIXED_PRICE_H
#define FIXED_PRICE_H

#include <iostream>
#include <math.h>


template <unsigned int size, typename T=int>
class Price{
public:
    Price(T, T);
    Price(T);
    Price();
    Price& operator=(const Price&);
    Price& operator+=(const Price&);
    Price& operator-=(Price);
    /*Price& operator*=(Price);
    Price& operator/=(Price);
    Price& operator%=(Price);*/
    Price& operator++();
    Price operator++(int);
    Price& operator--();
    Price operator--(int);
   T getDollar()const;
    T getCent()const;
    bool isPos()const;
    operator double ();
private:
    T m_dollars;
    T m_cents;
    bool m_neg;
    void change();
};
template <unsigned int size,typename T>
inline Price<size,T>::Price(T  dollar,T  cent):m_dollars(0),m_cents(0),m_neg(false){
    if(dollar<0)
    {
        m_dollars=-dollar;
        m_neg= true;
    }
    else
        m_dollars=dollar;

    if(cent<0)
    {
        m_cents=-cent;
        m_neg= true;
    }
    else
        m_cents=cent;

    //change();
    T tmp=m_cents;
    unsigned int count=0;
    while (tmp){
        count+=1;
        tmp/=10;
    }
    if(count>size)
    {
        m_cents/=(unsigned int)pow(10,count-size);
    }

    /*else
        m_cents/=pow(10,count-size);*/

}
template <unsigned int size,typename T>
inline Price<size,T>::Price(T  dollar):m_dollars(0),m_cents(0),m_neg(false){
    if(dollar<0)
    {
        m_dollars=-dollar;
        m_neg= true;
    }
    else
        m_dollars=dollar;
}

template <unsigned int size,typename  T>
inline Price<size,T>::Price():m_cents(0) ,m_dollars(0),m_neg(false){}

template <unsigned int size,typename  T>
inline void Price<size,T> ::change() {
    unsigned int i=pow(10,size);
    if (m_cents>=i)
    {
        m_dollars+=m_cents/i;
        m_cents%=i;
    }

}

template <unsigned int size,typename  T>
inline T Price<size,T>::getCent() const {return m_cents;}

template <unsigned int size,typename  T>
inline T Price<size,T>::getDollar() const { return m_dollars;}

template <unsigned int size,typename  T>
inline Price<size,T> operator-(const Price<size,T>& p1) {
    char flag;
    if(p1.isPos())
        flag=-1;
    else
        flag=1;

    return Price<size,T> (p1.getDollar()*flag,p1.getCent()*flag);
}

template <unsigned int size,typename  T>
inline bool Price<size,T>::isPos()const { return !m_neg;}

template <unsigned int size,typename  T>
inline Price<size,T>::operator double() {
    char flag;
    if(!m_neg)
        flag=1;
    else
        flag=-1;
    double tmp=(double(m_dollars)+double(m_cents)/pow(10,size))*flag;
    return tmp;
}

template <unsigned int size,typename  T>
inline bool operator>(const Price<size,T>& p1,const Price<size,T>& p2){
    if (p1.isPos()!=p2.isPos())
        return p1.isPos();
    if(p1.getDollar()>p2.getDollar())
        return p1.isPos();
    if(p1.getDollar()==p2.getDollar()&&p1.getCent()>p2.getCent())
        return p1.isPos();
    return !p1.isPos();
}
template <unsigned int size,typename  T>
inline bool operator<(const Price<size,T>& p1,const Price<size,T>& p2){
    if (p1.isPos()!=p2.isPos())
        return p2.isPos();
    if(p1.getDollar()<p2.getDollar())
        return p2.isPos();
    if(p1.getDollar()==p2.getDollar()&&p1.getCent()<p2.getCent())
        return p2.isPos();
    return !p2.isPos();
}
template <unsigned int size,typename  T>
inline bool operator==(const Price<size,T>& p1,const Price<size,T>& p2){
    return p1.getCent()==p2.getCent()&&p1.getDollar()==p2.getDollar()&&p1.isPos()==p2.isPos();
}
template <unsigned int size,typename  T>
inline bool operator!=(const Price<size,T>& p1,const Price<size,T>& p2){
    return p1.getCent()!=p2.getCent()||p1.getDollar()!=p2.getDollar()||p1.isPos()!=p2.isPos();
}
template <unsigned int size,typename  T>
inline bool operator>=(const Price<size,T>& p1,const Price<size,T>& p2){
    return (!(p1<p2));
}
template <unsigned int size,typename  T>
inline bool operator<=(const Price<size,T>& p1,const Price<size,T>& p2){
    return (!(p1>p2));
}
template <unsigned int size,typename  T>
inline Price<size,T> operator+(const Price<size,T>& p1,const Price<size,T>& p2)
{
   if(p1.isPos()==p2.isPos())
   {
        T cent=p1.getCent()+p2.getCent();
        T tmp=0;
        unsigned int p_pow= pow(10,size);
        char flag=p1.isPos()?1:-1;
        if(cent>=p_pow)
        {
            tmp=cent/p_pow;
        }
        Price<size,T> p_res((p1.getDollar()+p2.getDollar())*flag+tmp,(cent)%p_pow*flag);
        return p_res;
    }
    if(!p1.isPos())
    {
         return (p2-(-p1));
    }

    return (p1-(-p2));

}
template <unsigned int size,typename  T>
inline Price<size,T> operator-(const Price<size,T>& p1,const Price<size,T>& p2)
{
    if(p1==p2)
        return Price<size,T>(0);
    if(!p2.isPos())
        return (p1+(-p2));
    if(!p1.isPos())
        return (-((-p1)+p2));
    if(p1<p2)
        return -(p2-p1);
    unsigned int p_pow=pow(10,size);
    T tmp_dollar=p1.getDollar()-p2.getDollar();
    T tmp_cent=p1.getCent()-p2.getCent();
    T tmp;
    if(tmp_cent<0)
    {

        tmp_dollar-=1;
        tmp_cent+=p_pow;
    }
    if (tmp_cent>=p_pow)
    {
        if(tmp_cent>=p_pow)
        {
            tmp=tmp_cent/p_pow;
        }
        tmp_dollar+=tmp;
        tmp_cent%=p_pow;
    }
    return Price<size,T> (tmp_dollar,tmp_cent);


}
/*template <unsigned int size,typename  T>
inline Price<T> operator*(const Price<T>& p1,const Price<T>& p2)
{
    T res=(p1.getDollar()*100+p1.getCent())*(p2.getDollar()*100+p2.getCent());
    return Price<T> (res/100,res%100);

}
inline Price operator/(Price p1,Price p2)
{
    int res=p1.get_price_in_cent()/p2.get_price_in_cent();
    Price p_res(res/100,res%100);
    return p_res;
}
inline Price operator%(Price p1,Price p2)
{
    int res=p1.get_price_in_cent()%p2.get_price_in_cent();
    Price p_res(res/100,res%100);
    return p_res;
}*/
template <unsigned int size,typename  T>
inline Price<size,T>& Price<size,T>::operator+=(const Price<size,T>& p) {
    *this=(*this+p);
    return *this;
}

template <unsigned int size,typename  T>
inline Price<size,T>& Price<size,T>::operator-=(Price<size,T> p) {
    *this=(*this-p);
    return *this;
}
template <unsigned int size,typename  T>
inline Price<size,T>& Price<size,T>::operator++() {
    *this+=Price<size,T>(1);
    return *this;
}
template <unsigned int size,typename  T>
inline Price<size,T> Price<size,T>::operator++(int) {
    Price<size,T> p_res=*this;
   *this+=Price<size,T>(1);
    return p_res;
}
template <unsigned int size,typename  T>
inline Price<size,T>& Price<size,T>::operator--() {
    *this-=Price<size,T>(1);
    return *this;
}
template <unsigned int size,typename  T>
inline Price<size,T> Price<size,T>::operator--(int) {
    Price<size,T> p_res=*this;
    *this-=Price<size,T>(1);
    return p_res;
}
template <unsigned int size,typename T>
inline Price<size,T>& Price<size,T>::operator=(const Price<size,T> & p1) {
    m_dollars=p1.getDollar();
    m_cents=p1.getCent();
    m_neg=!p1.isPos();
    return *this;
}

/*inline Price& Price::operator*=(Price p) {
    int res=get_price_in_cent()*p.get_price_in_cent();
    m_dollars=abs(res)/100;
    m_cents=abs(res)%100;
    m_neg = (res<0);
    return *this;
}
inline Price& Price::operator/=(Price p) {
    int res=get_price_in_cent()/p.get_price_in_cent();
    m_dollars=abs(res)/100;
    m_cents=abs(res)%100;
    m_neg = (res<0);
    return *this;
}
inline Price& Price::operator%=(Price p) {
    int res=get_price_in_cent()%p.get_price_in_cent();
    m_dollars=abs(res)/100;
    m_cents=abs(res)%100;
    m_neg = (res<0);
    return *this;
}
*/
template <unsigned int size,typename T>
inline std::ostream& operator<<(std::ostream& cout,Price<size,T>& p){
    cout<<double(p)<<std::endl;
    return cout;
}


#endif //FIXED_PRICE_H
