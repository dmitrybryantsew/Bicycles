#ifndef BICYCLES_SIMPLEALLOCATORAWARETYPE_HPP
#define BICYCLES_SIMPLEALLOCATORAWARETYPE_HPP
template<class T, class Allocator = std::allocator<T>> class SimpleVector {
public:
    using allocator_type    = Allocator;
    using pointer           = typename Allocator::pointer;
    using value_type        = typename Allocator::value_type;
    using reference         = typename Allocator::reference;
    using const_reference   = typename Allocator::const_reference;
    using difference_type   = typename Allocator::difference_type;
    using size_type         = typename Allocator::size_type;



    class iterator {
    public:
        using value_type        = typename Allocator::value_type;
        using pointer           = typename Allocator::pointer;
        using reference         = typename Allocator::reference;
        using difference_type   = typename Allocator::difference_type;
        using iterator_category = std::random_access_iterator_tag;


        explicit iterator(pointer data)  : _data(data){}
        iterator() = default;
        iterator(const iterator& other) {this->_data = other.getPointer();};
        ~iterator() = default;

        iterator& operator=(const iterator& other) {
            if (this != &other)
            {
                this->_data = other.getPointer();
            }
            return *this;
        }
        bool operator==(const iterator& other) const{
            return this->_data == other._data;
        };
        bool operator!=(const iterator& other) const { return this->_data != other._data;}
        bool operator<(const iterator& other) const {

        } //optional
        bool operator>(const iterator&) const{

        }; //optional
        bool operator<=(const iterator&) const; //optional
        bool operator>=(const iterator&) const; //optional

        iterator& operator++(){
            _data+=1;
            return *this;
        }
        iterator operator++(int){
            return iterator(_data+1);
        } //optional
        iterator& operator--(); //optional
        iterator operator--(int); //optional
        iterator& operator+=(size_type); //optional
        iterator operator+(size_type) const; //optional
        friend iterator operator+(size_type, const iterator&); //optional
        iterator& operator-=(size_type); //optional
        iterator operator-(size_type) const; //optional
        difference_type operator-(iterator& other) const{
            return this->_data - &(*other);
        }; //optional

        reference operator*(){return *_data;}
        pointer operator->() const { return _data;};
        reference operator[](size_type) const; //optional

        pointer getPointer() const { return _data;}

        pointer _data;
    };
    class const_iterator {
    public:
        typedef typename Allocator::difference_type difference_type;
        typedef typename Allocator::value_type value_type;
        const typedef typename  Allocator::reference reference;
        const typedef typename  Allocator::pointer pointer;
        typedef std::random_access_iterator_tag iterator_category; //or another tag

        const_iterator () = default;
        const_iterator (const const_iterator& other) : _data(other.getPointer()){};
        const_iterator (const iterator& other) : _data(other.getPointer()){};
        ~const_iterator() = default;

        const_iterator& operator=(const const_iterator& other){
            if (this != &other)
            {
                this->_data = other.getPointer();
            }
            return *this;
        };
        bool operator==(const const_iterator& other) const {
            return this->_data == other._data;
        };
        bool operator!=(const const_iterator&) const;
        bool operator<(const const_iterator&) const; //optional
        bool operator>(const const_iterator&) const; //optional
        bool operator<=(const const_iterator&) const; //optional
        bool operator>=(const const_iterator&) const; //optional

        const_iterator& operator++();
        const_iterator operator++(int); //optional
        const_iterator& operator--(); //optional
        const_iterator operator--(int); //optional
        const_iterator& operator+=(size_type); //optional
        const_iterator operator+(size_type) const; //optional
        friend const_iterator operator+(size_type, const const_iterator&); //optional
        const_iterator& operator-=(size_type); //optional
        const_iterator operator-(size_type) const; //optional
        difference_type operator-(const_iterator) const; //optional

        reference operator*() const;
        pointer operator->() const;
        reference operator[](size_type) const; //optional

        pointer getPointer() const { return _data;}

        pointer _data;
    };

    //TODO rule of 5
    SimpleVector(){
        initPointersNull();

    };



    explicit SimpleVector( const Allocator& allocator ) : _alloc{allocator}{
       initPointersNull();
    };

    explicit SimpleVector( size_type count ,  const allocator_type& allocator =allocator_type() ) :
            _alloc{allocator}{
        _begin = _alloc.allocate(count);
        _capacity = count;
        _end = _begin + count + 1;
        _lastInArray = _begin;
    };
    SimpleVector( size_type count, const T& value, const Allocator& allocator = Allocator()) :
            _alloc{allocator}{
        _begin = _alloc.allocate(count+1);
        _capacity = count+1;
        _end = _begin + count + 1;
        _lastInArray = _begin + count;
        for(pointer tmp = _begin; tmp <= _lastInArray; ++tmp)
        {
            std::allocator_traits<allocator_type>::construct(_alloc, tmp, value);
        }
        _size = count;
    };
    template< class InputIt >
    SimpleVector( InputIt first, InputIt last, const Allocator& allocator = Allocator() ) : _alloc{allocator}{ //todo fix
        size_type newSize = last - first; //end points to memory one past allocated
        copyAllocate(&(*first), newSize);

    };

    SimpleVector( const SimpleVector& other ); //copy constructor
    SimpleVector( const SimpleVector& other, const Allocator& alloc );
    SimpleVector( SimpleVector&& other ) noexcept; // move constructor
    SimpleVector( SimpleVector&& other, const Allocator& alloc );
    SimpleVector( std::initializer_list<T> init, const Allocator& alloc = Allocator() );

    //assign
    void assign( size_type count, const T& value );
    template< class InputIt >
    void assign( InputIt first, InputIt last );
    void assign( std::initializer_list<T> ilist );

    ~SimpleVector(){
        clean_up_memory(_begin, _lastInArray, _size);
    }

    //element access
    //erase
    iterator erase(const_iterator pos){

    }

    iterator erase(const_iterator first, const_iterator last){

    }

    //at
    reference at(size_type pos){
        if (_lastInArray - _begin <= pos) throw;
        return *(_begin+pos);
    }

    const_reference at(size_type pos) const {
        if (_lastInArray - _begin <= pos) throw;
        return *(_begin + pos);
    }
    //front
    T& front(size_type pos){
        return *_begin;
    }
    //back
    T& back(size_type pos){
        return *_lastInArray;
    }
    //data
    T* data(size_type pos){
        return _begin;
    }
    //capacity
    size_type capacity(){
        return _capacity;
    }
    //empty
    void empty(){
        return _begin == _end;
    }
    //size
    size_type size(){
        return _size;
    }
    //max_size

    //reserve
    void reserve(size_type size) {
        reallocate(size);
    }
    //capacity

    //shrink to fit

    //modification
    //clear
    void clear(){
        clean_up_memory(_begin, _lastInArray, _lastInArray - _begin);
        initPointersNull();
        _size = 0;
        _capacity = 0;
    }
    //insert

    //emplace
    template <class... params>
    iterator emplace(const_iterator pos, params&&... param){

    }

    //emplace back
    template <class... params>
    decltype(auto) emplace_back(params&&... param){
        if(nullptr != _begin && _lastInArray != _end - 1){
            return emplace_back_available_place(std::forward<params>(param)...);
        }
        reference result = emplace_reallocate(std::forward<params>(param)...);
        return  result;
    }
    //emplace back in unused capacity
    template <class... params>
    decltype(auto) emplace_back_available_place(params&&... param){
        std::allocator_traits<allocator_type>::construct(_alloc, _lastInArray, std::forward<params>(param)...);
        ++_size;
        reference result = *_lastInArray;
        ++_lastInArray;
        return result;
    }



    //emplace back reallocate
    template <class... params>
    decltype(auto) emplace_reallocate(params&&... param){
        size_type newSize = _capacity > 0 ? _capacity * _growth : _capacity + 4;
        reallocate(newSize);

        std::allocator_traits<allocator_type>::construct(_alloc, _lastInArray, std::forward<params>(param)...);
        reference result = *_lastInArray;
        ++_size;
        ++_lastInArray;
        return result;
    }


    //push back
    void push_back(T& value){
        emplace_back(value);
    }
    void push_back(T&& value){
        emplace_back(std::move(value));

    }

    //pop_back
    void pop_back(){

        std::allocator_traits<allocator_type>::destroy(_alloc, _lastInArray);
        --_size;
        --_lastInArray;

    }
    //resize
    void resize( size_type count );
    void resize( size_type count, const value_type& value );
    //swap
    void swap(SimpleVector& other){

    }


    //utility
    void reallocate(size_type size){
        pointer oldBegin = _begin;
        _capacity = size;
        _begin = _alloc.allocate( size);
        _end = _begin + _capacity+1; //TODO bug?
        memcpy(_begin, oldBegin, sizeof(T) * _size);
        clean_up_memory(oldBegin, _lastInArray, _size);
        _lastInArray = _begin + _size;
    }

    void copyAllocate(pointer srcBegin, size_type size){
        _begin = _alloc.allocate( size + 1);
        memcpy(_begin, srcBegin, sizeof(T) * size);
        _size = size;
        _capacity = size + 1;
        _lastInArray = _begin + size;
        _end = _begin + size + 1;
    }
    inline allocator_type getAllocator(){return _alloc;}

    void clean_up_memory(pointer begin, pointer last, size_type size){
        for(pointer tmp = begin; tmp < last; tmp++){
            std::allocator_traits<allocator_type>::destroy(_alloc, tmp);
        }
        _alloc.deallocate(begin, size);
    }
    void initPointersNull(){
        _begin = nullptr;
        _lastInArray = _begin;
        _end = _begin;
    }
    iterator begin() {return iterator(_begin);};
    iterator end() {return iterator(_end);};  //TODO FIX
    iterator lastElem() {return iterator(_lastInArray);}
    reference operator[](size_type n){return *(_begin+n);}
    const_reference operator[](size_type n) const {return *(_begin+n);}

private:

    allocator_type _alloc; // Should probably be private
    pointer        _begin;
    pointer        _end;
    pointer        _lastInArray;
    size_type      _size = 0;
    size_type      _capacity = 0;
    size_type      _growth = 2;
};


#endif //BICYCLES_SIMPLEALLOCATORAWARETYPE_HPP
