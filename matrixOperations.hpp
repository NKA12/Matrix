#ifndef __MATRIX_OPERATIONS_HPP__
#define __MATRIX_OPERATIONS_HPP__

#include "Matrix.hpp"
#include <utility>
namespace nka
{

	
		//Matrix state
		template <typename T, class = typename std::enable_if<(std::is_arithmetic<T>::value  ), T>::type >
		bool isSquareMatrix(const Matrix<T>& _matrix)
		{
			return ( (_matrix.getMatrixLength() == _matrix.getMatrixHeight()) && _matrix.getMatrixHeight() >  0 ) ;
		}
		template <typename T, class = typename std::enable_if<(std::is_arithmetic<T>::value  ), T>::type >
		bool isUnitaryMatrix(const Matrix<T>& _matrix)
		{
			if(!isDiagonalMatrix(_matrix))
				return false; 
			
			for (unsigned int i = 0 ; i < _matrix.getMatrixLength() ; ++i) 
			{
				if(_matrix[i][i] != 1 )
					return false; 
			}
			return true; 
		}
		template <typename T, class = typename std::enable_if<(std::is_arithmetic<T>::value  ), T>::type >
		bool isDiagonalMatrix(const Matrix<T>& _matrix)
		{
			if(!isSquareMatrix(_matrix) ||
			   !isTriangSupMatrix(_matrix)||
			   !isTriangInfMatrix(_matrix))
				return false; 
			return true; 
		}
		template <typename T, class = typename std::enable_if<(std::is_arithmetic<T>::value  ), T>::type >
		bool isTriangSupMatrix(const Matrix<T>& _matrix)
		{
			if(!isSquareMatrix(_matrix))
				return false; 
			for (unsigned int i = 0 ; i < _matrix.getMatrixLength() -1 ; ++i) 
			{
				for (unsigned int j = i+1 ; j < _matrix.getMatrixHeight() ; ++j ) 
				{
					if(_matrix[i][j] != 0 )
						return false; 
				}
			
			}
			return true; 
		}
		template <typename T, class = typename std::enable_if<(std::is_arithmetic<T>::value  ), T>::type >
		bool isTriangInfMatrix(const Matrix<T>& _matrix)
		{
			if(!isSquareMatrix(_matrix))
				return false; 
			for (unsigned int i = 1 ; i < _matrix.getMatrixLength() ; ++i) 
			{
				for (unsigned int j = 0 ; j < i ; ++j ) 
				{
					if(_matrix[i][j] != 0 )
						return false; 
				}
			
			}
			return true; 
		}
		template <typename T, class = typename std::enable_if<(std::is_arithmetic<T>::value  ), T>::type >
		bool isSymetricMatrix(const Matrix<T>& _matrix)
		{
			if(!isDiagonalMatrix(_matrix))
				return false; 
			for (unsigned int i = 0 ; i < _matrix.getMatrixLength() ; ++i) 
			{
				if(!std::equal(_matrix.getRow(i).begin(), _matrix.getRow(i).end(),_matrix.getColumn(i).begin()))
					return false; 
			}					
			return true; 
		
		}
		template <typename T, class = typename std::enable_if<(std::is_arithmetic<T>::value  ), T>::type >
		bool isReversableMatrix(const Matrix<T>& _matrix)
		{
		
		}
		template <typename T, class = typename std::enable_if<(std::is_arithmetic<T>::value  ), T>::type >
		bool isOrthogonalMatrix(const Matrix<T>& _matrix)
		{
			return  (inverseMatrix (_matrix) == transMatrix(_matrix)); 
		}

		//operations return a ref or a copy ?
		template <typename T, class = typename std::enable_if<(std::is_arithmetic<T>::value  ), T>::type >
		Matrix<T> addMatrix(const Matrix<T>& _first,const Matrix<T>& _last)
		{
			//same dimensions 
			if((_first.getMatrixLength() != _last.getMatrixLength()) || (_first.getMatrixHeight() != _last.getMatrixHeight()) )
			{
				//LOG ERROR , THROW EXCEPTION 
			}
			Matrix<T> resultMatrix(_first.getMatrixLength(),_first.getMatrixHeight()); 
			for(unsigned int i = 0 ; i < _first.getMatrixLength(); ++i )
			{
				for (unsigned int j = 0 ; j < _first.getMatrixHeight() ; ++j)
				{
					resultMatrix[i][j] = _first[i][j] + _last[i][j] ;
				}
			}
			return resultMatrix;


		}
		template <typename T, class = typename std::enable_if<(std::is_arithmetic<T>::value  ), T>::type >
		Matrix<T> subMatrix(const Matrix<T>& _first,const Matrix<T>& _last)
		{
			//same dimensions 
			if((_first.getMatrixLength() != _last.getMatrixLength()) || (_first.getMatrixHeight() != _last.getMatrixHeight()) )
			{
				//LOG ERROR , THROW EXCEPTION 
			}
			Matrix<T> resultMatrix(_first.getMatrixLength(),_first.getMatrixHeight()); 
			for(unsigned int i = 0 ; i < _first.getMatrixLength(); ++i )
			{
				for (unsigned int j = 0 ; j < _first.getMatrixHeight() ; ++j)
				{
					resultMatrix[i][j] = _first[i][j] - _last[i][j] ;
				}
			}
			return resultMatrix ;
		
		}
		template <typename T, class = typename std::enable_if<(std::is_arithmetic<T>::value  ), T>::type >
		Matrix<T> MulMatrix(const Matrix<T>& _first,const Matrix<T>& _last)
		{
			
			if(_first.getMatrixHeight() != _last.getMatrixLength() )
			{
				//LOG ERROR , THROW EXCEPTION 
			}
			
			Matrix<T> resultMatrix(_first.getMatrixLength(),_last.getMatrixHeight()); 
			for(unsigned int i = 0 ; i < _first.getMatrixLength(); ++i )
			{
				for (unsigned int j = 0 ; j < _last.getMatrixHeight() ; ++j)
				{
					T somme = 0 ; 
					for (unsigned int k = 0 ; k < _first.getMatrixHeight() ; ++k)
					{
						somme+= _first[i][k] * _last[k][j] ;
					}
					resultMatrix[i][j] = somme ; 
				}
			}
			return resultMatrix ;
		}
		template <typename T, class = typename std::enable_if<(std::is_arithmetic<T>::value  ), T>::type >
		Matrix<T> MulMatrixNumber(const Matrix<T>& _matrix,const T & _num)
		{
			Matrix<T> resultMatrix(_matrix.getMatrixLength(),_matrix.getMatrixHeight()); 
			for(unsigned int i = 0 ; i < _matrix.getMatrixLength(); ++i )
			{
				for (unsigned int j = 0 ; j < _matrix.getMatrixHeight() ; ++j)
				{
					resultMatrix[i][j] = _matrix[i][j] * _num ;
				}
			}
			return resultMatrix ;
		}
		template <typename T, class = typename std::enable_if<(std::is_arithmetic<T>::value  ), T>::type >
		Matrix<T> transMatrix(const Matrix<T>& _matrix)
		{
			if(_matrix.getMatrixHeight() == 0 || _matrix.getMatrixLength() == 0 )
			{
				//LOG THROW EXCEPTION
			}
			Matrix<T> resultMatrix(_matrix.getMatrixHeight(),_matrix.getMatrixLength());
			for(unsigned int i = 0 ; i < _matrix.getMatrixLength() ; ++i )
			{
				for(unsigned int j = 0 ; j < _matrix.getMatrixHeight() ; ++j)
				{
					resultMatrix[j][i] = _matrix[i][j]; 
				}
			}
			return resultMatrix; 
		
		}
		template <typename T, class = typename std::enable_if<(std::is_arithmetic<T>::value  ), T>::type >
        	Matrix<T> cofactorMatrix(const Matrix<T>& _matrix)
        	{

			if(_matrix.getMatrixHeight() == 0 || _matrix.getMatrixLength() == 0 )
			{
				//LOG THROW EXCEPTION
			}
			Matrix<T> resultMatrix(_matrix.getMatrixHeight(),_matrix.getMatrixLength());
			for(unsigned int i = 0 ; i < _matrix.getMatrixLength() ; ++i )
			{
				short sign = 1; 
				if(i % 2 == 0)
					sign = 1 ;
				else sign = -1 ;
				for(unsigned int j = 0 ; j < _matrix.getMatrixHeight() ; ++j)
				{
					resultMatrix[i][j] = sign * getMatrixDeterminant(getSubMatrix(_matrix,i,j),0); 
					sign = sign * -1;
				}	
			}
			return resultMatrix; 

        	}
		template <typename T, class = typename std::enable_if<(std::is_arithmetic<T>::value  ), T>::type >
		Matrix<T> inverseMatrix(const Matrix<T>& _matrix)
		{
			T det = getMatrixDeterminant(_matrix,0 ) ; 
			if(!det)
			{
				//LOG THROW EXCEPTION
			}
			Matrix<T> resultMatrix = MulMatrixNumber(transMatrix(cofactorMatrix(_matrix)),(1/getMatrixDeterminant(_matrix,0))); 
			return resultMatrix ;
		
		}
		// determinant 
		template <typename T, class = typename std::enable_if<(std::is_arithmetic<T>::value  ), T>::type >
		static T getMatrixDeterminant(const Matrix<T>& _matrix, unsigned int _row)
		{
			 	T det = 0 ;
				if(!isSquareMatrix(_matrix) || (_row > _matrix.getMatrixLength()))
				{
					//LOG THROW EXCEPTION
				}
				if(_matrix.getMatrixLength() == 2 && _matrix.getMatrixLength() == 2 )
				{
						
					det = (_matrix[0][0]*_matrix[1][1] - _matrix[0][1]*_matrix[1][0]); 
				}
				else
				{
					for (unsigned int i = 0 ; i < _matrix.getMatrixHeight() ; ++i )
					{
						if(i%2 == 0 )
						{	
							det+=_matrix[_row][i] * getMatrixDeterminant(getSubMatrix(_matrix, _row, i ), 0);//always first line
						}
						else
						{
							det-=_matrix[_row][i] * getMatrixDeterminant(getSubMatrix(_matrix, _row, i ), 0);
						}
					
					
					}
				
				}
                        
			return det;
		
		
		}
		template <typename T, class = typename std::enable_if<(std::is_arithmetic<T>::value  ), T>::type >
        	Matrix<T> getSubMatrix(const Matrix<T>& _matrix, unsigned int _row , unsigned int _col)
        {
			if((_matrix.getMatrixHeight() ) < 2 ||
			   (_matrix.getMatrixLength() < 2 )||
			   (_matrix.getMatrixLength()< _row)||
			   (_matrix.getMatrixHeight()< _col)
			   )
			{
				//LOG THROW EXCEPTION
			}

			Matrix<T> resultMatrix(_matrix.getMatrixLength()-1,_matrix.getMatrixHeight()-1);
			unsigned int row = 0 , col = 0 ; 
			for (unsigned int i = 0 ; i < _matrix.getMatrixLength() ; ++i )
			{
			
				if(i==_row)
					continue; 
				for (unsigned int j =0 ; j < _matrix.getMatrixHeight() ; ++j )
				{
					if (j==_col)
						continue; 
					resultMatrix[row][col] = _matrix[i][j] ;
					++col;	
				}
				col = 0 ;
				++row;
			}

			return resultMatrix;

        }
    	//-----------------------------------------------------------------------------
		template <typename T, class = typename std::enable_if<(std::is_arithmetic<T>::value  ), T>::type >
		Matrix<T> swapLines(const Matrix<T> & _matrix, unsigned int _first, unsigned int _second )
		{

			Matrix<T> resultMatrix(_matrix);
			std::vector<T> firstVec = _matrix.getRow(_first); 
			std::vector<T> secondVec = _matrix.getRow(_second);
			
	
			for(unsigned j = 0 ; j < resultMatrix.getMatrixHeight() ; ++j)
			{
				resultMatrix[_first][j] = secondVec[j];
				resultMatrix[_second][j] = firstVec[j];
			}
			return resultMatrix; 
			
	    	}	

		//-------------------------------------------------------------------
	template <typename U, typename T, class = typename std::enable_if<(std::is_arithmetic<T>::value  ), T>::type >
		Matrix<decltype(std::declval<T>() * std::declval<U>())> mulLineScalar(const Matrix<T> & _matrix, U _scalar, unsigned int _row)
		{

			Matrix<decltype(std::declval<T>() * std::declval<U>())> resultMatrix(_matrix.getMatrixLength(), _matrix.getMatrixHeight());
			if(!_scalar)
			{
				//LOG + EXCEPTION
			
			}
			for(unsigned int i = 0 ; i < _matrix.getMatrixLength() ;  ++i)
			{
				for (unsigned int j = 0 ; j <  resultMatrix.getMatrixHeight() ; ++j)
				{
					if( i  != _row)	
						resultMatrix[i][j] = _matrix[i][j] ;
					else
						resultMatrix[_row][j] = _scalar * _matrix[_row][j] ;
				}
			}

			return resultMatrix; 
			
	    }	



}//namespace nka


#endif 
