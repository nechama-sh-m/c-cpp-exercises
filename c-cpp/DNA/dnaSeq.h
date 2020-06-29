//
// Created by student on 01/06/2020.
//

#ifndef DNA_DNASEQ_H
#define DNA_DNASEQ_H

#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include "exc.h"



static const char arr_val[4]={'A','C','T','G'};
class DnaSeq{
private:
    class DnaChar{
    public:
        DnaChar(char);
        DnaChar();
        DnaChar(const DnaChar &);
        DnaSeq::DnaChar& operator=(const DnaChar&);
        const char get_char()const;//remove ref and add const
        operator char();
        char comp(const char&) const;
    private:
        char ch;
    };
    DnaChar* m_seq;
    size_t m_len;
    DnaSeq::DnaChar* convert(const char*);
    DnaSeq::DnaChar* convert(std::string);

public:
    DnaSeq(const std::string&);
    DnaSeq(char *);
    DnaSeq(const DnaSeq &);
    ~DnaSeq();
    DnaSeq& operator= (const DnaSeq &);
    const std::string get_seq()const;
    const size_t get_len()const ;
    DnaSeq::DnaChar& operator[](size_t);
    const DnaSeq::DnaChar& operator[](size_t) const;
    DnaSeq slice(size_t,size_t);
    DnaSeq pairing();
    const size_t findIndexSub(const DnaSeq& d);
    const size_t count(const DnaSeq& d);
    const std::vector<size_t > findAllSub(const DnaSeq& d);
    const std::vector<DnaSeq >findCon();


};

inline DnaSeq::~DnaSeq(){
    delete[] m_seq;
}


inline DnaSeq::DnaSeq(const std::string& str):m_seq(convert(str.c_str())),m_len(strlen(str.c_str())){}

inline DnaSeq::DnaSeq(char * c ):m_seq(convert(c)),m_len(strlen(c)){}

inline DnaSeq::DnaSeq (const DnaSeq &d):m_seq(new DnaChar[d.get_len() + 1]),m_len(d.get_len()){
       m_seq=convert(d.get_seq());
}

inline const std::string DnaSeq::get_seq()const {
    std::string str;
    for (size_t i = 0; i < m_len; ++i) {
        str.push_back(m_seq[i].get_char());
    }
    return str;
}

inline const size_t DnaSeq::get_len()const{return m_len;}

inline DnaSeq& DnaSeq::operator= (const DnaSeq &d)
{
    if (this != &d)
    {
        DnaChar* tmp=m_seq;
        m_seq=new DnaChar[d.get_len() + 1];
        delete [] tmp;
        m_seq=convert(d.get_seq());
        m_len=d.get_len();
    }
    return *this;
}


inline std::ostream& operator<<(std::ostream& cout,const DnaSeq& d){
    cout<<d.get_seq()<<std::endl;
    return cout;
}


inline bool operator==(const DnaSeq& d,const DnaSeq& d1){
   if(d.get_seq()==d1.get_seq())
       return true;
    return false;
}

inline bool operator!=(const DnaSeq& d,const DnaSeq& d1){
    if(d.get_seq()!=d1.get_seq())
        return true;
    return false;
}


inline DnaSeq::DnaChar& DnaSeq::operator[](size_t index){
    return  m_seq[index];
}
inline const DnaSeq::DnaChar& DnaSeq::operator[](size_t index) const{
    return  m_seq[index];
}

inline DnaSeq::DnaChar::DnaChar(char c):ch(c){
    bool flag= false;
    for (size_t j = 0; j < sizeof(arr_val) ; j++)
    {

        if (ch==arr_val[j])
            flag= true;
    }

    if (!flag)
        throw InvalidDna();

}
inline DnaSeq::DnaChar::DnaChar(const DnaChar & d):ch(d.get_char()){}//copy constractor
inline DnaSeq::DnaChar::DnaChar(){}

inline DnaSeq::DnaChar& DnaSeq::DnaChar:: operator=(const DnaChar& d){
    ch=d.ch;
    return *this;
}



inline const char  DnaSeq::DnaChar::get_char()const{ return ch;}

inline  DnaSeq::DnaChar::operator char() {
    return ch;
}






DnaSeq readFromFile(const char* file_name);

void writeFromFile(DnaSeq d,const char* file_name);




#endif //DNA_DNASEQ_H
