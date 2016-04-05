#include <iostream>
#include "DoubleLinkedList.h"


int main() {
    DoubleLinkedList<int> doubleLinkedList;
    doubleLinkedList.push_back(5);
    doubleLinkedList.push_back(6);
    std::cout<<doubleLinkedList.element_at(1)<<std::endl;
    // doubleLinkedList.push_forward(7);
    //for(auto itter_liked_list = doubleLinkedList.begin();itter_liked_list!=doubleLinkedList.end();++itter_liked_list){
      //  std::cout<<(*itter_liked_list).data<<std::endl;
    //}
    return 0;
}