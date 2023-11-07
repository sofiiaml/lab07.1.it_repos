#include "pch.h"
#include "CppUnitTest.h"
#include "../PR7.1/PR7.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest71іт
{
	TEST_CLASS(UnitTest71іт)
	{
	public:
		
		TEST_METHOD(TestMethod1)
        {
            // Тестуємо функцію Calc з пустою матрицею
            const int rowCount = 0;
            const int colCount = 0;
            int** matrix = nullptr;
            int sum, count;

            Calc(matrix, rowCount, colCount, sum, count);

            // Перевіряємо, що сума та кількість залишилися нулями
            Assert::AreEqual(0, sum);
            Assert::AreEqual(0, count);
        }
	};
}
