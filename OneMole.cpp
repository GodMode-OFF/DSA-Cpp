#include <iostream>
#include <iomanip>  // For setting precision
using namespace std;

const double AVOGADRO_CONSTANT = 6.02214076e23;

int main() {
    double moles;
    cout << "Enter the number of moles: ";
    cin >> moles;

    // Calculate the number of particles
    double numberOfParticles = moles * AVOGADRO_CONSTANT;

    cout << fixed << setprecision(2);
    cout << "The number of particles in " << moles << " mole(s) is approximately: " 
         << numberOfParticles << " particles" << endl;

    return 0;
}
