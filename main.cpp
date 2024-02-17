#include <iostream>
#include <iomanip>

using std::cout, std::cin, std::endl, std::abs, std::setprecision;

// constexpr - C++ 11
constexpr double EPS = 1E-7;

double getSum(const double x) {
    double sum = 1.0;
    double term = x;

    int i = 1;
    while (abs(term) >= EPS) {
        const double newConstant = 1 / static_cast<double>(i + 1);
        term *= x * newConstant;
        sum += term;
        i++;
    }
    return sum;
}

int main() {
    double x;
    cout << "Введите x: ";
    cin >> x;
    while (cin.fail()) {
        cout << "Вы ввели некорректное значение! Попробуйте снова!\n";
        cin.clear();
        cin.sync();
        cout << "Введите x:";
        cin >> x;
    }
    const auto result = getSum(x);
    cout << "Сумма искомого выражения: " << setprecision(9) << result << endl;
    system("pause");
    return 0;
}
