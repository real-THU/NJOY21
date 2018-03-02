struct Jinp{
  using Value_t = std::vector< int >;
  static std::string name(){ return "jinp"; }
  static std::string description(){
    return "The jinp parameter specifies the input particle id for each\n"
           "data type.";
  }
  static bool verify( const Value_t jinpList, const unsigned int ntype ){
    if( jinpList.size() != ntype ) return false;
    auto pos = std::find_if( jinpList.begin(), jinpList.end(),
                             []( const int jinp )->bool{ return jinp < 0; } );
    if( pos != jinpList.end() ) return false;
    return true;
  }
};
