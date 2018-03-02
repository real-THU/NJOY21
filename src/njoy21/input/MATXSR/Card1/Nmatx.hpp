struct Nmatx{
  using Value_t = int;
  static std::string name(){ return "nmatx"; }
  static std::string description(){
    return "The nmatx parameter represents the unit used for output of this\n"
           "module.  The allowable values have absolute values between 20 and\n"
           "99, inclusively.  If the value is negative, it means that the \n"
           "file is in binary format.  If it is positive, the file is in\n"
           "plaintext. A value of 0 is also allowed.";
  }
  static bool verify( const Value_t nmatx,
                      const Value_t ngen2,
                      const Value_t ngen1 ){
    return MATXSR::Card1::Ngen2::verify( nmatx, ngen1 ) and
             std::abs( nmatx ) != std::abs( ngen2 );
  }
};
