#include <iostream>
#include "DoubleLinkedList.h"

bool func(int x){
    if(x>6)
        return false;
    return true;
}

int main() {
    DoubleLinkedList<int> doubleLinkedList;
    doubleLinkedList.push_back(5);
    doubleLinkedList.push_back(6);
    doubleLinkedList.push_back(7);
    doubleLinkedList.push_back(8);
    doubleLinkedList.delete_by_index(3);
    std::cout<<doubleLinkedList.element_at(2)<<std::endl;
    std::cout<<doubleLinkedList.length()<<std::endl;


    DoubleLinkedList<int> list;
    list.push_forward(10);
    list.push_back(6);
    list.push_back(8);
    list.push_forward(7);
    std::cout<<list.element_at(0)<<std::endl;


    for(auto itter_liked_list = doubleLinkedList.begin();itter_liked_list!=doubleLinkedList.end();++itter_liked_list){
        std::cout<<(*itter_liked_list).data<<std::endl;
    }
    auto deleted = doubleLinkedList.remove_if(func);


    return 0;
}