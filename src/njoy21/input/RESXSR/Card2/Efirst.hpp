struct Efirst {
  using Value_t = Quantity< ElectronVolt >;
  static std::string name(){ return "efirst"; }
  static std::string description(){
    return "The lower energy limit in eV.";
  }
  static bool verify( const Value_t ef ){
    return ef >= 0.0*dimwits::electronVolt;
  }
};
