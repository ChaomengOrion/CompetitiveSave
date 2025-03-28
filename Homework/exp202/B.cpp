#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <numbers>

// Shape 基类
class Shape {
public:
    virtual double getArea() const = 0;
    virtual ~Shape() = default;
};

// 二维抽象类
class TwoDimensionalShape : public Shape { };

// 三维抽象类
class ThreeDimensionalShape : public Shape {
public:
    virtual double getVolume() const = 0;
};

class Circle : public TwoDimensionalShape {
private:
    double r;

public:
    Circle(double r) : r(r) { }

    double getArea() const override { 
        return std::numbers::pi * r * r; 
    }
};

class Square : public TwoDimensionalShape {
private:
    double w, h;

public:
    Square(double w, double h) : w(w), h(h) { }

    double getArea() const override { 
        return w * h; 
    }
};

class Triangle : public TwoDimensionalShape {
private:
    double d, h;

public:
    Triangle(double d, double h) : d(d), h(h) { }

    double getArea() const override {
        return d * h / 2.0;
    }
};

class Sphere : public ThreeDimensionalShape {
private:
    double r;

public:
    Sphere(double r) : r(r) { }

    double getArea() const override {
        return 4.0 * std::numbers::pi * r * r;
    }

    double getVolume() const override {
        return 4.0 / 3.0 * std::numbers::pi * r * r * r;
    }
};

class Cube : public ThreeDimensionalShape {
private:
    double l, w, h;

public:
    Cube(double l, double w, double h) : l(l), w(w), h(h) { }

    double getArea() const override {
        return 2. * (l * w + l * h + w * h);
    }

    double getVolume() const override {
        return w * h * l;
    }
};

class Tetrahedron : public ThreeDimensionalShape {
    private:
        double a;
    
    public:
        Tetrahedron(double a) : a(a) { }
    
        double getArea() const override {
            return std::numbers::sqrt3 * a * a;
        }
    
        double getVolume() const override {
            return std::numbers::sqrt2 / 12. * a * a * a;
        }
    };

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;

    shapes.push_back(std::make_unique<Circle>(1.0));
    shapes.push_back(std::make_unique<Square>(1.2, 3.3));
    shapes.push_back(std::make_unique<Triangle>(1.2, 3.3));
    shapes.push_back(std::make_unique<Sphere>(1.0));
    shapes.push_back(std::make_unique<Cube>(1.2, 3.3, 5.0));
    shapes.push_back(std::make_unique<Tetrahedron>(4.));

    for (int i = 0; i < (int)shapes.size(); i++) {
        std::cout << "\033[32mShapes [" << i << "]:\033[m\n";
        auto two = dynamic_cast<TwoDimensionalShape*>(shapes[i].get());
        if (two) {
            std::cout << "\033[33mTwoDimensionalShape:" << "\033[m" << "\n";
            std::cout << "Area:" << two->getArea() << '\n';
        } else {
            auto three = dynamic_cast<ThreeDimensionalShape*>(shapes[i].get());
            std::cout << "\033[33mThreeDimensionalShape:" << "\033[m" << "\n";
            std::cout << "Area:" << three->getArea() << '\n';
        }
    }
}