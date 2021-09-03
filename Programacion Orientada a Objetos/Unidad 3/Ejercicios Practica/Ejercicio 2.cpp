#include <iostream>
#include <vector>
using namespace std;
class Alumno{
public:
	Alumno(string nombre, string apellido, int dni, int fecha_nacimiento, float promedio, int materias_aprobadas) {
		m_nombre = nombre;
		m_apellido = apellido;
		m_dni = dni;
		m_fecha_nacimiento = fecha_nacimiento;
		m_promedio = promedio;
		m_materias_aprobadas = materias_aprobadas;
	}
	string VerNombre() { return m_nombre; }
	string VerApellido(){ return m_apellido; }
	int VerEdad(int fecha_actual) { 
		//Descomposicion de la fecha de nacimiento
		int anio_naci, mes_naci, dia_naci;
		anio_naci = m_fecha_nacimiento / 10000;
		mes_naci = (m_fecha_nacimiento % 10000) /100;
		dia_naci = ((m_fecha_nacimiento % 10000) % 1000) % 100;
		//Descomposicion de la fecha actual
		int anio_actual, mes_actual, dia_actual;
		anio_actual = fecha_actual / 10000;
		mes_actual = (fecha_actual % 10000) /100;
		dia_actual = ((fecha_actual % 10000) % 1000) % 100;
		int edad = anio_actual-anio_naci;
		if(mes_naci == mes_actual) {
			if(dia_naci>dia_actual) {
				edad -= 1;
			} 
		} else {
			if(mes_naci > mes_actual) {
				edad -= 1;
			}
		}
		return edad;
	}
	int VerDni() { return m_dni; }
	int VerPromedioAlumno() { return m_promedio; }
	float MeritoAcademico(float promedio, int materias_aprobadas) { return promedio*materias_aprobadas; }
private:
	string m_nombre, m_apellido;
	int m_dni;
	int m_fecha_nacimiento;
	float m_promedio;
	int m_materias_aprobadas;
};
class Docente{
public:
	Docente(string nombre) { m_nombre = nombre; }
	Docente(string nombre, string apellido, int fecha_nacimiento, string estado_civil, int fecha_ingreso) {
		m_nombre = nombre;
		m_apellido = apellido;
		m_fecha_nacimiento = fecha_nacimiento;
		m_estado_civil = estado_civil;
		m_fecha_ingreso = fecha_ingreso;
	}
	string VerNombreDocente() { return m_nombre; }
	string VerApellidoDocente() { return m_apellido; }
	string VerEstadoCivil() { return m_estado_civil; }
	int Antiguedad(int fecha_ingreso) {
		//Descomposicion de la fecha de nacimiento
		int anio_naci, mes_naci, dia_naci;
		anio_naci = m_fecha_nacimiento / 10000;
		mes_naci = (m_fecha_nacimiento % 10000) /100;
		dia_naci = ((m_fecha_nacimiento % 10000) % 1000) % 100;
		//Descomposicion de la fecha de ingreso
		int anio_ingreso, mes_ingreso, dia_ingreso;
		anio_ingreso = fecha_ingreso / 10000;
		mes_ingreso = (fecha_ingreso % 10000) /100;
		dia_ingreso = ((fecha_ingreso % 10000) % 1000) % 100;
		int antiguedad = anio_ingreso-anio_naci;
		if(mes_naci == mes_ingreso) {
			if(dia_naci>dia_ingreso) {
				antiguedad -= 1;
			} 
		} else {
			if(mes_naci > mes_ingreso) {
				antiguedad -= 1;
			}
		}
		return antiguedad;
	}
private:
	string m_nombre;
	string m_apellido;
	int m_fecha_nacimiento;
	string m_estado_civil;
	int m_fecha_ingreso;
};
class Curso {
public:
	Curso(string nombre_curso, Docente d) : m_nombre_curso(nombre_curso), m_docente(d) {
		
	}
	void AgregarAlumnos(Alumno a) {
		m_vector_alumnos.push_back(a);
	}
	string VerNombreCurso() { return m_nombre_curso; }
	Docente VerNombreDocente() { return m_docente; }
	int MejorPromedio() {
		float mejorprom =  -1;
		for(size_t i=0;i<m_vector_alumnos.size();i++) {
			if(m_vector_alumnos[i].VerPromedioAlumno()>mejorprom) {
				mejorprom = m_vector_alumnos[i].VerPromedioAlumno();
			}
		}
		return mejorprom;
	}
private:
	string m_nombre_curso;
	Docente m_docente;
	vector<Alumno> m_vector_alumnos;
};
int main() {
	//		Utilice las clases Alumno y Docente del ejercicio anterior para crear una clase
	//		Curso que modele el cursado de una materia. Cada curso tiene un nombre, un
	//		profesor a cargo y un número máximo de 50 alumnos. Implemente un método
	//		AgregarAlumno(...) que permita agregar un alumno al curso y otro método
	//		MejorPromedio(...) que devuelva el alumno con mejor promedio. Proponga los
	//		constructores y métodos extra que considere necesarios.
	Docente d("Pablo"); //cree el docente
	Curso poo2020("P.O.O", d);
	for(size_t i=0;i<51;i++) {
		string nombre, apellido;
		int dni, fecha_nacimiento;
		float promedio;
		int materias_aprob;
		cout << "Ingrese nombre, apellido, dni, fecha de nacimiento, promedio y Nº de materias aprobadas del alumno Nº" << i+1 << ": ";
		cin >> nombre; cin >> apellido; cin >> dni; cin >> fecha_nacimiento; cin >> promedio; cin >> materias_aprob;
		Alumno a(nombre, apellido, dni, fecha_nacimiento, promedio, materias_aprob);
	}
	cout << "El mejor promedio de la clase es de: " << poo2020.MejorPromedio() << endl;
	return 0;
}
