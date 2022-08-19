//
// Created by Eli Levinkopf on 10/12/2021.
//

#include <cstdlib>
#include "MlpNetwork.h"

MlpNetwork::MlpNetwork (Matrix *weights, Matrix *biases)
{
  check_dimensions (weights, biases);
  for (int i = 0; i < MLP_SIZE; i++)
	{
	  _weights[i] = weights[i];
	  _bases[i] = biases[i];
	}
}

void
MlpNetwork::check_dimensions (const Matrix *weights, const Matrix *biases)
{
  for (int i = 0; i < MLP_SIZE; i++)
	{
	  if (weights[i].get_rows () != weights_dims[i].rows ||
		  weights[i].get_cols () != weights_dims[i].cols ||
		  biases[i].get_rows () != bias_dims[i].rows ||
		  biases[i].get_cols () != bias_dims[i].cols)
		{
		  std::cerr << INPUT_DIMENSIONS_ERROR << std::endl;
		  exit (EXIT_FAILURE);
		}
	}
}

digit MlpNetwork::operator() (Matrix &input_mat) const
{
  ActivationType activation_type = RELU;
  for (int i = 0; i < MLP_SIZE; i++)
	{
	  if (i == MLP_SIZE - 1)
		{
		  activation_type = SOFTMAX;
		}
	  Dense dense (_weights[i], _bases[i], activation_type);
	  input_mat = dense (input_mat);
	}
  digit output = get_output_value_and_its_probability (input_mat);
  return output;
}

digit
MlpNetwork::get_output_value_and_its_probability (const Matrix &output_mat)
{
  digit output = {ZERO_INITIALIZATION, ZERO_INITIALIZATION};
  for (int i = 0; i < output_mat.get_rows (); i++)
	{
	  if (output_mat[i] > output.probability)
		{
		  output.probability = output_mat[i];
		  output.value = i;
		}
	}
  return output;
}

