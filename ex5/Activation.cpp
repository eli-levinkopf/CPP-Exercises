//
// Created by Eli Levinkopf on 10/12/2021.
//

#include "Activation.h"

Activation::Activation (ActivationType act_type) : _activation (act_type)
{
  if (_activation != RELU && _activation != SOFTMAX)
	{
	  std::cerr << INVALID_ACTIVATION_ERROR << std::endl;
	  exit (EXIT_FAILURE);
	}
}

ActivationType Activation::get_activation_type () const
{
  return _activation;
}

Matrix Activation::operator() (const Matrix &input_mat) const
{
  if (_activation == RELU)
	{
	  return relu_func (input_mat);
	}
  return softmax_func (input_mat);

}

Matrix Activation::relu_func (Matrix input_mat)
{
  for (int i = 0; i < input_mat.get_rows () * input_mat.get_cols (); i++)
	{
	  if (input_mat[i] < 0)
		{
		  input_mat[i] = CELL_INITIALIZATION;
		}
	}
  return input_mat;
}

Matrix Activation::softmax_func (Matrix input_mat)
{
  float sum = ZERO_INITIALIZATION;
  for (int i = 0; i < input_mat.get_rows () * input_mat.get_cols (); i++)
	{
	  sum += std::exp (input_mat[i]);
	}
  for (int i = 0; i < input_mat.get_rows () * input_mat.get_cols (); i++)
	{
	  input_mat[i] = std::exp (input_mat[i]) / sum;
	}
  return input_mat;
}
