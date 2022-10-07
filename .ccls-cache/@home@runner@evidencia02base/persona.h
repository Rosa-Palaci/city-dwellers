class Persona{
  private:
    string first_name,last_name,city;
    int id, zip;
  public:
      Persona(int id = 0, int zip = 0, string fname = "", string lname = "", string city = ""){
        this->id = id;
        this->zip = zip;
        this->first_name = fname;
        this->last_name = lname;
        this->city = city;
      }

/*
Agrega las sobre cargas de operadores necesarias en la clase Persona.
*/
    
};