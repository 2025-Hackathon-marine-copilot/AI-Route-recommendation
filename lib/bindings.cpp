#define BOOST_PYTHON_STATIC_LIB

#include <boost/python.hpp>

#include "libnacho.h"

BOOST_PYTHON_MODULE(libnacho)
{
        // class Point
        boost::python::class_<nacho::Point>("Point", boost::python::init<double, double>())
                .boost::python::def_readwrite("lat", &nacho::Point::lat)
                .boost::python::def_readwrite("lon", &nacho::Point::lon);

        // enum Precision
        boost::python::enum_<nacho::Precision>("Precision")
                .boost::python::value("M", nacho::Precision::M)
                .boost::python::value("HM", nacho::Precision::HM)
                .boost::python::value("KM", nacho::Precision::KM)
                .boost::python::value("HKM", nacho::Precision::HKM);

        // Function
        boost::python::def("inner_map", inner_map);
}
