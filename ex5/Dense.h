//
// Created by yuval on 01-Oct-21.
//

#ifndef DENSE_H
#define DENSE_H

#include "Activation.h"
#define INPUT_DIMENSIONS_ERROR "Error: invalid weights or bias dimensions"

class Dense{
 public:

  //**************** Constructor ****************//
  /**
   * Constructs a new Dense object
   * @param weights_mat Weights Matrix
   * @param bias_mat Bias Matrix
   * @param activation_type RELU/SOFTMAX
   */
  Dense(const Matrix &weights_mat, const Matrix &bias_mat,
		ActivationType activation_type);

  //**************** Getters ****************//
  /**
   * @return The weights of this Matrix
   */
  const Matrix &get_weights () const;

  /**
   * @return The bias of this Matrix
   */
  const Matrix &get_bias () const;

  /**
   * @return  The activation of this Matrix
   */
  const Activation &get_activation () const;

  //**************** Parenthesis operator ****************//
  /**
   * Applies the layer on the input
   * @param input_mat Matrix to apply layer on
   * @return The output Matrix
   */
  Matrix operator()(const Matrix &input_mat)const;

  //**************** private methods ****************//
 private:
  Matrix _weights_mat;
  Matrix _bias_mat;
  Activation _activation;

};


#endif //DENSE_H