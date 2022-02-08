//
// Created by dmitr on 12/7/2021.
//

#ifndef BICYCLES_TRACKINGALLOCATOR_HPP
#define BICYCLES_TRACKINGALLOCATOR_HPP
#include <iostream>
#include <limits>
#include <memory>
#include <vector>
template <class T>
class TrackingAllocator
{
public:
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using void_pointer = void*;
    using const_void_pointer = const void*;
    using size_type = size_t;
    using difference_type = std::ptrdiff_t;
    using reference = T&;
    using const_reference = const T&;

    template<class U>
    struct rebind
    {
        using other = TrackingAllocator<U>;
    };

    TrackingAllocator() = default;
    //vector internally will try to use this mechanism to create another allocator  and copied to our allocator which means our allocator should be able to accept other allocators working on another types of object
    template<class U>
    TrackingAllocator(const TrackingAllocator<U> &other){}
    ~TrackingAllocator() = default;

    pointer allocate(size_type numObjects)
    {
        mAllocations+=numObjects;
        return static_cast<pointer>(operator new(sizeof(T) * numObjects));
    }
    //another version uses locality hint improve cache performance
    pointer allocate(size_type numObjects, const_void_pointer hint){
        return allocate(numObjects);
    }

    void deallocate(pointer p, size_type n)
    {
        std::cout << "deallocated " << sizeof(*p) * n << " bytes\n";
        operator delete(p);
    }

    size_type max_size() const
    {
        return std::numeric_limits<size_type>::max();
    }
    /* Deprecated in C++17
    template<class U, class... Args>
    void construct(U *p, Args && ...args)
    {
        new(p) U(std::forward<Args>(args)...);
    }

    template <class U>
    void destroy(U *p)
    {
        p->~U();
    }
*/
    size_type get_allocationCount() const
    {
        return mAllocations;
    }

private:
    static size_type mAllocations;
};

template <class T>
typename TrackingAllocator<T>::size_type TrackingAllocator<T>::mAllocations = 0;
#endif //BICYCLES_TRACKINGALLOCATOR_HPP
