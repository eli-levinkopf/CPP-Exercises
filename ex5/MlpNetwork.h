//MlpNetwork.h

#ifndef MLPNETWORK_H
#define MLPNETWORK_H

#include "Dense.h"

#define MLP_SIZE 4
#define ZERO_INITIALIZATION 0

/**
 * @struct digit
 * @brief Identified (by Mlp network) digit with
 *        the associated probability.
 * @var value - Identified digit value
 * @var probability - identification probability
 */
typedef struct digit {
  unsigned int value;
  float probability;
} digit;

const matrix_dims img_dims = {28, 28};

const matrix_dims weights_dims[] = {{128, 784},
									{64, 128},
									{20, 64},
									{10, 20}};

const matrix_dims bias_dims[] = {{128, 1},
								 {64, 1},
								 {20, 1},
								 {10, 1}};

class MlpNetwork {
 public:

  //**************** Constructor ****************//
  /**
   * Constructs a new MlpNetwork object
   * @param weights An array of (4) weights matrices
   * @param biases An array of (4) biases matrices
   */
  MlpNetwork (Matrix weights[], Matrix biases[]);

  //**************** Parenthesis operator ****************//

  /**
 * Applies the layer on the input
 * @param input_mat Matrix to apply layer on
 * @return The output Matrix
 */



  /**
   * Applies the entire network on the input
   * @param input_mat Input Matrix  to apply the network on
   * @return digit - Identified digit value & its probability
   */
  digit operator() (Matrix &input_mat) const;

  //**************** private methods ****************//
 private:
  Matrix _weights[MLP_SIZE];
  Matrix _bases[MLP_SIZE];
  /**
   * Get the value & its probability
   * @param output_mat Final Matrix
   * @return digit - Identified digit value & its probability
   */
  static digit get_output_value_and_its_probability (const Matrix &output_mat);

  /**
   * Check the input dimensions, exit if the dimensions are invalid
   * @param weights An array of (4) weights matrices
   * @param biases An array of (4) biases matrices
   */
  static void check_dimensions (const Matrix *weights, const Matrix *biases);
};

#endif // MLPNETWORK_H