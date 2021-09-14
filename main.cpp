#include "matrix.h"
#include "rgb_matrix.h"
#include "bw_matrix.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void GenMatrix(Matrix& mat, int min = 0, int max = 255){
    for (size_t r = 0; r < mat.getRows(); ++r) {
        for (size_t c = 0; c < mat.getCols(); ++c) {
            for (size_t ch = 0; ch < mat.getChannels(); ++ch) {
                mat.at(r, c, ch) = min + std::rand() % (max - min + 1);
            }
        }
    }
}

int main() {
    std::srand(std::time(nullptr));
    Matrix a(3, 3 , 3);
    Matrix b(3, 4, 2, 3);
    GenMatrix(a);

    std::cout << "A matrix: \n" << a << std::endl;
    std::cout << "B matrix: \n" << b << std::endl;

    RGBMatrix rgb(3,3);
    BWMatrix bw(2,2);
    GenMatrix(rgb);
    GenMatrix(bw);
    std::cout << "RGB matrix: \n" << rgb << std::endl;
    std::cout << "BW matrix: \n" << bw << std::endl;

    std::cout << "RGB matrix + 10: \n" << rgb + 10 << std::endl;
    std::cout << "BW matrix * 2: \n" << bw * 2 << std::endl;
    return 0;
}
