#include <QCoreApplication>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QTextStream cout (stdout);
    QTextStream cin (stdin);

    int number;
    cout << "Enter a number from 0 to 100: \n";
    cout.flush();
    cin >> number;

    if(number < 0) {
        cout << "The number is negative" ;
    } else if (number > 0) {
        cout << "The number is positive" ;
    } else {
        cout << "The number is zero" ;
    }
    char grade;
       switch (number) {
           case 90 ... 100:
               grade = 'A';
               break;
           case 80 ... 89:
               grade = 'B';
               break;
           case 70 ... 79:
               grade = 'C';
               break;
           case 60 ... 69:
               grade = 'D';
               break;
           default:
               grade = 'F';
       }

    cout << "your grade: " << grade ;

    cout << "numbers from 1 to 10: ";
    for(int i = 1; i <= 10; ++i)
    {
        cout << i << " ";
    }


    return app.exec();
}
