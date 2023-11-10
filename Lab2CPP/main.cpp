#include "Matrice.h"

int main() {
    Matrice mat1(3, 2);  
    Matrice mat2(3, 3); 
    Matrice mat3;

    mat3 = mat1 + mat2;  
    mat3.afisare();

    Matrice mat4 = mat1 - mat2;  
    mat4.afisare();

    Matrice mat5 = mat1 + 5;  
    mat5.afisare();

    Matrice mat6 = mat5 - mat1;  
    mat6.afisare();

    return 0;
}
