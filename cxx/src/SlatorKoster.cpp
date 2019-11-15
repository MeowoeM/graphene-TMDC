#include "SlatorKoster.h"

// Constructor
SlatorKoster::SlatorKoster() 
	: xMin(-16.0)
	, xMax( 16.0)
	, yMin(-16.0)
	, yMax( 16.0)
	, m(256)
	, n(256)
	{}

SlatorKoster::~SlatorKoster(){}

void SlatorKoster::setParameter(double V_pppi0, 
						   double V_ppsigma0, 
						   double V_pdpi0, 
						   double V_pdsigma0, 
						   double r_0, 
						   double r_0m, 
						   double d_cs, 
						   double d_moc,
						   double d,
						   double dm)
{
	this->V_pppi0 = V_pppi0;
	this->V_ppsigma0 = V_ppsigma0;
	this->V_pdpi0 = V_pdpi0;
	this->V_pdsigma0 = V_pdsigma0;
	this->r_0 = r_0;
	this->r_0m = r_0m;
	this->d_cs = d_cs;
	this->d_moc = d_moc;
	this->d = d;
	this->dm = dm;
}

void SlatorKoster::setIntegrateRegion(double xMin, double xMax, double yMin, double yMax)
{
	this->xMin = xMin;
	this->xMax = xMax;
	this->yMin = yMin;
	this->yMax = yMax;
}

void SlatorKoster::setIntegrateInterval(int m, int n)
{
	SlatorKoster::m = m;
	SlatorKoster::n = n;
}

double SlatorKoster::V_pppi(double r)
{
	return this->V_pppi0 * exp(-(r - this->d_cs) / this->r_0);
}

double SlatorKoster::V_ppsigma(double r)
{
	return this->V_ppsigma0 * exp(-(r - this->d_cs) / this->r_0);
}

double SlatorKoster::V_pdpi(double r)
{
	return this->V_pdpi0 * exp(-(r - this->d_moc) / this->r_0m);
}

double SlatorKoster::V_pdsigma(double r)
{
	return this->V_pdsigma0 * exp(-(r - this->d_moc) / this->r_0m);
}

double SlatorKoster::E_xz(double r, double l, double n)
{
	return l * n * (this->V_ppsigma(r) - this->V_pppi(r));
}

double SlatorKoster::E_zz(double r, double n)
{
	return n * n * this->V_ppsigma(r) + (1.0 - n * n) * this->V_pppi(r);
}

double SlatorKoster::E_z_xz(double r, double l, double n)
{
	return sqrt(3.0) * n * n * l * this->V_pdsigma(r) +
		   l * (1 - 2.0 * n * n) * this->V_pdpi(r);
}

double SlatorKoster::E_z_xy(double r, double l, double m, double n)
{
	return sqrt(3.0) * l * m * n * this->V_pdsigma(r) -
		   2.0 * l * m * n * this->V_pdpi(r);
}

double SlatorKoster::E_z_x2y2(double r, double l, double m, double n)
{
	return 0.5 * sqrt(3.0) * n * (l * l - m * m) * this->V_pdsigma(r) -
		   n * (l * l - m * m) * this->V_pdpi(r);
}

double SlatorKoster::E_z_z2(double r, double l, double m, double n)
{
	return n * (n * n - 0.5 * (l * l + m * m)) * this->V_pdsigma(r) +
		   sqrt(3.0) * n * (l * l + m * m) * this->V_pdpi(r);
}

double SlatorKoster::ft_E_xz(double kx, double ky)
{
	return simpson2d<double, double>([this, kx, ky](double x, double y)
		{
			double r = sqrt(x * x + y * y + this->d * this->d);
			return this->E_xz(r, x / r, this->d / r) * sin(x * kx + y * ky);
		}, 
		this->xMin, 
		this->xMax, 
		this->yMin, 
		this->yMax, 
		this->m, 
		this->n
	);
}

double SlatorKoster::ft_E_yz(double kx, double ky)
{
	return simpson2d<double, double>([this, kx, ky](double x, double y)
		{
			double r = sqrt(x * x + y * y + this->d * this->d);
			return this->E_xz(r, y / r, this->d / r) * sin(x * kx + y * ky);
		}, 
		this->xMin, 
		this->xMax, 
		this->yMin, 
		this->yMax, 
		this->m, 
		this->n
	);
}

double SlatorKoster::ft_E_zz(double kx, double ky)
{
	return simpson2d<double, double>([this, kx, ky](double x, double y)
		{
			double r = sqrt(x * x + y * y + this->d * this->d);
			return this->E_zz(r, this->d / r) * cos(x * kx + y * ky);
		}, 
		this->xMin, 
		this->xMax, 
		this->yMin, 
		this->yMax, 
		this->m, 
		this->n
	);
}

double SlatorKoster::ft_E_zz2(double kx, double ky, double V_pppi0, double V_ppsigma0, double a0, double d0, double delta0, double d)
{
	return simpson2d<double, double>([this, kx, ky](double x, double y)
	{
		double r = sqrt(x * x + y * y + 3.35 * 3.35);
		double n = 3.35 / r;
		return (-2.7 * exp(-(r - 1.42) / 0.45255) * (1 - n * n) +\
		0.48 * exp(-(r - 3.35) / 0.45255) * n * n) *\
		cos(x * kx + y * ky);
	}, 
	this->xMin, 
	this->xMax, 
	this->yMin, 
	this->yMax, 
	this->m, 
	this->n
	);
}

double SlatorKoster::ft_E_z_xz(double kx, double ky)
{
	return simpson2d<double, double>([this, kx, ky](double x, double y)
		{
			double r = sqrt(x * x + y * y + this->dm * this->dm);
			return this->E_z_xz(r, x / r, this->dm / r) * sin(x * kx + y * ky);
		}, 
		this->xMin, 
		this->xMax, 
		this->yMin, 
		this->yMax, 
		this->m, 
		this->n
	);
}

double SlatorKoster::ft_E_z_yz(double kx, double ky)
{
	return simpson2d<double, double>([this, kx, ky](double x, double y)
		{
			double r = sqrt(x * x + y * y + this->dm * this->dm);
			return this->E_z_xz(r, y / r, this->dm / r) * sin(x * kx + y * ky);
		}, 
		this->xMin, 
		this->xMax, 
		this->yMin, 
		this->yMax, 
		this->m, 
		this->n
	);
}

double SlatorKoster::ft_E_z_xy(double kx, double ky)
{
	return simpson2d<double, double>([this, kx, ky](double x, double y)
		{
			double r = sqrt(x * x + y * y + this->dm * this->dm);
			return this->E_z_xy(r, x / r, y / r, this->dm / r) * cos(x * kx + y * ky);
		}, 
		this->xMin, 
		this->xMax, 
		this->yMin, 
		this->yMax, 
		this->m, 
		this->n
	);
}

double SlatorKoster::ft_E_z_x2y2(double kx, double ky)
{
	return simpson2d<double, double>([this, kx, ky](double x, double y)
		{
			double r = sqrt(x * x + y * y + this->dm * this->dm);
			return this->E_z_x2y2(r, x / r, y / r, this->dm / r) * cos(x * kx + y * ky);
		}, 
		this->xMin, 
		this->xMax, 
		this->yMin, 
		this->yMax, 
		this->m, 
		this->n
	);
}

double SlatorKoster::ft_E_z_z2(double kx, double ky)
{
	return simpson2d<double, double>([this, kx, ky](double x, double y)
		{
			double r = sqrt(x * x + y * y + this->dm * this->dm);
			return this->E_z_z2(r, x / r, y / r, this->dm / r) * cos(x * kx + y * ky);
		}, 
		this->xMin, 
		this->xMax, 
		this->yMin, 
		this->yMax, 
		this->m, 
		this->n
	);
}