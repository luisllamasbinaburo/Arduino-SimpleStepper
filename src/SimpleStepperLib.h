/***************************************************
Copyright (c) 2017 Luis Llamas
(www.luisllamas.es)

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
****************************************************/

#ifndef _SIMPLESTEPPERLIB_h
#define _SIMPLESTEPPERLIB_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class SimpleStepper
{
public:
	typedef enum
	{
		HalfStep,
		OnePhase,
		TwoPhases,
	}  SecuenceType;
	
	SimpleStepper(uint8_t pin1, uint8_t pin2, uint8_t pin3, uint8_t pin4);
	SimpleStepper(SecuenceType secuence, uint8_t pin1, uint8_t pin2, uint8_t pin3, uint8_t pin4);

	uint8_t Pin1;
	uint8_t Pin2;
	uint8_t Pin3;
	uint8_t Pin4;

	void CW();
	void CCW();

private:
	uint16_t onePhaseSecuence[4] = { B1000, B0100, B0010, B0001 };
	uint16_t twoPhaseSecuence[4] = { B1001, B1100, B0110, B0011 };
	uint16_t halfStepSecuence[8] = { B1000, B1100, B0100, B0110, B0010, B0011, B0001, B1001 };
	uint16_t* secuence;

	uint8_t stepCount;
	uint8_t stepIndex;

	void setOutput() const;
};

#endif

