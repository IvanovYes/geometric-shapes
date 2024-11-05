#include <iostream>
#include <limits>

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

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void getInputData(double& outHight, double& outWidth, double& outRadius)
{
    while (true) // Loop until user enters a valid input
    {
        std::cout << "Последовательно введите 3 значения: длины, ширины прямоугольника и радиус круга \n";
        std::cin >> outHight >> outWidth >> outRadius;

        if (!std::cin and outHight < 0 and outWidth < 0 and outRadius < 0) // If the previous extraction failed
        {
            // Let's handle the failure
            std::cout << "Данные введены некорректно \n";
            std::cin.clear(); // Put us back in 'normal' operation mode
            ignoreLine();     // And remove the bad input
            continue;
        }

        // Our extraction succeeded
        ignoreLine(); // Ignore any additional input on this line
    }
}

int main()
{
    double hight;
    double width;
    double radius;
    getInputData(hight, width, radius);
    Shape* rectangule = new Rectangule{ hight, width};
    Shape* circle = new Circle{ radius};
    printShapeInfo(rectangule);
    printShapeInfo(circle);
    delete rectangule;
    delete circle;
    return 0;
}