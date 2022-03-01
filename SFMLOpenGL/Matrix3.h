#pragma once

class Matrix3B
{
public:
    double x1;
    double y1;
    double z1;
    double x2;
    double y2;
    double z2;
    double x3;
    double y3;
    double z3;

public:
    Matrix3B(double t_x1 = 0, double t_y1 = 0, double t_z1 = 0, double t_x2 = 0, double t_y2 = 0, double t_z2 = 0, double t_x3 = 0, double t_y3 = 0, double t_z3 = 0);

    Matrix3B operator +(Matrix3B t_m2)
    {
        x1 = x1 + t_m2.x1;
        y1 = y1 + t_m2.y1;
        z1 = z1 + t_m2.z1;
        x2 = x2 + t_m2.x2;
        y2 = y2 + t_m2.y2;
        z2 = z2 + t_m2.z2;
        x3 = x3 + t_m2.x3;
        y3 = y3 + t_m2.y3;
        z3 = z3 + t_m2.z3;

        Matrix3B that(x1, y1, z1, x2, y2, z2, x3, y3, z3);
        return that;
    }

    Matrix3B operator *(Matrix3B t_m2)
    {
        Matrix3B that;

        that.x1 = (x1 * t_m2.x1) + (y1 * t_m2.x2) + (z1 * t_m2.x3);
        that.y1 = (x1 * t_m2.y1) + (y1 * t_m2.y2) + (z1 * t_m2.y3);
        that.z1 = (x1 * t_m2.z1) + (y1 * t_m2.z2) + (z1 * t_m2.z3);
        that.x2 = (x2 * t_m2.x1) + (y2 * t_m2.x2) + (z2 * t_m2.x3);
        that.y2 = (x2 * t_m2.y1) + (y2 * t_m2.y2) + (z2 * t_m2.y3);
        that.z2 = (x2 * t_m2.z1) + (y2 * t_m2.z2) + (z2 * t_m2.z3);
        that.x3 = (x3 * t_m2.x1) + (y3 * t_m2.x2) + (z3 * t_m2.x3);
        that.y3 = (x3 * t_m2.y1) + (y3 * t_m2.y2) + (z3 * t_m2.y3);
        that.z3 = (x3 * t_m2.z1) + (y3 * t_m2.z2) + (z3 * t_m2.z3);

        return that;
    }
};

