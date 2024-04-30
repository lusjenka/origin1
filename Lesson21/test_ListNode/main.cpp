//подключаем макросы catch2
#include <iostream>
#include "List.h"
//#include <catch2/catch_test_macros.hpp>


/*//юнит-тест
TEST_CASE( "Empty check", "[Empty]" ) {
    REQUIRE( Empty( true) == 0 );
    //REQUIRE( Empty( false) == 0 );
   
}
//юнит-тест
TEST_CASE( "Size check", "[Size]" ) {
    m_size = 5;
    REQUIRE( Size() == 5 );
    //REQUIRE( Empty( false) == m_size );
   
}
//юнит-тест
TEST_CASE( "Clear check", "[Clear]" ) {
    m_size = 5;
    REQUIRE( Clear() == 5 );
    //REQUIRE( Empty( false) == m_size );
   
}*/

int main()
{
try {
    List L;
    L.PushFront(10);
    L.PushFront(20);
    L.PushBack(4);
    std::cout << "Size: " << L.Size();
    L.PopFront();
    std::cout << "\nSize: " << L.Size();
}
catch (const std::exception& ex) {
	std::cout << ex.what() << std::endl;
}
return 0;
}
