//////////////////////////////////////////////////////////////////////
//
//  University of Leeds
//  COMP 5812M Foundations of Modelling & Rendering
//  User Interface for Coursework
////////////////////////////////////////////////////////////////////////

// system libraries
#include <iostream>
#include "Matrix4.h"
#include "Point3.h"
#include "Vector3.h"
// main routine
int main()
{ // main()
	Point3 p(0, 1, 3);
	Point3 q(1, -1, 2);
	Point3 r(0, 0, 1);

	Vector3 u(-1, 2, 3);
	Vector3 v(1, 2, -1);
	Vector3 w(-1, 2, 4);

	Matrix4 m1;

	m1.SetIdentity();

	m1.coordinates[0][0] = 1.0f; m1.coordinates[0][1] = 0.0f; m1.coordinates[0][2] = 3.0f;

	m1.coordinates[1][0] = 1.0f; m1.coordinates[1][1] = 9.0f; m1.coordinates[1][2] = 2.0f;

	m1.coordinates[2][0] = 4.0f; m1.coordinates[2][1] = 3.0f; m1.coordinates[2][2] = 6.0f;


	Matrix4 m2;
	m2.SetIdentity();

	m2.coordinates[0][0] = 0.707f; m2.coordinates[0][1] = 0.707f; m2.coordinates[0][2] = 0.0f;

	m2.coordinates[1][0] = -0.707f; m2.coordinates[1][1] = 0.707f; m2.coordinates[1][2] = 0.0f;

	m2.coordinates[2][0] = 0.0f; m2.coordinates[2][1] = 0.0f; m2.coordinates[2][2] = 1.0f;

	Matrix4 m3;
	m3.SetIdentity();

	m3.coordinates[0][0] = 6.0f; m3.coordinates[0][1] = 0.0f; m3.coordinates[0][2] = 0.0f;

	m3.coordinates[1][0] = -1.0f; m3.coordinates[1][1] = 4.0f; m3.coordinates[1][2] = 0.0f;

	m3.coordinates[2][0] = 4.0f; m3.coordinates[2][1] = 2.0f; m3.coordinates[2][2] = -3.0f;


	std::cout << "p + u = " << p + u << '\n';
	std::cout << '\n';

	std::cout << "q + m1 * v = " << q + (m1 * v) << '\n';
	std::cout << '\n';

	std::cout << "r + (m3 * m2 * w) = " << r + (m3 * m2 * w) << '\n';
	std::cout << '\n';

	std::cout << "Orthogonal matrix m2 = \n " << m2.transpose() << '\n';
	std::cout << '\n';

	std::cout << "U Dot Product V = " << u.dot(v) << '\n';
	std::cout << '\n';

	std::cout << "U Cross Product W = " << v.cross(w) << '\n';

	std::cout << '\n';

	std::cout << "Check if U V and W are independent = " << u.dot(v.cross(w)) << '\n';

	std::cout << "Since the result is non-zero, the vectors are independent." << '\n';

	std::cout << "We can now construct a orthogonal basis from these vectors." << '\n';

	Vector3 w_prime = w - (w.dot(u.unit()) * u.unit()) - (w.dot(v.unit()) * v.unit());

	std::cout << "E1 = " << u.unit() << '\n';
	std::cout << "E2 = " << v.unit() << '\n';
	std::cout << "E3 = " << w_prime.unit() << '\n';	
	std::cout << '\n';

} // main()