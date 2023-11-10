#include "Matrice.h"
#include <iostream>

Matrice::Matrice() : matrice(nullptr), dimensiune(0) {}

Matrice::Matrice(int dim) : dimensiune(dim) {
    matrice = new int*[dim];
    for (int i = 0; i < dim; i++) {
        matrice[i] = new int[dim];
        for (int j = 0; j < dim; j++) {
            matrice[i][j] = 0;
        }
    }
}

Matrice::Matrice(int dim, int val) : dimensiune(dim) {
    matrice = new int*[dim];
    for (int i = 0; i < dim; i++) {
        matrice[i] = new int[dim];
        for (int j = 0; j < dim; j++) {
            matrice[i][j] = val;
        }
    }
}

Matrice::Matrice(const Matrice &other) : dimensiune(other.dimensiune) {
    matrice = new int*[dimensiune];
    for (int i = 0; i < dimensiune; i++) {
        matrice[i] = new int[dimensiune];
        for (int j = 0; j < dimensiune; j++) {
            matrice[i][j] = other.matrice[i][j];
        }
    }
}

Matrice::~Matrice() {
    if (matrice) {
        for (int i = 0; i < dimensiune; i++) {
            delete[] matrice[i];
        }
        delete[] matrice;
    }
}

Matrice& Matrice::operator=(const Matrice &other) {
    if (this == &other) {
        return *this;
    }

    if (matrice) {
        for (int i = 0; i < dimensiune; i++) {
            delete[] matrice[i];
        }
        delete[] matrice;
    }

    dimensiune = other.dimensiune;
    matrice = new int*[dimensiune];
    for (int i = 0; i < dimensiune; i++) {
        matrice[i] = new int[dimensiune];
        for (int j = 0; j < dimensiune; j++) {
            matrice[i][j] = other.matrice[i][j];
        }
    }

    return *this;
}

Matrice Matrice::operator+(const Matrice &other) {
    if (dimensiune != other.dimensiune) {
        throw std::invalid_argument("Dimensiunile matricelor nu coincid.");
    }

    Matrice result(dimensiune);

    for (int i = 0; i < dimensiune; i++) {
        for (int j = 0; j < dimensiune; j++) {
            result.matrice[i][j] = matrice[i][j] + other.matrice[i][j];
        }
    }

    return result;
}

Matrice Matrice::operator-(const Matrice &other) {
    if (dimensiune != other.dimensiune) {
        throw std::invalid_argument("Dimensiunile matricelor nu coincid.");
    }

    Matrice result(dimensiune);

    for (int i = 0; i < dimensiune; i++) {
        for (int j = 0; j < dimensiune; j++) {
            result.matrice[i][j] = matrice[i][j] - other.matrice[i][j];
        }
    }

    return result;
}

Matrice& Matrice::operator+=(const Matrice &other) {
    if (dimensiune != other.dimensiune) {
        throw std::invalid_argument("Dimensiunile matricelor nu coincid.");
    }

    for (int i = 0; i < dimensiune; i++) {
        for (int j = 0; j < dimensiune; j++) {
            matrice[i][j] += other.matrice[i][j];
        }
    }

    return *this;
}

Matrice& Matrice::operator-=(const Matrice &other) {
    if (dimensiune != other.dimensiune) {
        throw std::invalid_argument("Dimensiunile matricelor nu coincid.");
    }

    for (int i = 0; i < dimensiune; i++) {
        for (int j = 0; j < dimensiune; j++) {
            matrice[i][j] -= other.matrice[i][j];
        }
    }

    return *this;
}

Matrice Matrice::operator+(int scalar) {
    Matrice result(dimensiune);

    for (int i = 0; i < dimensiune; i++) {
        for (int j = 0; j < dimensiune; j++) {
            result.matrice[i][j] = matrice[i][j] + scalar;
        }
    }

    return result;
}

Matrice Matrice::operator-(int scalar) {
    Matrice result(dimensiune);

    for (int i = 0; i < dimensiune; i++) {
        for (int j = 0; j < dimensiune; j++) {
            result.matrice[i][j] = matrice[i][j] - scalar;
        }
    }

    return result;
}

Matrice operator+(int scalar, const Matrice &mat) {
    Matrice result(mat.dimensiune);

    for (int i = 0; i < mat.dimensiune; i++) {
        for (int j = 0; j < mat.dimensiune; j++) {
            result.matrice[i][j] = mat.matrice[i][j] + scalar;
        }
    }

    return result;
}

void Matrice::afisare() const {
    for (int i = 0; i < dimensiune; i++) {
        for (int j = 0; j < dimensiune; j++) {
            std::cout << matrice[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
