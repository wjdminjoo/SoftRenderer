#pragma once

#include "CoreDefinition.h"
#include <math.h>
#include "Vector2.h"

struct Vector3
{
public:
	Vector3() { }
	FORCEINLINE Vector3(const Vector2& InV, bool IsPoint) : X(InV.X), Y(InV.Y) { Z = IsPoint ? 1.f : 0.f; }
	constexpr FORCEINLINE Vector3(float InX, float InY, float InZ) : X(InX), Y(InY), Z(InZ) {}

	FORCEINLINE float SizeSquared() const;
	FORCEINLINE float Dot(const Vector3& InV) const;
	FORCEINLINE Vector3 Normalize() const;

	FORCEINLINE Vector2 ToVector2() const;

	FORCEINLINE bool IsZero() const
	{
		return X == 0.f && Y == 0.f && Z == 0.f;
	}

	FORCEINLINE float operator[](int InIndex) const;
	FORCEINLINE float& operator[](int InIndex);

	FORCEINLINE Vector3 operator*(float InScalar) const;
	FORCEINLINE Vector3 operator/(float InScalar) const;
	FORCEINLINE Vector3 operator+(const Vector3& InV) const;
	FORCEINLINE Vector3 operator-(const Vector3& InV) const;
	FORCEINLINE Vector3& operator+=(const Vector3& InV);

	static const Vector3 UnitX;
	static const Vector3 UnitY;
	static const Vector3 UnitZ;

	static const Vector3 One;
	static const Vector3 Zero;

public:
	float X = 0.f;
	float Y = 0.f;
	float Z = 0.f;
};

FORCEINLINE Vector3 Vector3::operator*(float InScalar) const
{
	return Vector3(X * InScalar, Y * InScalar, Z * InScalar);
}

FORCEINLINE Vector3 Vector3::operator/(float InScalar) const
{
	return Vector3(X / InScalar, Y / InScalar, Z / InScalar);
}

FORCEINLINE Vector3 Vector3::operator+(const Vector3& InV) const
{
	return Vector3(X + InV.X, Y + InV.Y, Z + InV.Z);
}

FORCEINLINE Vector3 Vector3::operator-(const Vector3& InV) const
{
	return Vector3(X - InV.X, Y - InV.Y, Z - InV.Z);
}

FORCEINLINE Vector3& Vector3::operator+=(const Vector3& InV)
{
	X += InV.X;
	Y += InV.Y;
	Z += InV.Z;

	return *this;
}


FORCEINLINE float Vector3::SizeSquared() const
{
	return X * X + Y * Y + Z * Z;
}

FORCEINLINE float Vector3::Dot(const Vector3& InV) const
{
	return X * InV.X + Y * InV.Y + Z * InV.Z;
}

FORCEINLINE float Vector3::operator[](int InIndex) const 
{
	return ((float *)this)[InIndex];
}

FORCEINLINE float &Vector3::operator[](int InIndex)
{
	return ((float *)this)[InIndex];
}

FORCEINLINE Vector3 Vector3::Normalize() const
{
	float squareSum = SizeSquared();
	if (squareSum == 1.f)
	{
		return *this;
	}
	else if (squareSum == 0.f)
	{
		return Vector3::Zero;
	}

	float invLength = 1 / sqrtf(squareSum);
	return Vector3(X * invLength, Y * invLength, Z * invLength);
}

FORCEINLINE Vector2 Vector3::ToVector2() const {
	return Vector2(X, Y);
}