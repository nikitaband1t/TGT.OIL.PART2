#include <iostream>
#include "DoubleLinkedList.h"
#include "Lists.h"
bool func(int x) {
    if (x < 6)
        return false;
    return true;
}

int main() {
    DoubleLinkedList<int> list;
    std::cout<<"Big routine check(insert,push,remove,get)"<<std::endl;
    for (int i = 0; i < 100; ++i) {
        if (i <= 50) {
            list.push_back(i);
        }
        else {
            list.push_forward(i);
        }
    }
    for (int i = 0; i <=9; ++i) {
        list.remove_index(i*10+9);
    }
    for (auto itt = list.begin(); itt != list.end(); ++itt){
        std::cout<<(*itt).get_data()<<" ";
    }
    std::cout<<std::endl;
    std::cout<<list.length()<<std::endl;
    /*erase,insert*/
    /*insert by itter*/
    /*erase by positionrealisze*/
    std::cout<<"RemoveIf func test by condition(x<6):"<<std::endl;
    list.remove_if(func);



    for (auto itt = list.begin(); itt != list.end(); ++itt){
        std::cout<<(*itt).get_data()<<" ";
    }
    std::cout<<std::endl<<"From array to list using length of array (1,2,3,4,5,6) "<<std::endl;

    int arr[] = {1,2,3,4,5,6};
    DoubleLinkedList<int> listt = Lists::get_doublelinkedlist_from_arr(arr,6);
    for (auto itt = listt.begin(); itt != listt.end(); ++itt){
        std::cout<<(*itt).get_data()<<" ";
    }


        return 0;
}