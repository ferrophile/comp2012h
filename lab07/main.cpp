#include <math.h>
#include "grid3d.h"


// As we use integer grid point, integer division is used and
// some precision may be lost.
grid3d findCentroid(grid3d A, grid3d B, grid3d C) {
int x, y, z;

   x = (A.getx() + B.getx() + C.getx()) / 3;
   y = (A.gety() + B.gety() + C.gety()) / 3;
   z = (A.getz() + B.getz() + C.getz()) / 3;

   return grid3d(x, y, z);
}

inline double sqr(double x) { return x * x; }

// Heron's formula: area=sqrt(s(s-a)(s-b)(s-c))
double findArea(grid3d A, grid3d B, grid3d C) {
double len1, len2, len3, s;

   len1 = sqrt( sqr(A.getx()-B.getx()) + sqr(A.gety()-B.gety()) + sqr(A.getz()-B.getz()) );

   len2 = sqrt( sqr(C.getx()-B.getx()) + sqr(C.gety()-B.gety()) + sqr(C.getz()-B.getz()) );

   len3 = sqrt( sqr(C.getx()-A.getx()) + sqr(C.gety()-A.gety()) + sqr(C.getz()-A.getz()) ); 

   s = (len1 + len2 + len3) * 0.5;

   return sqrt( s * (s-len1) * (s-len2) * (s-len3) );
}


int main(int argc, char *argv[]) {

   cout << endl << "Point A is created by ";
   grid3d ptA(3, 4, 5);
   cout << endl << "Point A is ";
   ptA.print();

   cout << endl << "Point B is created by ";
   grid3d ptB = 2; 
   cout << endl << "Point B is ";
   ptB.print();
  
   cout << endl << "Point C is created by ";
   grid3d ptC; ptC = -6;
   cout << endl << "Point C is ";
   ptC.print();

   cout << endl << "Point D is created by ";
   grid3d ptD(ptA);
   cout << endl << "Point D is ";
   ptD.print();

   cout << endl << "Point E is created by ";
   grid3d ptE = grid3d(-2,2,7);
   cout << endl << "Point E is ";
   ptE.print(); 

   cout << endl << "Creating an array of points... ";
   grid3d ptArr[2];
   cout << "The points in the array are ";
   ptArr[0].print(); ptArr[1].print(); 

   cout << endl << "Please enter three integers to set a point in the array ";
   cin >> ptArr[0];
   cout << endl << "The point is set to ";
   ptArr[0].print(); 

   cout << endl << "Start to compute centroid" << endl;
   grid3d centroid = findCentroid(ptA, ptB, ptE);
   cout << endl << "The centroid of triange ";
   ptA.print(); ptB.print(); ptE.print();
   cout << " is "; 
   centroid.print();

   cout << endl << "Start to compute area" << endl;
   double area;
   area = findArea(ptA, ptB, ptE);
   cout << endl << "The area of triangle ";
   ptA.print(); ptB.print(); ptE.print();
   cout << " is " << area << endl;

   return 0;
}
