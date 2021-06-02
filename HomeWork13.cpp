#include <iostream>

class Vector
{
public:
    Vector(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    friend Vector operator+ (const Vector& a, const Vector& b);
    friend Vector operator- (const Vector& a, const Vector& b);
    friend Vector operator* (const Vector& a, const Vector& b);
    friend Vector operator* (const Vector& a, const float b);

    friend std::ostream& operator<<(std::ostream& out, const Vector& v);

    float operator[](int idx) {
        switch (idx) {
        case 0: return x; break;
        case 1: return y; break;
        case 2: return z; break;
        default: std::cout << "index error"; return 0;
        }
    }
private:
    float x, y, z;
};

Vector operator+ (const Vector& a, const Vector& b)
{
    return Vector(a.x + b.x, a.y + b.y, a.z + b.z);
}

Vector operator- (const Vector& a, const Vector& b)
{
    return Vector(a.x - b.x, a.y - b.y, a.z - b.z);
}

Vector operator* (const Vector& a, const Vector& b)
{
    return Vector(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x);
}

Vector operator* (const Vector& a, const float b)
{
    return Vector(a.x * b, a.y * b, a.z * b);
}

std::ostream& operator<<(std::ostream& out, const Vector& v)
{
    return out << ' ' << v.x << ' ' << v.y << ' ' << v.z;
}

int main()
{
    Vector v1(.2, .4, .2);
    Vector v2(.3, .5, .1);

    std::cout << v1 + v2 << '\n';
    std::cout << "Vector index: " << v1[1];
}

// Не все можно перезагрузить через дружественные функции. 
// Нельзя использовать перезагрузку с операторами индекса, присваивания и оператором вызова члена. 
// Это требование языка С++.

// 
// 