#include <iostream>
#include "UPointer.hpp"
#include "SPointer.hpp"
#include <vector>
#include <algorithm>
#include "testStruct.hpp"
#include "trackingAllocator.hpp"
#include "simpleVector.hpp"
#include "basic_string.h"
#include "stack.h"
#include <vector>

#define N  13
int main(int argc, char** argv) {

    std::cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAHHHHHHHHHHHHH\n";
    SimpleVector<int, TrackingAllocator<int>> vec(3);
    for(int i= 0; i< N; i++)
        vec.push_back(i);

    for(int i = 0; i < N; i++){
        std::cout << vec.at(i) <<"\n";
    }

    SimpleVector<test, TrackingAllocator<test>> vec2(3);
    for(int i =0;i< N; i++)
        vec2.push_back(test(0+i, 0.0+i, "impost"));
    vec2.push_back(test());
    const int aaaa = 9;
    for(int i = 0; i < N+1; i++){
        std::cout << vec2.at(i) <<"\n";
    }

    std::cout << vec2.size() <<" " <<  vec2.capacity() << " " << sizeof(test) <<"\n";
    //vec2.pop_back();
    std::cout << vec2.size() <<" " <<  vec2.capacity() << " " << sizeof(test) <<"\n";
    for(int i = 0; i < N; i++){
        std::cout << vec2.at(i) <<"\n";
    }
    std::cout << "______________________________________\n";
    vec2.clear();
    for(int i =0;i< N; i++)
        vec2.push_back(test(0+i, 0.0+i, "clearance"));
    vec2.push_back(test());

    for(int i = 0; i < N+1; i++){
        std::cout << vec2.at(i) <<"\n";
    }

    std::cout << vec2.size() <<" " <<  vec2.capacity() << " " << sizeof(test) <<"\n";
    //vec2.pop_back();
    std::cout << vec2.size() <<" " <<  vec2.capacity() << " " << sizeof(test) <<"\n";
    for(int i = 0; i < N; i++){
        std::cout << vec2.at(i) <<"\n";
    }

    SimpleVector<test, TrackingAllocator<test>> vec3;
    for(int i =0;i< N; i++)
        vec3.push_back(test(0+i, 0.0+i, "new constructor"));
    vec3.push_back(test());
    for(int i = 0; i < N+1; i++){
        std::cout << vec3.at(i) <<"\n";
    }

    std::cout << vec3.size() <<" " <<  vec3.capacity() << " " << sizeof(test) <<"\n";
    //vec2.pop_back();
    std::cout << vec3.size() <<" " <<  vec3.capacity() << " " << sizeof(test) <<"\n";
    for(int i = 0; i < N; i++){
        std::cout << vec3.at(i) <<"\n";
    }
    std::cout << "vec 4 ______________________________________\n";
    SimpleVector<test, TrackingAllocator<test>> vec4(vec3.begin(), vec3.lastElem());
    for(int i =0;i< N; i++)
        vec4.push_back(test(0+i, 0.0+i, "ITERATED"));
    vec4.push_back(test());
    for(int i = 0; i < N+1; i++){
        std::cout << vec4.at(i) <<"\n";
    }

    std::cout << vec4.size() <<" " <<  vec4.capacity() << " " << sizeof(test) <<"\n";
    //vec4.pop_back();
    std::cout << vec4.size() <<" " <<  vec4.capacity() << " " << sizeof(test) <<"\n";
    for(int i = 0; i < N; i++){
        std::cout << vec4.at(i) <<"\n";
    }
    std::cout << "vec 5 ______________________________________\n";
    SimpleVector<test, TrackingAllocator<test>> vec5(N, test(22, 24, "letters"));
    for(int i =0;i< N; i++)
        vec5.push_back(test(0+i, 0.0+i, "test747"));
    vec5.push_back(test());
    for(int i = 0; i < N+1; i++){
        std::cout << vec5.at(i) <<"\n";
    }

    std::cout << vec5.size() <<" " <<  vec5.capacity() << " " << sizeof(test) <<"\n";
    //vec2.pop_back();
    std::cout << vec5.size() <<" " <<  vec5.capacity() << " " << sizeof(test) <<"\n";
    for(int i = 0; i < N; i++){
        std::cout << vec5.at(i) <<"\n";
    }
    return 0;
}
