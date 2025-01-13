/*
Name: Cliffansyah Yahya
Date : 3/2/2024
Description: This program computes and displays the charges for a patient hospital stay.
user input for patient if they are in-patient(stay overnight) 
or out-patient (in and out of hospital same day, not overnight)

if in-patient, user input for
a. The number of days spent in the hospital
b. The daily rate
c. Charges for hospital services (lab tests, etc.)
d. Hospital medication charges.

if out-patient, user input for
a. Charges for hospital services (lab tests, etc.)
b. Hospital medication charges.

Use a single, separate function to validate that no input is less than zero. If it is, it should
be re-entered before being returned. (while loop)

Once the required data has been input and validated, the program should use two
overloaded functions to calculate the total charges. One of the functions should accept
arguments for the in-patient data, while the other function accepts arguments for out-
patient data. Both functions should return the total charges.
*/

#include <iostream>
#include <string>

using namespace std;

/*before function call, put the other functions before main function
should have return type*/

//function prototypes or declaration
double validateLessThanZero(double validation);
double inChargesCalculation(double dailyRate, int daysSpent, double hospitalServices, double hospitalMedCharges);
double outChargesCalculation(double hospitalServices, double hospitalMedCharges);


int main()
{
	/*ask the user if they are an in-patient or out-patient*/
	char whatKindOfPatient;
	//use a boolean for the user input of what kind of patient they are,
	//loop until its a valid input
	bool patientInput = false;

	cout << " " << endl;
	cout << "This program computes and displays the charges for a patient hospital stay. " << endl;
	cout << " " << endl;

	while (!patientInput) {

	


		cout << "Are you an in-patient (i or I) or out-patient? (o or O): ";
		cin >> whatKindOfPatient;

		/*if in patient(stay overnight) user inputs*/
		if (whatKindOfPatient == 'I' || whatKindOfPatient == 'i') {

			//prompt for how many days spent in hospital, 
			//input validation for less than zero from a separate function
			int daysSpent;
			double total;
			cout << "The number of days spent in the hospital: ";
			cin >> daysSpent;
			daysSpent = validateLessThanZero(daysSpent); //input validation

			//prompt for daily rate
			//input validation for less than zero from a separate function
			double dailyRate;
			cout << "daily rate: $ ";
			cin >> dailyRate;
			dailyRate = validateLessThanZero(dailyRate);

			//Charges for hospital services (lab tests, etc.)
			//input validation for less than zero from a separate function
			double hospitalServices;
			cout << "hospital service charges: $ ";
			cin >> hospitalServices;
			hospitalServices = validateLessThanZero(hospitalServices); //input validation

			//Hospital medication charges
			//input validation for less than zero from a separate function
			double hospitalMedCharges;
			cout << "Hospital medication charges: $ ";
			cin >> hospitalMedCharges;
			hospitalMedCharges = validateLessThanZero(hospitalMedCharges); //input validation

			//calculate and display the total (function call)
			total = inChargesCalculation(dailyRate, daysSpent, hospitalServices, hospitalMedCharges);
			cout << " " << endl;
			cout << "--------------------------------" << endl;
			cout << " " << endl;
			cout << "Medical Invoice " << endl;
			cout << " " << endl;
			cout << "Your daily rate: $ " << dailyRate << endl;
			cout << "Days spent in hospital: " << daysSpent << endl;
			cout << "Amount for Hospital Services: $ " << hospitalServices << endl;
			cout << "Amount for Hospital Medication: $ " << hospitalMedCharges << endl;
			cout << "here is your total for (In-Patient): $ " << total << endl;


			patientInput = true;

		}
		else if (whatKindOfPatient == 'O' || whatKindOfPatient == 'o') {
			/*if out-patient, user input for
				a.Charges for hospital services(lab tests, etc.)
				b.Hospital medication charges.
			*/
			double total;

			double hospitalServices;
			cout << "hospital service charges: $ ";
			cin >> hospitalServices;
			hospitalServices = validateLessThanZero(hospitalServices); //input validation

			double hospitalMedCharges;
			cout << "Hospital medication charges: $ ";
			cin >> hospitalMedCharges;
			hospitalMedCharges = validateLessThanZero(hospitalMedCharges); //input validation

			//calculate and display the total (function call)
			total = outChargesCalculation(hospitalServices, hospitalMedCharges);
			cout << " " << endl;
			cout << "--------------------------------" << endl;
			cout << " " << endl;
			cout << "Medical Invoice " << endl;
			cout << " " << endl;
			cout << "Amount for Hospital Services: $ " << hospitalServices << endl;
			cout << "Amount for Hospital Medication: $ " << hospitalMedCharges << endl;
			cout << "here is your total for (Out-Patient): $ " << total << endl;
			patientInput = true;

		}
		else
		{
			cout << "Wrong letter, please enter 'I' or 'i' for in-patient, 'o' and 'O' for out-patient." << endl;
			//clear input 
			cin.clear();
			// ignore the previous character inputted, fixes the bug of infinite loop 
			// when input is neither of the character on the if statement 
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	return 0;

}

/*validation for input that can be no less than 0
use while loop so it keeps asking the user until
the number is validated */
double validateLessThanZero(double validation) {
	while (validation < 0) {
		cout << "Number can not be less than 0, try again: ";
		cin >> validation;
	}
	return validation;
}

//charges for in patient
double inChargesCalculation(double dailyRate, int daysSpent, double hospitalServices, double hospitalMedCharges) {
	return (dailyRate * daysSpent) + hospitalMedCharges + hospitalServices;
}

//charges for out patient
double outChargesCalculation(double hospitalServices, double hospitalMedCharges) {
	return hospitalMedCharges + hospitalServices;
}