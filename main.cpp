#include <iostream>

#include <../gsoc/boost/boost/convex_hull.hpp>

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/polygon.hpp>
#include <boost/geometry/geometries/adapted/boost_tuple.hpp>

BOOST_GEOMETRY_REGISTER_BOOST_TUPLE_CS(cs::cartesian)

namespace bg = boost::geometry;
int main()
{
	typedef boost::tuple<double, double> point;
    typedef bg::model::multi_point<point> mpoints;

    mpoints mps;
    bg::read_wkt("MULTIPOINT((2.0 1.3)"
    	", (2.4 1.7), (2.8 1.8), (3.4 1.2), (3.7 1.6),(3.4 2.0), (4.1 3.0)"
        ", (5.3 2.6), (5.4 1.2), (4.9 0.8), (2.9 0.7),(2.0 1.3))", mps);

    mpoints hull;

    convex_hull(mps, hull);

    std::cout << bg::num_points(hull) << std::endl;c

    typedef typename boost::range_const_iterator<mpoints>::type iterator;
    for ( iterator it = boost::begin(hull) ; it != boost::end(hull) ; ++it ) {
        std::cout << bg::get<0>(*it) << " " << bg::get<1>(*it) << std::endl;
    }
    return 0;
}