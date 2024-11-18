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

			// ��������� ��������� �����
			ofstream fout(testFileName);
			fout << "Hello, world,\n";
			fout << "This is a test, string, file\n";
			fout << "Another line without commas\n";
			fout.close();

			// ������ �������
			int lineNumber = 0, position;
			FindThirdComma(testFileName, lineNumber, position);

			// �������� ����������
			Assert::AreEqual(2, lineNumber); // ����� ���� �� ������� �����
			Assert::AreEqual(15, position);
		}
	};
}