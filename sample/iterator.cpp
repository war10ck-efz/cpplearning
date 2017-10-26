#include <iostream>
#include <map>

// DON'T break INSIDE
#define FOR_EACH( elemType, elem, containerType, container )	\
	for ( containerType::iterator __it = container.begin(); __it != container.end(); ++__it) 	\
		for ( bool __go = true; __go; )		\
			for ( elemType& elem = *__it; __go; __go =false )

// DON'T break INSIDE
#define FOR_EACH_CONST( elemType, elem, containerType, container )	\
	for ( containerType::const_iterator __it = container.begin(); __it != container.end(); ++__it) 	\
		for ( bool __go = true; __go; )		\
			for ( const elemType& elem = *__it; __go; __go =false )

std::map<std::string, std::map<std::string, int>> StudentGrades;

void cpp98()
{
	for ( std::map<std::string, std::map<std::string, int> >::iterator outerMap_Iter = StudentGrades.begin();
		   	outerMap_Iter != StudentGrades.end(); ++outerMap_Iter )
	{
		//Print out the student name
		std::cout << outerMap_Iter->first << std::endl;

		for ( std::map<std::string, int>::iterator innerMap_Iter = outerMap_Iter->second.begin();
				innerMap_Iter != outerMap_Iter->second.end(); ++innerMap_Iter )
		{
			//Print the grades here
			std::cout << innerMap_Iter->first << " : " << innerMap_Iter->second << std::endl;
		}
		std::cout << std::endl;
	}
}

void cpp11()
{
	for ( auto& outerMap_Iter : StudentGrades )
	{
		//Print out the student name
		std::cout << outerMap_Iter.first << std::endl;

		for ( auto& innerMap_Iter : outerMap_Iter.second )
		{
			//Print the grades here
			std::cout << innerMap_Iter.first << " : " << innerMap_Iter.second << std::endl;
		}
		std::cout << std::endl;
	}
}

int main()
{
	StudentGrades["Deb"]["Physics"] = 96;
	StudentGrades["Deb"]["Chemistry"] = 92;
	StudentGrades["Deb"]["Math"] = 82;
	StudentGrades["Vik"]["Physics"] = 92;
	StudentGrades["Vik"]["Chemistry"] = 88;
	StudentGrades["Vik"]["Math"] = 91;

	cpp98();

	std::cout << std::endl;

	cpp11();

	return 0;
}
