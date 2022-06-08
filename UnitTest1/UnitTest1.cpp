#include "pch.h"
#include "CppUnitTest.h"
#include "Tree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		//обмен поддеревьев, тест успешный
		TEST_METHOD(TestMethod1)
		{
			try
			{
				Tree tree(1);
				tree.insertData(&tree, 55);
				tree.insertData(&tree, 33);
				tree.insertData(&tree, 44);
				tree.insertData(&tree, 7);
				tree.insertData(&tree, 9);
				tree.insertData(&tree, 14);
				tree.insertData(&tree, 95);
				tree.insertData(&tree, 94);

				tree.printTree(&tree);

				tree.testser(&tree, 7, 44);
			}
			catch (const char* Error)
			{
				cerr << Error << endl;
			}
		}
		//обмен поддеревьев, левое есть, а правого нет, тест неуспешный
		TEST_METHOD(TestMethod2)
		{
			try
			{
				Tree tree(1);
				tree.insertData(&tree, 55);
				tree.insertData(&tree, 33);
				tree.insertData(&tree, 44);
				tree.insertData(&tree, 7);
				tree.insertData(&tree, 9);
				tree.insertData(&tree, 14);
				tree.insertData(&tree, 95);
				tree.insertData(&tree, 94);

				tree.printTree(&tree);

				tree.testser(&tree, 94, 99);
			}
			catch (const char* Error)
			{
				cerr << Error << endl;
			}
			
		}
		//обмен поддеревьев, правое есть, а левого нет, тест неуспешный
		TEST_METHOD(TestMethod3)
		{
			try
			{
				Tree tree(1);
				tree.insertData(&tree, 55);
				tree.insertData(&tree, 33);
				tree.insertData(&tree, 44);
				tree.insertData(&tree, 7);
				tree.insertData(&tree, 9);
				tree.insertData(&tree, 14);
				tree.insertData(&tree, 95);
				tree.insertData(&tree, 94);

				tree.printTree(&tree);

				tree.testser(&tree, 6, 9);
			}
			catch (const char* Error)
			{
				cerr << Error << endl;
			}
			
		}
		//Первое поддерево является поддеревом второго
		TEST_METHOD(TestMethod4)
		{
			try
			{
				Tree tree(1);
				tree.insertData(&tree, 55);
				tree.insertData(&tree, 33);
				tree.insertData(&tree, 44);
				tree.insertData(&tree, 7);
				tree.insertData(&tree, 9);
				tree.insertData(&tree, 14);
				tree.insertData(&tree, 95);
				tree.insertData(&tree, 94);

				tree.printTree(&tree);

				tree.testser(&tree, 6, 9);
			}
			catch (const char* Error)
			{
				cerr << Error << endl;
			}
			
		}
		//Второе поддерево является поддеревом первого
		TEST_METHOD(TestMethod5)
		{
			try
			{
				Tree tree(1);
				tree.insertData(&tree, 55);
				tree.insertData(&tree, 33);
				tree.insertData(&tree, 44);
				tree.insertData(&tree, 7);
				tree.insertData(&tree, 9);
				tree.insertData(&tree, 14);
				tree.insertData(&tree, 95);
				tree.insertData(&tree, 94);

				tree.printTree(&tree);

				tree.testser(&tree, 6, 9);
			}
			catch (const char* Error)
			{
				cerr << Error << endl;
			}
			
		}
		//обмен поддеревьев в пустом дереве
		TEST_METHOD(TestMethod6)
		{
			try
			{
				Tree tree(1);
				tree.testser(&tree, 3, 2);
			}
			catch (const char* Error)
			{
				cerr << Error << endl;
			}
		}
	};
}
