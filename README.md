# APE-04-Clases-Objetos-y-M-todos
# Sistema de Control de Estudiantes y Calificaciones

Este repositorio contiene la solución práctica de programación orientada a objetos (POO) descrita en la guía **SW-AyLP-APE-04: Clases, Objetos y Métodos** para la asignatura de *Algoritmos y Lógica de Programación*. 

El proyecto consiste en el desarrollo de un sistema básico que permite registrar información académica de los estudiantes utilizando estructuras orientadas a objetos tanto en **C++** como en **Java**, promoviendo la reutilización de código y la reducción de errores.

---

##  Descripción del Problema

El sistema permite gestionar la información y notas de un grupo de estudiantes. Cada objeto de la clase `Estudiante` almacena atributos específicos, calcula el promedio de forma automática y determina su estado académico final.

### Datos del Estudiante:
* **Cédula** (Identificación única)
* **Nombre**
* **Apellido**
* **Nota 1** (Validada entre 0 y 10)
* **Nota 2** (Validada entre 0 y 10)
* **Nota 3** (Validada entre 0 y 10)
* **Promedio** (Calculado automáticamente)
* **Estado** (Aprobado o Reprobado)

---

##  Requerimientos del Programa

El sistema implementa la clase "Estudiante" bajo los estándares de encapsulamiento y buenas prácticas de POO:

### Estructura de la Clase (`Estudiante`)
1. **Atributos privados:** Protección de datos miembro mediante encapsulamiento.
2. **Constructor:** Inicialización de las variables del objeto.
3. **Métodos Get y Set:** Acceso y modificación segura de los atributos.
4. **Método para calcular el promedio:** Suma de las 3 notas dividida para 3.
5. **Método para determinar si aprueba o reprueba:** Evaluación del estado según el promedio obtenido.
6. **Método para mostrar la información:** Impresión formateada de los datos del estudiante.

---

##  Funcionalidades Mínimas Implementadas

1. **Registro de Estudiantes:** Permite registrar un mínimo de 5 estudiantes en el sistema.
2. **Ingreso de Calificaciones:** Captura de las 3 notas independientes por cada alumno.
3. **Cálculo Automático:** Procesamiento inmediato del promedio y estado una vez ingresadas las notas.
4. **Reporte General:** Muestra el listado completo y ordenado con toda la información registrada.
5. **Métricas de Rendimiento:** * Contador total de estudiantes **Aprobados**.
   * Contador total de estudiantes **Reprobados**.
6. **Validación de Datos:** Restricción estricta para asegurar que ninguna nota sea menor a 0 o mayor a 10.
7. **Código Limpio:** Todo el código fuente en C++ y Java se encuentra debidamente documentado y comentado.
