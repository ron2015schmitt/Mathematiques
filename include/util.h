
#ifndef UTIL_H
#define UTIL_H



namespace mathq {



  //***********************************************************************
  //      Time related
  //***********************************************************************


  class Timer {
    time_t tm1_, tm2_;
    clock_t ckstart_, ckstop_, ckdiff_;
    double cputime_;
    //  string name;
  public:
    void start_timer_silent(void) {
      tm1_ = time(0);
      ckstart_ = clock();
    }
    void start_timer_verbose(void) {
      tm1_ = time(0);
      MOUT << "  The start time is: " << ctime(&tm1_);
      ckstart_ = clock();
    }
    void stop_timer_silent(void) {
      ckstop_ = clock();
      tm2_ = time(0);
      cputime_ = double(ckstop_-ckstart_)/double(CLOCKS_PER_SEC);
    }
    void stop_timer_curt(void) {
      using namespace display;
      ckstop_ = clock();
      tm2_ = time(0);
      cputime_ = double(ckstop_-ckstart_)/double(CLOCKS_PER_SEC);
      std::string timestr = num2string(cputime_);
      MOUT << "  CPU time = " << CREATESTYLE(BOLD).apply(timestr) << " sec" << std::endl;
    }
    void stop_timer_verbose(void) {
      using namespace display;
      ckstop_ = clock();
      tm2_ = time(0);
      ckdiff_ = ckstop_-ckstart_;
      cputime_ = double(ckstop_-ckstart_)/double(CLOCKS_PER_SEC);
      std::string timestr = num2string(cputime_);
      MOUT << "  Finished at: " << ctime(&tm2_);
      MOUT << "  CPU time = " << CREATESTYLE(BOLD).apply(timestr) << " sec" << std::endl;
    }

    double cputime(void) {
      cputime_ = double(ckstop_-ckstart_)/double(CLOCKS_PER_SEC);
      return cputime_;
    }
    clock_t ckstart(void) const {
      return ckstart_;
    }
    clock_t ckstop(void) const {
      return ckstop_;
    }
    clock_t ckdiff(void) {
      ckdiff_ = ckstop_-ckstart_;
      return ckdiff_;
    }

  };






};


#endif




