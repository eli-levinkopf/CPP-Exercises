//
// Created by Eli Levinkopf on 10/12/2021.
//

#include "Matrix.h"

Matrix::Matrix (int rows, int cols) : _rows (rows), _cols (cols)
{
  if (_rows <= EMPTY_SIZE || _cols <= EMPTY_SIZE)
	{
	  std::cerr << INVALID_PARAMETER_ERROR << std::endl;
	  exit (EXIT_FAILURE);
	}
  _data = new (std::nothrow) float[_rows * _cols] ();
  if (!_data)
	{
	  std::cerr << ALLOCATION_ERROR << std::endl;
	  exit (EXIT_FAILURE);
	}
}

Matrix::Matrix () : Matrix (MINIMAL_DIMENSIONS, MINIMAL_DIMENSIONS)
{}

Matrix::Matrix (const Matrix &m)
	: _rows (m.get_rows ()), _cols (m.get_cols ()), _data (data_copy (m))
{}

float *Matrix::data_copy (const Matrix &m) const
{
  int data_size = m.get_rows () * m.get_cols ();
  auto *new_data = new (std::nothrow) float[data_size];
  if (!new_data)
	{
	  std::cerr << ALLOCATION_ERROR << std::endl;
	  exit (EXIT_FAILURE);
	}
  for (int i = 0; i < data_size; i++)
	{
	  new_data[i] = m._data[i];
	}
  return new_data;
}

Matrix::~Matrix ()
{
  delete[] _data;
}
int Matrix::get_rows () const
{
  return _rows;
}
int Matrix::get_cols () const
{
  return _cols;
}

Matrix &Matrix::transpose ()
{
  Matrix copy_matrix (*this);
  _rows = copy_matrix.get_cols ();
  _cols = copy_matrix.get_rows ();
  for (int i = 0; i < _rows; i++)
	{
	  for (int j = 0; j < _cols; j++)
		{
		  (*this) (i, j) = copy_matrix (j, i);
		}
	}

  return *this;
}

Matrix &Matrix::vectorize ()
{
  _rows = _rows * _cols;
  _cols = VECTOR_COLS_SIZE;
  return *this;
}

void Matrix::plain_print () const
{
  for (int i = 0; i < _rows; i++)
	{
	  for (int j = 0; j < _cols; j++)
		{
		  std::cout << _data[i * (_cols) + j] << SINGLE_SPACE;
		}
	  std::cout << std::endl;
	}
}
Matrix Matrix::dot (const Matrix &m) const
{
  check_matrix_dimension(m);
  Matrix dot_matrix (_rows, _cols);
  for (int i = 0; i < _rows * _cols; i++)
	{
	  dot_matrix._data[i] = _data[i] * m._data[i];
	}
  return dot_matrix;
}

float Matrix::norm () const
{
  float norm = ZERO_INITIALIZATION;
  for (int i = 0; i < _rows * _cols; i++)
	{
	  norm += _data[i] * _data[i];
	}
  return sqrt (norm);
}

Matrix Matrix::operator+ (const Matrix &mat) const
{
  check_matrix_dimension(mat);
  Matrix new_mat (_rows, _cols);
  for (int i = 0; i < _rows * _cols; i++)
	{
	  new_mat._data[i] = _data[i] + mat._data[i];
	}
  return new_mat;
}

Matrix &Matrix::operator= (const Matrix &mat)
{
  if (this != &mat)
	{
	  delete[] _data;
	  _data = data_copy (mat);
	  _rows = mat.get_rows ();
	  _cols = mat.get_cols ();
	}
  return *this;
}

Matrix Matrix::operator* (const Matrix &mat) const
{
  if (_cols != mat.get_rows ())
	{
	  std::cerr << INVALID_DIMENSIONS_FOR_MULT_ERROR << std::endl;
	  exit (EXIT_FAILURE);
	}
  Matrix mult_mat (_rows, mat.get_cols ());
  float elem = ZERO_INITIALIZATION;
  int rows_idx = ZERO_INITIALIZATION, cols_idx = ZERO_INITIALIZATION;
  for (int i = 0; i < _rows * mat.get_cols (); i++)
	{
	  for (int j = 0; j < _cols; j++)
		{
		  elem += _data[j + rows_idx * _cols]
				  * mat._data[j * (mat._cols) + cols_idx];
		}
	  mult_mat._data[i] = elem;
	  cols_idx++;
	  if (cols_idx % mat.get_cols () == 0)
		{
		  rows_idx++;
		  cols_idx = ZERO_INITIALIZATION;
		}
	  elem = 0;
	}
  return mult_mat;
}

Matrix Matrix::operator* (const float c) const
{
  Matrix scalar_mult_mat (_rows, _cols);
  for (int i = 0; i < _rows * _cols; i++)
	{
	  scalar_mult_mat._data[i] = _data[i] * c;
	}
  return scalar_mult_mat;
}

Matrix operator* (float c, const Matrix &mat)
{
  return mat * c;
}

Matrix &Matrix::operator+= (const Matrix &mat)
{
  check_matrix_dimension(mat);
  for (int i = 0; i < _rows * _cols; i++)
	{
	  (*this)._data[i] += mat._data[i];
	}
  return *this;
}

float Matrix::operator() (int i, int j) const
{
  this->check_two_index (i, j);
  return _data[i * _cols + j];
}

float &Matrix::operator() (int i, int j)
{
  this->check_two_index (i, j);
  return _data[i * _cols + j];
}

float Matrix::operator[] (int i) const
{
  this->check_one_index (i);
  return _data[i];
}

float &Matrix::operator[] (int i)
{
  this->check_one_index (i);
  return _data[i];
}

std::ostream &operator<< (std::ostream &os, const Matrix &mat)
{
  for (int i = 0; i < mat.get_rows (); i++)
	{
	  for (int j = 0; j < mat.get_cols (); j++)
		{
		  if (mat (i, j) > MIN_PROBABILITY)
			{
			  std::cout << DOUBLE_ASTERISK;
			}
		  else
			{
			  std::cout << DOUBLE_SPACE;
			}
		}
	  std::cout << std::endl;
	}
  return os;
}

std::istream &operator>> (std::istream &is, const Matrix &mat)
{
  if (!is)
	{
	  std::cerr << INVALID_INPUT_STREAM_ERROR << std::endl;
	  exit (EXIT_FAILURE);
	}
  is.seekg (ZERO_STEPS, std::istream::end);
  auto data_length = is.tellg ();
  is.seekg (ZERO_STEPS, std::istream::beg);

  if ((size_t)data_length < (size_t)(mat._rows * mat._cols * sizeof (float)))
	{
	  std::cerr << FILE_LENGTH_ERROR << std::endl;
	  exit (EXIT_FAILURE);
	}
  is.read ((char *)mat._data, data_length);
  if (!is.good ())
	{
	  std::cerr << READING_FAILED_ERROR << std::endl;
	  exit (EXIT_FAILURE);
	}
  return is;
}

void Matrix::check_two_index (int i, int j) const
{
  if (i >= _rows || j >= _cols || i < ZERO_INITIALIZATION
	  || j < ZERO_INITIALIZATION)
	{
	  std::cerr << INVALID_INDEX_ERROR << std::endl;
	  exit (EXIT_FAILURE);
	}
}

void Matrix::check_one_index (int i) const
{
  if (i >= _rows * _cols || i < ZERO_INITIALIZATION)
	{
	  std::cerr << INVALID_INDEX_ERROR << std::endl;
	  exit (EXIT_FAILURE);
	}
}

void Matrix::check_matrix_dimension (const Matrix &mat) const
{
  if (_rows != mat.get_rows () || _cols != mat.get_cols ())
	{
	  std::cerr << INVALID_DIMENSIONS_ERROR << std::endl;
	  exit (EXIT_FAILURE);
	}
}

