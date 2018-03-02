struct Hdescr {
  using Value_t = std::string;
  static std::string name(){ return "hdescr"; }
  static std::string description(){
    return
      "hdescr is an input string used as additional descriptive information,\n"
      "such as perhaps the location and date that the library was produced. \n"
      "The hdescr string is also written on the data header records.\n"
      "\n"
      "hdescr has a maximum length of 21 characters.";
  }
  static bool verify( const Value_t str ){ return str.length() <= 21; } 
};

