#ifndef MATRIX_4x4_H
#define MATRIX_4x4_H

class Mat4x4{
    public:
        float matVals[16];

        Mat4x4();
        Mat4x4(const float& value);
        Mat4x4(const float newMatVals[16]);
        Mat4x4(const Mat4x4& srcMat);
        virtual ~Mat4x4();

        float operator()(const int& row, const int& col) const;
        float& operator()(const int& row, const int& col);
        friend Mat4x4 operator*(const Mat4x4& LHS, const Mat4x4& RHS);
        friend Mat4x4 operator*(const float& scalarAmp, const Mat4x4& RHS);
        friend Mat4x4 operator+(const Mat4x4& LHS, const Mat4x4& RHS); 


};

#endif
