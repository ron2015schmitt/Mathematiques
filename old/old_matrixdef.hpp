#ifndef MATRIX_H
#define MATRIX_H





namespace mathq {




  /****************************************************************************
   * Matrix --  Full (i.e. dense) matrix implementation, row major order
   ****************************************************************************   
   */

  template <class D> class Matrix : public MorE<D,Matrix<D> > {

  private:

    // *********************** OBJECT DATA ***********************************

    size_type Nrows_;
    size_type Ncols_;
    std::valarray<D>* data_;

  public:

    // ************************** CONSTRUCTOR **********************************

    explicit Matrix<D>(const size_type NR, const size_type NC) {
      // allocate store
      size_type N = NR*NC;
      bool bad=false;
      double Ncheck = double(NR)*double(NC);
      if (Ncheck>double(maxsize)) {
	bad=true;
	N=0;
	Nrows_=0;
	Ncols_=0; 
      } else if (N==0) {
	Nrows_=0;
	Ncols_=0; 
      }else {
	Nrows_=NR;
	Ncols_=NC; 
      }

      data_ = new std::valarray<D>(N); 

      
    
    }

    // ****************** DEFAULT CONSTRUCTOR **********************************

    explicit Matrix<D>() {
      size_type NR=0;
      size_type NC=0;

      // allocate store
      size_type N = NR*NC;
      bool bad=false;
      double Ncheck = double(NR)*double(NC);
      if (Ncheck>double(maxsize)) {
	bad=true;
	N=0;
	Nrows_=0;
	Ncols_=0; 
      } else if (N==0) {
	Nrows_=0;
	Ncols_=0; 
      }else {
	Nrows_=NR;
	Ncols_=NC; 
      }

      data_ = new std::valarray<D>(N); 


    
    }


    // ************************** COPY CONSTRUCTOR **********************************

    Matrix<D>(const Matrix<D>& m2) {
      // allocate store
      const size_type NR = m2.Nrows();
      const size_type NC = m2.Ncols();
      size_type N = NR*NC;
      bool bad=false;
      double Ncheck = double(NR)*double(NC);
      if (Ncheck>double(maxsize)) {
	bad=true;
	N=0;
	Nrows_=0;
	Ncols_=0; 
      } else {
	Nrows_=NR;
	Ncols_=NC; 
      }

      *this = m2;
    }


    // ************************** EXPRESSION CONSTRUCTOR ****************

    template <class A>
    Matrix<D>(const Mexpr<D,A>& x) {

 
      // allocate store
      const size_type NR = x.Nrows();
      const size_type NC = x.Ncols();
      size_type N = NR*NC;
      bool bad=false;
      double Ncheck = double(NR)*double(NC);
      if (Ncheck>double(maxsize)) {
	bad=true;
	N=0;
	Nrows_=0;
	Ncols_=0; 
      } else {
	Nrows_=NR;
	Ncols_=NC; 
      }

      data_ = new std::valarray<D>(N); 



      *this = x;
      
    }




    // **************************** DESTRUCTOR **********************************
    ~Matrix<D>() {
      delete  data_ ;

    }


    // ******************** RESIZING AND RESHAPING ********************************

    // These allow the user to resize a matrix

    // *** this is used for recon by assignment ***

    MReconObj<D>  resize(void) { 
      return  MReconObj<D>(*this);
    }

    // *** resize from given size *** 

    Matrix<D>&  resize(const size_type NR, const size_type NC) { 

      if (NR==this->Nrows() && NC==this->Ncols())
	return *this;

      // allocate store
      size_type N = NR*NC;
      bool bad=false;
      double Ncheck = double(NR)*double(NC);
      if (Ncheck>double(maxsize)) {
	bad=true;
	N=0;
	Nrows_=0;
	Ncols_=0; 
      } else if (N==0) {
	Nrows_=0;
	Ncols_=0; 
      }else {
	Nrows_=NR;
	Ncols_=NC; 
      }
      if (N==this->size())
	return *this;
      data_ = new std::valarray<D>(N); 
      return *this;
    }


    Matrix<D>&  clear(void) { 
      return this->resize(0,0);
    }


    // reshape(matrix,nr,nc)
    // the new matrix has teh same # of entries but has different number of rows/columns
    // data is left unchanged
    Matrix<D>&  reshape(const size_type nr, const size_type nc) { 

      const size_type nn = nr*nc;

      if (nn==0) {
	Nrows_=0;
	Ncols_=0; 
      }else {
	Nrows_=nr;
	Ncols_=nc; 
      }
      return *this;
    }



    // In-place transpose. 
    // For square matrices this operation is quick and easy.
    // For non-square matrices, this changes the shape and operation is time-consuming
    Matrix<D>  transpose(void) { 
      const index_type NR = index_type(Nrows());
      const index_type NC = index_type(Ncols());
      const index_type N = index_type(size());
      const index_type Nminus1 = N-1;

      // symmetric matrix  
      if (NC == NR) {
	index_type r,c;
	D temp;
	for (r = 0; r < NR; ++r)
	  for (c = r + 1; c < NR; ++c) {
	    temp = (*this)(r + c * NR);
	    (*this)(r + c * NR) = (*this)(c + r * NR);
	    (*this)(c + r * NR) = temp;
	  }
	return *this;
      }

      reshape(NC,NR);

      // for "vectors" 
      if (NC == 1 || NR==1) {
	return *this;
      }

      // boolean array to make searching faster
      // can set Nmove=1, but this will be very slow
      // Nmove=(NR+NC)/2 is optimal
      const bool Nmove =(NR+NC)/2;
      index_type move[Nmove];
      for (index_type i = 0; i < Nmove; ++i)
	move[i] = false;


      // there are always at least 2 fixed points (at j=0 and j=Nminus1)
      index_type count = 2;		
      // find the rest of the fixed points
      if (NC >= 3 && NR >= 3)
	count += gcd(NC - 1, NR - 1) - 1;	/* # fixed points */

      index_type jstart = 1;
      index_type magicnum = NC;

      while (1) {
	index_type jnext,jnextc;
	index_type jstartC = Nminus1 - jstart;
	index_type j = jstart;
	index_type jC = jstartC;
	D dstart = (*this)(jstart);
	D dstartC = (*this)(jstartC);

	// PROCESS THE CURRENT SEQUENCE AND ITS COMPLIMENTARY SEQUENCE
	while (1) {
	  jnext = NC * j - Nminus1 * (j / NR);
	  jnextc = Nminus1 - jnext;
	  if (j < Nmove)
	    move[j] = true;
	  if (jC < Nmove)
	    move[jC] = true;
	  count += 2;
	  if (jnext == jstart) {
	    (*this)(j) = dstart;
	    (*this)(jC) = dstartC;
	    break;
	  }
	  if (jnext == jstartC) {
	    (*this)(j) = dstartC;
	    (*this)(jC) = dstart;
	    break;
	  }
	  (*this)(j) = (*this)(jnext);
	  (*this)(jC) = (*this)(jnextc);
	  j = jnext;
	  jC = jnextc;
	}
	// DONE PROCESSING SEQUENCE


	// CHECK TO SEE IF WE'RE FINISHED
	if (count >= N)
	  break;	

	// FIND THE START OF THE NEXT SEQUENCE
	while (1)  {
	  // skip fixed points (jstart==magicnum)
	  do  {
	    jstart++;
	    if ((magicnum +=NC)>Nminus1)
	      magicnum -= Nminus1;
	  } while (jstart==magicnum);
	   
	  jnext = magicnum;
	  const  index_type max = Nminus1-jstart+1;
	  if (jstart < Nmove){
	    if (!move[jstart])
	      break;
	  } else {
	    // this while loop is needed to cull out previously 
	    // processed slcuences
	    while (jnext > jstart && jnext < max) {
	      j = jnext;
	      jnext = NC * j - Nminus1 * (j / NR);
	    }
	  }
	  if (jnext == jstart)
	    break;
	} 
	// WE HAVE FOUND START OF THE NEXT SEQUENCE

      }
      return *this;
    }

  








    // ************************* SINGLE INDEX ELEMENT ACCESS *********************************



    inline D& operator()(const index_type i)  {
      return (*data_)[i]; 
    }


    inline const D operator()(const index_type i) const {
      return (*data_)[i]; 
    }



    

    // Accessing a slcuence of values
    
    inline  MRangeObj<D>  operator()(const slc& i)  { 
      return MRangeObj<D>(*this,i);
    }
    inline  const MRangeObj<D>  operator()(const slc& i) const  { 
      return MRangeObj<D>(*this,i);
    }
    



    // Accessing a SET of values 

    const MSetObj<D> operator()(const Vector<index_type>& ii) const {
      return MSetObj<D>(*this, ii);
    }
    MSetObj<D> operator()(const Vector<index_type>& ii) {
      return MSetObj<D>(*this, ii);
    }

    // Accessing a SET of values using a subscript matrix

    const MSetObj<D> operator()(const Matrix<index_type>& subs) const {
      return MSetObj<D>(*this, subs );
    }
    MSetObj<D> operator()(const Matrix<index_type>& subs)  {
      return MSetObj<D>(*this, subs );
    }


    // Accessing a SET of values using a Matrix MASK
    
    MSetObj<D> operator()(const Matrix<bool>& mask)  {
      return  MSetObj<D>(*this,mask);
    }
    const MSetObj<D> operator()(const Matrix<bool>& mask)  const {
      return  MSetObj<D>(*this,mask);
    }


    // Accessing a SET of values using a vector MASK
    
    MSetObj<D> operator()(const Vector<bool>& mask)  {
      return  MSetObj<D>(*this,mask);
    }
    const MSetObj<D> operator()(const Vector<bool>& mask) const  {
      return  MSetObj<D>(*this,mask);
    }


    // ************************* (ROW,COL) INDEX ELEMENT ACCESS **************************

    inline index_type index(const index_type r, const index_type c) const {
      return c + Ncols_*r;
    }

    inline D& operator()(const index_type r, const index_type c) {
      return (*data_)[c + Ncols_*r]; 
    }

    inline const D operator()(const index_type r, const index_type c) const {
      return (*data_)[c + Ncols_*r]; 
    }


    // Accessing a (set,set)

    const MDualSetObj<D> operator()(const Vector<index_type>& ii, const Vector<index_type>& jj) const {
      return MDualSetObj<D>(*this, ii, jj);
    }
    MDualSetObj<D> operator()(const Vector<index_type>& ii, const Vector<index_type>& jj)  {
      return MDualSetObj<D>(*this, ii, jj);
    }

    // Accessing a (set,integer) 

    const MDualSetObj<D> operator()(const Vector<index_type>& ii, const index_type j) const {
      return MDualSetObj<D>(*this, ii, j);
    }
    MDualSetObj<D> operator()(const Vector<index_type>& ii, const index_type j)  {
      return MDualSetObj<D>(*this, ii, j);
    }

    // Accessing a (integer,set) 

    const MDualSetObj<D> operator()(const index_type i, const Vector<index_type>& jj) const {
      return MDualSetObj<D>(*this, i,jj);
    }
    MDualSetObj<D> operator()(const index_type i, const Vector<index_type>& jj)  {
      return MDualSetObj<D>(*this, i,jj);
    }

    // Accessing a (slc,slc)

    const MDualRangeObj<D> operator()(const slc& ii, const slc& jj) const {
      return MDualRangeObj<D>(*this, ii, jj);
    }
    MDualRangeObj<D> operator()(const slc& ii, const slc& jj)  {
      return MDualRangeObj<D>(*this, ii, jj);
    }

    // Accessing  (set,slc)

    const MSetRangeObj<D> operator()(const Vector<index_type>& ii, const slc& jj) const {
      return MSetRangeObj<D>(*this, ii, jj);
    }
    MSetRangeObj<D> operator()(const Vector<index_type>& ii, const slc& jj)  {
      return MSetRangeObj<D>(*this, ii, jj);
    }
    // Accessing  (slc,set)

    const MRangeSetObj<D> operator()(const slc& ii, const Vector<index_type>& jj) const {
      return MRangeSetObj<D>(*this, ii, jj);
    }
    MRangeSetObj<D> operator()(const slc& ii, const Vector<index_type>& jj)  {
      return MRangeSetObj<D>(*this, ii, jj);
    }

    // Accessing  (integer,slc)

    const MSetRangeObj<D> operator()(const index_type i, const slc& jj) const {
      return MSetRangeObj<D>(*this, i, jj);
    }
    MSetRangeObj<D> operator()(const index_type i, const slc& jj)  {
      return MSetRangeObj<D>(*this, i, jj);
    }
    // Accessing  (slc,integer)

    const MRangeSetObj<D> operator()(const slc& ii, const index_type j) const {
      return MRangeSetObj<D>(*this, ii, j);
    }
    MRangeSetObj<D> operator()(const slc& ii, const index_type j)  {
      return MRangeSetObj<D>(*this, ii, j);
    }


    // ************************* SUBMATRIX, ROW, COL ACCESS **************************


    // Accessing a submatrix of values
                                                                                        
    inline MSubmatObj<D>
    submat(const index_type rstart, const index_type rend,
	   const index_type cstart, const index_type cend)  {
      return MSubmatObj<D>(*this, rstart,  rend, cstart, cend);
    }
    inline const MSubmatObj<D>
    submat(const index_type rstart, const index_type rend,
	   const index_type cstart, const index_type cend)  const {
      return MSubmatObj<D>(*this, rstart,  rend, cstart, cend);
    }
    
    // Accessing a row
    inline  MSubmatObj<D> 
    row(const index_type r) {
      return submat(r,r,0,Ncols()-1);
    }
    inline const  MSubmatObj<D> 
    row(const index_type r) const {
      return submat(r,r,0,Ncols()-1);
    }

    // Accessing a column
    inline  MSubmatObj<D> 
    col(const index_type c) {
      return submat(0,Nrows()-1,c,c);
    }
    inline const MSubmatObj<D> 
    col(const index_type c) const {
      return submat(0,Nrows()-1,c,c);
    }



    // ************************** ATTRIBUTE ACCESS ********************************

    inline size_type size(void) const {
      return data_->size();
    }

    inline size_type Nrows(void) const {
      return Nrows_;
    }

    inline size_type Ncols(void) const {
      return Ncols_;
    }


    inline static METypes metype(void)  {
      return ME_Matrix;
    }


    bool mustcopy(const void* maddr) const {
      return false;
    }

    bool addrmatch(const void *maddr) const {
      return maddr==static_cast<const void*>(this);
    }




    // ******************** ASSIGNMENT OPERATORS ********************************


    // Assign all elements to the same constant value
    Matrix<D>& operator=(const D d) { 
      const size_type NN = size();
      for(register index_type i=0; i<NN; i++) 
	(*data_)[i] = d; 
      return *this;
    }


    // Assignment to a matrix expression
    template <class A>  Matrix<D>& operator=(const Mexpr<D,A>& x) {
      const size_type NN = x.size();
      const size_type NR = x.Nrows();
      const size_type NC = x.Ncols();

      resize(NR,NC);

      if (x.mustcopy(this)) {    
	Matrix<D> mtemp(NR,NC);
	for(register index_type i = 0; i < NN; i++) 
	  mtemp(i) = x(i);   
	for(register index_type i = 0; i < NN; i++) 
	  (*this)(i) = mtemp(i);
      } else {
	for(register index_type i = 0; i < NN; i++) 
	  (*this)(i) = x(i);   
      }
      return *this; 
    }


    // assign to recon object (issue error)
    Matrix<D>& operator=(const MReconObj<D>& b) { 
      return *this;
    }


    // Copy asignment 
    Matrix<D>& operator=(const Matrix<D>& m2) {

      resize(m2.Nrows(),m2.Ncols());

      const size_type NN = size();
      for(register index_type i=0; i<NN; i++) 
	(*data_)[i] = m2(i);    
      return *this;
    }


    //assign to vector(expression)
    
    template <class B>
    Matrix<D>& operator=(const TensorR<D,B>& rhs) { 
      const size_type N =size();


      if ( rhs.mustcopy(this) ) {    
	Vector<D> y(N);
	for(register index_type i=0; i<N; i++) 
	  y[i] = rhs[i]; 
	for(register index_type i=0; i<N; i++) 
	  (*data_)[i] = y[i]; 
      } else {
	for(register index_type i=0; i<N; i++) 
	  (*data_)[i] = rhs[i]; 
      }
      return *this;
    }

    // ******************************* TEXT STUFF *******************************


    static std::string classname() const {
      return "Matrix";
    }

    static std::string fullclassname() const {
      Matrix<D> dummy;
      return getTypeString(dummy);
    }


    std::string expression(void) const {
      return "";
    }
    



    static std::string datatype(void) {
      D dummy = D();
      return getTypeString(dummy);
    }




    // stream << operator

    friend std::ostream& operator<<(std::ostream &stream, const Matrix<D>& m) {
      // const size_type NR = m.Nrows();
      // const size_type NC = m.Ncols();
      // const size_type w = m.width();
      // std::string sep;
      // switch (m.textformt()) {
      // case text_braces:
      // 	stream << "{";
      // 	if (NR>0)
      // 	  stream << " {";
      // 	for(index_type r=0; r < NR; r++) {
      // 	  if (r>0)  
      // 	    stream << "  {";
      // 	  for(index_type c=0; c < NC; c++) {
      // 	    if ( (c>0) && ( (c%m.perline()) == 0 ) )
      // 	      stream << std::endl << "   ";
      // 	    stream <<std::setw(w) << m(r,c);
      // 	    if (c < (NC-1) )
      // 	      stream << ",";
      // 	  }
      // 	  stream << "}";
      // 	  if (r < (NR-1) ) {
      // 	    stream << ","<<std::endl;
      // 	  }
      // 	}      
      // 	stream << " }" ;
      // 	break;
      // case text_nobraces:
      // 	if (m.width()==0)
      // 	  sep = " ";
      // 	else
      // 	  sep="";
      // 	for(index_type r=0; r < NR; r++) {
      // 	  for(index_type c=0; c < NC; c++) {
      // 	    stream <<std::setw(w) << m(r,c);
      // 	    if (c < (NC-1) )
      // 	      stream << sep;
      // 	  }
      // 	  if (r < (NR-1) )
      // 	    stream << std::endl;
      // 	}      
      // 	break;
      // default:
      // 	break;
      // } //switch
      return stream;
    }







    friend std::istream& operator>>(std::istream& stream,  Matrix<D>& m) {	
      // const size_type LINESZ = 32768;
      // char line[LINESZ];
      // size_type Nlines = 0;
      // std::vector<D> v;
      // size_type NR=0;
      // size_type NC=0;
      // size_type N=0;
      // const size_type NCold=m.Ncols();
      // const size_type NRold=m.Nrows();
      // const size_type Nold=NRold*NCold;
      // D temp;
      // std::istringstream strmline;

      // switch (m.textformat()) {
      // case text_braces:
      // 	{
      // 	  enum States {begin, betweenrows, inrow, waitingforcomma, end};
      // 	  States state = begin;
      // 	  index_type col = 0;
      // 	  while( (state!=end) && stream.getline(line,LINESZ) ){
      // 	    Nlines++;
      // 	    strmline.clear();
      // 	    strmline.str(line);
	    
      // 	    char c;
      // 	    size_type Nchars=0;
      // 	    while((state!=end) && strmline.get(c) ){
      // 	      Nchars++;
      // 	      if (isspace(c))
      // 		continue;
      // 	      if (c=='%')
      // 		break; // ignore rest of line "%" signifies a comment
	      
      // 	      //	States oldstate = state;
      // 	      switch (state) {
      // 	      case begin:
      // 		if  (c=='{')  {
      // 		  state = betweenrows;
      // 		  break;
      // 		}else {
      // 		  std::string extrastr = "Expecting an opening brace.";
      // 		  msyntax_error(m.name(),line,N,NRold,NCold,Nlines,Nchars,c,extrastr,m.textformat());
      // 		  return stream;
      // 		}
      // 		break;
      // 	      case betweenrows:
      // 		col=0;
      // 		if  (c=='{') {
      // 		  state = inrow;
      // 		  break;
      // 		}
      // 		if  (c=='}') {
      // 		  state = end;
      // 		  break;
      // 		}
      // 		if  (c==',') {
      // 		  state = state;
      // 		  break;
      // 		}else {
      // 		  std::string extrastr = "Expecting a closing brace or an opening brace for a new row.";
      // 		  msyntax_error(m.name(),line,N,NRold,NCold,Nlines,Nchars,c,extrastr,m.textformat());
      // 		  return stream;
      // 		}
      // 		break;
      // 	      case inrow:
      // 		if  (c=='}') {
      // 		  state = betweenrows;
      // 		  NR++;
      // 		  if (NR==1) {
      // 		    NC = col;
      // 		  } else if (NC!=col){
      // 		    mcol_number_error(m.name(),line, NR, NC, col, Nlines,m.textformat());
      // 		    return stream;
      // 		  }
      // 		  break;
      // 		}
      // 		strmline.putback(c);
      // 		if (strmline>>temp){
      // 		  v.push_back(temp);
      // 		  col++;
      // 		  state = waitingforcomma;
      // 		  break;
      // 		}else {
      // 		  std::string extrastr = "Expecting a matrix element.";
      // 		  msyntax_error(m.name(),line,N,NRold,NCold,Nlines,Nchars,c,extrastr,m.textformat());
      // 		  return stream;
      // 		}
      // 		break;
      // 	      case waitingforcomma:
      // 		if  (c=='}') {
      // 		  state = betweenrows;
      // 		  NR++;
      // 		  if (NR==1) {
      // 		    NC = col;
      // 		  } else if (NC!=col) {
      // 		    mcol_number_error(m.name(),line, NR, NC, col, Nlines,m.textformat());
      // 		    return stream;
      // 		  }
      // 		  break;
      // 		}
      // 		if  (c==',') {
      // 		  state = inrow;
      // 		  break;
      // 		}else {
      // 		  std::string extrastr = "Expecting a comma.";
      // 		  msyntax_error(m.name(),line,N,NRold,NCold,Nlines,Nchars,c,extrastr,m.textformat());
      // 		  return stream;
      // 		}
      // 		break;
      // 	      case end:
      // 		{
      // 		  std::string extrastr = "Expecting a closing brace.";
      // 		  msyntax_error(m.name(),line,N,NRold,NCold,Nlines,Nchars,c,extrastr,m.textformat());
      // 		}
      // 		return stream;
      // 		break;
      // 	      default:
      // 		bug_report(__FILE__,__LINE__);
      // 		return stream;
      // 		break;
      // 	      }
      // 	    }
      // 	  }
      // 	  if (Nold==0) {
      // 	    m.resize(NR,NC);
      // 	  } else if ((NR != NRold)||(NR != NRold)) {
      // 	    mbad_input_stream_size(m.name(),line,NR,NC,NRold,NCold);
      // 	    return stream;
      // 	  }
      // 	}
      // 	break;
      // case text_nobraces:
      // 	{
      // 	  std::string oldline = line;
      // 	  if (Nold==0) {
      // 	    while( stream.getline(line,LINESZ) ){ // read as "one row per line" until end of stream
      // 	      index_type col = 0;
      // 	      Nlines++;
      // 	      strmline.clear();
      // 	      strmline.str(line);
	    
      // 	      char c;
      // 	      size_type Nchars=0;
      // 	      while(strmline.get(c)){
      // 		Nchars++;
      // 		if (isspace(c))
      // 		  continue;
      // 		if (c=='%')
      // 		  break; // ignore rest of line "%" signifies a comment
	      
      // 		strmline.putback(c);
      // 		if (strmline>>temp){
      // 		  v.push_back(temp);
      // 		  col++;
      // 		} else { 
      // 		  std::string extrastr ="";
      // 		  if ( (c=='{') || (c=='}')||(c==','))
      // 		    extrastr = "Braces and commas are not allowed in 'text_nobraces' mode";
      // 		  msyntax_error(m.name(),line,N,NRold,NCold,Nlines,Nchars,c,extrastr,m.textformat());
      // 		  return stream;
      // 		}
      // 	      } // done with this line/row
      // 	      if (col>0)
      // 		NR++;
      // 	      if (NR==1) {
      // 		NC = col;
      // 	      } else if (NC!=col){
      // 		mcol_number_error(m.name(),line, NR, NC, col, Nlines,m.textformat());
      // 		return stream;
      // 	      }
      // 	    }
      // 	    m.resize(NR,NC);
      // 	  } else {
      // 	    // just read N numbers, regardless of spacing and carraige returns
      // 	    while( (N<Nold) && stream.getline(line,LINESZ)  ){
      // 	      Nlines++;
      // 	      strmline.clear();
      // 	      strmline.str(line);
      // 	      char c;
      // 	      size_type Nchars=0;
      // 	      while((N<Nold) && strmline.get(c)){
      // 		Nchars++;
      // 		if (isspace(c))
      // 		  continue;
      // 		if (c=='%')
      // 		  break; // ignore rest of line "%" signifies a comment
	      
      // 		strmline.putback(c);
      // 		if (strmline>>temp) {
      // 		  v.push_back(temp);
      // 		  N++;
      // 		} else { 
      // 		  std::string extrastr ="";
      // 		  if ( (c=='{') || (c=='}')||(c==','))
      // 		    extrastr = "Braces and commas are not allowed in 'text_nobraces' mode";
      // 		  msyntax_error(m.name(),line,N,NRold,NCold,Nlines,Nchars,c,extrastr,m.textformat());
      // 		  return stream;
      // 		}
      // 	      } // done with line
      // 	      oldline = line;
      // 	    } //done reading input

      // 	    if (N != Nold) {
      // 	      minput_stream_size_too_small(m.name(),oldline,N,NRold,NCold);
      // 	      return stream;
      // 	    }
      // 	    NR=NRold;
      // 	    NC=NCold;
      // 	  }
      // 	}
      // 	break;
      // default:
      // 	bug_report(__FILE__,__LINE__);
      // 	return stream;
      // 	break;
      // }//switch
      
      // const size_type len=NR*NC;
      // for(index_type i=0; i<len; i++)
      // 	m(i) = v[i];
  
      // return restore_stream(stream,strmline);
      return stream;
    }

  

    //template <class D>	
    friend inline std::istream& operator>>(const std::string s,  Matrix<D>& x) {	
      std::istringstream st(s);
      return (st >> x);
    }

    
  };









};
#endif 
