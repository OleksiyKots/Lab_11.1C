#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include "../Lab_11.1C.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestForHasThreeStars
{
    TEST_CLASS(UnitTestForHasThreeStars)
    {
    public:

        // Тест: Файл містить три зірочки поспіль
        TEST_METHOD(TestThreeStarsPresent)
        {
            const char* testFile = "test1.txt";
            std::ofstream fout(testFile);
            fout << "This is a test line.\n";
            fout << "Another line with *** three stars.\n";
            fout.close();

            Assert::IsTrue(HasThreeStarsInRow(testFile), L"Three stars should be found in the file.");
        }

        // Тест: Файл не містить три зірочки поспіль
        TEST_METHOD(TestNoThreeStars)
        {
            const char* testFile = "test2.txt";
            std::ofstream fout(testFile);
            fout << "This is a test line.\n";
            fout << "Another line with no stars here.\n";
            fout.close();

            Assert::IsFalse(HasThreeStarsInRow(testFile), L"Three stars should not be found in the file.");
        }

        // Тест: Порожній файл
        TEST_METHOD(TestEmptyFile)
        {
            const char* testFile = "test3.txt";
            std::ofstream fout(testFile); // Створюємо порожній файл
            fout.close();

            Assert::IsFalse(HasThreeStarsInRow(testFile), L"Three stars should not be found in an empty file.");
        }

        // Тест: Великий файл без зірочок
        TEST_METHOD(TestLargeFileWithoutStars)
        {
            const char* testFile = "test4.txt";
            std::ofstream fout(testFile);
            for (int i = 0; i < 1000; i++) {
                fout << "This is line number " << i << ".\n";
            }
            fout.close();

            Assert::IsFalse(HasThreeStarsInRow(testFile), L"Three stars should not be found in the file.");
        }

        // Тест: Великий файл із трьома зірочками
        TEST_METHOD(TestLargeFileWithStars)
        {
            const char* testFile = "test5.txt";
            std::ofstream fout(testFile);
            for (int i = 0; i < 999; i++) {
                fout << "This is line number " << i << ".\n";
            }
            fout << "Here are the *** three stars.\n"; // Додаємо зірочки наприкінці
            fout.close();

            Assert::IsTrue(HasThreeStarsInRow(testFile), L"Three stars should be found in the file.");
        }
    };
}
