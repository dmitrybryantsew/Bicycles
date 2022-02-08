//
// Created by dmitr on 12/7/2021.
//

#ifndef BICYCLES_TESTSTRUCT_HPP
#define BICYCLES_TESTSTRUCT_HPP
struct test{
    int _field1;
    float _field2;
    char* _field3;
    test(){
        std::cout << "struct default constructor called. size of " << sizeof(test) << "\n";
        _field1 = 1;
        _field2 =2.0;
        _field3 = "working";
    }
    ~test(){std::cout << "struct delete is called " << *this;}
    test(int field1, float field2, char* field3 ):_field1(field1), _field2(field2), _field3(field3) {std::cout << "struct constructor called. size of " << sizeof(test) << "\n";}
    //test(int field1, float field2, std::string field3 ):_field1(field1), _field2(field2), _field3(
            //)) {std::cout << "struct constructor called. size of " << sizeof(test) << "\n";}

    inline bool operator==(int other){
        return _field1 > other;
    }
    friend std::ostream & operator << (std::ostream &os, test & t){
        std::cout  << t._field1 << t._field2 << t._field3 << "\n";
        return os;
    }

};
#endif //BICYCLES_TESTSTRUCT_HPP
