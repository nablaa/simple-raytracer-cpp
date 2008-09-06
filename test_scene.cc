#include <iostream>
#include "scene.hh"
#include "vector.hh"
#include "common.hh"
#include "tests.hh"

int main()
{
	BEGIN_TESTS("Camera");

	{
	Point o = { 0, 0, 0 };
	Vector3 d(0, 0, 1);
	Camera cam(o, d, 100, 100, 10, 45.0);


	}


	BEGIN_TESTS("Scene");
}

