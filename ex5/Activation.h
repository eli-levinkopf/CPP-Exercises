//Activation.h


#ifndef ACTIVATION_H
#define ACTIVATION_H

#include "Matrix.h"
#include <cmath>

#define CELL_INITIALIZATION 0
#define ZERO_INITIALIZATION 0
#define INVALID_ACTIVATION_ERROR "Error: Invalid activation type"

/**
 * @enum ActivationType
 * @brief Indicator of activation function.
 */
enum ActivationType
{
  RELU,
  SOFTMAX
};

class Activation{
 public:

  //**************** Constructor ****************//
  /**
   * Constructs a new Activation object
   * @param act_type RELU/SOFTMAX
   */
  explicit Activation(ActivationType act_type);

  //**************** Getter ****************//
  /**
   * @return The Activation type (RELU/SOFTMAX)
   */
  ActivationType get_activation_type () const;
  //**************** Parenthesis operator ****************//
  /**
   * Applies activation on the input
   * @param input_mat Matrix to apply activation on
   * @return Activated Matrix
   */
  Matrix operator()(const Matrix &input_mat)const;

  //**************** private methods ****************//
 private:
  ActivationType _activation;
  /**
   * Apply RELU activation on a Matrix
   * @param input_mat Matrix to apply RELU activation on
   * @return Activated Matrix
   */
  static Matrix relu_func (Matrix input_mat) ;

  /**
 * Apply SOFTMAX activation on a Matrix
 * @param input_mat Matrix to apply RELU activation on
 * @return Activated Matrix
 */
  static Matrix softmax_func (Matrix input_mat) ;
};

#endif //ACTIVATION_H