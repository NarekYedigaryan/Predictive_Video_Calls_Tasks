#include <QCoreApplication>
#include <QDebug>

void print(int, float, double, char, bool);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    print(1, 4.5f, 3.14, 'a', true);
    return a.exec();
}

void print(int var1, float var2, double var3, char var4, bool var5)
{
    QDebug debug = qDebug();
    debug << var1 << " " << var2 << " " << var3 << " " << var4 << " " << var5;
}
