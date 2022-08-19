//
// Created by Eli Levinkopf on 10/12/2021.
//

#include "Dense.h"

Dense::Dense (const Matrix &weights_mat, const Matrix &bias_mat,
			  ActivationType activation_type) : _weights_mat (weights_mat),
												_bias_mat (bias_mat),
												_activation (activation_type)
{
  if (weights_mat.get_rows () != bias_mat.get_rows () ||
	  bias_mat.get_cols () != 1)
	{
	  std::cerr << INPUT_DIMENSIONS_ERROR << std::endl;
	  exit (EXIT_FAILURE);
	}
}

const Matrix &Dense::get_weights () const
{
  return _weights_mat;
}

const Matrix &Dense::get_bias () const
{
  return _bias_mat;
}

const Activation &Dense::get_activation () const
{
  return _activation;
}

Matrix Dense::operator() (const Matrix &input_mat) const
{
  Matrix output_mat (_weights_mat * input_mat + _bias_mat);

  return _activation (output_mat);
}