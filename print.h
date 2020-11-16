#include <CGAL/Polygon_2.h>
#include <CGAL/Polygon_with_holes_2.h>

template<class K>
void print_point ( CGAL::Point_2<K> const& p )
{
  std::cout << "(" << p.x() << "," << p.y() << ")" ;
}

template<class K, class C>
void print_polygon ( CGAL::Polygon_2<K,C> const& poly )
{
  typedef CGAL::Polygon_2<K,C> Polygon ;
  
  std::cout << "Polygon with " << poly.size() << " vertices" << std::endl ;
  
  for( typename Polygon::Vertex_const_iterator vi = poly.vertices_begin() ; vi != poly.vertices_end() ; ++ vi )
  {
    print_point(*vi); std::cout << std::endl ;
  }
}

template<class K, class C>
void print_polygons ( std::vector< boost::shared_ptr< CGAL::Polygon_2<K,C> > > const& polies )
{
  typedef std::vector< boost::shared_ptr< CGAL::Polygon_2<K,C> > > PolygonVector ;
  
  std::cout << "Polygon list with " << polies.size() << " polygons" << std::endl ;
  
  for( typename PolygonVector::const_iterator pi = polies.begin() ; pi != polies.end() ; ++ pi )
    print_polygon(**pi);
}

template<class K, class C>
void print_polygon_with_holes ( CGAL::Polygon_with_holes_2<K,C> const& polywh )
{
  typedef CGAL::Polygon_with_holes_2<K,C> PolygonWithHoles ;
  
  std::cout << "Polygon_with_holes having " << polywh.number_of_holes() << " holes" << std::endl ;
  
  print_polygon(polywh.outer_boundary());
  
  for( typename PolygonWithHoles::Hole_const_iterator hi = polywh.holes_begin() ; hi != polywh.holes_end() ; ++ hi )
    print_polygon(*hi);
}

template<class K, class C>
void print_polygons_with_holes ( std::vector< boost::shared_ptr< CGAL::Polygon_with_holes_2<K,C> > > const& polies )
{

  typedef std::vector< boost::shared_ptr< CGAL::Polygon_with_holes_2<K,C> > > PolygonWithHolesVector ;

  std::cout << "Polygon_with_holes list with " << polies.size() << " element" << std::endl ;

  for( typename PolygonWithHolesVector::const_iterator pi = polies.begin() ; pi != polies.end() ; ++ pi )
    print_polygon_with_holes(**pi);
}


template<class K>
void print_straight_skeleton( CGAL::Straight_skeleton_2<K> const& ss )
{
  typedef CGAL::Straight_skeleton_2<K> Ss ;
  
  typedef typename Ss::Vertex_const_handle     Vertex_const_handle ;
  typedef typename Ss::Vertex_const_iterator   Vertex_const_iterator ;
  typedef typename Ss::Halfedge_const_handle   Halfedge_const_handle ;
  typedef typename Ss::Halfedge_const_iterator Halfedge_const_iterator ;
  
  Halfedge_const_handle null_halfedge ;
  Vertex_const_handle   null_vertex ;

  std::cout << "Straight skeleton with " << ss.size_of_vertices() 
            << " vertices, " << ss.size_of_halfedges()
            << " halfedges and " << ss.size_of_faces()
            << " faces" << std::endl ;

  for ( Vertex_const_iterator i = ss.vertices_begin(); i != ss.vertices_end(); ++i )
  {
      std::cout << std::distance(ss.vertices_begin(), i) << " ";
      print_point(i->point());
      std::cout << std::endl;
  }

  for ( Halfedge_const_iterator i = ss.halfedges_begin(); i != ss.halfedges_end(); ++i )
  {
    std::cout << "[" << std::distance(ss.vertices_begin(), i->opposite()->vertex()) << "]";
    print_point(i->opposite()->vertex()->point()) ;
    std::cout << "->" ;
    std::cout << "[" << std::distance(ss.vertices_begin(), i->vertex()) << "]";
    print_point(i->vertex()->point());
    std::cout << " " << ( i->is_bisector() ? "bisector" : "contour" ) << std::endl;
  }
}

template<class K>
void print_offffff_straight_skeleton( CGAL::Straight_skeleton_2<K> const& ss )
{
  typedef CGAL::Straight_skeleton_2<K> Ss ;
  typedef CGAL::Line_2<K> Line_2 ;
  
  typedef typename Ss::Vertex_const_handle     Vertex_const_handle ;
  typedef typename Ss::Vertex_const_iterator   Vertex_const_iterator ;
  typedef typename Ss::Halfedge_const_handle   Halfedge_const_handle ;
  typedef typename Ss::Halfedge_const_iterator Halfedge_const_iterator ;
  
  Halfedge_const_handle null_halfedge ;
  Vertex_const_handle   null_vertex ;

  std::cout << "Straight skeleton with " << ss.size_of_vertices() 
            << " vertices, " << ss.size_of_halfedges()
            << " halfedges and " << ss.size_of_faces()
            << " faces" << std::endl ;

  for ( Vertex_const_iterator i = ss.vertices_begin(); i != ss.vertices_end(); ++i )
  {
      std::cout << std::distance(ss.vertices_begin(), i) << " ";
      print_point(i->point());
      std::cout << " " << (i->is_skeleton() ? "skeleton" : "contour");
      std::cout << " bisector: " << std::distance(ss.halfedges_begin(), i->primary_bisector());
      
      std::cout << "\n    next edge: " << std::distance(ss.halfedges_begin(), i->primary_bisector()->next());


      Line_2 l(
              i->primary_bisector()->next()->vertex()->point(),
              i->primary_bisector()->vertex()->point()
            );
      auto d = (i->is_skeleton()) ? CGAL::squared_distance(i->point(), l) : 0.0;
      
      std::cout << " distance: " << std::sqrt(d);
      std::cout << std::endl;
  }

  for ( Halfedge_const_iterator i = ss.halfedges_begin(); i != ss.halfedges_end(); ++i )
  {
    std::cout << "[" << std::distance(ss.halfedges_begin(), i) << "] :: ";
    std::cout << "[" << std::distance(ss.vertices_begin(), i->opposite()->vertex()) << "]";
    print_point(i->opposite()->vertex()->point()) ;
    std::cout << "->" ;
    std::cout << "[" << std::distance(ss.vertices_begin(), i->vertex()) << "]";
    print_point(i->vertex()->point());
    std::cout << " " << ( i->is_bisector() ? "bisector" : "contour" ) << std::endl;
  }
}


template<class K>
void print_off_straight_skeleton( CGAL::Straight_skeleton_2<K> const& ss )
{
    typedef CGAL::Straight_skeleton_2<K> Ss ;

    typedef typename Ss::Vertex_const_handle     Vertex_const_handle ;
    typedef typename Ss::Vertex_const_iterator   Vertex_const_iterator ;
    typedef typename Ss::Halfedge_const_handle   Halfedge_const_handle ;
    typedef typename Ss::Halfedge_const_iterator Halfedge_const_iterator ;
    typedef typename Ss::Face_const_handle       Face_const_handle ;
    typedef typename Ss::Face_const_iterator     Face_const_iterator ;

    // count vertices for the floor (i.e. skeleton vertices)
    // and build an index for them
    int floor_vertices_number = 0;
    std::vector<int> floor_vertices_index(ss.size_of_vertices(), 0);
    for ( Vertex_const_iterator i = ss.vertices_begin(); i != ss.vertices_end(); ++i ) {
        if (i->is_skeleton()) {
            int d = std::distance(ss.vertices_begin(), i);
            floor_vertices_index[d] = ss.size_of_vertices() + floor_vertices_number;
            floor_vertices_number ++;
        }
    }

    // count bisector edges 
    int bisector_number = 0;
    for ( Halfedge_const_iterator i = ss.halfedges_begin(); i != ss.halfedges_end(); ++i )
    {
        if (i->is_bisector()) {
            bisector_number++;
        }
    }

    std::cout << "OFF\n";
    std::cout << ss.size_of_vertices() + floor_vertices_number
        << " " << ss.size_of_faces() * 2
        << " " << ss.size_of_halfedges() + bisector_number
        << "\n";

    for ( Vertex_const_iterator i = ss.vertices_begin(); i != ss.vertices_end(); ++i )
    {
        std::cout << i->point().x() << " " << i->point().y() << " " << i->time()
            << std::endl;
    }
    for ( Vertex_const_iterator i = ss.vertices_begin(); i != ss.vertices_end(); ++i )
    {
        if (i->is_skeleton()) {
            std::cout << i->point().x() << " " << i->point().y() << " " << 0.0
                << std::endl;
        }
    }

    for ( Face_const_iterator i = ss.faces_begin(); i != ss.faces_end(); ++i )
    {
        int vertex_count = 0;
        Halfedge_const_handle h0 = i->halfedge();
        Halfedge_const_handle h = h0;
        do {
            h = h->next();
            vertex_count++;
        } while (h != h0);
        
        // roof
        std::cout << vertex_count;
        do {
            h = h->next();
            std::cout << " " << std::distance(ss.vertices_begin(), h->vertex());
        } while (h != h0);
        std::cout << "\n";

        // floor
        std::cout << vertex_count;
        do {
            h = h->next();
            if (h->vertex()->is_skeleton()) {
                std::cout << " " << floor_vertices_index[std::distance(ss.vertices_begin(), h->vertex())];
            } else {
                std::cout << " " << std::distance(ss.vertices_begin(), h->vertex());
            }
        } while (h != h0);
        std::cout << "\n";
    }
}

