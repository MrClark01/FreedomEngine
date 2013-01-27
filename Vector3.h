#include "Advanced2D.h"

#pragma once

namespace Freedom {

	class Vector3 
	{

	public:
		double x, y, z;

		Vector3();
		Vector3(const Vector3& v);
		Vector3(double x, double y, double z);
		Vector3(int x, int y, int z);
		D3DXVECTOR3 ToD3DXVECTOR3();
		D3DXVECTOR2 ToD3DXVECTOR2();

		void Set(double x1,double y1,double z1);
		void Set(const Vector3& v);
		double getX() { return x; }
		void setX(double v) { x = v; }
		double getY() { return y; }
		void setY(double v) { y = v; }
		double getZ() { return z; }
		void setZ(double v) { z = v; }
		void Move( double mx,double my,double mz);
		void operator+=(const Vector3& v);
		void operator-=(const Vector3& v);
		void operator*=(const Vector3& v);
		void operator/=(const Vector3& v);
		bool operator==( const Vector3& v ) const;
		bool operator!=( const Vector3& p ) const;
		Vector3& operator=( const Vector3& v);
		double Distance( const Vector3& v );
		double Length();
		double DotProduct( const Vector3& v );
		Vector3 CrossProduct( const Vector3& v );
		Vector3 Normal();
	}; //class
};


