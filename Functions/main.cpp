#include <QCoreApplication>
#include <QDebug>
#include <stdexcept>

double add(double num1, double num2) {
    return num1 + num2;
}

double sub(double num1, double num2) {
    return num1 - num2;
}

double mul(double num1, double num2) {
    return num1 * num2;
}

double divide(double num1, double num2) {
    if (num2 != 0)
        return num1 / num2;
    throw std::invalid_argument("Division by zero");
}
int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    QDebug debug = qDebug();

    debug << add(2.5, 4.5) ;
    debug << sub(3.7, 1.2) ;
    debug << mul(4.0, 6.0) ;
    debug << divide(6.3, 1.5) ;

    return a.exec();
}

