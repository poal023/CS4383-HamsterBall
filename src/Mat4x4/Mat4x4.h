#ifndef MATRIX_4x4_H
#define MATRIX_4x4_H
#include <cassert>
#include <cmath>
#define PI 3.1415926535897

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
        friend Mat4x4 operator*(const Mat4x4& LHS, const float& scalarAmp);
        friend Mat4x4 operator+(const Mat4x4& LHS, const Mat4x4& RHS); 

        inline Mat4x4 transposeMat();
        inline Mat4x4 identityMat();
        //To do: Translate, Scale, Shear and Rotate Transforms (+ Perspective matricies, but this is what they are essentially)
        // + Inline F'ns for determinant and invert?
	    inline float determinant();
        inline Mat4x4 invertMat();
        
        inline Mat4x4 translateMat(float Tx, float Ty, float Tz);
        inline Mat4x4 rotMatX(float degrees);
        inline Mat4x4 rotMatY(float degrees);
        inline Mat4x4 rotMatZ(float degrees);

        inline Mat4x4 shearMat();
        inline Mat4x4 scaleMat(float Sx, float Sy, float Sz);
        
};


inline Mat4x4 Mat4x4::transposeMat(){
    Mat4x4 newMat = Mat4x4();
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            newMat(j,i) = matVals[4*i + j];
        }
    }

    return newMat;
}

inline Mat4x4 Mat4x4::identityMat(){
    float newMatVals[16] = {1,0,0,0,
                            0,1,0,0,
                            0,0,1,0,
                            0,0,0,1};
    Mat4x4 newMat(newMatVals);
    return newMat;

}
inline float Mat4x4::determinant(){
    return (matVals[0]*(matVals[5]*(matVals[10]*matVals[15] - matVals[11]*matVals[14]) - matVals[6]*(matVals[9]*matVals[15]-matVals[11]*matVals[13]) + matVals[7]*(matVals[9]*matVals[14]-matVals[10]*matVals[13]))
            - matVals[1]*(matVals[4]*(matVals[10]*matVals[15] - matVals[11]*matVals[14]) - matVals[6]*(matVals[8]*matVals[15] - matVals[11]*matVals[12]) + matVals[7]*(matVals[8]*matVals[14] - matVals[10]*matVals[12]))
            + matVals[2]*(matVals[4]*(matVals[9]*matVals[15] - matVals[11]*matVals[13]) - matVals[5]*(matVals[8]*matVals[15] - matVals[11]*matVals[12]) + matVals[7]*(matVals[8]*matVals[13] - matVals[9]*matVals[12]))
            - matVals[3]*(matVals[4]*(matVals[9]*matVals[14] - matVals[10]*matVals[13]) - matVals[5]*(matVals[14]*matVals[8] - matVals[10]*matVals[12]) + matVals[6]*(matVals[8] * matVals[13] - matVals[12] * matVals[9])));
}

inline Mat4x4 Mat4x4::invertMat(){
    assert(determinant() != 0);
    
    Mat4x4 result(matVals);
    Mat4x4 sqMat = result * result; 
    Mat4x4 cubeMat = sqMat * result;

    float traceA = matVals[0] + matVals[5] + matVals[10] + matVals[15];
    float traceA2 = sqMat.matVals[0] + sqMat.matVals[5] + sqMat.matVals[10] + sqMat.matVals[15];
    float traceA3 = cubeMat.matVals[0] + cubeMat.matVals[5] + cubeMat.matVals[10] + cubeMat.matVals[15];

    result = (1/6.0) * ((traceA * traceA * traceA) - 3*traceA2*traceA + 2*traceA3)*identityMat() + (-1/2.0)*(result)*(traceA * traceA - traceA2) + traceA * sqMat + (-1)*cubeMat;
    return (1.0 / determinant()) * result;
}


inline Mat4x4 Mat4x4::translateMat(float Tx, float Ty, float Tz) {
    Mat4x4 TMat = identityMat();
    
    TMat(0, 3) = Tx;
    TMat(1, 3) = Ty;
    TMat(2, 3) = Tz;


    return TMat;
}

inline Mat4x4 Mat4x4::rotMatX(float degrees) {
    float radians = degrees * (PI / 180.0f);
    Mat4x4 TMat = identityMat();

    TMat(1, 1) = cos(radians);
    TMat(2, 2) = cos(radians);
    TMat(2, 1) = sin(radians);
    TMat(1, 2) = -sin(radians);

    return TMat;

}
inline Mat4x4 Mat4x4::rotMatY(float degrees) {
    float radians = degrees * (PI / 180.0f);
    Mat4x4 TMat = identityMat();

    TMat(0, 0) = cos(radians);
    TMat(0, 2) = cos(radians);
    TMat(2, 1) = sin(radians);
    TMat(2, 0) = -sin(radians);

    return TMat;
}
inline Mat4x4 Mat4x4::rotMatZ(float degrees) {
    float radians = degrees * (PI / 180.0f);
    Mat4x4 TMat = identityMat();
    
    TMat(0, 0) = cos(radians);
    TMat(1, 1) = cos(radians);
    TMat(1, 0) = sin(radians);
    TMat(0, 1) = -sin(radians);
   
    return TMat;
}

inline Mat4x4 Mat4x4::scaleMat(float Sx, float Sy, float Sz) {

}


#endif
