import java.util.ArrayList;
import java.util.Scanner;

//Clase Main
public class Main {

    // CLASE ESTUDIANTE
    public static class Estudiante {
        // Atributos privados para asegurar el encapsulamiento de los datos
        private String cedula;
        private String nombre;
        private String apellido;
        private double nota1;
        private double nota2;
        private double nota3;
        private double promedio;
        private String estado;

        // Constructor por defecto para inicializar valores limpios
        public Estudiante() {
            this.nota1 = 0.0;
            this.nota2 = 0.0;
            this.nota3 = 0.0;
            this.promedio = 0.0;
            this.estado = "Reprobado";
        }

        // Constructor parametrizado para la carga directa de datos
        public Estudiante(String cedula, String nombre, String apellido, double n1, double n2, double n3) {
            this.cedula = cedula;
            this.nombre = nombre;
            this.apellido = apellido;
            this.nota1 = n1;
            this.nota2 = n2;
            this.nota3 = n3;
            // Los cálculos de rendimiento se ejecutan inmediatamente al instanciar
            calcularPromedio();
            determinarEstado();
        }

        // MÉTODOS GETTERS Y SETTERS
        public String getCedula() { return cedula; }
        public void setCedula(String cedula) { this.cedula = cedula; }

        public String getNombre() { return nombre; }
        public void setNombre(String nombre) { this.nombre = nombre; }

        public String getApellido() { return apellido; }
        public void setApellido(String apellido) { this.apellido = apellido; }

        // Si se modifica una nota de forma externa, el promedio y el estado se recalculan al instante
        public double getNota1() { return nota1; }
        public void setNota1(double n1) { this.nota1 = n1; calcularPromedio(); determinarEstado(); }

        public double getNota2() { return nota2; }
        public void setNota2(double n2) { this.nota2 = n2; calcularPromedio(); determinarEstado(); }

        public double getNota3() { return nota3; }
        public void setNota3(double n3) { this.nota3 = n3; calcularPromedio(); determinarEstado(); }

        public double getPromedio() { return promedio; }
        public String getEstado() { return estado; }
        
        // Realiza el cálculo del promedio aritmético de las tres notas ingresadas
        public void calcularPromedio() {
            this.promedio = (this.nota1 + this.nota2 + this.nota3) / 3.0;
        }

        // Evalúa la condición final del alumno basándose en el puntaje de corte (7.00)
        public void determinarEstado() {
            if (this.promedio >= 7.00) {
                this.estado = "Aprobado";
            } else {
                this.estado = "Reprobado";
            }
        }

        // Envía a la consola la fila de datos formateada y alineada en columnas
        public void mostrarInformacion() {
            System.out.printf("%-12s %-15s %-15s %-8.2f %-8.2f %-8.2f %-10.2f %-12s\n", 
                    cedula, nombre, apellido, nota1, nota2, nota3, promedio, estado);
        }
    }

    // MÉTODOS AUXILIARES DE VALIDACIÓN

    private static String ingresarCedulaValidada(Scanner scanner) {
        String ced;
        while (true) {
            System.out.print("Ingrese Cedula: ");
            ced = scanner.next();
            
            // Valida los 10 dígitos obligatorios usando expresiones regulares
            if (ced.matches("\\d{10}")) {
              
                int provincia = Integer.parseInt(ced.substring(0, 2));
                if ((provincia >= 1 && provincia <= 24) || provincia == 30) {
                    return ced;
                } else {
                    System.out.println("[Error] Región o provincia no identificada en el territorio nacional.");
                }
            } else {
                System.out.println("[Error] Formato incorrecto. Ingrese exactamente 10 numeros.");
            }
        }
    }

    
    private static double ingresarNotaValidada(Scanner scanner, String mensaje) {
        double nota;
        while (true) {
            System.out.print(mensaje);
            if (scanner.hasNextDouble()) {
                nota = scanner.nextDouble();
                if (nota >= 0 && nota <= 10) {
                    return nota;
                }
            } else {
                scanner.next(); // Limpieza del buffer del scanner ante ingresos tipo String
            }
            System.out.println("[Error] Rango no válido (Debe ser entre 0 y 10). Intente nuevamente.");
        }
    }

    // CONTROLADOR PRINCIPAL
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<Estudiante> listaEstudiantes = new ArrayList<>();
        int limiteEstudiantes = 5;

        System.out.println("=== SISTEMA DE CONTROL DE ESTUDIANTES Y CALIFICACIONES ===");
        System.out.println("Asignatura: Algoritmos y Logica de Programacion\n");

        // Captura estructurada de datos por consola
        for (int i = 0; i < limiteEstudiantes; i++) {
            System.out.println("--- Registro del Estudiante " + (i + 1) + " ---");
            
            String cedula = ingresarCedulaValidada(scanner);
            
            System.out.print("Ingrese Nombre: ");
            String nombre = scanner.next();
            System.out.print("Ingrese Apellido: ");
            String apellido = scanner.next();

            double n1 = ingresarNotaValidada(scanner, "Ingrese Nota 1: ");
            double n2 = ingresarNotaValidada(scanner, "Ingrese Nota 2: ");
            double n3 = ingresarNotaValidada(scanner, "Ingrese Nota 3: ");
            System.out.println();

            // Construcción del objeto y almacenamiento en el arreglo dinámico
            Estudiante estudiante = new Estudiante(cedula, nombre, apellido, n1, n2, n3);
            listaEstudiantes.add(estudiante);
        }

        // Impresión del reporte general resumido
        System.out.println("========================================= LISTADO DE ESTUDIANTES =========================================");
        System.out.printf("%-12s %-15s %-15s %-8s %-8s %-8s %-10s %-12s\n", 
                "Cedula", "Nombre", "Apellido", "Nota 1", "Nota 2", "Nota 3", "Promedio", "Estado");
        System.out.println("----------------------------------------------------------------------------------------------------------");

        int acumuladorAprobados = 0;
        int acumuladorReprobados = 0;

        // Recorrido de los objetos para la extracción de métricas cuantitativas
        for (Estudiante est : listaEstudiantes) {
            est.mostrarInformacion();
            if (est.getEstado().equals("Aprobado")) {
                acumuladorAprobados++;
            } else {
                acumuladorReprobados++;
            }
        }
        System.out.println("==========================================================================================================");

        // Bloque informativo final de estadísticas
        System.out.println("=== ESTADISTICAS FINALIZADAS ===");
        System.out.println("Cantidad de estudiantes aprobados: " + acumuladorAprobados);
        System.out.println("Cantidad de estudiantes reprobados: " + acumuladorReprobados);
        
        scanner.close();
    }
}
