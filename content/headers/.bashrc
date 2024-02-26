c() {
	g++ -std=c++20 -Wall -Wno-sign-conversion -Wextra -Wshadow -Wconversion -Wfloat-equal \
	-fsanitize=address,undefined -DLOCAL -DDEBUG -D_GLIBCXX_DEBUG -ggdb3 $1.cpp -o $1
}

nc() {
	g++ -std=c++20 -DLOCAL -O3 -static $1.cpp -o $1
}

alias cp='cp -i'
alias mv='mv -i'
