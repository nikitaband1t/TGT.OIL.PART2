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
class MyIterator : std::iterator<std::input_iterator_tag, std::shared_ptr<Node<T>>> {
    std::shared_ptr<Node<T>> ptr;
public:
    MyIterator(std::shared_ptr<Node<T>> val) {
        ptr = val;
    }

    MyIterator(const MyIterator &mit) : MyIterator(mit.ptr) { }

    MyIterator &operator++() {
        ptr = ptr.get()->right;
        return *this;
    }

    MyIterator &operator--() {
        if (ptr->left != nullptr) {
           ptr = ptr.get()->left;
            return *this;
        }
    }

    bool operator!=(const MyIterator &myIterator) { return ptr != myIterator.ptr; }

    Node<T> &operator*() { return *ptr.get(); }

};

template<class T>
class DoubleLinkedList {
private:
    int _length;
    std::shared_ptr<Node<T>> _begin, _end, _now;
public:
    DoubleLinkedList();

    T push_back(T elem);

    T push_forward(T elem);

    T add_at(int ind);

    T delete_by_index(long num);

    T *delete_first_elem(T elem);

    std::shared_ptr<Node<T>> previous();

    std::shared_ptr<Node<T>> next();

    MyIterator<T> &begin();

    MyIterator<T> &end();


    T remove();

    DoubleLinkedList &remove_if(bool f(T data));

    T element_at(int ind);

    long length();
};

template<class T>
DoubleLinkedList<T>::DoubleLinkedList() {
    _length = 0;
}

template<class T>

MyIterator<T> &DoubleLinkedList<T>::begin() {
    MyIterator<T> *bgt = new MyIterator<T>(_begin);
    return *bgt;
}

template<class T>
MyIterator<T> &DoubleLinkedList<T>::end() {
    MyIterator<T> *bgt = new MyIterator<T>(_end);
    return *bgt;
}

template<class T>
T DoubleLinkedList<T>::push_back(T elem) {
    _length++;
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


template<class T>
T DoubleLinkedList<T>::delete_by_index(long num) {
    if (num >= 0 && num < _length) {
        _length--;
        if (num == 0) {
            _begin = _begin.get()->right;
        }
        else if (num == (_length)) {
            _end = _end.get()->left;
        }
        else {
            int itterator = 0;
            std::shared_ptr<Node<T>> begin_itt = _begin;
            while (itterator != num) {
                begin_itt = begin_itt.get()->right;
                itterator++;
            }
            std::cout << begin_itt.use_count() << std::endl;
            begin_itt.get()->right.get()->left = begin_itt.get()->left;
            begin_itt.get()->left.get()->right = begin_itt.get()->right;
            return begin_itt.get()->get_data();
        }

    }

}

template<class T>
T DoubleLinkedList<T>::push_forward(T elem) {
    _length++;
    if (_begin == nullptr) {
        _begin = std::shared_ptr<Node<T>>(new Node<T>(elem));
        _begin.get()->left = nullptr;
        _end = _begin;
        return elem;
    }
    std::shared_ptr<Node<T>> new_begin(new Node<T>(elem));
    new_begin.get()->right = _begin;
    _begin.get()->left = new_begin;
    _begin = new_begin;
}

template<class T>
long DoubleLinkedList<T>::length() {
    return _length;
}


template<class T>
DoubleLinkedList &DoubleLinkedList<T>::remove_if(bool (*func)(T data)) {
    std::shared_ptr<DoubleLinkedList> list_out(new DoubleLinkedList());

    for (auto itt = begin(); itt != end(); ++itt) {
        if (func((*itt).data)) {
            list_out.get()->push_back((*itt).remove());
            --itt;
        }

    }
    return  *list_out.get();
}


#endif //LIST_DOUBLELINKEDLIST_H
