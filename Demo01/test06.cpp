#include <iostream>
using namespace std;

namespace test06
{
    struct vec2
    {
        union
        {
            struct { double x, y; };
            struct { double r, g; };
        };

        vec2(double x = 0.0, double y = 0.0) :x(x), y(y) {}
    };

    template<int index1, int index2>
    struct swizzle2d
    {
        swizzle2d& operator=(const vec2& v2)
        {
            static_assert(index1 != index2, "index1 != index2");
            elem(index1) = v2.x;
            elem(index2) = v2.y;
            return *this;
        }

        operator vec2()
        {
            vec2 v2;
            v2.x = elem(index1);
            v2.y = elem(index2);
            return v2;
        }

    protected:
        double elem(int i)const
        {
            return *(((double*)this) + i);
        }

        double& elem(int i)
        {
            return *(((double*)this) + i);
        }
    };

    struct vec3
    {
        union
        {
            struct { double x, y, z; };
            struct { double r, g, b; };
            swizzle2d<0, 0> xx;
            swizzle2d<0, 1> xy;
            swizzle2d<0, 2> xz;
            swizzle2d<1, 0> yx;
            swizzle2d<1, 1> yy;
            swizzle2d<1, 2> yz;
            swizzle2d<2, 0> zx;
            swizzle2d<2, 1> zy;
            swizzle2d<2, 2> zz;
        };
        vec3(double x = 0.0, double y = 0.0, double z = 0.0) :x(x), y(y), z(z) {}
    };

    ostream& operator<<(ostream& out, const vec2& v2)
    {
        return out << "(" << v2.x << "," << v2.y << ")";
    }

    ostream& operator<<(ostream& out, const vec3& v3)
    {
        return out << "(" << v3.x << "," << v3.y << "," << v3.z << ")";
    }

    void dotest()
    {
        vec2 v2(10, 20);
        vec3 v3(500, 500, 500);
        v3.x = v3.y = v3.z = 500;
        v3.xz = v2;
        cout << v3 << endl;
    }
}