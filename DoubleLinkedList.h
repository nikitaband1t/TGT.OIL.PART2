//
// Created by bandit on 4/5/16.
//
#ifndef LIST_DOUBLELINKEDLIST_H
#define LIST_DOUBLELINKEDLIST_H

#include <iostream>
#include <memory>


template<class T>
struct Node {
    T data;

    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;

    Node(T data);

    void set_data(T data);

    T get_data();

    T remove();
};

template<class T>
Node<T>::Node(T data) {
    this->data = data;
}

template<class T>
void Node<T>::set_data(T data) {
    this->data = data;
}

template<class T>
T Node<T>::get_data() {
    return this->data;
}

template<class T>
T Node<T>::remove() {
    right.reset();
    left.reset();
    right.get()->left = left;
    left.get()->right = right;
    return data;
}


template<class T>
class DoubleLinkedList {
private:
    std::shared_ptr<Node<T>> _begin, _end, _now;
public:
    DoubleLinkedList();

    T push_back(T elem);

    T push_forward(T elem);

    T add_at(int ind);

    T delete_by_index(int num);

    T delete_first_elem(T elem);

    std::shared_ptr<Node<T>> previous();

    std::shared_ptr<Node<T>> next();

    //MyIterator &begin();

    //MyIterator &end();


    T remove();

    T remove_if(bool f(T data));

    T element_at(int ind);

};

template<class T>
DoubleLinkedList<T>::DoubleLinkedList() {
}

template<class T>
T DoubleLinkedList<T>::push_back(T elem) {
    if (_begin == nullptr) {
        _begin = std::shared_ptr<Node<T>>(new Node<T>(elem));
        _begin.get()->left = nullptr;
        _end = _begin;
        return elem;
    }
    _end.get()->right = std::shared_ptr<Node<T>>(new Node<T>(elem));
    _end.get()->right.get()->left = std::shared_ptr<Node<T>>(new Node<T>(elem));
    _end = _end.get()->right;
    return elem;
}


template<class T>
T DoubleLinkedList<T>::element_at(int ind) {
    int itterator = 0;
    std::shared_ptr<Node<T>> begin_itt = _begin;
    while (itterator != ind) {
        begin_itt = begin_itt.get()->right;
        itterator++;
    }
    return begin_itt.get()->data;
}


#endif //LIST_DOUBLELINKEDLIST_H
