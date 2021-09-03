#include <iostream>
#include <vector>
#include <tuple>
#include <limits>
using namespace std;
struct Alumno{
	string nombre;
	float nota;
};
class Curso {
public:
	Curso(string nombre_materia, int nro_alumnos) : m_nombre_materia(nombre_materia), m_nro_alumnos(nro_alumnos) {
		
	}
	void AgregarAlumno(string nombre, int calificacion) {
		Alumno aux;
		aux.nombre = nombre;
		aux.nota = calificacion;
		m_lista_alumnos.push_back(aux);
	}
	float PromedioCurso() {
		float promedio = 0;
		for(size_t i=0;i<m_lista_alumnos.size();++i) {
			promedio += m_lista_alumnos[i].nota;
		}
		return promedio;
	}
	Alumno CalificacionMasAlta() {
		Alumno mejor_calificacion;
		mejor_calificacion.nota = numeric_limits<float>::min();
		for(size_t i=0;i<m_lista_alumnos.size();++i) {
			if(m_lista_alumnos[i].nota>mejor_calificacion.nota) {
				mejor_calificacion.nota = m_lista_alumnos[i].nota;
				mejor_calificacion.nombre = m_lista_alumnos[i].nombre;
			}
		}
		return mejor_calificacion;
	}
//	tuple<string,int> CalificacionMasAlta() {
//		int mejor_calificacion = numeric_limits<int>::min();
//		string nombre;
//		for(size_t i=0;i<m_lista_alumnos.size();++i) {
//			if(m_lista_alumnos[i].nota>mejor_calificacion) {
//				mejor_calificacion = m_lista_alumnos[i].nota;
//				nombre = m_lista_alumnos[i].nombre;
//			}
//		}
//		return make_tuple(nombre,mejor_calificacion);
	
private:
	string m_nombre_materia;
	int m_nro_alumnos;
	vector<Alumno> m_lista_alumnos;

};
int main() {
//		Se dispone del siguiente tipo de dato:
//		struct Alumno{
//			string nombre;
//			float nota;
//		};
//		En base al mismo se desea crear una clase Curso para modelar el cursado de una
//		materia. La clase deber� contener el nombre de la materia y la cantidad de
//		alumnos en el curso junto con una lista de los mismos. Proponga los siguientes
//		m�todos:
//		a. Constructores y destructores seg�n lo considere conveniente.
//		b. Un m�todo que permita agregar un Alumno.
//		c. Un m�todo que determine el promedio del curso.
//		d. Un m�todo que devuelva la calificaci�n m�s alta y el nombre del alumno
//		que la obtuvo.
	int nro_alumnos;
	cout << "Ingrese el numero de alumnos: "; cin >> nro_alumnos;
	Curso Algebra2020("Algebra", nro_alumnos);
	string nombre;
	float calificacion;
	for(int i=0;i<nro_alumnos;i++) {
		cin.ignore();
		cout << "ingrese el nombre del alumno a agregar: "; getline(cin, nombre);
		cout << "ingrese la calificacion del alumno: "; cin >> calificacion;
		Algebra2020.AgregarAlumno(nombre,calificacion);
	}
	
	cout << "El promedio del curso es de " << Algebra2020.PromedioCurso() << endl;

	Alumno mejor_calificacion = Algebra2020.CalificacionMasAlta();
	cout << "La calificacion mas alta es " << mejor_calificacion.nota << " del alumno " << mejor_calificacion.nombre << endl;
	
	return 0;
}

