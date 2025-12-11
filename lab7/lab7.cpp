#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdlib>


using namespace std;


int main() {
	setlocale(LC_ALL, "ukr");
	system("chcp 65001");

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << "Введіть кількість цілих чисел:\n";
	int N;
	if (!(cin >> N) || N < 0) return 0;
	vector<int> v(N);

	cout << "Введіть " << N << " цілих чисел:\n";
	for (int i = 0; i < N; ++i) cin >> v[i];

	sort(v.begin(), v.end(), [](int a, int b) {
		if (abs(a) != abs(b)) return abs(a) < abs(b);
		return a < b;
		});

	cout << "Відсортовані за модулем числа:\n";
	for (size_t i = 0; i < v.size(); ++i) {
		if (i) cout << ' ';
		cout << v[i];
	}
	cout << '\n';
	return 0;
}