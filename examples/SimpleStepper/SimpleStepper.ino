/***************************************************
Copyright (c) 2017 Luis Llamas
(www.luisllamas.es)

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
****************************************************/

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