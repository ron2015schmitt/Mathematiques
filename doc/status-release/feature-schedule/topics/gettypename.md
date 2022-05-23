# Refactor getTypeName

_Back to [Table of Contents](../README.md)_

1. perhaps use Pytrhon scripting to generate code
1. clearly document MACROS in User Guide. Mimimize use of macros
   1. recall macros take on the naemspace from where they are called!  Location of the definition is irrelevant.

From (https://dev.krzaq.cc/post/checking-whether-a-class-has-a-member-function-with-a-given-signature/)
```C++
template<typename T>
struct has_size_method
{
private:
	typedef std::true_type yes;
	typedef std::false_type no;
 
	template<typename U> static auto test(int) -> decltype(std::declval<U>().size() == 1, yes());
 
	template<typename> static no test(...);
 
public:
 
	static constexpr bool value = std::is_same<decltype(test<T>(0)),yes>::value;
};
```

See also (https://gist.github.com/fenbf/d2cd670704b82e2ce7fd) :
```C++
// SFINAE, enable_if example
// based on http://stackoverflow.com/questions/257288/is-it-possible-to-write-a-c-template-to-check-for-a-functions-existence


#include <iostream>
#include <type_traits>

class ClassWithToString
{
public:
    std::string ToString() { return "description of ClassWithToString object"; }
};

class ClassNoToString
{
public:
    int a;
};


// SFINAE test
template <typename T>
class HasToString
{
private:
    typedef char YesType[1];
    typedef char NoType[2];

    template <typename C> static YesType& test( decltype(&C::ToString) ) ;
    template <typename C> static NoType& test(...);


public:
    enum { value = sizeof(test<T>(0)) == sizeof(YesType) };
};

template<typename T> 
typename std::enable_if<HasToString<T>::value, std::string>::type
CallToString(T * t) {
   /* something when T has toString ... */
   return t->ToString();
}

/*
template<typename T> 
typename std::enable_if<std::is_class<T>::value, std::string>::type
CallToString(T * t) {
   return "a class without ToString() method!";
}
*/

std::string CallToString(...)
{
    return "undefined object, cannot call ToString() method here";
}


int main(int argc, char *argv[])
{
    std::cout << HasToString<ClassWithToString>::value << std::endl;
    std::cout << HasToString<ClassNoToString>::value << std::endl;
    std::cout << HasToString<int>::value << std::endl;
    
    ClassWithToString c1;
    std::cout << CallToString(&c1) << std::endl;
    
    ClassNoToString c2;
    std::cout << CallToString(&c2) << std::endl;
    
    int c3 = 0;
    std::cout << CallToString(&c3) << std::endl;
    
    return 0;
}
```

1. Look into creating a companion function that just takes a type as its input instead of needing an instance
