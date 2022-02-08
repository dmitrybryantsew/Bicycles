//
// Created by dmitr on 11/21/2021.
//

#ifndef BICYCLES_UPOINTER_HPP
#define BICYCLES_UPOINTER_HPP

template <class T>
class UPointer {
public:
    UPointer() = default;
    explicit UPointer(T* data);
    ~UPointer();
    UPointer(const UPointer& other) = delete; // copy
    UPointer(UPointer&& other) noexcept ; // move
    UPointer& operator=(const UPointer& other) = delete; // copy assigment
    UPointer& operator=(UPointer&& other) noexcept; // move assigment
    T* operator->(){return _data;}
    T& operator*(){return *_data;}
private:
    T* _data = nullptr;
};

template<class T>
UPointer<T>::UPointer(T* data) : _data(data) {}

template<class T>
UPointer<T>::~UPointer() {

    if(_data) {
        std::cout << "destructor called! deleting " << *_data << " adress is " << _data << "\n";
        delete _data;
    }
}

template<class T>
UPointer<T> &UPointer<T>::operator=(UPointer &&other) noexcept {
    if(this != &other){
        std::cout << "move assigment\n";
        this->_data = other->_data;
        other._data = nullptr;
    }
    return *this;
}

template<class T>
UPointer<T>::UPointer(UPointer &&other) noexcept {
    if(this != &other){
        std::cout << "move\n";
        this->_data = other._data;
        other._data = nullptr;

    }

}


#endif //BICYCLES_UPOINTER_HPP
