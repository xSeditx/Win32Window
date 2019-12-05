#pragma once

#include<iostream>

constexpr double toDegrees(double _deg) {
	return _deg * (3.14159 / 180.0);
}
 
#ifndef Vec2

///====================================================================================================================================
///================ INCASE A VECTOR HAS NOT BEEN DEFINED ===============================================================================================
///====================================================================================================================================


template<typename _Ty>
struct vec2_point
{
	vec2_point(_Ty _x, _Ty _y)
		:
		x(_x), y(_y)
	{}

	_Ty x;
	_Ty y;

	vec2_point<_Ty> operator +(vec2_point<_Ty> _other) { return vec2_point<_Ty>(this->x + _other.x, this->y + _other.y); }
	vec2_point<_Ty> operator -(vec2_point<_Ty> _other) { return vec2_point<_Ty>(this->x - _other.x, this->y - _other.y); }
	vec2_point<_Ty> operator *(vec2_point<_Ty> _other) { return vec2_point<_Ty>(this->x * _other.x, this->y * _other.y); }
	vec2_point<_Ty> operator /(vec2_point<_Ty> _other) { return vec2_point<_Ty>(this->x / _other.x, this->y / _other.y); }

	// Operator Definitions
	vec2_point<_Ty>& operator +=(const vec2_point<_Ty>& _other) { return add(_other); }
	vec2_point<_Ty>& operator -=(const vec2_point<_Ty>& _other) { return subtract(_other); }
	vec2_point<_Ty>& operator *=(const vec2_point<_Ty>& _other) { return multiply(_other); }
	vec2_point<_Ty>& operator /=(const vec2_point<_Ty>& _other) { return divide(_other); }

	// Operating on Two Vectors 
	vec2_point<_Ty>& add(const vec2_point<_Ty>& other) {
		x += other.x; y += other.y;
		return *this;
	}
	vec2_point<_Ty>& subtract(const vec2_point<_Ty>& other) {
		x -= other.x; y -= other.y;
		return *this;
	}
	vec2_point<_Ty>& divide(const vec2_point<_Ty>& other) {
		x /= other.x; y /= other.y;
		return *this;
	}
	vec2_point<_Ty>& multiply(const vec2_point<_Ty>& other) {
		x *= other.x; y *= other.y;
		return *this;
	}

	// Operating on a Vector and a Single other Value
	vec2_point<_Ty>& add(_Ty other) {
		x += other; y += other;
		return *this;
	}
	vec2_point<_Ty>& subtract(_Ty other) {
		x -= other; y -= other;
		return *this;
	}
	vec2_point<_Ty>& divide(_Ty other) {
		x /= other; y /= other;
		return *this;
	}
	vec2_point<_Ty>& multiply(_Ty other) {
		x *= other; y *= other;
		return *this;
	}


	// Arithmatic
	_Ty Dot(vec2_point<_Ty> A)
	{
		return A.x * this.x + A.y * this.y;
	}

	_Ty Cross(vec2_point<_Ty> A)
	{
		return A.x * this.y - A.y * this.x;
	}

	_Ty g_Angle(vec2_point<_Ty> A)
	{
		// HACK Idk just fix this shit later
		return atan2f(this.y - A.y, this.x - A.x) / 3.14159 * 180;
	}

	vec2_point<_Ty> g_Displacement(vec2_point<_Ty> A) {
		return { A.x - this.x,  A.y - this.y };
	}


	static vec2_point<_Ty> g_Displacement(vec2_point<_Ty> A, vec2_point<_Ty> B) {
		return { A.x - B.x,  A.y - B.y };
	}

	static _Ty Dot(vec2_point<_Ty> A, vec2_point<_Ty> B)
	{
		return A.x * B.x + A.y * B.y;
	}

	static _Ty Cross(vec2_point<_Ty> A, vec2_point<_Ty> B)
	{
		return A.x * B.y - A.y * B.x;
	}

	static double g_Angle(vec2_point<_Ty> A, vec2_point<_Ty> B)
	{
		return atan2f(B.y - A.y, B.x - A.x) / 3.14159 * 180;
	}

	// Comparison Operators
	bool operator ==(const vec2_point<_Ty>& other)
	{
		return x == other.x && y == other.y;
	}
	bool operator !=(const vec2_point<_Ty>& other)
	{
		return !(*this == other);
	}
};

typedef vec2_point<float>   Vec2;
typedef vec2_point<int>    iVec2;
typedef vec2_point<double> dVec2;

std::ostream& operator<<(std::ostream& stream, const Vec2& vector);

//__________________________________________________________________________________________________________________________________



inline double Squared(double x) {
	return x * x;
}




#endif





#ifndef Vec3

///====================================================================================================================================
///================ INCASE A VECTOR HAS NOT BEEN DEFINED ===============================================================================================
///====================================================================================================================================


template<typename _Ty>
struct vec3_point
{
	vec3_point(_Ty _x, _Ty _y, _Ty _z)
		:
		x(_x), y(_y), z(_z)
	{}

	_Ty x;
	_Ty y;
	_Ty z;

	vec3_point<_Ty> operator +(vec3_point<_Ty> _other) { return vec3_point<_Ty>(this->x + _other.x, this->y + _other.y, this->z + _other.z); }
	vec3_point<_Ty> operator -(vec3_point<_Ty> _other) { return vec3_point<_Ty>(this->x - _other.x, this->y - _other.y, this->z - _other.z); }
	vec3_point<_Ty> operator *(vec3_point<_Ty> _other) { return vec3_point<_Ty>(this->x * _other.x, this->y * _other.y, this->z * _other.z); }
	vec3_point<_Ty> operator /(vec3_point<_Ty> _other) { return vec3_point<_Ty>(this->x / _other.x, this->y / _other.y, this->z / _other.z); }

	// Operator Definitions
	vec3_point<_Ty>& operator +=(const vec3_point<_Ty>& _other) { return add(_other); }
	vec3_point<_Ty>& operator -=(const vec3_point<_Ty>& _other) { return subtract(_other); }
	vec3_point<_Ty>& operator *=(const vec3_point<_Ty>& _other) { return multiply(_other); }
	vec3_point<_Ty>& operator /=(const vec3_point<_Ty>& _other) { return divide(_other); }

	// Operating on Two Vectors 
	vec3_point<_Ty>& add(const vec3_point<_Ty>& other) {
		x += other.x; y += other.y; z += other.z;
		return *this;
	}
	vec3_point<_Ty>& subtract(const vec3_point<_Ty>& other) {
		x -= other.x; y -= other.y; z -= other.z;
		return *this;
	}
	vec3_point<_Ty>& divide(const vec3_point<_Ty>& other) {
		x /= other.x; y /= other.y; z /= other.z;
		return *this;
	}
	vec3_point<_Ty>& multiply(const vec3_point<_Ty>& other) {
		x *= other.x; y *= other.y; z *= other.z;
		return *this;
	}

	// Operating on a Vector and a Single other Value
	vec3_point<_Ty>& add(_Ty other) {
		x += other; y += other; z += other;
		return *this;
	}
	vec3_point<_Ty>& subtract(_Ty other) {
		x -= other; y -= other; z -= other;
		return *this;
	}
	vec3_point<_Ty>& divide(_Ty other) {
		x /= other; y /= other; z /= other;
		return *this;
	}
	vec3_point<_Ty>& multiply(_Ty other) {
		x *= other; y *= other; z *= other;
		return *this;
	}


	// Arithmatic
	_Ty Dot(vec3_point<_Ty> A)
	{ 
		return A.x * this.x + A.y * this.y + A.z * this.z;
	}
	
	vec3_point<_Ty> Cross(vec3_point<_Ty> A)
	{
		return
		{
			(A.y * this.z - A.z * this.y),
			(A.z * this.x - A.x * this.z),
			(A.x * this.y - A.y * this.x),
		};
	}

 



	_Ty g_Angle(vec3_point<_Ty> A)
	{
		// HACK Idk just fix this shit later
		return atan2f(this.y - A.y, this.x - A.x) / 3.14159 * 180;
	}

	vec3_point<_Ty> g_Displacement(vec3_point<_Ty> A) {
		return { A.x - this.x,  A.y - this.y, A.z - this.z };
	}


	static vec3_point<_Ty> g_Displacement(vec3_point<_Ty> A, vec3_point<_Ty> B) {
		return { A.x - B.x,  A.y - B.y, A.z - this.z };
	}

	static double Dot(vec3_point<_Ty> A, vec3_point<_Ty> B)
	{
		return A.x * B.x + A.y * B.y + A.z * B.z;
	}

///static double Cross(vec3_point<_Ty> A, vec3_point<_Ty> B)
///{
///	return A.x * B.y - A.y * B.x;
///}
///
///static double g_Angle(vec3_point<_Ty> A, vec3_point<_Ty> B)
///{
///	return atan2f(B.y - A.y, B.x - A.x) / 3.14159 * 180;
///}

	// Comparison Operators
	bool operator Equals(const vec3_point<_Ty>& other)
	{
		return x == other.x && y == other.y && z == other.z;
	}
	bool operator isNotEqualTo(const vec3_point<_Ty>& other)
	{
		return !(*this == other);
	}
	bool operator ==(const vec3_point<_Ty>& other)
	{
		return x == other.x && y == other.y && z == other.z;
	}
	bool operator !=(const vec3_point<_Ty>& other)
	{
		return !(*this == other);
	}
};

typedef vec3_point<float>   Vec3;
typedef vec3_point<int>    iVec3;
typedef vec3_point<double> dVec3;

std::ostream& operator<<(std::ostream& stream, const Vec3& vector);

//__________________________________________________________________________________________________________________________________



inline double Cubed(double x)
{
	return x * x * x;
}




#endif

