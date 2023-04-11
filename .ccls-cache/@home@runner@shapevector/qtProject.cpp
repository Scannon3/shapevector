#include "shapeVector.h"
#include <iostream>
using namespace std;
int main() {
  std::cout << "Hello World!\n";
  shapeVector<Shape> v1;
	Shape s1;
	s1.data = 5;
	v1.push_back(s1);
	cout << v1[0].data;
	
	
	
	
}