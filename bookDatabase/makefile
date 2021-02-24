
test: menu.o book.o dataBase.o
	g++ -o test menu.o book.o dataBase.o 

# only need to link if menu.cpp has changed
menu: menu.cpp
	g++ -c menu.cpp

# only compile if book.h or book.cpp has changed since last compile
book: book.h book.cpp
	g++ -c book.cpp

# only compile if dataBase.h or dataBase.cpp has changed since last compile
dataBase: dataBase.h dataBase.cpp
	g++ -c dataBase.cpp

clean:
	rm -f test menu.o book.o dataBase.o

# Set the C++ compiler options:
#   -std=c++14 compiles using the C++14 standard (or at least as 
#    much as is implemented by the compiler, e.g. for g++ see
#    http://gcc.gnu.org/projects/cxx0x.html)
#   -Wall turns on all warnings
#   -Wextra turns on even more warnings
#   -Werror causes warnings to be errors 
#   -Wfatal-errors stops the compiler after the first error
#   -Wno-sign-compare turns off warnings for comparing signed and 
#    unsigned numbers
#   -Wnon-virtual-dtor warns about non-virtual destructors
#   -g puts debugging info into the executables (makes them larger)
CPPFLAGS = -std=c++14 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g
