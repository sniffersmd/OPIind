#include "pch.h"
#include "CppUnitTest.h"
#include "input.h"
#include "iostream"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1 {
	TEST_CLASS(UnitTest1)
	{
	public:
		
        // проверка на double n
        TEST_METHOD(TestInvalidNInput)
        {
            int n, k;
            std::vector<int> a;
            std::istringstream input("3.14\n");

            std::cin.rdbuf(input.rdbuf());

            try {
                getInput(n, a, k);
                Assert::Fail(L"Expected invalid_argument exception");
            }
            catch (const std::invalid_argument& e) {
                Assert::AreEqual("Неверное количество институтов", e.what());
            }
        }
        // проверка на 0 количество институтов
        TEST_METHOD(TestZeroNInput)
        {
            int n, k;
            std::vector<int> a;
            std::istringstream input("0\n");

            std::cin.rdbuf(input.rdbuf());

            try {
                getInput(n, a, k);
                Assert::Fail(L"Expected invalid_argument exception");
            }
            catch (const std::invalid_argument& e) {
                Assert::AreEqual("Неверное количество институтов", e.what());
            }
        }
        // проверка на большое количество институтов, превышающих допустимые значения
        TEST_METHOD(TestLargePositiveNInput)
        {
            int n, k;
            std::vector<int> a;
            std::istringstream input("999999999\n");

            std::cin.rdbuf(input.rdbuf());

            try {
                getInput(n, a, k);
                Assert::Fail(L"Expected invalid_argument exception");
            }
            catch (const std::invalid_argument& e) {
                Assert::AreEqual("Неверное количество институтов", e.what());
            }
        }
        // проверка на большое отрицательно количество институтов, превышающих допустимые значения 
        TEST_METHOD(TestLargeNegativeNInput)
        {
            int n, k;
            std::vector<int> a;
            std::istringstream input("-999999999\n");

            std::cin.rdbuf(input.rdbuf());

            try {
                getInput(n, a, k);
                Assert::Fail(L"Expected invalid_argument exception");
            }
            catch (const std::invalid_argument& e) {
                Assert::AreEqual("Неверное количество институтов", e.what());
            }
        }
        // проверка на граничащее количество институтов
        TEST_METHOD(TestMinimumNInput)
        {
            int n, k;
            std::vector<int> a;
            std::istringstream input("1\n1\n1\n");

            std::cin.rdbuf(input.rdbuf());

            try {
                getInput(n, a, k);
                Assert::AreEqual(1, n);
                Assert::AreEqual(1, (int)a.size());
                Assert::AreEqual(1, a[0]);
                Assert::AreEqual(1, k);
            }
            catch (const std::invalid_argument&) {
                Assert::Fail(L"Did not expect invalid_argument exception");
            }
        }
        // проверка на граничащее количество институтов
        TEST_METHOD(TestMaximumNInput)
        {
            int n, k;
            std::vector<int> a;
            std::ostringstream input_stream;
            input_stream << "1000\n";
            for (int i = 0; i < 1000; ++i) {
                input_stream << "1\n";
            }
            input_stream << "1000\n";
            std::istringstream input(input_stream.str());

            std::cin.rdbuf(input.rdbuf());

            try {
                getInput(n, a, k);
                Assert::AreEqual(1000, n);
                Assert::AreEqual(1000, (int)a.size());
                for (const int& teams : a) {
                    Assert::AreEqual(1, teams);
                }
                Assert::AreEqual(1000, k);
            }
            catch (const std::invalid_argument&) {
                Assert::Fail(L"Did not expect invalid_argument exception");
            }
        }

        // проверка на 1 команд от института
        TEST_METHOD(TestMinimumKInput)
        {
            int n = 1, k;
            std::vector<int> a = { 1 };
            std::istringstream input("1\n1\n1\n1\n");

            std::cin.rdbuf(input.rdbuf());

            try {
                getInput(n, a, k);
                Assert::AreEqual(1, k);
            }
            catch (const std::invalid_argument&) {
                Assert::Fail(L"Did not expect invalid_argument exception");
            }
        }

        
        // Тест на проверку ввода дробного числа для количества команд
        TEST_METHOD(TestInvalidTeamCount)
        {
            int n;
            std::vector<int> a;
            int k;

            std::istringstream input("2\n1\n2.5\n");
            std::cin.rdbuf(input.rdbuf());

            try {
                getInput(n, a, k);
                Assert::Fail(L"Expected std::invalid_argument");
            }
            catch (const std::invalid_argument& e) {
                Assert::AreEqual("Неверное количество команд", e.what());
            }
        }

        // проверка на 0 количество команд
        TEST_METHOD(TestZeroArr)
        {
            int n;
            std::vector<int> a;
            int k;

            std::istringstream input("1\n0\n");
            std::cin.rdbuf(input.rdbuf());

            try {
                getInput(n, a, k);
                Assert::Fail(L"Expected std::invalid_argument");
            }
            catch (const std::invalid_argument& e) {
                Assert::AreEqual("Неверное количество команд", e.what());
            }
        }

        // проверка на максимальное большое число

        TEST_METHOD(TestMAXArr)
        {
            int n;
            std::vector<int> a;
            int k;

            std::istringstream input("1\n9999999999\n");
            std::cin.rdbuf(input.rdbuf());

            try {
                getInput(n, a, k);
                Assert::Fail(L"Expected std::invalid_argument");
            }
            catch (const std::invalid_argument& e) {
                Assert::AreEqual("Неверное количество команд", e.what());
            }
        }

        // проверка на минимальное большое число
        TEST_METHOD(TestMINArr)
        {
            int n;
            std::vector<int> a;
            int k;

            std::istringstream input("1\n-9999999999\n");
            std::cin.rdbuf(input.rdbuf());

            try {
                getInput(n, a, k);
                Assert::Fail(L"Expected std::invalid_argument");
            }
            catch (const std::invalid_argument& e) {
                Assert::AreEqual("Неверное количество команд", e.what());
            }
        }


        // Тест на проверку ввода дробного числа для количества аудиторий
        TEST_METHOD(TestInvalidAuditoriumCount)
        {
            int n;
            std::vector<int> a;
            int k;

            std::istringstream input("2\n1\n2\n3.5\n");
            std::cin.rdbuf(input.rdbuf());

            try {
                getInput(n, a, k);
                Assert::Fail(L"Expected std::invalid_argument");
            }
            catch (const std::invalid_argument& e) {
                Assert::AreEqual("Неверное количество аудиторий", e.what());
            }
        }
        // Проверка на 0 количество команд от института
        TEST_METHOD(TestKZero)
        {
            int n;
            std::vector<int> a;
            int k;

            std::istringstream input("2\n1\n2\n0\n");
            std::cin.rdbuf(input.rdbuf());

            try {
                getInput(n, a, k);
                Assert::Fail(L"Expected std::invalid_argument");
            }
            catch (const std::invalid_argument& e) {
                Assert::AreEqual("Неверное количество аудиторий", e.what());
            }
        }
        // Проверка на большое отрицательное число команд, превышающее допустимые значения
        TEST_METHOD(TestKMIN)
        {
            int n;
            std::vector<int> a;
            int k;

            std::istringstream input("2\n1\n2\n-9999999999\n");
            std::cin.rdbuf(input.rdbuf());

            try {
                getInput(n, a, k);
                Assert::Fail(L"Expected std::invalid_argument");
            }
            catch (const std::invalid_argument& e) {
                Assert::AreEqual("Неверное количество аудиторий", e.what());
            }
        }
        // Проверка на большое число команд, превышающее допустимые значения
        TEST_METHOD(TestKMAX)
        {
            int n;
            std::vector<int> a;
            int k;

            std::istringstream input("2\n1\n2\n999999999999\n");
            std::cin.rdbuf(input.rdbuf());

            try {
                getInput(n, a, k);
                Assert::Fail(L"Expected std::invalid_argument");
            }
            catch (const std::invalid_argument& e) {
                Assert::AreEqual("Неверное количество аудиторий", e.what());
            }
        }

        // проверка на ситуацию, когда количество комнат меньше количества команд
        TEST_METHOD(TestTeamCountGreaterThanRoomCount)
        {
            int n;
            std::vector<int> a;
            int k;

            std::istringstream input("3\n2\n3\n4\n2\n");
            std::cin.rdbuf(input.rdbuf());

            try {
                getInput(n, a, k);
            }
            catch (const std::invalid_argument& e) {
                Assert::Fail(L"Unexpected std::invalid_argument");
            }
        }


        // проверка на ситуацию, когда количество команд равно количеству комнат
        TEST_METHOD(TestTeamCountEqualsRoomCount)
        {
            int n;
            std::vector<int> a;
            int k;

            // Ввод данных: 3 института, с 2, 3 и 4 командами соответственно, и 3 аудитории
            std::istringstream input("3\n2\n3\n4\n3\n");
            std::cin.rdbuf(input.rdbuf());

            try {
                getInput(n, a, k);
                // Ожидаем, что в этот раз данные будут успешно приняты
            }
            catch (const std::invalid_argument& e) {
                Assert::Fail(L"Unexpected std::invalid_argument");
            }
        }

        // проверка на ситуацию, когда количество комнат больше количества команд
        TEST_METHOD(TestRoomCountGreaterThanTeamCount)
        {
            int n;
            std::vector<int> a;
            int k;

            // Ввод данных: 3 института, с 2, 1 и 2 командами соответственно, и 4 аудитории
            std::istringstream input("3\n2\n1\n2\n4\n");
            std::cin.rdbuf(input.rdbuf());

            try {
                getInput(n, a, k);
                // Ожидаем, что в этот раз данные будут успешно приняты
            }
            catch (const std::invalid_argument& e) {
                Assert::Fail(L"Unexpected std::invalid_argument");
            }
        }
	};
}
