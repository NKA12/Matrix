#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include  <type_traits>
#include <algorithm>
#include <vector>
#include <iostream>

namespace nka
{

	/*template <typename T>
	struct isMatrixType
	{
		static const bool value = false; 
	};
	template <typename T>
	struct isMatrixType<T**>
	{
		static const bool value = true ; 
	}; */
	template <typename  T , class = typename std::enable_if<(std::is_arithmetic<T>::value  ), T>::type> 
	class Matrix
	{
	public: 
		Matrix(unsigned int _row, unsigned int _col) :mLineLength(_row), mColumnLength(_col)
		{
			mMatrix = new T*[mLineLength];
			
			for (unsigned int counter = 0 ; counter < mLineLength ; ++counter  )
			{
				mMatrix[counter] = new T[mColumnLength];	
			}
			
		} 
		~Matrix()
		{
			for (unsigned int counter = 0 ; counter < mLineLength ; ++counter  )
			{
				delete [] mMatrix[counter] ;	
			}
			delete [] mMatrix ;
		}
		
		Matrix(const Matrix& _origin)
		{
			mColumnLength = _origin.mColumnLength ; 
			mLineLength  = _origin.mLineLength ;
			mMatrix = new T*[mLineLength];
			for (unsigned int counter = 0 ; counter < mLineLength ; ++counter  )
			{
				mMatrix[counter] = new T[mColumnLength];	
			}
			for (unsigned int copyCounter = 0 ; copyCounter < mLineLength ; ++copyCounter  )
			{
				for (unsigned int i = 0 ; i < mColumnLength ; ++i)
				{
					mMatrix[copyCounter][i] = _origin.mMatrix[copyCounter][i]; 
				}
				
			}

		
		}

		const Matrix & operator =(const Matrix & _origin)
		{
			swapMatrix(*this, _origin);
			return *this ; 	
		}
		//overloading [] operator to have access using [][]
		T* operator [](unsigned int _row) const
		{
			return mMatrix[_row];
		}
		T& operator ()(unsigned int _row, unsigned int _column) 
		{
			return mMatrix[_row][_column]; 
		}
		bool operator ==(const Matrix & _matrix)
		{
			if (getMatrixLength() != _matrix.getMatrixLength() || getMatrixHeight() != _matrix.getMatrixHeight())
			{
				return false;
			}
			for (unsigned int i = 0 ; i < getMatrixLength() ; ++i)
			{
				for (unsigned int j = 0 ; j < getMatrixHeight() ; ++j)
				{
					if (mMatrix[i][j] != _matrix[i][j])
						return false; 
				}
				
			}
			return true; 
			
		}
		unsigned int getMatrixLength() const {return mLineLength; }
		unsigned int getMatrixHeight() const {return mColumnLength; }
		friend void swapMatrix(Matrix& _first, Matrix& _second)
		{
			std::swap(_first.mColumnLength, _second.mColumnLength) ; 
			std::swap(_first.mLineLength, _second.mLineLength);
			std::swap(_first.mMatrix, _second.mMatrix); //we just swap addresses
		}

		std::vector<T> getRow(unsigned int _row)const
		{
			std::vector<T> vec ; 
			//vec.resize(mColumnLength);

			for(unsigned int i = 0 ; i < mColumnLength ; ++i )
			{
				vec.push_back(mMatrix[_row][i]); 
			}
			return vec ; 
		}
		std::vector<T> getColumn(unsigned int _col) const
		{
			std::vector<T> vec ; 
			vec.resize(mLineLength);

			for(unsigned int i = 0 ; i < mLineLength ; ++i )
			{
				vec.push_back(mMatrix[i][_col]); 
			}
			return vec ; 
		}

		friend std::ostream& operator<< (std::ostream & oss , const Matrix<T> & _matrix)
		{
			for(unsigned int i = 0 ; i < _matrix.getMatrixLength() ; ++i)
			{
				for (unsigned int j = 0 ; j < _matrix.getMatrixHeight() ; ++j)
				{
					oss << _matrix[i][j] << "\t | " ; 
					
				}
				oss << std::endl;
			}
			return oss ;
		
		}
	private : 
		T** mMatrix ; 
		unsigned int mLineLength ;
		unsigned int mColumnLength; 
	
	}; 

	
	


}//namesapce nka




#endif 
