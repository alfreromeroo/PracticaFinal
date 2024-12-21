#include "../include/quienesquien.h"
#include <sstream>
#include <iostream>
#include <iterator>
#include <math.h>
#include <algorithm>

QuienEsQuien::QuienEsQuien(){
}

QuienEsQuien::QuienEsQuien(const QuienEsQuien &quienEsQuien){
}

QuienEsQuien& QuienEsQuien::operator= (const QuienEsQuien &quienEsQuien){
     return *this;
}

QuienEsQuien::~QuienEsQuien(){
     this->limpiar() ;
}

void QuienEsQuien::limpiar(){
     this->personajes.clear();
     this->atributos.clear();
     this->personajes_images.clear();
     for(vector<vector<bool>>::iterator it_tablero = this->tablero.begin();
         it_tablero != this->tablero.end();
         it_tablero++){
          (*it_tablero).clear();
     }
     this->tablero.clear();
     this->arbol.clear() ;
}

template <typename T>
std::ostream& operator<<  (std::ostream& out, const std::vector<T>& v) {
     if ( !v.empty() ) {
          out <<  '[' ;
          std::copy (v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
          out <<  "\b\b]";
     }

     return out;
}

void QuienEsQuien::mostrar_estructuras_leidas(){
     cout <<  "personajes: " <<  (this->personajes) <<  endl;
     cout <<  "atributos: " <<  (this->atributos) <<  endl;
     cout <<  "tablero:    " <<  endl;
     // Escribe la cabecera del tablero
     for(vector<string>::iterator it_atributos = this->atributos.begin() ;
         it_atributos != this->atributos.end() ;
         it_atributos++){
          cout <<  *it_atributos << "\t";
     }
     cout << endl;

     int indice_personaje = 0;
     for(vector<vector<bool>>::iterator it_tablero_atributos = tablero.begin();
         it_tablero_atributos!= tablero.end();
         it_tablero_atributos++){
          string personaje = this->personajes[indice_personaje];
          int indice_atributo = 0;
          for(vector<bool>::iterator it_atributos_personaje = (*it_tablero_atributos).begin();
              it_atributos_personaje != (*it_tablero_atributos).end() ;
              it_atributos_personaje++){
               cout <<  *it_atributos_personaje<< "\t";
               indice_atributo++;
          }
          cout <<  personaje <<  endl;
          indice_personaje++;
     }
}

/**
  * @brief Devuelve una copia de la cadena original sin las subcadenas no deseadas.
  *
  * @param cadena_original Cadena de la que se eliminan las subcadenas no deseadas.
  * @param cadena_a_eliminar Subcadena que se busca y se elimina.
  *
  * @return Copia de la cadena original sin las subcadenas no deseadas.
  */


string limpiar_string(string cadena_original,string cadena_a_eliminar){
     string linea(cadena_original);
     while(linea.find_first_of(cadena_a_eliminar) != std::string::npos){
          linea.erase(linea.find_first_of(cadena_a_eliminar),cadena_a_eliminar.length());
     }

     return linea;
}

istream& operator >>  (istream& is, QuienEsQuien &quienEsQuien) {
     quienEsQuien.limpiar();
     if(is.good()){ //Lee la linea con los nombres de las columnas
          string linea;
          getline(is, linea, '\n');
          linea = limpiar_string(linea,"\r");
          bool salir=false;
          while(!salir && linea.find('\t') != string::npos ){
               string atributo = linea.substr(0,linea.find('\t'));
               quienEsQuien.atributos.push_back(atributo);
               linea = linea.erase(0,linea.find('\t')+1);
               if (linea.substr(0,linea.find('\t'))=="Nombre personaje")
                   salir=true;
          }
     }
     //LEE los atributos para cada personaje
     while( is.good()) {
          string linea;
          getline(is, linea, '\n');
          linea = limpiar_string(linea,"\r");

          //Si la linea contiene algo extrae el personaje.
          //Si no la ignora.
          if(linea != ""){;
               vector<bool> atributos_personaje;
               int indice_atributo=0;
               bool salir=false;
               while(!salir && linea.find('\t') != string::npos){
                   string valor = linea.substr(0,linea.find('\t'));
                   if (valor == "0" || valor == "1"){
                    bool valor_atributo = valor == "1";
                    atributos_personaje.push_back(valor_atributo);
                    linea = linea.erase(0,linea.find('\t')+1) ;
                    indice_atributo++;
                   }
                   else{
                       salir=true;
                   }
               }
               string nombre_personaje;
               string imagen_personaje;
               if (linea.find('\t') == string::npos){
                nombre_personaje = linea;
                imagen_personaje=""; //no tiene imagen
               }
               else{
                nombre_personaje=linea.substr(0,linea.find('\t'));
                linea = linea.erase(0,linea.find('\t')+1) ;
                imagen_personaje=linea;

               }
               quienEsQuien.personajes.push_back(nombre_personaje);
               quienEsQuien.tablero.push_back(atributos_personaje);
               quienEsQuien.personajes_images.push_back(imagen_personaje);
          }
     }

     quienEsQuien.mostrar_estructuras_leidas();
     quienEsQuien.arbol = quienEsQuien.crear_arbol();
     quienEsQuien.tg=nullptr; //puntero al tablero grafico
     quienEsQuien.con=nullptr; //puntero a la consola
     if (quienEsQuien.modo_graph){
        int nper = quienEsQuien.personajes.size();
        int nrows,ncols=3;
        if (nper<8)
           nrows = nper/ncols;
        else{
            ncols=4;
            nrows = nper/ncols;
        }
        //se crea un tablero grafico
        quienEsQuien.tg = new TableroGrafico(400,400,nrows,ncols);
        //ponemos en el tablero grafico las im�genes
        for (int i=0;i<nper;i++){

            quienEsQuien.tg->putImagen(i/ncols,i%ncols,quienEsQuien.personajes_images[i].c_str());
        }
        //creamos la consola
        quienEsQuien.con=new Consola();
     }
     return is;
}

ostream& operator <<  (ostream& os, const QuienEsQuien &quienEsQuien){
     //Escribimos la cabecera, que contiene los atributos y al final una columna para el nombre

     cout<<"NUmero de Atributos "<<quienEsQuien.atributos.size()<<endl;
     for(vector<string>::const_iterator it_atributos = quienEsQuien.atributos.begin();
         it_atributos != quienEsQuien.atributos.end();
         it_atributos++){
          os << *it_atributos << "\t";
     }

     os << "Nombre personaje" << endl;
     
     //Rellenamos con ceros y unos cada linea y al final ponemos el nombre del personaje.
     for(int indice_personaje=0;indice_personaje<quienEsQuien.personajes.size();indice_personaje++){
          for(int indice_atributo=0;indice_atributo<quienEsQuien.atributos.size();indice_atributo++){
               os << quienEsQuien.tablero[indice_personaje][indice_atributo] << "\t";
          }
          os << quienEsQuien.personajes[indice_personaje] << endl;
     }
     
     return os;
}

/**
* @brief Convierte un numero a un vector de bool que corresponde
*        con su representadon en binario con un numero de digitos
*              f i j o.
*
* @param n Numero a convertir en binario.
* @param digitos Numero de digitos de la representaddn binaria.
*
* @return Vector de booleanos con la representadon en binario de @e n
*      con el numero de elementos especificado por @e digitos.
*/
vector<bool> convertir_a_vector_bool(int n, int digitos) {
     vector<bool> ret;
     while(n) {
          if (n&1)
               ret.push_back(true);
          else
               ret.push_back(false);

          n>>=1;
     }

     while(ret.size()<digitos)
          ret.push_back(false);

     reverse(ret.begin(),ret.end());
     return ret;
}

/**
* @brief Esta es una propuesta de cabecera de la funcion para crear el arbol.
*/
bintree<Pregunta> QuienEsQuien::crear_arbol( vector<string> atributos,
                                             int indice_atributo,
                                             vector<string> personajes,
                                             vector<bool> personajes_restantes,
                                             vector<vector<bool>> tablero){
          
     int num_personajes_restantes = count(personajes_restantes.begin(), personajes_restantes.end(), true);
     if (num_personajes_restantes == 1){
          
          int indice_personaje = distance(personajes_restantes.begin(), find(personajes_restantes.begin(), personajes_restantes.end(), true));
          return bintree<Pregunta>(Pregunta(personajes[indice_personaje], num_personajes_restantes));
     }

     bintree<Pregunta> arbol(Pregunta(atributos[indice_atributo], num_personajes_restantes));

     vector<bool> personajes_si(personajes.size(), false);
     vector<bool> personajes_no(personajes.size(), false);
     int contador_si = 0;
     int contador_no = 0;

     for(size_t i=0; i<personajes.size(); ++i){
          if(personajes_restantes[i]){
               if (tablero[i][indice_atributo]){
                    personajes_si[i] = true;
                    ++contador_si;
               }else{
                    personajes_no[i] = true;
                    ++contador_no;
               }
          }
     }

     bintree<Pregunta> arbol_si;
     bintree<Pregunta> arbol_no;

     if (indice_atributo + 1 <atributos.size()){
          if (contador_si > 0){
               arbol_si = crear_arbol(atributos, indice_atributo + 1, personajes, personajes_si, tablero);
               arbol.insert_left(arbol.root(), arbol_si);
          }
          if (contador_no > 0){
               arbol_no = crear_arbol(atributos, indice_atributo + 1, personajes, personajes_no, tablero);
               arbol.insert_right(arbol.root(), arbol_no);
          }
                 
     }
     
     return arbol;
}

/**
* @brief Igual que el método crear_arbol, pero elige las preguntas maximizando la entropía.
*/
bintree<Pregunta> QuienEsQuien::crear_arbol_mejorado( vector<string> atributos,
                                             int indice_atributo,
                                             vector<string> personajes,
                                             vector<bool> personajes_restantes,
                                             vector<vector<bool>> tablero){

     //TODO :D:D
     bintree<Pregunta> arbol;
     return arbol;
}


bintree<Pregunta> QuienEsQuien::crear_arbol(){
     int indice_atributo = 0;
     vector<bool> personajes_restantes;
     for(vector<string>::iterator it = personajes.begin();it!=personajes.end();it++){
          personajes_restantes.push_back(true);
     }
     
     if (arbol_mejorado)
          return crear_arbol_mejorado(this->atributos, indice_atributo, this->personajes,
                        personajes_restantes, this->tablero);
     else
          return crear_arbol(this->atributos, indice_atributo, this->personajes,
                        personajes_restantes, this->tablero);
}

void QuienEsQuien::usar_arbol(bintree<Pregunta> arbol_nuevo){
     arbol = arbol_nuevo;
}

void QuienEsQuien::iniciar_juego(){
     
     auto jugada_actual = arbol.root();

     Ventana v(tg,con,"WisW");
     if (modo_graph){
          v.getTableroGrafico();
     }
     
     while (!jugada_actual.null() && (!jugada_actual.left().null() || !jugada_actual.right().null())){

          con ->WriteText("¿Tu personaje tiene el atributo: ");
          con ->WriteText(jugada_actual.operator*().obtener_pregunta());
          con->WriteText("? (s/n): ");

          char respuesta;
          do{
               respuesta = con ->ReadChar();
          }while (respuesta != 's' && respuesta != 'n');

          if (respuesta == 's' && !jugada_actual.left().null()){
               jugada_actual = jugada_actual.left();
          }else if (respuesta == 'n' && !jugada_actual.right().null()){
               jugada_actual = jugada_actual.right();
          }
     }

     if (!jugada_actual.null()){
          con ->WriteText("Tu personaje es: ");
          con ->WriteText(jugada_actual.operator*().obtener_personaje());
          con ->WriteText("\n");
     }else{
          con ->WriteText("No he podido adivinar tu personaje. \n");
     }
    
     if (modo_graph){
          con->WriteText("Cuando completes QuienEsQuien, este mensaje lo podr�s quitar");
          char c;
          
          do{
               con->WriteText("Pulsa 0 para salir");
               c = con->ReadChar();
          
          }while (c!='0');
          
     }
     v.cerrar();
}	

set<string> QuienEsQuien::informacion_jugada(bintree<Pregunta>::node jugada_actual){
     set<string> personajes_levantados;
     if (jugada_actual.null()){
          return personajes_levantados;
     }

     if (jugada_actual.left().null() && jugada_actual.right().null()){
          const Pregunta& pregunta_actual = jugada_actual.operator*();
          if (pregunta_actual.obtener_num_personajes() == 1){
               personajes_levantados.insert(pregunta_actual.obtener_personaje());
          }
          return personajes_levantados;
     }

     set<string> conjunto_personajes_izquierdo = informacion_jugada(jugada_actual.left());
     set<string> conjunto_personajes_derecho = informacion_jugada(jugada_actual.right());

     personajes_levantados.insert(conjunto_personajes_izquierdo.begin(), conjunto_personajes_izquierdo.end());
     personajes_levantados.insert(conjunto_personajes_derecho.begin(), conjunto_personajes_derecho.end());

     return personajes_levantados;
}

void escribir_esquema_arbol(ostream& ss, const bintree <Pregunta>& a,
                            bintree<Pregunta>::node n, string& pre){
     if (n.null())
          ss <<  pre <<  "-- x" <<  endl;
     else {
          ss <<  pre <<  "-- " <<  (*n) <<  endl;
          if ( !n.right().null() || !n.left().null()) {// Si no es una hoja
               pre += "   |";
               escribir_esquema_arbol(ss,a, n.right(), pre);
               pre.replace(pre.size()-4, 4, "    ");
               escribir_esquema_arbol (ss,a, n.left(), pre);
               pre.erase(pre.size()-4, 4);
          }
     }
}

void QuienEsQuien::escribir_arbol_completo() const{
     string pre = "";
     escribir_esquema_arbol(cout,this->arbol,this->arbol.root(),pre);
}

void QuienEsQuien::eliminar_nodos_recursivo(bintree<Pregunta>::node n){

     //si es una hoja no se hace nada
     if (n.left().null() && n.right().null()){

          return;
     }

     // eliminacion recursiva
     if(!n.left().null() && !n.right().null()){
          
          eliminar_nodos_recursivo(n.left());
          eliminar_nodos_recursivo(n.right());
     }

     if(!n.left().null() && n.right().null()){

          bintree<Pregunta> arbol_izq;
          arbol.prune_left(n, arbol_izq);

          bintree<Pregunta>::node padre = n.parent();

          if (!padre.null()){

               if(padre.left() == n){

                    arbol.insert_left(padre, arbol_izq);
                    eliminar_nodos_recursivo(padre.left());

               }else{

                    arbol.insert_right(padre, arbol_izq);
                    eliminar_nodos_recursivo(padre.right());
               }
          }
     }

     if(n.left().null() && !n.right().null()){

          bintree<Pregunta> arbol_der;
          arbol.prune_right(n, arbol_der);

          bintree<Pregunta>::node padre = n.parent();

          if (!padre.null()){

               if(padre.left() == n){

                    arbol.insert_left(padre, arbol_der);
                    eliminar_nodos_recursivo(padre.left());

               }else{

                    arbol.insert_right(padre, arbol_der);
                    eliminar_nodos_recursivo(padre.right());
               }
          }
     }
}



void QuienEsQuien::eliminar_nodos_redundantes(){

     if(!arbol.empty()){

          eliminar_nodos_recursivo(arbol.root());
     }
     
}

float QuienEsQuien::profundidad_promedio_hojas(){

     if (arbol.empty() || arbol.root().null()){

          return {};

     }

     vector <int> profundidades;

     

     if (profundidades.empty()){
          return -1;
     }

     float suma = 0;
     for (size_t i=0; i<profundidades.size(); ++i){
          suma += profundidades[i];
     }

     return suma / profundidades.size();
}

/**
* @brief Genera numero enteros positivos aleatorios en el rango [min,max].
**/
int generaEntero(int min, int max){
     int tam= max-min;
     return ((rand( )%tam)+min) ;
}

void QuienEsQuien::tablero_aleatorio(int numero_de_personajes){
     srand(0);
     this->limpiar();
     float log_2_numero_de_personajes = log(numero_de_personajes)/log(2);
     int numero_de_atributos = ceil(log_2_numero_de_personajes);

     cout <<  "Peticion para generar " <<  numero_de_personajes << " personajes ";
     cout <<  "con " << numero_de_atributos <<  " atributos" << endl;
     cout <<  "Paso 1: generar " <<  pow(2, numero_de_atributos) <<  " personajes" << endl;

     //Fase 1: completar el tablero con todos los personajes posibles
     //Complete el tablero y los nombres de personajes a la vez
     for(int indice_personaje=0;indice_personaje< pow(2,numero_de_atributos);indice_personaje++){
          vector<bool> atributos_personaje =
                                    convertir_a_vector_bool(indice_personaje,numero_de_atributos);
          string nombre_personaje = "Personaje_"+to_string(indice_personaje);

          this->personajes.push_back(nombre_personaje);
          this->tablero.push_back(atributos_personaje);
     }

     // Completo los nombres de los atributos.
     for( int indice_atributo=0;indice_atributo<numero_de_atributos;indice_atributo++){
          string nombre_atributo = "Atributo_"+to_string(indice_atributo);
          this->atributos.push_back(nombre_atributo);
     }
     cout <<  "Paso 2: eliminar " << (pow(2,numero_de_atributos)-numero_de_personajes) <<  "personajes" << endl;

     //Fase 2. Borrar personajes aleatoriamente hasta que quedan solo los que hemos pedido.
     while(personajes.size()>numero_de_personajes){
          int personaje_a_eliminar = generaEntero(0,personajes.size());
          personajes.erase(personajes.begin()+personaje_a_eliminar);
          tablero.erase(tablero.begin()+personaje_a_eliminar);
     }
}
void QuienEsQuien::ocultar_personajes_graph(const set<string> &personajes_activos){
    //ocultamos los personajes
    int idx=0;
    int ncols=tg->getNcols();
    for (auto it=personajes.begin();it!=personajes.end();++it,idx++){
        if ( personajes_activos.find(*it)==personajes_activos.end())
            tg->putImagen(idx/ncols,idx%ncols,imagen_ocultar.c_str());
    }
}


void QuienEsQuien::setImagenOcultar(const char * n){
    imagen_ocultar=n;
}

void QuienEsQuien::setModoGraph(bool m){
    modo_graph=m;
}

/*void QuienEsQuien::aniade_personaje (string nombre, vector<bool> caracteristica,
                                    string nombre_imagen_personaje= ""){

     bintree<Pregunta>::node n = arbol.root();

     //si esta vacio, creamos un arbol con la pregunta
     if (n.null()){

          arbol = bintree<Pregunta>(Pregunta(nombre, 1));
          return;          
     }

     if(n.left().null() && n.right().null() && n.operator*().es_personaje()){

          string personaje_existe = n.operator*().obtener_personaje();

          int atributo_distintivo = -1;
          for(size_t i = 0; i < atributos.size(); i++ ){

               if[atributos[i] != tablero[atributo_distintivo][i]]{

                    atributo_distintivo = i;
                    break;
               }
          }
     }

     



}*/