#include <iostream>
#include "poly2.h"
#include <fstream>




int main(int argc, const char* argv[])
{

std::ifstream infile("coeffs.txt");  // Öppnar coeffs.txt fil som input
std::ofstream outfile("roots.txt");  // Öppnar roots.txt fil som output

    float polynomcoeffs1; //a
    float polynomcoeffs2; //b
    float polynomcoeffs3; //c


   while (infile >> polynomcoeffs1 >> polynomcoeffs2 >> polynomcoeffs3)
   {
	outfile << "Polynom coeffs are : a = " << polynomcoeffs1 << ", b = " << polynomcoeffs2 << ", c = " << polynomcoeffs3 << std::endl;

  
    Poly2 poly = Poly2(polynomcoeffs1, polynomcoeffs2, polynomcoeffs3);

      // lagra roots och antalet roots.
   int numRoots;
   float root1, root2;
       //anropa metoden findRoots för att skicka polynom koeffs och för att hitta roots och antal roots.
   poly.findRoots(numRoots, root1, root2);


        if (numRoots == 0) {
            outfile << "No real roots." << std::endl;
        } else if (numRoots == 1) {
            outfile << "One real root: " << root1 << std::endl;
            outfile << "eval y(x) at root = " << poly.eval(root1) << std::endl;
        } else {
            outfile << "Two real roots: " << root1 << ", " << root2 << std::endl;
            outfile << "eval y(x) at root1 = " << poly.eval(root1) << std::endl;
            outfile << "eval y(x) at root2 = " << poly.eval(root2) << std::endl;
        }
        outfile << std::endl;
    }

    infile.close();
    outfile.close();
    return 0;
}
