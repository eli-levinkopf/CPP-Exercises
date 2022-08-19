//
// Created by Eli Levinkopf on 10/12/2021.
//

#include <fstream>
#include <iostream>
#include <cmath>
#include "Matrix.h"
#include "Activation.h"
#include "Dense.h"
#include "MlpNetwork.h"

bool readFileToMatrix (const std::string &filePath, Matrix &mat)
{
  std::ifstream is;
  is.open (filePath, std::ios::in | std::ios::binary | std::ios::ate);
  if (!is.is_open ())
	{
	  return false;
	}

  long int matByteSize =
	  (long int)mat.get_cols () * mat.get_rows () * sizeof (float);
  if (is.tellg () != matByteSize)
	{
	  is.close ();
	  return false;
	}

  is.seekg (0, std::ios_base::beg);
  is >> mat;
  is.close ();
  return true;
}

Matrix &randomly_fill_matrix(Matrix &mat){
  for (int i = 0; i < mat.get_rows () * mat.get_cols(); i++){
	mat[i] = (float)rand()/(float)(rand()+1);
  }
  return mat;
}



int main ()
{

  Matrix mat1 (3, 4);
  Matrix mat2 (3, 4);
  Matrix matt = Matrix(mat1);
  randomly_fill_matrix (mat1);
  randomly_fill_matrix (mat2);
  std::cout << "rows: " << mat1.get_rows () << ", ";
  std::cout << "cols: " << mat1.get_cols () << std::endl;
  mat1.plain_print ();
  std::cout << std::endl;

  std::cout << "rows: " << mat2.get_rows () << ", ";
  std::cout << "cols: " << mat2.get_cols () << std::endl;
  mat2.plain_print ();
  std::cout << std::endl;

  Matrix mat3 = 4* mat2;
  std::cout << "rows: " << mat3.get_rows () << ", ";
  std::cout << "cols: " << mat3.get_cols () << std::endl;
  mat3.plain_print ();
  std::cout << std::endl;
  mat1[12];
  mat1(1,2)

//  Matrix mat1_transpose(mat1);
//  mat1_transpose.transpose ();
//  std::cout << "rows: " << mat1_transpose.get_rows () << ", ";
//  std::cout << "cols: " << mat1_transpose.get_cols () << std::endl;
//  mat1_transpose.plain_print ();
//  std::cout << std::endl;
//
//  mat1_transpose.transpose ();
//  std::cout << "rows: " << mat1_transpose.get_rows () << ", ";
//  std::cout << "cols: " << mat1_transpose.get_cols () << std::endl;
//  mat1_transpose.plain_print ();
//
//  std::cout << std::endl;
//  mat1.plain_print ();


//  std::cout << std::endl;
//  Matrix mat4 = mat1.dot(mat3);
//  mat4.plain_print();
//  mat1.transpose ();
//  std::cout << "rows: " << mat1.get_rows () << ", ";
//  std::cout << "cols: " << mat1.get_cols () << std::endl;
//  mat1.plain_print ();
//  mat1.vectorize();
//  std::cout << "cols: " << mat1.get_cols () << ", ";
//  std::cout << "rows: " << mat1.get_rows () << std::endl;
//  mat1.plain_print ();
//  std::cout <<mat1.norm ();

//  Matrix mat3 = mat1 * mat2;
//  Matrix mat3 = 3 * mat2;
//  Matrix mat3 = mat2 * 3;
//  Matrix mat3 = mat2;
//  mat1 += mat2;
//  std::cout << "rows: " << mat1.get_rows () << ", ";
//  std::cout << "cols: " << mat1.get_cols () << std::endl;
//  mat1.plain_print ();
//  std::cout <<mat1[40]<<std::endl;
//  std::cout <<mat1(3,2)<<std::endl;
//  std::cout << "rows: " << mat4.get_rows () << ", ";
//  std::cout << "cols: " << mat4.get_cols () << std::endl;
//  mat4.plain_print();
//  std::cout <<mat4;
//  std::cout<<(readFileToMatrix ("/Users/elilevinkopf/CLionProjects/ex5-eli.levinkopf/images/im1", mat1));



  return 0;
}

//int main ()
//{
//  std::ifstream is;
//  is.open("/Users/elilevinkopf/CLionProjects/ex5-eli.levinkopf/images/im0", std::ios::in | std::ios::binary | std::ios::ate);
//  if (is)
//	{
//	  // get length of file:
//	  is.seekg (0, is.end);
//	  int length = is.tellg ();
//	  std::cout<<length<<std::endl;
//	  is.seekg (0, is.beg);
//
//	  // allocate memory:
//	  char *buffer = new char[length];
//
//	  // read data as a block:
//	  is.read (buffer, length);
//
//	  is.close ();
//
//	  // print content:
//	  std::cout.write (buffer, length);
//
//	  delete[] buffer;
//	}
//
//
//  return 0;
//}


