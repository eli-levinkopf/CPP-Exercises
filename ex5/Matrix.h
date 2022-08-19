// Matrix.h

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cmath>

#define EMPTY_SIZE 0
#define ZERO_STEPS 0
#define ZERO_INITIALIZATION 0
#define MIN_PROBABILITY 0.1
#define VECTOR_COLS_SIZE 1
#define MINIMAL_DIMENSIONS 1
#define DOUBLE_ASTERISK "**"
#define DOUBLE_SPACE "  "
#define SINGLE_SPACE " "
#define INVALID_PARAMETER_ERROR "Error: Invalid parameter for rows/cols index"
#define ALLOCATION_ERROR "Error: Data allocation was failed"
#define INVALID_DIMENSIONS_ERROR "Error: Invalid matrix dimensions"
#define INVALID_INDEX_ERROR "Error: Invalid index (i/j)"
#define INVALID_INPUT_STREAM_ERROR "Error: Invalid input stream"
#define READING_FAILED_ERROR "Error: Reading from file failed"
#define FILE_LENGTH_ERROR "Error: File length is not match to the matrix"
#define INVALID_DIMENSIONS_FOR_MULT_ERROR "Error: cols_left != rows_right - \
invalid dimensions for matrix multiplication"

/**
 * @struct MatrixDims
 * @brief Matrix dimensions container. Used in MlpNetwork.h and in main.cpp.
 */
typedef struct matrix_dims {
  int rows, cols;
} matrix_dims;

class Matrix {
 public:

  //**************** constructors ****************//
  /**
   * Constructs a new Matrix instance with rows number of rows and
   * cols number of column. Inits all elements to 0. exit if fail in allocation
   * @param rows number of rows
   * @param cols number of column
   */
  Matrix (int rows, int cols);

  /**
   * Constructs a new Matrix instance of size 1x1. Inits all elements
   * to 0.
   */
  Matrix ();

  /**
   * Constructs a new Matrix instance from anther Matrix
   * @param m The anther Matrix
   */
  Matrix (const Matrix &m);

  //**************** destructor ****************//
  /**
   * Destructor for a Matrix instance. deletes the Matrix resources.
   */
  ~Matrix ();

  //**************** getters ****************//
  /**
   * Get the number of rows in the Matrix
   * @return amount of rows in the Matrix
   */
  int get_rows () const;

  /**
 * Get the number of column in the Matrix
 * @return amount of column in the Matrix
 */
  int get_cols () const;

  //**************** matrix operations ****************//
  /**
   * Transpose the Matrix into a transpose Matrix
   * @return The transposed Matrix with an appropriate dimensions
   */
  Matrix &transpose ();

  /**
   * Transpose the Matrix into a column vector
   * @return A column vector (dimensions - 1x(rows x cols))
   */
  Matrix &vectorize ();

  /**
   * Prints Matrix elements
   */
  void plain_print () const;

  /**
   * Make a dot product on the Matrix
   * @param m Matrix to multiplication
   * @return dot product Matrix
   */
  Matrix dot (const Matrix &m) const;

  /**
   * Calculates the norm of the Matrix
   * @return Norm of the Matrix, exit if fail
   */
  float norm () const;

  //**************** arithmetic operators ****************//
  /**
   * Addition operator
   * @param mat Another Matrix object
   * @return The Matrix after the addition, exit if fail
   */
  Matrix operator+ (const Matrix &mat) const;

  /**
   * Assignment operator
   * @param mat Matrix to copy values from
   * @return Copy of the Matrix, exit if fail
   */
  Matrix &operator= (const Matrix &mat);

  /**
   * Matrix multiplication operator
   * @param mat Another Matrix object
   * @return Matrix after the multiplication, exit if fail
   */
  Matrix operator* (const Matrix &mat) const;

  /**
   * Scalar multiplication (on the right) operator
   * @param c A scalar to multiply the Matrix
   * @return Matrix multiplied by c
   */
  Matrix operator* (float c) const;

  /**
 * Scalar multiplication (on the left) operator
 * @param c A scalar to multiply the Matrix
 * @return Matrix multiplied by c
 */
  friend Matrix operator* (float c, const Matrix &mat);

  /**
   * Add to this operator
   * @param mat Another Matrix object
   * @return The Matrix after adding the another Matrix object, exit if fail
   */
  Matrix &operator+= (const Matrix &mat);

  /**
   * Parenthesis indexing operator (const version)
   * @param i Index for rows
   * @param j Index for cols
   * @return The element in cell (i,j), exit if fail
   */
  float operator() (int i, int j) const;

  /**
   * Parenthesis indexing operator
   * @param i Index for rows
   * @param j Index for cols
   * @return The element in cell (i,j), exit if fail
   */
  float &operator() (int i, int j);

  /**
   * Brackets indexing operator. allows accessing members (const version)
   * @param i Index for the cell
   * @return the element in cell i, exit if fail
   */
  float operator[] (int i) const;

  /**
 * Brackets indexing operator. allows accessing members and changing them
 * @param i Index for the cell
 * @return the element in cell i, exit if fail
 */
  float &operator[] (int i);

  //**************** IO stream methods ****************//
  /**
   * Output stream operator
   * @param os Output stream to print to
   * @param mat Matrix to print its values
   */
  friend std::ostream &operator<< (std::ostream &os, const Matrix &mat);

  /**
   * Input stream operator
   * @param is Input stream to read from
   * @param mat Matrix to read to
   */
  friend std::istream &operator>> (std::istream &is, const Matrix &mat);

  //**************** private methods ****************//
 private:
  int _rows = 0;
  int _cols = 0;
  float *_data = {nullptr};
  /**
   * Copy the data array
   * @param m Matrix to copy its data
   * @return Data array
   */
  float *data_copy (const Matrix &m) const;

  /**
   * Check if the indexes are valid (for parenthesis access)
   * @param i Row index
   * @param j Col index
   */
  void check_two_index (int i, int j) const;

  /**
   * Check if the index is valid (for brackets access)
   * @param i Element index
   */
  void check_one_index (int i) const;

  /**
   * Check if the dimension of the Matrix is valid
   * @param mat Matrix to check its dimension
   */
  void check_matrix_dimension (const Matrix &mat) const;
};

#endif //MATRIX_H
