#pragma once

class Vector3B
{
public:
    double x;
    double y;
    double z;

public:
    Vector3B();
    Vector3B(double t_x, double t_y, double t_z);

    // Basic operators
    Vector3B operator +(Vector3B B) {
        Vector3B temp;
        temp.x = x + B.x;
        temp.y = y + B.y;
        temp.z = z + B.z;

        return temp;
    }

    Vector3B operator -(Vector3B B) {
        Vector3B temp;
        temp.x = x - B.x;
        temp.y = y - B.y;
        temp.z = z - B.z;

        return temp;
    }

    Vector3B operator *(Vector3B B) {
        Vector3B temp;
        temp.x = x * B.x;
        temp.y = y * B.y;
        temp.z = z * B.z;

        return temp;
    }

    Vector3B operator /(Vector3B B) {
        Vector3B temp;
        temp.x = x / B.x;
        temp.y = y / B.y;
        temp.z = z / B.z;

        return temp;
    }

    // Equals ones
    Vector3B operator +=(Vector3B B) {
        x += B.x;
        y += B.y;
        z += B.z;

        Vector3B temp(x, y, z);
        return temp;
    }

    Vector3B operator -=(Vector3B B) {
        x -= B.x;
        y -= B.y;
        z -= B.z;

        Vector3B temp(x, y, z);
        return temp;
    }

    Vector3B operator *=(Vector3B B) {
        x *= B.x;
        y *= B.y;
        z *= B.z;

        Vector3B temp(x, y, z);
        return temp;
    }

    Vector3B operator /=(Vector3B B) {
        x /= B.x;
        y /= B.y;
        z /= B.z;

        Vector3B temp(x, y, z);
        return temp;
    }

    // Returns
    double returnLength();
    void normalize();
};

