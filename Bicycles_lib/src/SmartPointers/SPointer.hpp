//
// Created by dmitr on 11/21/2021.
//

#ifndef BICYCLES_SPOINTER_HPP
#define BICYCLES_SPOINTER_HPP
template <class T>
class SPointer {
public:
    SPointer() = default;
    SPointer(T* data);
    ~SPointer();
    SPointer(const SPointer& other); // copy
    SPointer(SPointer&& other) noexcept ; // move
    SPointer& operator=(const SPointer& other); // copy assigment
    SPointer& operator=(SPointer&& other) noexcept; // move assigment
    T* operator->() const {return _data;}
    T& operator*() const {return *_data;}
    T * get() const {
        return _data;
    }
    std::size_t getRefcount(){
        return *_refcount;
    }
private:
    T* _data = nullptr;
    std::size_t* _refcount = new std::size_t(0);
};

template<class T>
SPointer<T>::SPointer(T* data) : _data(data) {
    //std::cout << *_refcount << "\n";
    (*_refcount)++;
    //std::cout << *_refcount << "\n";
}

template<class T>
SPointer<T>::~SPointer() {

    if(_data){
        //std::cout << "refcount = " << *_refcount << "\n";
        if(--(*_refcount) == 0){
            std::cout << "destructor called! deleting " << *_data << " adress is " << _data << "\n";
            delete _data;
            delete _refcount;
        } else {
            std::cout << "we still have refs! ref count: " << *_refcount << "\n";
        }
    }

}

template<class T>
SPointer<T>::SPointer(const SPointer &other) {
    std::cout << "Scopy\n";
    if(this != &other){
        _data = other._data;
        _refcount = other._refcount;
        (*_refcount)++;
    }

}

template<class T>
SPointer<T> &SPointer<T>::operator=(const SPointer &other) {
    std::cout << "Scopy assigment\n";
    if(this != &other){
        _data = other._data;
        (*_refcount)++;
    }
    return *this;
}

template<class T>
SPointer<T> &SPointer<T>::operator=(SPointer &&other) noexcept { //todo check default
    std::cout << "Smove assigment\n";
    if(this != &other){
        _data = other._data;
        _refcount = other._refcount;
        other._data = other._refcount = nullptr;
    }
    return *this;
}

template<class T>
SPointer<T>::SPointer(SPointer &&other) noexcept {
    std::cout << "Smove\n";
    if(this != &other) {
        _data = other._data;
        _refcount = other._refcount;
        other._data = other._refcount = nullptr;
    }

}

#endif //BICYCLES_SPOINTER_HPP
