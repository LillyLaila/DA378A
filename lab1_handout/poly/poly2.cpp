#include "poly2.h"
#include <cmath>
#include <iostream>

Poly2::Poly2(float a, float b, float c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}

float Poly2::eval(float x)
{
return (a*(pow(x,2))) + (b*x) +c ;
}

void Poly2::findRoots(int &numRoots, float &root1, float &root2)
{
	    
float discriminant = b * b - 4 * a * c;

    if (discriminant < 0) { // 2 imaginära roots men inga reala roots.
        numRoots = 0;  // Inga rella roots. 

        //std::cout << "No real roots " << std::endl; //Uppgift 8
    } else if (discriminant == 0) {
        numRoots = 1;  // One real root (double root)
        root1 = -b / (2 * a);   

       // float root = -b / (2 * a); //uppgift 8
      //  std::cout << "One real root (dubbelrot): " << root << std::endl; //uppgift 8

    } else { //discriminant d>0

        numRoots = 2;  // två rella roots.
        float sqrtDiscriminant = sqrt(discriminant);
        root1 = (-b + sqrtDiscriminant) / (2 * a);
        root2 = (-b - sqrtDiscriminant) / (2 * a);


       // std::cout << "Two real roots: " << root1 << ", " << root2 << std::endl; 
    }

}