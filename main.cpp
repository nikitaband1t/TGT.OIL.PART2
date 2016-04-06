#include <iostream>
#include "DoubleLinkedList.h"

bool func(int x) {
    if (x > 6)
        return false;
    return true;
}

int main() {
    DoubleLinkedList<int> list;
    for (int i = 0; i < 100; ++i) {
        if (i <= 50) {
            list.push_back(i);
        }
        else {
            list.push_forward(i);
        }
    }
    for (int i = 0; i <=9; ++i) {
        list.delete_by_index(i*10+9);
    }
    for (auto itt = list.begin(); itt != list.end(); ++itt){
        std::cout<<(*itt).get_data()<<" ";
    }
    std::cout<<std::endl;
    std::cout<<list.length()<<std::endl;
    /*erase,insert*/
    /*insert by itter*/
    /*erase by positionrealisze*/
    for(int i = 0 ; i<list.length();++i){
        list.delete_by_index(0);
    }

    for (auto itt = list.begin(); itt != list.end(); ++itt){
        std::cout<<(*itt).get_data()<<" ";
    }
    std::cout<<std::endl;
    std::cout<<list.length()<<std::endl;
        return 0;
}