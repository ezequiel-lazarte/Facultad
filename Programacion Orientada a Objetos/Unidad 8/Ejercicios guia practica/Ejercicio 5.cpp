#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
struct FichaMedico{
	string nombreMedico;
	vector<long> dniPacientes;
};
class Clinica{
public:
	Clinica();
	void AgregarMedico(string nombre, int nro_medico);
	void AgregarPaciente(int nro_medico, int DNI); // a)
	stringstream ListaMedico(int nro_medico); // b)
	void EliminaPaciente(int DNI); // c)
	void VerNombreMedico(int nro_medico);
private:
	vector<FichaMedico> m_f;
};
int main() {
	/**La clase será utilizada para administrar los pacientes de una clínica. La clínica está
	conformada por 6 médicos y cada uno de ellos atiende a un número variable de
	pacientes.
	Crear una clase llamada Clinica que posea funciones para:
	a. Incorporar nuevos pacientes indicando el número de médico y el DNI del
	paciente.
	b. Listar el nombre de cada médico y los DNI de los pacientes que atiende.
	c. Eliminar un paciente indicando solamente su DNI.
	Utilice la clase desarrollada desde un programa cliente.
	**/
	int n=6;
	Clinica sayago;
	string medico; int nro_medico=0;
	for(int i=0;i<n;i++) { 
		cout << "Ingrese el nombre del medico y luego el numero: "; getline(cin, medico); cin >> nro_medico;
		sayago.AgregarMedico(medico, nro_medico-1);
	}
	int dni_paciente; nro_medico=0;
	while(nro_medico!=-1) {
		cout << "Ingrese dni del paciente y luego el numero del medico: "; cin >> dni_paciente >> nro_medico;
		sayago.AgregarPaciente(nro_medico, dni_paciente);
	}
	cout << "Ingrese el numero de medico para ver la lista de pacientes: "; cin >> nro_medico;
	cout << "La lista del medico " << sayago.VerNombreMedico(nro_medico) << " es: " << endl << sayago.ListaMedico(nro_medico) << endl;
	return 0;
}
Clinica::Clinica() { m_f.resize(m_f.size()+6); }
void Clinica::AgregarMedico(string nombre, int nro_medico) {
	m_f[nro_medico].nombreMedico = nombre;
}
void Clinica::AgregarPaciente(int nro_medico, int DNI) { m_f[nro_medico].dniPacientes.push_back(DNI); }
stringstream Clinica::ListaMedico(int nro_medico) {
	stringstream ficha;
	ficha << m_f[nro_medico].nombreMedico << << endl;
	for(size_t i=0;i<m_f[nro_medico].dniPacientes.size();i++) { 
		ficha << "Dni Nº" << i+1 << ": " << m_f[nro_medico].dniPacientes[i] << endl;
	}
	return ficha;
}
void Clinica::VerNombreMedico(int nro_medico) {
	return << m_f[nro_medico].nombreMedico << << endl;
}
void Clinica::EliminaPaciente(int DNI) {
	for(size_t i=0;i<m_f.size();i++) { 
		auto it = find(m_f[i].dniPacientes.begin(),m_f[i].dniPacientes.end(),DNI);
		if(it!=it.end()) {
			*it.erase();
			break;
		}
	}
}
ostream operator<<(stringstream &x) {
	x << 
}
