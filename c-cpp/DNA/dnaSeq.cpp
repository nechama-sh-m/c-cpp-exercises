//
// Created by student on 01/06/2020.
//


#include "dnaSeq.h"

DnaSeq::DnaChar* DnaSeq::convert(const char* c){
    size_t len=strlen(c);
    DnaChar* tmp=new DnaChar[(len+1)];
    for (size_t i = 0; i <len ; ++i) {
        try {
            tmp[i] = c[i];
        }
        catch (InvalidDna& e){
            delete[]tmp;
            throw ;
        }
    }
    return tmp;

}
DnaSeq::DnaChar* DnaSeq::convert(std::string str){
    return convert(str.c_str());
}
const size_t DnaSeq::count(const DnaSeq &d) {
    size_t counter=0;
    size_t index;
    std::string tmp=get_seq();
    for (size_t i = 0; i <m_len ; i++) {
        index=tmp.find(d.get_seq());
        if(index==-1)
            break;
        tmp.erase(tmp.begin(),tmp.begin()+index+1);
        counter+=1;
    }
    return counter;

}
const std::vector<size_t > DnaSeq::findAllSub(const DnaSeq& d){
    std::vector<size_t > indexs;
    std::string tmp=get_seq();
    size_t index;
    for (size_t i = 0; i <m_len ; i++) {
        index=tmp.find(d.get_seq());
        if(index==-1)
            break;
        indexs.push_back(index+(m_len-tmp.length()));
        tmp.erase(tmp.begin(),tmp.begin()+index+1);
    }
    return indexs;
}
const std::vector<DnaSeq >DnaSeq::findCon(){
    std::vector<DnaSeq> tmp;
    std::string str=get_seq();
    std::vector<size_t> start=findAllSub("ATG");
    std::vector<size_t>::iterator it=start.begin();
    for (;it!=start.end();it++)
    {
        for (size_t i = *it+3; i <m_len ; i+=3) {
            if(str[i]=='T')
            {
                if(str[i+1]=='A') {
                    if(str[i+2]=='G'||str[i+2]=='A')
                    {
                        tmp.push_back(slice((*it-1),i+3)) ;
                    }
                }
                else
                {
                    if(str[+i+1]=='G' && str[i+2]=='A')
                    {
                        tmp.push_back(slice((*it-1),i+3)) ;
                    }
                }

            }
        }

    }
    return tmp;
}
DnaSeq DnaSeq::pairing() {
    std::string tmp;
    for (size_t i = 0; i < m_len ; i++) {
        tmp.push_back(m_seq->comp(m_seq[m_len-1-i].get_char()));
    }

    return tmp;

}
DnaSeq readFromFile(const char* file_name){
    std::string tmp;
    std::ifstream dna_file;
    dna_file.open(file_name);
    if(!dna_file.is_open())
    {
        throw OpenFileFail();
    }

    getline(dna_file,tmp);
    dna_file.close();
    return tmp;
}
void writeFromFile(DnaSeq d,const char* file_name){

    std::ofstream dna_file;
    dna_file.open(file_name);
    if(dna_file.is_open())
    {
        dna_file<<d.get_seq();
        dna_file.close();
    }
    else
    {
        throw OpenFileFail();
    }

}
DnaSeq DnaSeq::slice(size_t start, size_t end) {
    std::string tmp;
    for (size_t i = start+1; i < end ; i++) {
        tmp.push_back( m_seq[i].get_char()) ;
    }
    return tmp;

}


char DnaSeq::DnaChar::comp(const char & c) const {
    if (c=='T') return 'A';
    if (c=='A') return 'T';
    if (c=='G') return 'C';
    if (c=='C') return 'G';
    return '\0';
}
const size_t DnaSeq::findIndexSub( const DnaSeq& d) {
    return get_seq().find(d.get_seq());
}
