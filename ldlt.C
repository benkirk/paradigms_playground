#include "programming_paradigms_config.h"

#ifdef HAVE_OPENMP
#ifdef HAVE_EIGEN


#include <iostream>
#include <omp.h>
#include <Eigen/Core>
#include <Eigen/Dense>



int main (int argc, char **argv)
{

  const unsigned int N  = (argc == 1) ? 10 : std::atoi(argv[1]);
  const unsigned int MT = (argc != 3) ?  1 : std::atoi(argv[2]);

  Eigen::setNbThreads(MT);

  std::cout << "max_threads: " << MT << std::endl;

  //std::cout << "N, MT=" << N << ", " << MT << std::endl;

  const double t_tot_start = omp_get_wtime();

  Eigen::MatrixXd _tmp = Eigen::MatrixXd::Random(N,N), A = _tmp + _tmp.transpose();
  Eigen::MatrixXd B = Eigen::MatrixXd::Random(N,1);
  Eigen::LDLT<Eigen::MatrixXd> llt;

  //std::cout << "Here is the invertible matrix A:" << std::endl << A << std::endl;
  std::cout << "norm(A-A^T): " << (A - A.transpose()).norm() << std::endl;
  //std::cout << "Here is the matrix B:" << std::endl << B << std::endl;

  const double t_ops_start = omp_get_wtime();

  llt.compute(A);
  Eigen::MatrixXd X = llt.solve(B);

  const double t_end = omp_get_wtime();



  //std::cout << "Here is the (unique) solution X to the equation A.X=B:" << std::endl << X << std::endl;
  std::cout << "Relative error: " << (A*X-B).norm() / B.norm() << std::endl;

  std::cout << "Total time: "      << (t_end - t_tot_start) << std::endl
            << "Operations time: " << (t_end - t_ops_start) << std::endl;


 return 0;
}


#endif // #ifdef HAVE_EIGEN
#endif // #ifdef HAVE_OPENMP
