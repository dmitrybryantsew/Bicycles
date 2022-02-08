//
// Created by dmitr on 1/20/2022.
//

#include <gtest/gtest.h>
#include "trackingAllocator.hpp"
#include "simpleVector.hpp"
#include "testStruct.hpp"
#include "SPointer.hpp"
#include "stack.h"

//    std::vector<test, TrackingAllocator<test>> v;
//    v.reserve(4);
//    v.push_back({2, 2.f, "test"});
//    v.push_back({3, 23.f, "test1"});
//    v.push_back({4, 222.f, "test3"});
//    //UPointer<int> myInt(new int(201));
//    //UPointer<test> myStruct(new test(201, 3.4, "Nagga"));
//    //UPointer<test> otherStruct(std::move(myStruct));
//
//    //std::cout << *otherStruct;
//    /**SHARED PTR
//    SPointer<int> myInt;
//    SPointer<test> myStruct(new test(201, 3.4, "Nagga"));
//
//    auto another = myStruct;
//    auto third = another;
//    myFunc(myStruct);
//    auto myAnotherStruct(std::move(myStruct));
//    */

//    //std::cout << *myStruct.getRefcount() << *myStruct.getData() << std::endl;
//    //mySecondFunc();
//    //test s[11];
//    std::cout << "-------------------------------------\n";
//    auto end = std::remove(v.begin(), v.end(), 3);
//    for (auto e : v){
//        std::cout << "printing vec data: "<< e << " " << "\n";
//    }
//    std::cout <<"\n allocated objects:" << v.get_allocator().get_allocationCount() << "\n";
//    std::cout << "-------------------------------------\n";
//
//    Collection<int,11> test1;
//
//    std::fill(test2.begin(), test1.end(), 2);
//
//    std::transform(test2.begin(), test1.end(), test1.begin(), [](int i)
//    {
//        return i * i;
//    });
//
//    for(auto t : test2)
//        std::cout << t << std::endl;
//
//    Container2<int, TrackingAllocator<int>> c {5, 5};
//    std::cout << "allocations count on cont2: "<< c.m_alloc.get_allocationCount() << "\n";
//
//    auto te = AllocatorAwareStruct<int>(2, 3.f, "test");
//char* test2 = "imTestString";
//char* test3 = mygetstring();

//std::cout << "string :" << test2 << " adress :" << &test1 << "\n";
//std::cout << "string :" << test3 << " adress :" << &test2 << "\n";

//    SimpleVector<test > vec(3);
//    vec[0]._field3 = "imposter";
//    SimpleVector<int, TrackingAllocator<int>> vec2(3);
//    {
//        SimpleVector<std::string, TrackingAllocator<std::string>> vecs(10);
//        vecs[0] = "i am very fat string i wont fit on stack hahahahahahah";
//        std::cout << vecs.getAllocator().get_allocationCount();
//    }
//
//    vec2[0] = 200;
//    vec2[1] = 210;
//    std::for_each(vec2.begin(), vec2.end(),  [](int&a){ a+= 10;}); // FUCK
//    std::cout <<"\n" << vec2[0] << " " << vec2[1] << "\n";
//    std::vector<test> v;


void smartPointerTestFunc(const SPointer<test>& t){
    auto anotherT = t;
    auto another = anotherT;
    auto third = another;
}

void stackTest(){
    stack new_stack = NULL;
    push(&new_stack, 11);
    push(&new_stack, 229);
    push(&new_stack, 323);
    printf("stack address is %p\n", (void *)&new_stack);
    printf("top is %i\n", top(&new_stack));
    pop(&new_stack); // pop 323 -> 2 elements left
    printf("popping elements: %i %i %i\n", pop(&new_stack), pop(&new_stack), pop(&new_stack)); // забавно, что порядок вычисления аргументов обратный - пачиму?
    printf("________________________________________________\n");
    push(&new_stack, 12);
    printf("stack address is %p\n",  (void*)new_stack);
    push(&new_stack, 230);
    push(&new_stack, 324);
    delete_stack(&new_stack);
    printf("size of stack is %i,size of stack element is %i\n", sizeof(stack), sizeof(stack_element));
    printf("stack address is %p\n", new_stack);
    free(new_stack);
    new_stack = NULL;
    printf("stack address is %p\n", new_stack);
    printf("________________________________________________\n");
    for (int i = 2; i < 4; ++i)
    {
        push(&new_stack, i);
    }
    delete_stack(&new_stack);
}
TEST(testName, subtest_1){
    SimpleVector<test, TrackingAllocator<test>> vec2(3);
    vec2.push_back(test(11, 22.0, "impost"));
    vec2.push_back(test());
    ASSERT_TRUE(vec2[1]._field1 == 1);
}
TEST(testName, subtest_2){
    ASSERT_FALSE(1 == 2);
}

TEST(testName2, subtest_1){


    ASSERT_TRUE(1 == 1);
}
