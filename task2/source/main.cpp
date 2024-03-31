#include <fstream>

#include "students_work_sim.hpp"
#include "teacher.hpp"


void resetOutputFile() {
	std::ofstream file(outputFileName);

	file.clear();
	file.close();
}


void printMenu() {
	std::cout << "--- ������������� �������� ������ �� ���������� ---" << std::endl;
	std::cout << "1. teacher - ���� �������" << std::endl;
	std::cout << "2. students - ������ ��" << std::endl;
}


void startSimulation(int studentsNum, double goodStudentProb, double badStudentProb) {
	Teacher teacher;
	StudentsWorkSim studentsWorkSim(studentsNum, goodStudentProb, badStudentProb);
	teacher.generateEquations(49);
	studentsWorkSim.simulateSolvings();
	teacher.checkSolutions();
	teacher.printGradesTable();
}


int main() {
	std::setlocale(LC_ALL, "Russian");

	resetOutputFile();

	printMenu();
	std::cout << "������� ��������� ������ � �������:" << std::endl;
	std::cout << "<����� ���������> (�� 100, ������ ��� ����...) <���� �������> < ���� ������>" << std::endl;
	std::cout << "> ";
	int studentsNum;
	double goodStudentProb, badStudentProb;

	if (!(std::cin >> studentsNum >> goodStudentProb >> badStudentProb)) {
		std::cout << "������, ������� �������� ������ :(" << std::endl;
		return 1;
	}

	startSimulation(studentsNum, goodStudentProb, badStudentProb);

	return 0;
}