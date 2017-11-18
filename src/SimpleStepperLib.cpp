/***************************************************
Copyright (c) 2017 Luis Llamas
(www.luisllamas.es)

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
****************************************************/

#include "SimpleStepperLib.h"

SimpleStepper::SimpleStepper(uint8_t pin1, uint8_t pin2, uint8_t pin3, uint8_t pin4)
	: SimpleStepper(SimpleStepper::HalfStep, pin1, pin2, pin3, pin4)
{
}

SimpleStepper::SimpleStepper(SecuenceType secuenceType, uint8_t pin1, uint8_t pin2, uint8_t pin3, uint8_t pin4)
{
	if (secuenceType == SimpleStepper::OnePhase)
	{
		stepCount = 4;
		secuence = onePhaseSecuence;
	}
	else if(secuenceType == SimpleStepper::TwoPhases)
	{
		stepCount = 4;
		secuence = twoPhaseSecuence;
	}
	else
	{
		stepCount = 8;
		secuence = halfStepSecuence;
	}

	Pin1 = pin1;
	Pin2 = pin2;
	Pin3 = pin3;
	Pin4 = pin4;

	pinMode(Pin1, OUTPUT);
	pinMode(Pin2, OUTPUT);
	pinMode(Pin3, OUTPUT);
	pinMode(Pin4, OUTPUT);
}


void SimpleStepper::CW()
{
	stepIndex++;
	if (stepIndex >= stepCount) stepIndex = 0;
	setOutput();
}

void SimpleStepper::CCW()
{
	stepIndex--;
	if (stepIndex >= stepCount) stepIndex = stepCount - 1;
	setOutput();
}

void SimpleStepper::setOutput() const
{
	digitalWrite(Pin1, bitRead(secuence[stepIndex], 0));
	digitalWrite(Pin2, bitRead(secuence[stepIndex], 1));
	digitalWrite(Pin3, bitRead(secuence[stepIndex], 2));
	digitalWrite(Pin4, bitRead(secuence[stepIndex], 3));
}
