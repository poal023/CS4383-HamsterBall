#ifndef VECTOR3_H
#define VECTOR3_H

class Vector3{
	public:
		float x;
		float y;
		float z;
		
		Vector3();
		Vector3(float xComp, float yComp, float zComp);
        Vector3(const Vector3& srcVec);
		virtual ~Vector3();
		friend Vector3& operator+(const Vector3& LHS, const Vector3& RHS); // Vector + Vector = Vector
		friend float& operator*(const Vector3& LHS, const Vector3& RHS);  // Dot product for two vectors
		friend Vector3& operator*(const float& scalarAmp, const Vector3& RHS); // Amplify the components of a vector by a scalar, s.t k<x,y,z> = <kx, ky, kz>
		friend Vector3& operator%(const Vector3& LHS, const Vector3& RHS);  // Cross Product for two vectors (assuming LHS x RHS = Resultant)

		float vecMagnitude(); // Calculate the magnitude of a Vector V, ||V||. where ||V|| = sqrt(x^2 + y^2 + z^2)
		Vector3 normalizedVec();
	
};


#endif
