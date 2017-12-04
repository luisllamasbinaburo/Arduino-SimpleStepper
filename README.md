# Librería Arduino SimpleStepper

La librería SimpleStepper implementa las acciones necesarias para controlar un motor paso a paso unipolar, como el 28BYJ-48. Es una alternativa conveniente a clases más complejas como la librería Stepper.

Más información https://www.luisllamas.es/libreria-arduino-simplestepper/


## Instrucciones de uso

La clase SimpleStepper es un objeto sencillo que únicamente contiene las secuencias de pasos. Únicamente dispone de dos métodos, CW y CCW, que avanzan un paso respectivamente en sentido horario y anti horario.

La instancia del objeto no conoce ni el número de pasos del motor, ni el estado del mismo. Estas deberán ser controladas desde un nivel superior.

En el constructor de la tarea podemos especificar la secuencia deseada, siendo posible Halfphase, OnePhase y TwoPhases. La secuencia por defecto es HalfPhase.

La librería SimpleStepper está principalmente pensada para emplearse de forma conjunta a AsyncStepper, permitiendo manejar múltiples motores paso a paso con velocidades independientes de forma sencilla y no bloqueante.

### Comstructor
La clase SimpleStepper se instancia a través de uno de sus constructores
```c++
SimpleStepper(uint8_t pin1, uint8_t pin2, uint8_t pin3, uint8_t pin4)
SimpleStepper(SecuenceType secuenceType, uint8_t pin1, uint8_t pin2, uint8_t pin3, uint8_t pin4)
```

### Uso de SimpleStepper
```c++
// Mover en el sentido horario
void CW();

// Mover en el sentido antihorario
void CCW();
```


## Ejemplos
La librería SimpleStepper incluye los siguientes ejemplos para ilustrar su uso.

* SImpleStepper: Ejemplo que muestra como hacer un efecto balanceo con AsyncServo
```c++
#include "SimpleStepperLib.h"

SimpleStepper stepper(SimpleStepper::HalfStep, 8, 9, 10, 11);
int motorSpeed = 1200;

void setup()
{
	Serial.begin(9600);
}

void loop()
{
	for (auto i = 0; i < 20; i++)
	{
		stepper.CW();
		delayMicroseconds(motorSpeed);
	}

	for (auto i = 0; i < 20; i++)
	{
		stepper.CCW();
		delayMicroseconds(motorSpeed);
	}
}
```
