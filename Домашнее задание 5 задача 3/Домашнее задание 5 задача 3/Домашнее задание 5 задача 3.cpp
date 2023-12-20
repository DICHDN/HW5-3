/*
Задача 3. Фигуры. Методы
В этом задании вы добавите в вашу иерархию классов больше функциональности.

Теперь ваши фигуры должны уметь немного больше:

выводить информацию о себе;
проверять правильность своих данных.
Ваши фигуры:

фигура (количество сторон равно 0);
треугольник (стороны и углы произвольные, количество сторон равно 3, сумма углов равна 180);
прямоугольный треугольник (угол C всегда равен 90);
равнобедренный треугольник (стороны a и c равны, углы A и C равны);
равносторонний треугольник (все стороны равны, все углы равны 60);
четырёхугольник (стороны и углы произвольные, количество сторон равно 4, сумма углов равна 360);
прямоугольник (стороны a,c и b,d попарно равны, все углы равны 90);
квадрат (все стороны равны, все углы равны 90);
параллелограмм (стороны a,c и b,d попарно равны, углы A,C и B,D попарно равны);
ромб (все стороны равны, углы A,C и B,D попарно равны).
Вы должны иметь возможность попросить фигуру вывести информацию о себе на консоль, а также узнать, является ли фигура правильной, то есть выполняются ли условия, указанные в списке выше.

Информация о фигуре включает в себя:

название фигуры;
количество сторон;
длины её сторон, если есть;
величины её углов, если есть;
является ли фигура правильной.
Задача: спроектировать и реализовать классы, описывающие предметную область. Продемонструйте их работу: создайте по одному экземпляру каждой фигуры и выведите на экран информацию о фигурах.

Реализуйте методы вывода на консоль и проверки правильности фигуры с помощью виртуальных функций и переопределений. Используйте вызов базовой версии метода.

Ваша задача — работать с экземплярами дочерних классов полиморфно, то есть с помощью указателя на базовый класс.

Пример работы программы
Консоль
Фигура:
Правильная
Количество сторон: 0

Треугольник:
Правильная
Количество сторон: 3
Стороны: a=10 b=20 c=30
Углы: A=50 B=60 C=70

Прямоугольный треугольник:
Неправильная
Количество сторон: 3
Стороны: a=10 b=20 c=30
Углы: A=50 B=60 C=90

Прямоугольный треугольник:
Правильная
Количество сторон: 3
Стороны: a=10 b=20 c=30
Углы: A=50 B=40 C=90

Равнобедренный треугольник:
Неправильная
Количество сторон: 3
Стороны: a=10 b=20 c=10
Углы: A=50 B=60 C=50

Равносторонний треугольник:
Правильная
Количество сторон: 3
Стороны: a=30 b=30 c=30
Углы: A=60 B=60 C=60

Четырёхугольник:
Неправильная
Количество сторон: 4
Стороны: a=10 b=20 c=30 d=40
Углы: A=50 B=60 C=70 D=80

Прямоугольник:
Правильная
Количество сторон: 4
Стороны: a=10 b=20 c=10 d=20
Углы: A=90 B=90 C=90 D=90

Квадрат:
Правильная
Количество сторон: 4
Стороны: a=20 b=20 c=20 d=20
Углы: A=90 B=90 C=90 D=90

Параллелограмм:
Неправильная
Количество сторон: 4
Стороны: a=20 b=30 c=20 d=30
Углы: A=30 B=40 C=30 D=40

Ромб:
Неправильная
Количество сторон: 4
Стороны: a=30 b=30 c=30 d=30
Углы: A=30 B=40 C=30 D=40
*/




#include <iostream>
#include <windows.h>
#include <string>

class figura
{
protected:
    int field1;
    std::string name;
    

public:
    figura()
    {
        this->field1 = 0;
        this->name = "точка";
    }
    int get_sides_count()
    {
        return field1;
    }
    std::string get_name()
    {
        return name;
    }
    virtual std::string  get_pass()
    {
        if ((field1 == 0) && (name == "точка")) return "правильная";
        else return "Не правильная";
    }
    virtual void get_info()
    {
        std::cout << "Простая фигура с количеством сторн " << field1 << " - это " << name << std::endl;
        std::cout << "Фигура " << get_pass() ;
        std::cout << std::endl;
    }
     
};
class triangle : public figura
{
protected:
    int a = 10, b = 20, c = 30;
    int A = 30, B = 70, C = 80;
    
    
public:
    triangle()
    {
        this->field1 = 3;
        this->name = "треугольник";
    }
    virtual std::string  get_pass() override
    {
        if ((field1 == 3) && (A + B + C == 180)) return "правильная";
        else return "Не правильная";
    }
    void get_info() override
    {
        std::cout << "Простая фигура с количеством сторн " << field1 << " - это " << name << std::endl;
        std::cout << "Фигура " << get_pass();
        std::cout << std::endl;
        std::cout << "Стороны а=" << a << ", b=" << b << ", c=" << c << std::endl;
        std::cout << "Углы A=" << A << ", B=" << B << ", C=" << C << std::endl;
    }
};
class quadrilateral : public figura
{
protected:
    int a = 10, b = 20, c = 30, d = 40;
    int A = 30, B = 40, C = 50, D = 60;
   
    
public:
    quadrilateral()
    {
        this->field1 = 4;
        this->name = "четырехугольник";
    }
    virtual std::string  get_pass() override
    {
        if ((field1 == 4) && (A + B + C + D == 360)) return "правильная";
        else return "Не правильная";
    }
    void get_info() override
    {
        std::cout << "Простая фигура с количеством сторн " << field1 << " - это " << name << std::endl;
        std::cout << "Фигура " << get_pass();
        std::cout<< std::endl;
        std::cout << "Стороны а=" << a << ", b=" << b << ", c=" << c << ", d=" << d << std::endl;
        std::cout << "Углы A=" << A << ", B=" << B << ", C=" << C << ", D=" << D << std::endl;
    }
};
class triangle90 : public triangle
{
public:

    triangle90()
    {
        this->field1 = 3;
        this->name = "прямоугольный треугольник";
        this->C = 90;
    }
    virtual std::string  get_pass() override
    {
        if ((field1 == 3) && (A + B + C == 180))
            if (C == 90) return "правильная";
            else return "Не правильная";
        else return "Не правильная";
    }
};

class isosceles_triangle :public triangle
{
public:
    isosceles_triangle()
    {
        this->field1 = 3;
        this->name = "равнобедренный треугольник";
        this->c = a;
        this->C = A;
    }
    virtual std::string  get_pass() override
    {
        if ((field1 == 3) && (A + B + C == 180))
            if ((A == C) && (a == c)) return "правильная";
            else return "Не правильная";
        else return "Не правильная";
    }
};
class equilateral_triangle : public triangle
{
public:
    equilateral_triangle()
    {
        this->field1 = 3;
        this->name = "равносторонний треугольник";
        this->A = 60;
        this->c = a;
        this->b = a;
        this->C = A;
        this->B = A;
    }
    virtual std::string  get_pass() override
    {
        if ((field1 == 3) && (A + B + C == 180))
            if (((A==60) && (B==60) && (C == 60)) && ((a==b) && (b==c))) return "правильная";
            else return "Не правильная";
        else return "Не правильная";
    }
};

class rectangle : public quadrilateral
{
public:
    rectangle()
    {
        this->name = "прямоугольник";
        this->c = a;
        this->d = b;
        this->A = 90;
        this->B = A;
        this->C = A;
        this->D = A;
    }
    virtual std::string  get_pass() override
    {
        if ((field1 == 4) && (A + B + C + D == 360)) 
        {
            if (((a==c) && (b==d)) && (( A == 90) && (B==90) && (C==90) && (D==90)))
                return "правильная";
            else return "не правильная";
        }
        else return "не правильная";
    }
};
class square : public rectangle
{
public:
    square()
    {
        this->name = "квадрат";
        this->c = a;
        this->b = a;
        this->d = a;
        this->A = 90;
        this->B = A;
        this->C = A;
        this->D = A;
    }
    virtual std::string  get_pass() override
    {
        if ((field1 == 4) && (A + B + C + D == 360))
        {
            if (((a == c) && (b == d) && (c==d)) && ((A == 90) && (B == 90) && (C == 90) && (D == 90)))
                return "правильная";
            else return "не правильная";
        }
        else return "не правильная";
    }
};
class parallelogram : public quadrilateral
{
public:
    parallelogram()
    {
        this->name = "параллелограмм";
        this->c = a;
        this->d = b;
        this->C = A;
        this->D = B;
    }
    virtual std::string  get_pass() override
    {
        if ((field1 == 4) && (A + B + C + D == 360))
        {
            if (((a == c) && (b == d)) && ((A == C) && (B == D)))
                return "правильная";
            else return "не правильная";
        }
        else return "не правильная";
    }
};
class rhomb : public parallelogram
{
public:
    rhomb()
    {
        this->name = "ромб";
        this->c = a;
        this->b = a;
        this->d = b;
        this->C = A;
        this->D = B;
    }
    virtual std::string  get_pass() override
    {
        if ((field1 == 4) && (A + B + C + D == 360))
        {
            if (((a == c) && (b == d) && (c == d)) && ((A == C) && (B == D)))return "правильная";
            else return "не правильная";
        }
        else return "не правильная";
    }
};

void print_info(figura* a)
{
    a->get_info();
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    figura dot;
    triangle tri;
    quadrilateral quadro;
    triangle90 tri1;
    isosceles_triangle tri2;
    equilateral_triangle tri3;
    rectangle quadro1;
    square quadro2;
    parallelogram quadro3;
    rhomb quadro4;

    print_info(&dot);
    print_info(&tri);
    print_info(&tri1);
    print_info(&tri2);
    print_info(&tri3);
    print_info(&quadro);
    print_info(&quadro1);
    print_info(&quadro2);
    print_info(&quadro3);
    print_info(&quadro4);

    return 0;
}