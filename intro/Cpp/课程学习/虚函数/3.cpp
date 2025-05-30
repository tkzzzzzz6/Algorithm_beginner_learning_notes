
class Shape
{
public:
    // 纯虚函数
    virtual double getArea() = 0;
};

// 继承自抽象类Shape
class Rectangle : public Shape
{
public:
    double width;
    double height;
    double getArea() { return width * height; }
};

// 继承自抽象类Shape
class Circle : public Shape
{
public:
    double radius;
    double getArea() { return 3.14 * radius * radius; }
};