#include <iostream>

class Shape
{
private:
    std::string idShape;
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    Shape(std::string _idShape = "Shape") : idShape{_idShape}
    {}

    std::string getId()
    {
        return idShape;
    }

    virtual ~Shape() = default;
};

class Rectangule : public Shape
{
private:
    double hight;
    double width;

public:
    Rectangule(const double& _hight = 5, const double& _width = 4, std::string _idShape = "прямоугольника ") :
        hight { _hight }, width{ _width }, Shape{ _idShape }
    {}

    double area() const override
    {
        return hight * width;
    }

    double perimeter() const override
    {
        return (hight + width) / 2;
    }
};

class Circle : public Shape
{
private:
    double radius;
public:
    Circle(const double& _radius = 7, std::string _idShape = "круга ") :
        radius{ _radius }, Shape{ _idShape }
    {}

    double area() const override
    {
        return 3.14 * radius * radius;
    }

    double perimeter() const override
    {
        return 2 * 3.14 * radius;
    }
};

void printShapeInfo(Shape* figure)
{
    std::cout << "Площадь" << figure->getId() << "равна: " << figure->area() << '\n';
    std::cout << "Периметр" << figure->getId() << "равен: " << figure->perimeter() << '\n';
}

int main()
{
    double hight;
    double width;
    double radius;
    std::cout << "Последовательно введите 3 значения: длины, ширины прямоугольника и радиуса круг \n";
    std::cin >> hight >> width >> radius;
    // В дальнейшем тут будет реализован обраотчик ошибок пользовательского ввода
    Shape* rectangule = new Rectangule{ hight, width};
    Shape* circle = new Circle{ radius};
    printShapeInfo(rectangule);
    printShapeInfo(circle);
    delete rectangule;
    delete circle;

    return 0;
}