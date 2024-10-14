#include <iostream>

class Shape
{
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual ~Shape() = default;
};

class Rectangule : public Shape
{
private:
    double hight;
    double width;

public:
    Rectangule(double _hight = 5, double _width = 4) : hight{ _hight }, width{ _width }
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
    Circle(double _radius = 7) : radius { _radius }
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
    std::cout << figure->area() << '\n';
    std::cout << figure->perimeter() << '\n';
}

int main()
{
    Shape* rectangule = new Rectangule{};
    Shape* circle = new Circle{};
    printShapeInfo(rectangule);
    printShapeInfo(circle);
    delete rectangule;
    delete circle;

    return 0;
}