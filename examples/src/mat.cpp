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

/**
 * @brief Translates this matrix by the given vector
 * 
 * @param translation Vector of translation (x, y, z)
 */
void Matrix::translate(glm::vec3 translation) {
    matrix = glm::translate(matrix, translation);
}

/**
 * @brief Rotates this matrix along the given axis for 'rotation' radians
 * 
 * @param axis Axis about which to rotate
 * @param rotation Magnitude of rotation in radians
 */
void Matrix::rotate(glm::vec3 axis, float rotation) {
    matrix = glm::rotate(matrix, rotation, axis);
}

/**
 * @brief Scales this matrix by the given vector
 * 
 * @param scale Vector of scale (x, y, z)
 */
void Matrix::scale(glm::vec3 scale) {
    matrix = glm::scale(matrix, scale);
}