#include <iostream>

using namespace std;
class Persona {
public:
	Persona();
	Persona(string apellido_nombre,int dni, int fecha_nacimiento, string estado_civil);
	int Edad(int fecha_nacimiento, int fecha_actual);
	string VerNombre() { return m_apellido_nombre; }
	int VerDni() { return m_dni; }
private:
	string m_apellido_nombre;
	int m_dni, m_fecha_nacimiento;
	string m_estado_civil;
}; //listo
class Alumno : public Persona {
public:
	Alumno();
	Alumno(string apellido_nombre,int dni, int fecha_nacimiento, string estado_civil, float promedio, int materias_aprobadas) : Persona(apellido_nombre, dni, fecha_nacimiento, estado_civil) {
		m_promedio = promedio;
		m_materias_aprobadas = materias_aprobadas;
	}
	float MeritoAcademico(float promedio, int materias_aprobadas) { return promedio*materias_aprobadas; }
private:
	float m_promedio;
	int m_materias_aprobadas;
}; // listo
class Docente : public Persona {
public:
	Docente();
	Docente(string apellido_nombre,int dni, int fecha_nacimiento, string estado_civil, int fecha_ingreso) : Persona(apellido_nombre,dni,fecha_nacimiento,estado_civil) {
		m_fecha_ingreso = fecha_ingreso;
	}
	int Antiguedad(int fecha_nacimiento, int fecha_ingreso);
	
private:
	int m_fecha_ingreso;
};
int main() {
//		DiseÒe una clase Persona que contenga los siguientes atributos: apellido y
//		nombre, DNI, fecha de nacimiento y estado civil. La clase debe poseer, ademas, un
//		metodo Edad(...) que calcule la edad actual de la persona en base a la fecha de
//		nacimiento y la fecha actual (que recibe como argumento).
//		Implemente una clase Alumno para contener la siguiente informacion de un
//		alumno: apellido y nombre, DNI, ano de nacimiento, estado civil, promedio y
//		cantidad de materias aprobadas. La clase debe poseer, ademas, un metodo
//		MeritoAcademico() que devuelve el merito academico del alumno (este se calcula
//																	   como el producto entre el promedio y la cantidad de materias aprobadas).
//		Cree, tambien, una clase Docente para modelar un docente a partir de la siguiente
//		informacion: apellido y nombre, DNI, ano de nacimiento, estado civil y fecha de
//		ingreso. La clase debe poseer, ademas, un metodo Antiguedad() que calcule la
//		antiguedad del docente en base a su fecha de ingreso y la fecha actual.
//		Proponga una jerarquia de clases adecuada para evitar repetir atributos.
//		Implemente constructores y metodos extra que considere adecuados. Codifique un
//		programa cliente que cree instancias de Alumno y Docente y utilice sus funciones.
//		Responda:
//		Å.Puede crearse un objeto de tipo persona? .Para que sirve esto?
//		Å.Existe alguna clase abstracta en la jerarquia?
	int fecha_actual, fecha_nacimiento_conserje;
	cout << "Ingrese la fecha actual: "; cin >> fecha_actual;
	cout << "Ingrese la fecha de nacimiento del conserje: "; cin >> fecha_nacimiento_conserje;
	
	Persona conserje("Rodrigo Lazarte", 78213414, fecha_nacimiento_conserje, "Soltero" );
	cout << "El Sr/a " << conserje.VerNombre() << " tiene " << conserje.Edad(fecha_nacimiento_conserje, fecha_actual) << " aÒos" << endl;
	
	float promedio; int materias_aprobadas;
	cout <<"Ingrese el promedio del chico: "; cin >> promedio;
	cout <<"Ingrese el N∫ de materias aprobadas: "; cin >> materias_aprobadas;
	
	Alumno chico("Ezequiel Lazarte", 77842242, 19990328, "Casado", promedio, materias_aprobadas);
	cout << "El merito academico de " << chico.VerNombre() << " es un total de " << chico.MeritoAcademico(promedio,materias_aprobadas) << "%" << endl;
	
	
	int fecha_ingreso, fecha_nacimiento_adulto;
	cout << "Ingrese la fecha de ingreso del adulto: "; cin >> fecha_ingreso;
	cout << "Ingrese la fecha de nacimiento del adulto: "; cin >> fecha_nacimiento_adulto;
	
	Docente adulto("Luis Lazarte", 66423523, fecha_nacimiento_adulto, "Casado", fecha_ingreso);
	cout << "La antiguedad de " << adulto.VerNombre() << " como docente es de " << adulto.Antiguedad(fecha_nacimiento_adulto,fecha_ingreso) << " aÒos" << endl;
	// si puede crearse un objeto de tipo persona y sirve como base para otras clases mas especificas
	// ...
	return 0;
}
Persona::Persona(string apellido_nombre, int dni, int fecha_nacimiento, string estado_civil) {
	m_apellido_nombre = apellido_nombre;
	m_dni = dni;
	m_fecha_nacimiento = fecha_nacimiento;
	m_estado_civil = estado_civil;
}
int Persona::Edad(int fecha_nacimiento, int fecha_actual) { // listo
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
int Docente::Antiguedad(int fecha_nacimiento, int fecha_ingreso) {
	//Descomposicion de la fecha de nacimiento
	int anio_naci, mes_naci, dia_naci;
	anio_naci = fecha_nacimiento / 10000;
	mes_naci = (fecha_nacimiento % 10000) /100;
	dia_naci = ((fecha_nacimiento % 10000) % 1000) % 100;
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
