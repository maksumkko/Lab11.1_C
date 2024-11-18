#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab11.1_C++/Lab11.1_C++.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab111C
{
	TEST_CLASS(Lab111C)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const char* testFileName = "testfile.txt";

			// Створення тестового файлу
			ofstream fout(testFileName);
			fout << "Hello, world,\n";
			fout << "This is a test, string, file\n";
			fout << "Another line without commas\n";
			fout.close();

			// Виклик функції
			int lineNumber = 0, position;
			FindThirdComma(testFileName, lineNumber, position);

			// Перевірка результатів
			Assert::AreEqual(2, lineNumber); // Третя кома на другому рядку
			Assert::AreEqual(15, position);
		}
	};
}