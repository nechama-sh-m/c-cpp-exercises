#include "stdio.h"
#include "cstdint"
#include <stdexcept>
template<typename T>
class Vector
{
public:
Vector();
Vector(size_t size, T val);
Vector(const Vector &other);
~Vector();
size_t size() const;
size_t max_size() const;
void resize(size_t size);
Vector& operator = (const Vector &other);
    size_t capacity() const;
    bool empty();
    void reserve (size_t n);
    Vector<T>& operator[](size_t n);
    const Vector<T>& operator[](size_t n) const;
    Vector<T>& at(size_t n);
    const Vector<T>& at(size_t n) const;
    Vector<T>& front();
    const Vector<T>& front() const;
    Vector<T>& back();
    const Vector<T>& back() const;
    T* data();
    const T* data() const;
    void assign(size_t,const T&);
    void push_back (const T& val);
    void pop_back();
    void insert(size_t index,size_t num,T val);
    void erase(size_t);
    void swap (Vector& x);
    void clear();



private:
    T *m_vector;
    size_t m_size;
    size_t m_capacity;
};

template<typename T>
inline Vector<T>::Vector():m_vector(NULL),m_size(0),m_capacity(0)
{
	/*m_vector=new T[0];
	m_size=0;
	m_capacity=0;*/
}

template<typename T>
inline Vector<T>::Vector(size_t size, T val):m_vector(new T[size]),m_size(size),m_capacity(size)
{
	/*m_vector=new T[size];
	m_size=size;
	m_capacity=size;*/
	size_t i;
	for(i=0;i<size;i++)
	    m_vector[i]=val;
}

template<typename T>
inline Vector<T>::Vector(const Vector &other)
{
        m_vector=new T[other.capacity()];
        m_size=other.size();
        m_capacity=other.capacity();
        size_t i;
        for(i=0;i<other.capacity();i++)
            m_vector[i]=other[i];
}

template<typename T>
inline Vector<T>::~Vector()
{
	delete [] m_vector;
}

template<typename T>
inline Vector<T>& Vector<T>::operator = (const Vector &other)
{
    if(this->m_vector!=other.m_vector)
    {
        delete[] m_vector;
        this->resize(other.size());
        m_size = other.size();
        m_capacity = other.size();
        size_t i;
        for (i = 0; i < other.size(); i++)
            m_vector[i] = other[i];
    }
	return *this;
}

template<typename T>
inline size_t Vector<T>::size ()const
{
	return m_size;
	
}

template<typename T>
inline size_t Vector<T>::max_size ()const
{
	return SIZE_MAX;

}

template<typename T>
inline void Vector<T>::resize (size_t size)
{
    size_t i;
	if(size<=m_capacity)
	{
	    m_capacity=size;
	    if(size<m_size)
	    {
	        for (i=size;i<m_size;i++)
	            m_vector[i].~T();
	    	m_size=size;
	    }
	}
	else
	{
	    T *vec=m_vector;
		m_vector= new T[size];
		for(i=0;i<m_size;i++)
	           m_vector[i]=vec[i];
	        m_capacity=size;
	        delete [] vec;      
	}
}

template <typename T>
inline size_t Vector<T>::capacity() const {
    return m_capacity;
}

template <typename T>
inline bool Vector<T>::empty() {
    return m_size==0;
}

template <typename T>
inline void Vector<T>::reserve(size_t n) {
    int i;
    if(n<=m_capacity)
        return;
    size_t size=m_capacity*2?n<=m_capacity*2:n;
    T* tmp=new T[size];
    for(i=0;i<m_size;i++)
        tmp[i]=m_vector[i];
    for(i=m_size;i<n;i++)
        tmp[i]=0;
    delete [] m_vector;
    m_vector=tmp;
    m_capacity=n;

}

template <typename T>
inline Vector<T>& Vector<T>::operator[](size_t n) {
    return m_vector[n];
}

template <typename T>
inline const Vector<T>& Vector<T>::operator[](size_t n) const{
    return m_vector[n];
}

template <typename T>
inline Vector<T>& Vector<T>::at(size_t n){
    if(n>m_size)
        throw std::out_of_range("The index out of range");
    return m_vector[n];
}

template <typename T>
inline const Vector<T>& Vector<T>::at(size_t n) const {
    if(n>m_size)
        throw std::out_of_range("The index out of range");
    return m_vector[n];
}

template <typename T>
Vector<T>& Vector<T>::front(){
    return m_vector[0];
}

template <typename T>
const Vector<T>& Vector<T>::front()const{
    return m_vector[0];
}

template <typename T>
inline Vector<T>& Vector<T>::back(){
    return m_vector[m_size-1];
}

template <typename T>
inline const Vector<T>& Vector<T>::back()const{
    return m_vector[m_size-1];
}

template <typename T>
inline T* Vector<T>::data() {
    return m_vector;
}

template <typename T>
inline const T* Vector<T>::data() const {
    return m_vector;
}

template <typename T>
inline void Vector<T>::assign(size_t num, const T &val) {
    int i;
    size_t size=m_capacity ?num<m_capacity:num;
    m_capacity=size;
    T* tmp=new T[size];
    for (i=0;i<num;i++)
        tmp[i]=val;
    for(i=num;i<m_capacity;i++)
        tmp[i]=0;
    delete [] m_vector;
    m_vector=tmp;
    m_size=num;
}

template <typename T>
inline void Vector<T>::push_back(const T &val) {
    size_t i;
    if(m_capacity==m_size){
        T* tmp=new T[m_capacity*2];
        for(i=0;i<m_size;i++)
            tmp[i]=m_vector[i];
        m_capacity*=2;
        for(i=m_size;i<m_capacity;i++)
            tmp[i]=0;
        delete [] m_vector;
        m_vector=tmp;
    }
    m_vector[m_size]=val;
    m_size+=1;
}

template <typename T>
inline void Vector<T>::pop_back() {
    if(!empty())
    {
        m_vector[m_size-1].~T();
        m_size-=1;
    }
}
template <typename T>
inline void Vector<T>::insert(size_t index,size_t num,T val){
    size_t i,j;
    size_t tmpp=m_size;
    m_capacity=m_capacity ?m_size+num<m_capacity:m_capacity*2;
    m_capacity=m_capacity ?m_size+num<m_capacity:m_size+index;
    T* tmp=new T[m_capacity];
    for(i=0;i<index;i++)
        tmp[i]=m_vector[i];
    for (j=0;j<num;j++)
        tmp[i+j]=val;
    for(i=i+num;i<tmpp+num;i++)
        tmp[i]=m_vector[i-num];
    for(;i<m_capacity;i++)
        tmp[i]=0;
    delete [] m_vector;
    m_vector=tmp;
    m_size+=num;
}

template <typename T>
inline void Vector<T>::erase(size_t pos){
    size_t i;
    for(i=pos;i<m_size-1;i++)
    {
        m_vector[i].~T();
        m_vector[i]=m_vector[i+1];
    }

    m_vector[m_size].~T();
    m_size-=1;
}

template <typename T>
inline void Vector<T>::swap(Vector<T> &x) {
    Vector<T>tmp=x;
    x=this;
    this=tmp;
}
template <typename T>
inline void Vector<T>::clear() {
    resize(0);
}

template <typename T>
inline Vector<T>& operator+(Vector<T> v1,Vector<T>v2) {
    size_t i;
    Vector<T> res = v1;
    for (i = 0; i < v2.size(); i++)
        res.push_back(v2[i]);
    return res;
}

template <typename T>
inline void operator+=(Vector<T> v1,Vector<T>v2){
    v1=v1+v2;
}

template <typename T>
inline std::ostream & operator<<(std::ostream& cout,Vector<T> v){


}