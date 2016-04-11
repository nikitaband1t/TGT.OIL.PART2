#include "DoubleLinkedList.h"
#include "string.h"
namespace Lists{
    template <class T>
    DoubleLinkedList<T> get_doublelinkedlist_from_arr(T *arr, long length);
}
template <class T>
DoubleLinkedList<T> Lists::get_doublelinkedlist_from_arr(T *arr, long length) {
    DoubleLinkedList<T> list;
 for (int i = 0;i<length;++i){
     list.push_back(*(arr+i));
 }
    return list;
}