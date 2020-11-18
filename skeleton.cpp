#include<boost/shared_ptr.hpp>
#include<CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include<CGAL/Polygon_2.h>
#include<CGAL/create_straight_skeleton_2.h>
#include<CGAL/draw_polygon_2.h>
#include "print.h"
typedef CGAL::Exact_predicates_inexact_constructions_kernel K ;
typedef K::Point_2                   Point ;
typedef CGAL::Polygon_2<K>           Polygon_2 ;
typedef CGAL::Straight_skeleton_2<K> Ss ;
typedef boost::shared_ptr<Ss> SsPtr ;
int main()
{
  Polygon_2 poly ;

  int k = 2;
  if (k==0) {
      poly.push_back( Point(-2,-1) ) ;
      poly.push_back( Point(2,-1) ) ;
      poly.push_back( Point(2,1) ) ;
      poly.push_back( Point(-2,1) ) ;
  } else if (k==1) {
      poly.push_back( Point(-5,-1) ) ;
      poly.push_back( Point(5,-1) ) ;
      poly.push_back( Point(5, 1) ) ;
      poly.push_back( Point(1, 1) ) ;
      poly.push_back( Point(0, 0) ) ;
      poly.push_back( Point(-1, 1) ) ;
      poly.push_back( Point(-5, 1) ) ;
} else {
poly.push_back(Point(4.13124,0.100418));
poly.push_back(Point(4.71887,-0.00509644));
poly.push_back(Point(5.22809,-0.180969));
poly.push_back(Point(5.65889,-0.427185));
poly.push_back(Point(6.00159,-0.738312));
poly.push_back(Point(6.24637,-1.10875));
poly.push_back(Point(6.39323,-1.5385));
poly.push_back(Point(6.4422,-2.02759));
poly.push_back(Point(6.43372,-2.23207));
poly.push_back(Point(6.40826,-2.42511));
poly.push_back(Point(6.36586,-2.60672));
poly.push_back(Point(6.30649,-2.77689));
poly.push_back(Point(6.2317,-2.93646));
poly.push_back(Point(6.14291,-3.08629));
poly.push_back(Point(6.04015,-3.22636));
poly.push_back(Point(5.92339,-3.35669));
poly.push_back(Point(5.78841,-3.47939));
poly.push_back(Point(5.63097,-3.59657));
poly.push_back(Point(5.45107,-3.70824));
poly.push_back(Point(5.24869,-3.81439));
poly.push_back(Point(5.00119,-3.92017));
poly.push_back(Point(4.68587,-4.03059));
poly.push_back(Point(4.30273,-4.14566));
poly.push_back(Point(3.85179,-4.2654));
poly.push_back(Point(3.38387,-4.38406));
poly.push_back(Point(3.00409,-4.48917));
poly.push_back(Point(2.71246,-4.5807));
poly.push_back(Point(2.50899,-4.65869));
poly.push_back(Point(2.35939,-4.7337));
poly.push_back(Point(2.22926,-4.81635));
poly.push_back(Point(2.11864,-4.9066));
poly.push_back(Point(2.0275,-5.00449));
poly.push_back(Point(1.95631,-5.11302));
poly.push_back(Point(1.90547,-5.23509));
poly.push_back(Point(1.87495,-5.37071));
poly.push_back(Point(1.86479,-5.5199));
poly.push_back(Point(1.88937,-5.75809));
poly.push_back(Point(1.96312,-5.96407));
poly.push_back(Point(2.08603,-6.13783));
poly.push_back(Point(2.25809,-6.27939));
poly.push_back(Point(2.48192,-6.38916));
poly.push_back(Point(2.75996,-6.46756));
poly.push_back(Point(3.09225,-6.51462));
poly.push_back(Point(3.47879,-6.53029));
poly.push_back(Point(3.83289,-6.51398));
poly.push_back(Point(4.14926,-6.46501));
poly.push_back(Point(4.42793,-6.38342));
poly.push_back(Point(4.6689,-6.2692));
poly.push_back(Point(4.86958,-6.12448));
poly.push_back(Point(5.02747,-5.95137));
poly.push_back(Point(5.14253,-5.74983));
poly.push_back(Point(5.2148,-5.5199));
poly.push_back(Point(6.31329,-5.65559));
poly.push_back(Point(6.18553,-6.09468));
poly.push_back(Point(5.99207,-6.46935));
poly.push_back(Point(5.73288,-6.77959));
poly.push_back(Point(5.40799,-7.02539));
poly.push_back(Point(5.01915,-7.2123));
poly.push_back(Point(4.56799,-7.34579));
poly.push_back(Point(4.05453,-7.42589));
poly.push_back(Point(3.47879,-7.45259));
poly.push_back(Point(2.83479,-7.41974));
poly.push_back(Point(2.27257,-7.3212));
poly.push_back(Point(1.79213,-7.15694));
poly.push_back(Point(1.39349,-6.92699));
poly.push_back(Point(1.08051,-6.63435));
poly.push_back(Point(0.856949,-6.28197));
poly.push_back(Point(0.722809,-5.86981));
poly.push_back(Point(0.678085,-5.39789));
poly.push_back(Point(0.693771,-5.13724));
poly.push_back(Point(0.740814,-4.89777));
poly.push_back(Point(0.819229,-4.67949));
poly.push_back(Point(0.928986,-4.48239));
poly.push_back(Point(1.06653,-4.30289));
poly.push_back(Point(1.22821,-4.13737));
poly.push_back(Point(1.41408,-3.98584));
poly.push_back(Point(1.6241,-3.8483));
poly.push_back(Point(1.88412,-3.71715));
poly.push_back(Point(2.22002,-3.58472));
poly.push_back(Point(2.63177,-3.451));
poly.push_back(Point(3.11938,-3.31599));
poly.push_back(Point(3.99419,-3.08549));
poly.push_back(Point(4.30356,-2.99141));
poly.push_back(Point(4.56717,-2.88544));
poly.push_back(Point(4.785,-2.76761));
poly.push_back(Point(4.95709,-2.63789));
poly.push_back(Point(5.08765,-2.49211));
poly.push_back(Point(5.18089,-2.32599));
poly.push_back(Point(5.23685,-2.13951));
poly.push_back(Point(5.25549,-1.93269));
poly.push_back(Point(5.22858,-1.66565));
poly.push_back(Point(5.14784,-1.43422));
poly.push_back(Point(5.01328,-1.2384));
poly.push_back(Point(4.82489,-1.07819));
poly.push_back(Point(4.57843,-0.953598));
poly.push_back(Point(4.26967,-0.864594));
poly.push_back(Point(3.89859,-0.811188));
poly.push_back(Point(3.46519,-0.793396));
poly.push_back(Point(3.05492,-0.810562));
poly.push_back(Point(2.69212,-0.862045));
poly.push_back(Point(2.37677,-0.947861));
poly.push_back(Point(2.10889,-1.06799));
poly.push_back(Point(1.88556,-1.22505));
poly.push_back(Point(1.70377,-1.42152));
poly.push_back(Point(1.56351,-1.65739));
poly.push_back(Point(1.4648,-1.93269));
poly.push_back(Point(0.38649,-1.7224));
poly.push_back(Point(0.530807,-1.27591));
poly.push_back(Point(0.739975,-0.892563));
poly.push_back(Point(1.01396,-0.572357));
poly.push_back(Point(1.3528,-0.315292));
poly.push_back(Point(1.76329,-0.118027));
poly.push_back(Point(2.2522,0.0228729));
poly.push_back(Point(2.81949,0.107407));
poly.push_back(Point(3.46519,0.13559));

poly.reverse_orientation();
  }

    if (!poly.is_simple()) {
        std::cout << "POLYGON IS NOT SIMPLE\n";
    }


  
  

  SsPtr ass = CGAL::create_interior_straight_skeleton_2(poly);
  
  
  //double lMaxOffset = 5 ;
  //SsPtr ass = CGAL::create_exterior_straight_skeleton_2(lMaxOffset, poly);
  
  //print_straight_skeleton(*ass);
  
  //print_off_straight_skeleton(*ass);
  
  test9(*ass, 0.125);
  return 0;
}
