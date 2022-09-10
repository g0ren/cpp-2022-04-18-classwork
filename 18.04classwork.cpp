#include <iostream>

template<class T>
void print(T *m, int size) {
	for (int i { 0 }; i < size; i++)
		std::cout << m[i] << " ";
	std::cout << std::endl;
}

template<>
void print(char *m, int size) {
	for (int i { 0 }; i < size; i++)
		std::cout << m[i];
	std::cout << std::endl;
}

template<class T>
auto getSum(T *m, int size) {
	T sum = 0;
	for (int i { 0 }; i < size; i++)
		sum += m[i];
	return sum;
}

template<>
auto getSum<char>(char *m, int size) {
	int sum = 0;
	for (int i { 0 }; i < size; i++)
		sum += (int) m[i];
	return sum;
}

template<class T, int size>
class Array {
	T mass[10] { };

public:
	Array() {
		for (auto i { 0 }; i < size; i++)
			mass[i] = rand() % 101;
	}
	void print() const;

	auto sum() const {
		T sum = 0;
		for (T i { 0 }; i < size; i++)
			sum = sum + mass[i];
		return sum;
	}

	T get(int ind) const {
		if (ind >= 0 && ind < 10)
			return mass[ind];
		return 0;
	}

	T getMax();

	T getMin();

};

template<class T, int size>
void Array<T, size>::print() const {
	for (int i { 0 }; i < size; i++)
		std::cout << mass[i] << " ";
	std::cout << std::endl;

}

template<class T, int size>
T Array<T, size>::getMax() {
	T m = this->mass[0];
	for (int i = 1; i < 10; i++)
		if (this->mass[i] > m)
			m = this->mass[i];
	return m;
}

template<class T, int size>
T Array<T, size>::getMin() {
	T m = this->mass[0];
	for (int i = 1; i < 10; i++)
		if (this->mass[i] < m)
			m = this->mass[i];
	return m;
}

template<class T, int size, class T2, int size2>
bool operator==(const Array<T, size> &a1, const Array<T2, size2> &a2) {
	return a1.sum() == a2.sum();
}

template<class T, int size, class T2, int size2>
bool operator>(const Array<T, size> &a1, const Array<T2, size2> &a2) {
	return a1.sum() > a2.sum();
}

template<class T, int size, class T2, int size2>
bool operator<(const Array<T, size> &a1, const Array<T2, size2> &a2) {
	return a1.sum() < a2.sum();
}

template<class T, int size, class T2, int size2>
bool operator>=(const Array<T, size> &a1, const Array<T2, size2> &a2) {
	return a1.sum() >= a2.sum();
}

template<class T, int size, class T2, int size2>
bool operator<=(const Array<T, size> &a1, const Array<T2, size2> &a2) {
	return a1.sum() <= a2.sum();
}

int main() {
	//setlocale(LC_ALL, "Russian");
	srand(time(0));

	Array<int, 10> a;
	a.print();
	std::cout << a.getMax() << " " << a.getMin() << std::endl;
	Array<char, 25> a1;
	a1.print();

//	int mm[] = { 5, 1, 2, 3, 4, 5 };
//	int sum = getSum(mm,6);
//	print(mm, 6);
//	std::cout << "sum = " << sum << std::endl;
//
//
//	char ch[] = { 'n','b','x','z','a','e' };
//	print(ch, 6);
//	sum=getSum(ch, 6);
//	std::cout << "sum = " << sum << std::endl;

//system("pause");

	return 0;
}
