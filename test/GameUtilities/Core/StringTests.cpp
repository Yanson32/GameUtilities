#include <catch2/catch_test_macros.hpp>
#include <GameUtilities/Core/String.h>
#include <iostream>
#include <string>

TEST_CASE( "String class default constructor", "[String::DefaultConstructor]" ) 
{
    GU::Core::String test1;
    REQUIRE(test1 == GU::Core::String(""));
}

TEST_CASE( "String class std::string constructor", "[String::std::stringConstructor]" )
{
    const char *s = "Hello";
    std::string stdstring(s);
    GU::Core::String test1(stdstring);
    REQUIRE( test1 == s);
}

TEST_CASE( "String class single argument constructor", "[String::SingleConstructor]" ) 
{
    GU::Core::String test1("Hello");
    REQUIRE( test1 == "Hello");
}


TEST_CASE( "String class copy constructor", "[String::Copy]" ) 
{
    GU::Core::String test1("Hello");
    GU::Core::String test2 = test1;
    REQUIRE( test1.compare(GU::Core::String("Hello")) == 0);
}

TEST_CASE( "String class cast to char pointer", "[String::CharPointerCast]" ) 
{
    GU::Core::String s = "Hello";
    GU::Core::String test1(s);
    REQUIRE( static_cast<const char*>(test1) == s);
}

TEST_CASE( "String class assignment operator", "[String::AssignmentOperator]" ) 
{
    GU::Core::String test1("Hello");
    test1 = "World";
    REQUIRE( test1 == "World");

    GU::Core::String test2("Hello");
    GU::Core::String s2("World");
    test2 = s2;
    REQUIRE( test2 == "World");

    GU::Core::String test3("Hello");
    std::string s3("World");
    test3 = s3; 
    REQUIRE( test3 == "World");
}

TEST_CASE( "String class equality operator", "[String::Equality]" ) 
{
    GU::Core::String test1("Hello");
    GU::Core::String test2("Hello");
    REQUIRE( test1  == test2);

    const char* test3 = "Hello";
    REQUIRE(test1 == test3);

}

TEST_CASE( "String class less than or equal to", "[String::LessThanOrEqualTo]" ) 
{
    GU::Core::String test1("Hello");
    GU::Core::String test2("Hello");
    REQUIRE(test1 <= test2);
    
    GU::Core::String test3("a");
    GU::Core::String test4("b");
    REQUIRE(test3 <= test4);
    
    GU::Core::String test5("A");
    GU::Core::String test6("a");
    REQUIRE(test5 <= test6);
}

TEST_CASE( "String class greater than or equal to", "[String::GreaterThanOrEqualTo]" ) 
{
    GU::Core::String test1("Hello");
    GU::Core::String test2("Hello");
    REQUIRE(test1 >= test2);
    
    GU::Core::String test3("a");
    GU::Core::String test4("b");
    REQUIRE(test4 >= test3);
    
    GU::Core::String test5("A");
    GU::Core::String test6("a");
    REQUIRE(test6 >= test5);
}


TEST_CASE( "String class not equal operator", "[String::Unequal]" ) 
{
    GU::Core::String test1("Hello");
    GU::Core::String test2("World");
    
    REQUIRE( test1  != GU::Core::String("World"));
    REQUIRE( test1  != test2);

    const char* const test3 = "World";
    REQUIRE( test1  != test3);
}

TEST_CASE( "String class addition operator", "[String::Addition]" ) 
{
    GU::Core::String test1("Hello ");
    GU::Core::String test2("World");
    std::string test3("World");  
    REQUIRE( test1 +  test2 == "Hello World");
    REQUIRE( test1 +  "World" == "Hello World");
    REQUIRE( test1 +  test3 == "Hello World");

}

TEST_CASE( "String class plus equals operator", "[String::PlusEquals]" ) 
{
    GU::Core::String test1("Hello ");
    GU::Core::String test2("World");
    test1 += test2;   
    REQUIRE( test1 == "Hello World");
    
    GU::Core::String test3("Hello ");
    test3 += "World";   
    REQUIRE( test3 == "Hello World");

    GU::Core::String test4("Hello ");
    std::string test5("World");
    test4 += test5;   
    REQUIRE( test4 == "Hello World");
}

TEST_CASE( "String class size method", "[String::Size]" ) 
{
    GU::Core::String test1("Hello");
    REQUIRE( test1.size() == 5);

    test1 += " World";
    REQUIRE( test1.size() == 11);

    GU::Core::String test2("Hello ");
    std::string test3("World");
    test2 += test3;
    REQUIRE( test1.size() == 11);
            
}

TEST_CASE( "String class begin method", "[String::Begin]" ) 
{
    GU::Core::String test1("Hello");
    REQUIRE( (*test1.begin()) == test1[0]);
    
    GU::Core::String test2("Hello");
    test2 += " World";
    REQUIRE( (*test2.begin()) == test2[0]);
    
    GU::Core::String test3("Hello");
    test3 += std::string(" World");
    REQUIRE( (*test3.begin()) == test3[0]);
}

TEST_CASE( "String class reverse begin method", "[String::ReverseBegin]" ) 
{
    GU::Core::String test1("Hello");
    REQUIRE( (*test1.rbegin()) == test1[4]);
    
    GU::Core::String test2("Hello");
    test2 += " World";
    REQUIRE( (*test2.rbegin()) == test2[10]);
    
    GU::Core::String test3("Hello");
    test3 += std::string(" World");
    REQUIRE( (*test3.rbegin()) == test3[10]);
}

TEST_CASE( "String class end method", "[String::End]" ) 
{
    GU::Core::String test1("Hello");
    REQUIRE( (*test1.end()) == test1[5]);
    
    GU::Core::String test2("Hello");
    test2 += " World";
    REQUIRE( (*test2.end()) == test2[11]);
    
    GU::Core::String test3("Hello");
    test3 += std::string(" World");
    REQUIRE( (*test3.end()) == test3[11]);
}

TEST_CASE( "String class reverse end method", "[String::ReverseEnd]" ) 
{
    GU::Core::String test1("Hello");
    REQUIRE( (*test1.rend()) == test1[GU::Core::String::npos]);
    REQUIRE( (*test1.rend()) == test1[0 - 1]);
    
    GU::Core::String test2("Hello");
    test2 += " World";
    REQUIRE( (*test2.rend()) == test2[GU::Core::String::npos]);
    
    GU::Core::String test3("Hello");
    test3 += std::string(" World");
    REQUIRE( (*test3.rend()) == test3[GU::Core::String::npos]);
}

TEST_CASE( "String class length method", "[String::Length]" ) 
{
    GU::Core::String test1("Hello");
    REQUIRE( test1.length() == 5);
    
    GU::Core::String test2("Hello");
    test2 += " World";
    REQUIRE( test2.length() == 11);
    
    GU::Core::String test3("Hello");
    test3 += std::string(" World");
    REQUIRE(test3.length() == 11);
}

TEST_CASE( "String class clear method", "[String::Clear]" ) 
{
    GU::Core::String test1("Hello");
    test1.clear();
    REQUIRE( test1.length() == 0);
    REQUIRE( test1.size() == 0);
}

TEST_CASE( "String class empty method", "[String::Empty]" ) 
{
    GU::Core::String test1;
    REQUIRE( test1.empty());
}

TEST_CASE( "String class resize method", "[String::Resize]" ) 
{
    GU::Core::String test1;
    test1.resize(10);
    REQUIRE( test1.size() == 10);
    REQUIRE( test1.length() == 10);

    GU::Core::String test2;
    test2.resize(10, 'a');
    REQUIRE( test2.size() == 10);
    REQUIRE( test2.length() == 10);
    REQUIRE( test2 == "aaaaaaaaaa");
}

TEST_CASE( "String class capacity method", "[String::Capacity]" ) 
{
    GU::Core::String test1;
    test1.reserve(50);
    REQUIRE( test1.capacity() == 50);
}

TEST_CASE( "String class subscript operator", "[String::Subscript]" ) 
{
    GU::Core::String test1("Hello World");
    REQUIRE(test1[0] == 'H');
    REQUIRE(test1[4] == 'o');
    REQUIRE(test1[10] == 'd');
    REQUIRE_NOTHROW(test1[100]);
    
    GU::Core::String test2("Hello World");
    REQUIRE(test2[0] == 'H');
    REQUIRE(test2[4] == 'o');
    REQUIRE(test2[10] == 'd');
    REQUIRE_NOTHROW(test2[100]);
}

TEST_CASE( "String class at operator", "[String::at]" ) 
{
    GU::Core::String test1("Hello World");
    REQUIRE(test1.at(0) == 'H');
    REQUIRE(test1.at(4) == 'o');
    REQUIRE(test1.at(10) == 'd');
    REQUIRE_THROWS_AS(test1.at(100), std::out_of_range);

    const GU::Core::String test2("Hello World");
    REQUIRE(test2.at(0) == 'H');
    REQUIRE(test2.at(4) == 'o');
    REQUIRE(test2.at(10) == 'd');
    REQUIRE_THROWS_AS(test2.at(100), std::out_of_range);
    
}

TEST_CASE( "String class c_str method", "[String::c_str]" ) 
{
    GU::Core::String test1("Hello");
    REQUIRE( test1.c_str() == static_cast<const char*>(test1));
    
}

TEST_CASE( "String class toStdString method", "[String::toStdString]" ) 
{
    GU::Core::String test1("Hello");
    std::string test2 = test1.toStdString(); 
    REQUIRE( test2 == "Hello");
}

TEST_CASE( "String class back method", "[String::back]" ) 
{
    GU::Core::String test1("Hello");
    REQUIRE( test1.back() == 'o');

    const GU::Core::String test2("Hello");
    REQUIRE( test2.back() == 'o');
}

TEST_CASE( "String class front method", "[String::front]" ) 
{
    GU::Core::String test1("Hello");
    REQUIRE( test1.front() == 'H');

    const GU::Core::String test2("Hello");
    REQUIRE( test2.front() == 'H');
}

TEST_CASE( "String class front append", "[String::append]" ) 
{
    //Append 
    GU::Core::String test1("Hello");
    GU::Core::String world(" World");
    test1.append(world);
    REQUIRE(test1 == "Hello World");
    REQUIRE(test1.size() == 11);

    //Append substring char
    GU::Core::String test2("Hello");
    test2.append("Hello World", 5, 6);
    REQUIRE(test2 == "Hello World");
    REQUIRE(test2.size() == 11);

 
    GU::Core::String test3("Hello");
    test3.append("Hello World", 5, GU::Core::String::npos);
    REQUIRE(test3 == "Hello World");
    REQUIRE(test3.size() == 11);

    GU::Core::String test4("Hello");
    test4.append(" World");
    REQUIRE(test4 == "Hello World");
    REQUIRE(test4.size() == 11);

    GU::Core::String test5("Hello");
    test5.append(" World Hello World Hello World", 6);
    REQUIRE(test5 == "Hello World");
    REQUIRE(test5.size() == 11);

    GU::Core::String test6("Hello");
    test6.append(5, 'W');
    REQUIRE(test6 == "HelloWWWWW");
    REQUIRE(test6.size() == 10);
   
    //Append range 
    GU::Core::String test7("Hello");
    GU::Core::String test8(" World");
    //test7.append(test8.begin(), test8.end());
    REQUIRE(test7 == "Hello World");
    REQUIRE(test7.size() == 11);
    
    //Append initializer list 
    GU::Core::String test9("Hello");
    test9.append({' ', 'W', 'o', 'r', 'l', 'd'});
    REQUIRE(test9 == "Hello World");
    REQUIRE(test9.size() == 11);
}

TEST_CASE( "String class push_back", "[String::push_back]" ) 
{
    GU::Core::String test;
    test.push_back('H');
    test.push_back('e');
    test.push_back('l');
    test.push_back('l');
    test.push_back('o');
    REQUIRE(test.size() == 5);
    REQUIRE(test == "Hello");
}

TEST_CASE( "String class assign", "[String::assign]" ) 
{
    GU::Core::String test("Hello");
    GU::Core::String test2("World");
    test.assign(test2);
    REQUIRE(test == "World");
    REQUIRE(test2 == "World");

    //Copy substring
    GU::Core::String test3("Hello");
    test3.assign(test2, 0, 4);
    REQUIRE(test3 == "Worl");

    //Copy const char*
    GU::Core::String test4("Hello");
    const char* test4p = "Hello World";
    test4.assign(test4p);
    REQUIRE(test4 == "Hello World");
    
    //Copy substring of const char*
    GU::Core::String test5("Hello");
    const char* test5p = "Hello World";
    test5.assign(test5p, 6, 5);
    REQUIRE(test5 == "World");

    //Fill 
    GU::Core::String test6("Hello");
    test6.assign(2, 'R');
    REQUIRE(test6 == "RR");

    //Range
    GU::Core::String test7("Hello");
    GU::Core::String test7p("World");
    //test7.assign(test7p.begin(), test7p.end() - 1);
    REQUIRE(test7 == "World");

    //Initializer list
    GU::Core::String test8("Hello");
    test8.assign({'W', 'o', 'r', 'l', 'd'}); 
    REQUIRE(test8 == "World");


}

TEST_CASE( "String class reserve", "[String::reserve]" ) 
{
    GU::Core::String test;
    test.reserve(100);
    REQUIRE(test.capacity() == 100);
}

TEST_CASE( "String class erase method", "[String::erase]" ) 
{
    //Sequence 
    GU::Core::String test("123456");
    test.erase(0, 1);
    REQUIRE(test.compare("23456") == 0);


    //Character
    GU::Core::String test2("123456");
    test2.erase(test2.begin() + 3);
    REQUIRE(test2 == "12356");
   
    //Range 
    GU::Core::String test3("123456");
    test3.erase(test3.begin(), test3.begin() + 2); 
    REQUIRE(test3 == "3456");
}

TEST_CASE( "String class replace method ", "[String::replace]" ) 
{
    //Replace a substring
    GU::Core::String test("123456");
    test.replace(1, 4, GU::Core::String("987"));
    REQUIRE(test == "19876");
    REQUIRE_THROWS_AS(test.replace(20, 4, GU::Core::String("987")), std::out_of_range);
    

    //Replace a substring pointed to by iterators
    GU::Core::String test2("123456");
    test2.replace(test2.begin(), test2.begin() + 3, GU::Core::String("987"));
    REQUIRE(test2 == "987456");


    //Replace substring with substring
    GU::Core::String test3("123456");
    test3.replace(2, 2, "987654321", 0, 2);
    REQUIRE(test3 == GU::Core::String("129856"));
    REQUIRE_THROWS_AS(test3.replace(2, 2, "987654321", 0, 2), std::out_of_range);
    

    //Replace a substring 
    GU::Core::String test4("123456");
    test4.replace(1, 4, "987");
    REQUIRE(test4 == "19876");
    
    
    //Replace a substring pointed to by iterators with const char*
    GU::Core::String test5("123456");
    test5.replace(test5.begin(), test5.begin() + 3, "987");
    REQUIRE(test5 == "987456");


    //Replace a substring with the first characters of a const char*
    GU::Core::String test6("123456");
    test6.replace(1, 3, "987", 2);
    REQUIRE(test6 == "19856");
   
 
    //Replace a substring pointed to  by iterators with the first characters of a const char*
    GU::Core::String test7("123456");
    test7.replace(test7.begin() + 1, test7.begin() + 4, "987", 2);
    REQUIRE(test7 == "19856");
    

    //Replace a substring with fill characters
    GU::Core::String test8("123456");
    test8.replace(3, 3, 3, 'c');
    REQUIRE(test8 == "123ccc");
   
 
    //Replace a substring pointed to by iterators with fill characters
    GU::Core::String test9("123456");
    test9.replace(test9.begin() + 3, test9.begin() + 6, 3, 'c');
    REQUIRE(test9 == "123ccc");
   
 
    GU::Core::String test10("123456");
    GU::Core::String test11("987");
    //test10.replace(test10.begin(), test10.end(), test11.begin(), test11.end());
    REQUIRE(test10 == "987");
    

    //Replace a substring pointed to by iterators with initializer list 
    GU::Core::String test12("123456");
    test12.replace(test12.begin() + 3, test12.begin() + 6, {'9', '8', '7'});
    REQUIRE(test12 == "123987");
}


TEST_CASE( "String class swap", "[String::Swap]" ) 
{
    GU::Core::String test("123456");
    std::string test2("ABCDEFG");
    test.swap(test2);
    REQUIRE(test == "ABCDEFG");
    REQUIRE(test2 == "123456");
    
    GU::Core::String test3("123456");
    GU::Core::String test4("ABCDEFG");
    test3.swap(test4);
    REQUIRE(test3 == "ABCDEFG");
    REQUIRE(test4 == "123456");
}

TEST_CASE( "String class pop back", "[String::pop_back]" ) 
{
    GU::Core::String test("123456");
    test.pop_back();
    REQUIRE(test == "12345");
    
}

TEST_CASE( "String class data", "[String::data]" ) 
{
    GU::Core::String test("123456");
    REQUIRE(test.data() == test.c_str()); 
    
}


TEST_CASE( "String class foreach loop", "[String::Foreach]" ) 
{
    GU::Core::String test("123456");

    int count = 1;

    for(auto &element: test)
    {
        REQUIRE(element == static_cast<char>(count + '0'));

        count += 1;
    }
    

    const GU::Core::String test2("123456");

    count = 1;

    for(auto &element: test2)
    {
        REQUIRE(element == static_cast<char>(count + '0'));

        count += 1;
    }
}

TEST_CASE( "String class loop with iterators", "[String::IteratorLoop]" ) 
{
    GU::Core::String test("123456");

    int count = 1;

    for(auto it = test.begin(); it != test.end(); ++it) 
    {
        REQUIRE((*it) == static_cast<char>(count + '0'));

        count += 1;
    }
    

    const GU::Core::String test2("123456");

    count = 1;

    for(auto it = test2.begin(); it != test2.end(); ++it) 
    {
        REQUIRE((*it) == static_cast<char>(count + '0'));

        count += 1;
    }
    
    const GU::Core::String test3("123456");

    count = 1;

    for(auto it = test3.begin(); it != test3.end(); ++it) 
    {
        REQUIRE((*it) == static_cast<char>(count + '0'));

        count += 1;
    }
}

TEST_CASE( "String class reverse fol loop", "[String::ReverseForeach]" ) 
{
    GU::Core::String test("123456");

    int count = 6;

    for(auto it = test.rbegin(); it != test.rend(); ++it)
    {
        REQUIRE(static_cast<char>(*it) == static_cast<char>(count + '0'));
        count -= 1;

    }
    
    count = 6;

    const GU::Core::String test2("123456");

    for(auto it = test2.rbegin(); it != test2.rend(); ++it)
    {
        REQUIRE(static_cast<char>(*it) == static_cast<char>(count + '0'));
        count -= 1;

    }
    
    count = 6;

    const GU::Core::String test3("123456");

    for(auto it = test3.crbegin(); it != test3.crend(); ++it)
    {
        REQUIRE(static_cast<char>(*it) == static_cast<char>(count + '0'));
        count -= 1;

    }
}

