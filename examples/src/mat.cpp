#include "mat.h"

/**
 * @brief Construct a new Matrix:: Matrix object
 * 
 */
Matrix::Matrix() {
    makeIdentity();
}

/**
 * @brief Convert this matrix to an identity matrix
 * 
 */
void Matrix::makeIdentity() {
    matrix = glm::mat4(1.0f);
}


void Matrix::translate(glm::vec3 translation) {
    matrix = glm::translate(matrix, translation);
}


void Matrix::rotate(glm::vec3 axis, float rotation) {
    matrix = glm::rotate(matrix, rotation, axis);
}


void Matrix::scale(glm::vec3 scale) {
    matrix = glm::scale(matrix, scale);
}