

#ifndef MATHQIO_H
#define MATHQIO_H



namespace mathq {





  /* "save"
   * works for any objects that overload the << operator
   */

  template <class X>
  bool save(X& x, std::string fname, size_type precision, std::ios_base::fmtflags flags) {
    std::ofstream out(fname.data(), std::ios::out);

    if (!out) {
      //      cant_open_file(fname);
      return 1;
    }

    out.flags(flags);
    out.precision(precision);

    out << x;
    out.close();

    return 0;
  }

  template <class X>
  bool save(X& x, std::string fname, std::ios_base::fmtflags flags, size_type precision) {
    return save(x, fname, flags, precision);
  }

  template <class X>
  bool save(X& x, std::string fname, size_type precision = 16) {
    std::ios_base::fmtflags flags = std::ios_base::fmtflags();
    return save(x, fname, precision, flags);
  }

  template <class X>
  bool save(X& x, std::string fname, std::ios_base::fmtflags flags) {
    return save(x, fname, 16, flags);
  }




  // load  

  template <class X>
  bool load(X& x, std::string fname) {
    std::ifstream in(fname.data(), std::ios::in);
    if (!in) {
      //      cant_open_file(fname);
      return 1;
    }

    x.clear();
    in >> x;
    in.close();

    return 0;
  }


};


#endif

