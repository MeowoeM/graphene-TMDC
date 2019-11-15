#include "SlatorKoster.h"
#include "iostream"
#include "random"
#include "functional"
#include <ctime>

int main(int argc, char const *argv[])
{
	std::random_device r;
	std::default_random_engine generator{r()};
	std::uniform_real_distribution<double> distribution(-2.0, 2.0);
	auto rand = std::bind(distribution, generator);

	double k[2];
	k[0] = rand();
	k[1] = rand();
	double z = rand();
	double R = sqrt(k[0] * k[0] + k[1] * k[1] + z * z);

	// std::cout << R << ", " << k[0] / R << ", " << k[1] / R << ", " << z / R << '\n';

	int start_s=clock();
 
	SlatorKoster sk;
	sk.setParameter(-1.449281487743026,
				     5.106991909189713,
				     1.12839749441,
				    -2.93166268717,
				     0.790415957064,
				     0.894212338239,
				     1.82,
				     2.059,
				     2.059,
				     2.059);

	// std::cout << sk.E_z_xy(R, k[0] / R, k[1] / R, z / R) 	<< '\t'
	// 		  << sk.E_z_x2y2(R, k[0] / R, k[1] / R, z / R) 	<< '\t'
	// 		  << sk.E_z_xz(R, k[0] / R, z / R) 				<< '\t'
	// 		  << sk.E_z_z2(R, k[0] / R, k[1] / R, z / R) 	<< '\t'
	// 		  << sk.E_zz(R, z / R) 							<< '\t'
	// 		  << sk.E_xz(R, k[0] / R, z / R) 				<< std::endl;

	std::cout.precision(17);
	std::cout << std::fixed << k[0] << ", " << k[1] << std::endl;
	std::cout << "E_xz:\t" << std::fixed << sk.ft_E_xz(k[0], k[1]) << std::endl;
	std::cout << "E_yz:\t" << std::fixed << sk.ft_E_yz(k[0], k[1]) << std::endl;
	std::cout << "E_zz:\t" << std::fixed << sk.ft_E_zz(k[0], k[1]) << std::endl;
	std::cout << "E_z_xz:\t" << std::fixed << sk.ft_E_z_xz(k[0], k[1]) << std::endl;
	std::cout << "E_z_yz:\t" << std::fixed << sk.ft_E_z_yz(k[0], k[1]) << std::endl;
	std::cout << "E_z_xy:\t" << std::fixed << sk.ft_E_z_xy(k[0], k[1]) << std::endl;
	std::cout << "E_z_x2y2:\t" << std::fixed << sk.ft_E_z_x2y2(k[0], k[1]) << std::endl;
	std::cout << "E_z_z2:\t" << std::fixed << sk.ft_E_z_z2(k[0], k[1]) << std::endl;

	int stop_s=clock();
	std::cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << std::endl;

	sk.setParameter(-1.449281487743026,
				     5.106991909189713,
				     1.12839749441,
				    -2.93166268717,
				     0.390415957064,
				     0.894212338239,
				     1.82,
				     2.059,
				     2.059,
				     2.059);

	std::cout.precision(17);
	std::cout << std::fixed << k[0] << ", " << k[1] << std::endl;
	std::cout << "E_xz:\t" << std::fixed << sk.ft_E_xz(k[0], k[1]) << std::endl;
	std::cout << "E_yz:\t" << std::fixed << sk.ft_E_yz(k[0], k[1]) << std::endl;
	std::cout << "E_zz:\t" << std::fixed << sk.ft_E_zz(k[0], k[1]) << std::endl;
	std::cout << "E_z_xz:\t" << std::fixed << sk.ft_E_z_xz(k[0], k[1]) << std::endl;
	std::cout << "E_z_yz:\t" << std::fixed << sk.ft_E_z_yz(k[0], k[1]) << std::endl;
	std::cout << "E_z_xy:\t" << std::fixed << sk.ft_E_z_xy(k[0], k[1]) << std::endl;
	std::cout << "E_z_x2y2:\t" << std::fixed << sk.ft_E_z_x2y2(k[0], k[1]) << std::endl;
	std::cout << "E_z_z2:\t" << std::fixed << sk.ft_E_z_z2(k[0], k[1]) << std::endl;

	return 0;
}