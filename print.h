#include <CGAL/Polygon_2.h>
#include <CGAL/Polygon_with_holes_2.h>
#include <stack>

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
    std::cout << " " << ( i->is_bisector() ? "bisector" : "contour" );
    std::cout << " " << ( i->is_border() ? "border" : "no-border" ) << std::endl;
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

template<class K>
void test9( CGAL::Straight_skeleton_2<K> const& ss, double delta)
{
    typedef CGAL::Straight_skeleton_2<K> Ss ;

    typedef typename Ss::Vertex_const_handle     Vertex_const_handle ;
    typedef typename Ss::Vertex_const_iterator   Vertex_const_iterator ;
    typedef typename Ss::Halfedge_const_handle   Halfedge_const_handle ;
    typedef typename Ss::Halfedge_const_iterator Halfedge_const_iterator ;
    typedef typename Ss::Face_const_handle       Face_const_handle ;
    typedef typename Ss::Face_const_iterator     Face_const_iterator ;

    typedef std::pair<int,int>                   pair_int;

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
    
    // count subdivision vertices,
    // remember their coordinates
    // and build an index for them
    int subdiv_vertices_number = 0;
    std::vector<CGAL::Point_3<K>> subdiv_vertices;
    std::map<pair_int, int> subdiv_vertices_index;
    for ( Halfedge_const_iterator i = ss.halfedges_begin(); i != ss.halfedges_end(); ++i ) {
        double t0 = i->opposite()->vertex()->time(),
               t1 = i->vertex()->time();
        if (t1 > t0) {
            int n0 = std::floor(t0 / delta),
                n1 = std::floor(t1 / delta),
                ii = std::distance(ss.halfedges_begin(), i);
//std::cout << "index for edge ";
//print_point(i->opposite()->vertex()->point());
//print_point(i->vertex()->point());
//std::cout << "\n";
            for (int n=n0; n <= n1; n++) {
                if (n == n0 && t0 != delta * n0) {
                    continue;
                }
                if (n == n0) {
                    subdiv_vertices_index[pair_int(ii, n)] = 
                        std::distance(ss.vertices_begin(), i->opposite()->vertex());
                } else if (n == n1 && t1 == delta * n1) {
                    subdiv_vertices_index[pair_int(ii, n)] = 
                        std::distance(ss.vertices_begin(), i->vertex());
                } else {
                    subdiv_vertices_index[pair_int(ii, n)] =
                        ss.size_of_vertices()
                        + floor_vertices_number
                        + subdiv_vertices_number;
                }
                double x0 = i->opposite()->vertex()->point().x(),
                       y0 = i->opposite()->vertex()->point().y(),
                       x1 = i->vertex()->point().x(),
                       y1 = i->vertex()->point().y();
                double t = n * delta,
                       x = x0 + (x1 - x0) * (t - t0) / (t1 - t0),
                       y = y0 + (y1 - y0) * (t - t0) / (t1 - t0);
                subdiv_vertices.push_back(CGAL::Point_3<K>(x, y, t));
                subdiv_vertices_number++;
//std::cout << "  n: "  << n << " point: " << subdiv_vertices_index[pair_int(ii, n)]
//    << "(" << x << "," << y << "," << t << ")"
//    << "\n";
            }
        }
    }

    std::vector<std::vector<int>> faces;

    // floor
    for ( Face_const_iterator i = ss.faces_begin(); i != ss.faces_end(); ++i ) {
        Halfedge_const_handle h0 = i->halfedge();
        Halfedge_const_handle h = h0;

        faces.emplace_back();
        do {
            h = h->next();
            if (h->vertex()->is_skeleton()) {
                faces.back().push_back(floor_vertices_index[std::distance(ss.vertices_begin(), h->vertex())]);
            } else {
                faces.back().push_back(std::distance(ss.vertices_begin(), h->vertex()));
            }
        } while (h != h0);
    }

    // roof
    for ( Halfedge_const_iterator i = ss.halfedges_begin(); i != ss.halfedges_end(); ++i ) {
        if (i->is_border() || i->is_bisector()) {
            continue;
        }

        struct Task {
            Halfedge_const_handle e;
            int n;
        };

        std::stack<Task> tasks;
        tasks.push({i->next(), 0});

        while (tasks.size() > 0) {
            Task q = tasks.top();
            tasks.pop();

            Halfedge_const_handle e = q.e;
            int e_index = std::distance(ss.halfedges_begin(), e);
            bool e_up = true;
            bool inside = true;

            std::vector<int> face = { subdiv_vertices_index[pair_int(e_index, q.n)] };
            

            do {
                auto v0 = subdiv_vertices_index.find(pair_int(e_index, q.n));
                auto v1 = subdiv_vertices_index.find(pair_int(e_index, q.n+1));
                
                if (e_up) {
                    if (v1 != subdiv_vertices_index.end()) {
                        if (face.back() != v1->second) {
                            face.push_back(v1->second);
                            tasks.push({e, q.n+1});
                        }
                        inside = false;
                    } else if (inside) {
                        int j = std::distance(ss.vertices_begin(), e->vertex());
                        if (face.back() != j)
                            face.push_back(j);
                    }
                } else {
                    if (v1 != subdiv_vertices_index.end()) {
                        if (face.back() != v1->second)
                            face.push_back(v1->second);
                        inside = true;
                    }
                    
                    if (inside && v0 == subdiv_vertices_index.end()) {
                        int j = std::distance(ss.vertices_begin(), e->vertex());
                        if (face.back() != j)
                            face.push_back(j);
                    }

                    if (v0 != subdiv_vertices_index.end()) {
                        if (face.back() != v0->second) {
                            face.push_back(v0->second);
                        }
                        break;
                    }
                }
                
                e = e->next();
                e_up = e->vertex()->time()  >  e->opposite()->vertex()->time();
                if (e_up) {
                    e_index = std::distance(ss.halfedges_begin(), e);
                } else {
                    e_index = std::distance(ss.halfedges_begin(), e->opposite());
                }

            } while(true);
            
            if (face.size() > 2) {
                faces.push_back(face);
            }

        }

    }
   
    auto rooof = [](auto z) {
        return 0.5*(1-std::exp(-4*z));
    };

    std::cout << "OFF\n";
    std::cout << ss.size_of_vertices() + floor_vertices_number + subdiv_vertices_number
        << " " << faces.size()
        << " " << 0
        << "\n";

    // ss vertices
    for ( Vertex_const_iterator i = ss.vertices_begin(); i != ss.vertices_end(); ++i ) {
        std::cout << i->point().x() << " " << i->point().y() << " " << rooof(i->time())
            << std::endl;
    }
    // floor vertices
    for ( Vertex_const_iterator i = ss.vertices_begin(); i != ss.vertices_end(); ++i ) {
        if (i->is_skeleton()) {
            std::cout << i->point().x() << " " << i->point().y() << " " << 0.0
                << std::endl;
        }
    }
    // subdiv vertices
    for (auto p = subdiv_vertices.begin(); p != subdiv_vertices.end(); p++) {
        std::cout << p->x() << " " << p->y() << " " << rooof(p->z())
            << std::endl;
    }

    // faces
    for (auto f=faces.begin(); f!=faces.end(); f++) {
        std::cout << (*f).size();
        for (auto v=(*f).begin(); v!=(*f).end(); v++) {
            std::cout << " " << *v;
        }
        std::cout << "\n";
    }
    
//std::cout << "# faces: \n";


}
