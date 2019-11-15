#ifndef SLATORKOSTER_H
#define SLATORKOSTER_H

#include <math.h>
#include "simpson2d.h"

class SlatorKoster
{
public:
	SlatorKoster();
	~SlatorKoster();
	void setParameter(double, double, double, double, double, double, double, double, double, double);
	double V_pppi(double r);
	double V_ppsigma(double r);
	double V_pdpi(double r);
	double V_pdsigma(double r);
	double E_xz(double r, double l, double n);
	double E_zz(double r, double n);
	double E_z_xz(double r, double l, double n);
	double E_z_xy(double r, double l, double m, double n);
	double E_z_x2y2(double r, double l, double m, double n);
	double E_z_z2(double r, double l, double m, double n);

	double ft_E_xz(double kx, double ky);
	double ft_E_yz(double kx, double ky);
	double ft_E_zz(double kx, double ky);
	double ft_E_zz2(double kx, double ky, double V_pppi0 = -2.7, double V_ppsigma0 = 0.48, double a0 = 1.42, double d0 = 3.35, double delta0 = 0.45264, double d = 0.45255);
	double ft_E_z_xz(double kx, double ky);
	double ft_E_z_yz(double kx, double ky);
	double ft_E_z_xy(double kx, double ky);
	double ft_E_z_x2y2(double kx, double ky);
	double ft_E_z_z2(double kx, double ky);

	void setIntegrateRegion(double xMin, double xMax, double yMin, double yMax);
	void setIntegrateInterval(int m, int n);

private:
	double d;
	double dm;
	double V_pppi0;
	double V_ppsigma0;
	double V_pdpi0;
	double V_pdsigma0;
	double r_0;
	double r_0m;
	double d_cs;
	double d_moc;
	double xMin, xMax, yMin, yMax;
	int m, n;
};

#endif 