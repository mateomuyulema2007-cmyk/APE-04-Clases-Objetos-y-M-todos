#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

// ==========================================
// CLASE ESTUDIANTE
// ==========================================
class Estudiante {
private:
    // Atributos privados para asegurar el encapsulamiento de los datos
    string cedula;
    string nombre;
    string apellido;
    double nota1;
    double nota2;
    double nota3;
    double promedio;
    string estado;

public:
    // Constructor por defecto para inicializar valores limpios
    Estudiante() {
        this->nota1 = 0.0;
        this->nota2 = 0.0;
        this->nota3 = 0.0;
        this->promedio = 0.0;
        this->estado = "Reprobado";
    }

    // Constructor parametrizado para la carga directa de datos
    Estudiante(string cedula, string nombre, string apellido, double n1, double n2, double n3) {
        this->cedula = cedula;
        this->nombre = nombre;
        this->apellido = apellido;
        this->nota1 = n1;
        this->nota2 = n2;
        this->nota3 = n3;
        // Los cálculos de rendimiento se ejecutan inmediatamente al instanciar
        calcularPromedio();
        determinarEstado();
    }

    // MÉTODOS GETTERS Y SETTERS
    string getCedula() const { return cedula; }
    void setCedula(string cedula) { this->cedula = cedula; }

    string getNombre() const { return nombre; }
    void setNombre(string nombre) { this->nombre = nombre; }

    string getApellido() const { return apellido; }
    void setApellido(string apellido) { this->apellido = apellido; }

    // Si se modifica una nota de forma externa, el promedio y el estado se recalculan al instante
    double getNota1() const { return nota1; }
    void setNota1(double n1) { this->nota1 = n1; calcularPromedio(); determinarEstado(); }

    double getNota2() const { return nota2; }
    void setNota2(double n2) { this->nota2 = n2; calcularPromedio(); determinarEstado(); }

    double getNota3() const { return nota3; }
    void setNota3(double n3) { this->nota3 = n3; calcularPromedio(); determinarEstado(); }

    double getPromedio() const { return promedio; }
    string getEstado() const { return estado; }

    // Realiza el cálculo del promedio aritmético de las tres notas ingresadas
    void calcularPromedio() {
        this->promedio = (this->nota1 + this->nota2 + this->nota3) / 3.0;
    }

    // Evalúa la condición final del alumno basándose en el puntaje de corte (7.00)
    void determinarEstado() {
        if (this->promedio >= 7.00) {
            this->estado = "Aprobado";
        } else {
            this->estado = "Reprobado";
        }
    }

    // Envía a la consola la fila de datos formateada y alineada en columnas
    void mostrarInformacion() const {
        cout << left << setw(12) << cedula
             << setw(15) << nombre
             << setw(15) << apellido
             << setw(8) << fixed << setprecision(2) << nota1
             << setw(8) << nota2
             << setw(8) << nota3
             << setw(10) << promedio
             << setw(12) << estado << endl;
    }
};

// ==========================================
// MÉTODOS AUXILIARES DE VALIDACIÓN
// ==========================================

/**
 * Filtra la entrada de la cédula asegurando que contenga un formato numérico
 * válido de 10 dígitos y correspondencia regional correcta (Ecuador).
 */
string ingresarCedulaValidada() {
    string ced;
    while (true) {
        cout << "Ingrese Cedula: ";
        cin >> ced;

        // Valida que tenga exactamente 10 caracteres
        if (ced.length() != 10) {
            cout << "[Error] Formato incorrecto. Ingrese exactamente 10 numeros.\n";
            continue;
        }

        // Valida que todos los caracteres ingresados sean numéricos
        bool esNumerico = true;
        for (char c : ced) {
            if (!isdigit(c)) {
                esNumerico = false;
                break;
            }
        }

        if (!esNumerico) {
            cout << "[Error] Formato incorrecto. Ingrese exactamente 10 numeros.\n";
            continue;
        }

        // Comprobación del código de provincia (primeros dos números)
        // stoi convierte el sub-string de los 2 primeros caracteres a entero
        int provincia = stoi(ced.substr(0, 2));
        if ((provincia >= 1 && provincia <= 24) || provincia == 30) {
            return ced;
        } else {
            cout << "[Error] Region o provincia no identificada en el territorio nacional.\n";
        }
    }
}

/**
 * Restringe el flujo de captura de calificaciones para mantenerlas
 * dentro de la escala numérica de 0.00 a 10.00 puntos.
 */
double ingresarNotaValidada(string mensaje) {
    double nota;
    while (true) {
        cout << mensaje;
        // Si la entrada es un número válido y está en el rango [0, 10]
        if (cin >> nota && nota >= 0 && nota <= 10) {
            return nota;
        } else {
            cout << "[Error] Rango no valido (Debe ser entre 0 y 10). Intente nuevamente.\n";
            cin.clear(); // Limpia los flags de error del flujo cin
            cin.ignore(10000, '\n'); // Descarta caracteres incorrectos del buffer (como letras)
        }
    }
}

// ==========================================
// CONTROLADOR PRINCIPAL
// ==========================================
int main() {
    vector<Estudiante> listaEstudiantes; // Reemplazo directo de ArrayList en C++
    int limiteEstudiantes = 5;

    cout << "=== SISTEMA DE CONTROL DE ESTUDIANTES Y CALIFICACIONES ===\n";
    cout << "Asignatura: Algoritmos y Logica de Programacion\n\n";

    // Captura estructurada de datos por consola
    for (int i = 0; i < limiteEstudiantes; i++) {
        cout << "--- Registro del Estudiante " << (i + 1) << " ---\n";

        string cedula = ingresarCedulaValidada();

        string nombre, apellido;
        cout << "Ingrese Nombre: ";
        cin >> nombre;
        cout << "Ingrese Apellido: ";
        cin >> apellido;

        double n1 = ingresarNotaValidada("Ingrese Nota 1: ");
        double n2 = ingresarNotaValidada("Ingrese Nota 2: ");
        double n3 = ingresarNotaValidada("Ingrese Nota 3: ");
        cout << endl;

        // Construcción del objeto y almacenamiento en el vector dinámico
        Estudiante estudiante(cedula, nombre, apellido, n1, n2, n3);
        listaEstudiantes.push_back(estudiante);
    }

    // Impresión del reporte general resumido
    cout << "========================================= LISTADO DE ESTUDIANTES =========================================\n";
    cout << left << setw(12) << "Cedula"
         << setw(15) << "Nombre"
         << setw(15) << "Apellido"
         << setw(8) << "Nota 1"
         << setw(8) << "Nota 2"
         << setw(8) << "Nota 3"
         << setw(10) << "Promedio"
         << setw(12) << "Estado" << endl;
    cout << "----------------------------------------------------------------------------------------------------------\n";

    int acumuladorAprobados = 0;
    int acumuladorReprobados = 0;

    // Recorrido de los objetos para la extracción de métricas cuantitativas
    for (const auto& est : listaEstudiantes) {
        est.mostrarInformacion();
        if (est.getEstado() == "Aprobado") {
            acumuladorAprobados++;
        } else {
            acumuladorReprobados++;
        }
    }
    cout << "==========================================================================================================\n";

    // Bloque informativo final de estadísticas
    cout << "=== ESTADISTICAS FINALIZADAS ===\n";
    cout << "Cantidad de estudiantes aprobados: " << acumuladorAprobados << endl;
    cout << "Cantidad de estudiantes reprobados: " << acumuladorReprobados << endl;

    return 0;
}
