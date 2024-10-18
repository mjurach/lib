/**
 *	Opis: Potencjalnie szybszy alokator, jeżeli dopychamy kolanem, szczególnie działa gdy alokujemy dużo małych vectorów. 
 */

namespace 
{
	char buf[400'000'000];
	char *buf_ptr = buf;
}

template<typename T> struct my_allocator {
	using value_type = T;
	using size_type = size_t;

	T *allocate (size_type count) {
		if(count * sizeof(T) <= 4096) {
			T *result = (T *) buf_ptr;
			buf_ptr += count * sizeof(T);
			return result;
		} else {
			return new T[count];
		}
	}

	void deallocate(T *pointer, size_type count) {
		//delete[] pointer;
	}
};

vector<int, my_allocator<int>> v; //zamiast vector<int> v;
