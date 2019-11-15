#include "SlatorKoster.h"
#include <boost/python.hpp>

using namespace boost::python;

BOOST_PYTHON_MODULE(SlatorKosterExt)
{
    class_<SlatorKoster>("SlatorKoster", init<double, double, double, double, double, double, double, double>())
        .def("V_pppi", &SlatorKoster::V_pppi)
        .def("V_ppsigma", &SlatorKoster::V_ppsigma)
        .def("V_pdpi", &SlatorKoster::V_pdpi)
        .def("V_pdsigma", &SlatorKoster::V_pdsigma)
        .def("E_xz", &SlatorKoster::E_xz)
        .def("E_zz", &SlatorKoster::E_zz)
        .def("E_z_xz", &SlatorKoster::E_z_xz)
        .def("E_z_xy", &SlatorKoster::E_z_xy)
        .def("E_z_x2y2", &SlatorKoster::E_z_x2y2)
        .def("E_z_z2", &SlatorKoster::E_z_z2)

        .def("ft_E_xz", &SlatorKoster::ft_E_xz)
        .def("ft_E_yz", &SlatorKoster::ft_E_yz)
        .def("ft_E_zz", &SlatorKoster::ft_E_zz)
        .def("ft_E_zz2", &SlatorKoster::ft_E_zz2)
        .def("ft_E_z_xz", &SlatorKoster::ft_E_z_xz)
        .def("ft_E_z_yz", &SlatorKoster::ft_E_z_yz)
        .def("ft_E_z_xy", &SlatorKoster::ft_E_z_xy)
        .def("ft_E_z_x2y2", &SlatorKoster::ft_E_z_x2y2)
        .def("ft_E_z_z2", &SlatorKoster::ft_E_z_z2)

        .def("setIntegrateRegion", &SlatorKoster::setIntegrateRegion)
        .def("setIntegrateInterval", &SlatorKoster::setIntegrateInterval)
    ;
}