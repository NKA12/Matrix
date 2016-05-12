#include "matrixOperations.hpp"
#include <iostream>



int  main()
{




nka::Matrix<int> myMatrix(2,3);
        myMatrix[0][0]=12;
        myMatrix[0][1]=11;
        myMatrix[0][2]=11;
        myMatrix[1][2]=1;
        myMatrix[1][0]=2;
        myMatrix[1][1]=4;


		//Test isSquare 
        std::cout << (nka::isSquareMatrix<int>(myMatrix) )<< std::endl;
        std::cout << myMatrix<< std::endl;

        nka::Matrix<int> myMatrix2(2,3);
        myMatrix2[0][0]=1;
        myMatrix2[0][1]=1;
        myMatrix2[0][2]=2;
        myMatrix2[1][0]=3;
        myMatrix2[1][1]=0;
        myMatrix2[1][2]=0;
		std::cout << myMatrix2<< std::endl;
		//test addition 
		std::cout << nka::addMatrix<int>(myMatrix , myMatrix2) << std::endl;

		//test multiplication 
		std::cout << nka::MulMatrixNumber<int>(myMatrix , 2) << std::endl;
		//test multiplication 2 
		nka::Matrix<int> myMatrix1(3,2);
		myMatrix1[0][0]=5;
        myMatrix1[0][1]=6;
        myMatrix1[1][0]=3;
        myMatrix1[1][1]=4;
        myMatrix1[2][0]=2;
        myMatrix1[2][1]=7;

	std::cout << myMatrix1[2][0]  << "    "  << myMatrix1[2][1] << std::endl;
  std::cout << myMatrix1<< std::endl;
		std::cout << nka::MulMatrix<int>(myMatrix1 , myMatrix2) << std::endl;
	std::cout << "------------trans---------------------" << std::endl;
	std::cout << nka::transMatrix(myMatrix1) << std::endl;


	nka::Matrix<int> myMatrix3(4,5);
        myMatrix3[0][0]=12;
        myMatrix3[0][1]=11;
        myMatrix3[0][2]=1;
        myMatrix3[0][3]=4;
        myMatrix3[0][4]=6;
        myMatrix3[1][2]=1;
        myMatrix3[1][0]=2;
        myMatrix3[1][1]=4;
        myMatrix3[1][3]=5;
        myMatrix3[1][4]=0;
	
        myMatrix3[2][4]=3;
        myMatrix3[2][2]=1;
        myMatrix3[2][0]=6;
        myMatrix3[2][1]=4;
        myMatrix3[2][3]=0;
	
	
        myMatrix3[3][4]=-3;
        myMatrix3[3][2]=0;
        myMatrix3[3][0]=2;
        myMatrix3[3][1]=1;
        myMatrix3[3][3]=0;

	std::cout << "----------------Matrix3-----------------" << std::endl;
  	std::cout << myMatrix3<< std::endl;
	
	std::cout << "-----------------subMatrix----------------" << std::endl;
	std::cout << nka::getSubMatrix(myMatrix3,2,1) << std::endl;


        nka::Matrix<int> myMatrixDet(3,3);
        myMatrixDet[0][0]=-3;
        myMatrixDet[0][1]=5;
        myMatrixDet[0][2]=6;
        myMatrixDet[1][0]=-1;
        myMatrixDet[1][1]=2;
        myMatrixDet[1][2]=2;
        myMatrixDet[2][0]=1;
        myMatrixDet[2][1]=-1;
        myMatrixDet[2][2]=-1;
		std::cout << myMatrixDet<< std::endl;
		//test determinant 
		std::cout << nka::getMatrixDeterminant(myMatrixDet,0) << std::endl;

        nka::Matrix<int> myMatrixDet1(4,4);
        myMatrixDet1[0][0]=1;
        myMatrixDet1[0][1]=5;
        myMatrixDet1[0][2]=2;
        myMatrixDet1[0][3]=1;
        myMatrixDet1[1][0]=2;
        myMatrixDet1[1][1]=-3;
        myMatrixDet1[1][2]=5;
        myMatrixDet1[1][3]=1;
        myMatrixDet1[2][0]=2;
        myMatrixDet1[2][1]=8;
        myMatrixDet1[2][2]=5;
        myMatrixDet1[2][3]=6;
        myMatrixDet1[3][0]=1;
        myMatrixDet1[3][1]=2;
        myMatrixDet1[3][2]=3;
        myMatrixDet1[3][3]=-5;
		std::cout << myMatrixDet1<< std::endl;
		//test determinant 
		std::cout << nka::getMatrixDeterminant(myMatrixDet1,0) << std::endl;

	std::cout << "---------------------cofactor-----------------------"<<std::endl;
	std::cout << nka::cofactorMatrix(myMatrixDet)<< std::endl;
	std::cout << "---------------------inverse-----------------------"<<std::endl;
	std::cout << nka::inverseMatrix(myMatrixDet) << std::endl;
	std::cout << "---------------------orthogonal-----------------------"<<std::endl;
	
        nka::Matrix<int> myMatrixOrt(3,3);
        myMatrixOrt[0][0]=0;
        myMatrixOrt[0][1]=1;
        myMatrixOrt[0][2]=0;
        myMatrixOrt[1][0]=0;
        myMatrixOrt[1][1]=0;
        myMatrixOrt[1][2]=1;
        myMatrixOrt[2][0]=1;
        myMatrixOrt[2][1]=0;
        myMatrixOrt[2][2]=0;
	std::cout << nka::inverseMatrix(myMatrixOrt) << std::endl;
	std::cout << nka::transMatrix(myMatrixOrt) << std::endl;
	std::cout << "---------------------------trasn-------------------" << std::endl;


	std::cout << nka::isOrthogonalMatrix(myMatrixOrt) << std::endl;
	std::cout << "---------------------------original-------------------" << std::endl;
	std::cout << myMatrixOrt << std::endl;
	std::cout << "---------------------------swapLine-------------------" << std::endl;
	std::cout << nka::swapLines(myMatrixOrt, 1,2) << std::endl;
	std::cout << "---------------------------mulLineScalar-------------------" << std::endl;
	std::cout << nka::mulLineScalar(myMatrixOrt,3.5 ,1) << std::endl;

return 0; 

}
