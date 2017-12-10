#include <iostream>
#include <Engine/math/Matrix.hpp>
#include <Engine/Vector.hpp>
#include <Engine/Utils.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <Engine/MatrixTransformations.hpp>

using namespace fiene;
using namespace std;

int main()
{

    glm::mat4 glmMat1 (
        2, 3, -4, 6,
        -1, 0, 2, 4,
        2, -6, 5, 6,
        8, 2, 1, -1
    );

    glm::mat4 glmMat2 (
        1, 3, -4, -1,
        4, 8, 1, 3,
        2, 6, 5, 6,
        8, -2, 2, 9
    );

    Matrix4 mat1 (
        2, 3, -4, 6,
        -1, 0, 2, 4,
        2, -6, 5, 6,
        8, 2, 1, -1
    );

    Matrix4 mat2 (
        1, 3, -4, -1,
        4, 8, 1, 3,
        2, 6, 5, 6,
        8, -2, 2, 9
    );

    Vec3 vec1(1.0f, 0.4f, 0.0f);
    glm::vec3 vec2(1.0f, 0.4f, 0.0f);

    Matrix4 norm1 = Math::rotate(mat1, vec1, 45.0f);
    glm::mat4 nana = glm::rotate(glmMat1, 45.0f, vec2);

    glm::vec3 test (1, 4.5, 5);
    Vec3 test2(4, 2, 6);
    Vec3 test3(test3.normalized());

    Vec2 screenCords ( 100, 100);
    screenCords *= Vec2(20, 20);

    glm::mat4 Result(glmMat1);
    Result[3] = glmMat1[0] * vec2[0] + glmMat1[1] * vec2[1] + glmMat1[2] * vec2[2] + glmMat1[3];

    Matrix4 Result2(mat1);
    Result2[3] = mat1[0] * vec1[0] + mat1[1] * vec1[1] + mat1[2] * vec1[2] + mat1[3];

//    std::cout << test[0] << " " << test[1] << " " << " " << test[2] << std::endl;
//    std::cout << test2[0] << " " << test2[1] << " " << " " << test2[2] << std::endl;
//    std::cout << test3[0] << " " << test3[1] << " " << " " << test3[2] << std::endl;
//    std::cout << screenCords[0] << " " << screenCords[1] << std::endl;

    std::cout << vec1[0] << " " << vec1[1] << " " << vec1[2] << std::endl;
    std::cout << vec2[0] << " " << vec2[1] << " " << vec2[2] << std::endl;

    std::cout << "--------------------------------------------------------------" << std::endl;


    std::cout << norm1[0][0] << " " << norm1[1][0] << " " << norm1[2][0] << " " << norm1[3][0] << std::endl;
    std::cout << norm1[0][1] << " " << norm1[1][1] << " " << norm1[2][1] << " " << norm1[3][1] << std::endl;
    std::cout << norm1[0][2] << " " << norm1[1][2] << " " << norm1[2][2] << " " << norm1[3][2] << std::endl;
    std::cout << norm1[0][3] << " " << norm1[1][3] << " " << norm1[2][3] << " " << norm1[3][3] << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;

    std::cout << nana[0][0] << " " << nana[1][0] << " " << nana[2][0] << " " << nana[3][0] << std::endl;
    std::cout << nana[0][1] << " " << nana[1][1] << " " << nana[2][1] << " " << nana[3][1] << std::endl;
    std::cout << nana[0][2] << " " << nana[1][2] << " " << nana[2][2] << " " << nana[3][2] << std::endl;
    std::cout << nana[0][3] << " " << nana[1][3] << " " << nana[2][3] << " " << nana[3][3] << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;




   // std::cout << nana2[3][0] << nana2[3][1] << " " << nana2[3][2] << nana2[3][3] << std::endl;

    return 0;
}