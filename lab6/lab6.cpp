#include <iostream>
#include <vector>
#include <cassert>
#include "Tests.h"


using namespace std;


int main() {
	cout << "min_t()\n";


	int a = Tests::min_t<int>(5, 7);
	int b = Tests::min_t<int>(-10, -3);
	int c = Tests::min_t<int>(-2, 4);
	char d = Tests::min_t<char>('b', 'a');


	assert(a == 5);
	assert(b == -10);
	assert(c == -2);
	assert(d == 'a');


	cout << "min_t(5, 7) = " << a << endl;
	cout << "min_t(-10, -3) = " << b << endl;
	cout << "min_t(-2, 4) = " << c << endl;
	cout << "min_t('b', 'a') = '" << d << "'" << endl;


	cout << "\nsort_t()\n";


	vector<int> arr1 = { 5, 2, -1, 7, 0 };
	vector<int> expected1 = { -1, 0, 2, 5, 7 };


	cout << "Before sorting: ";
	for (int x : arr1) cout << x << " ";
	cout << endl;


	Tests::sort_t(arr1);


	cout << "After sorting: ";
	for (int x : arr1) cout << x << " ";
	cout << endl;


	for (size_t i = 0; i < arr1.size(); ++i) {
		assert(arr1[i] == expected1[i]);
	}


	cout << "\nsum_t()\n";


	vector<int> arr2 = { -5, 10, 0, -2, 3 };
	int sum_expected = 13;
	int sum_got = Tests::sum_t<int>(arr2);


	cout << "Array: ";
	for (int x : arr2) cout << x << " ";
	cout << "\nSum of positives = " << sum_got << endl;


	assert(sum_got == sum_expected);


	cout << "\nAll correct tests passed successfully.\n";
	return 0;
}