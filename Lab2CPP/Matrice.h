#ifndef MATRICE_H
#define MATRICE_H

class Matrice {
private:
    int **matrice;
    int dimensiune;

public:
    Matrice();  
    Matrice(int dim);  
    Matrice(int dim, int val);  
    Matrice(const Matrice &other);  
    ~Matrice();  

    Matrice& operator=(const Matrice &other);  
    Matrice operator+(const Matrice &other);  
    Matrice operator-(const Matrice &other);  
    Matrice& operator+=(const Matrice &other);  
    Matrice& operator-=(const Matrice &other);  
    Matrice operator+(int scalar);  
    Matrice operator-(int scalar);  

    friend Matrice operator+(int scalar, const Matrice &mat);  

    void afisare() const;  
};

#endif
