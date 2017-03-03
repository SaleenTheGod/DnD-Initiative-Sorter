#include <iostream>
#include <string>
#include <map>
#include <list>
#include <fstream>


void outputMapList (std::list<int> inputList, std::map<int, std::string> inputMap)
{
	while (!inputList.empty())
	{
		std::cout << "Character : " << inputMap[inputList.back()] << "\t Roll : " << inputList.back() << std::endl;
		inputList.pop_back();
	}
}


void main()
{


	int amount_of_players;
	std::map<int, std::string> DnDSorter;
	short int roll_storage[255];
	std::ofstream file_output;
	std::string output_ans;

	std::cout << "*** D&D Initiative Sorter ***\n\n\n";

	std::cout << "How many players are there?\n\n";
	std::cin >> amount_of_players;

	std::cout << "---------------------------\n";

	for (auto i = 0; i < amount_of_players; i++)
	{
		std::string temp_name = "";
		short int temp_roll = 0;

		std::cout << "Enter Player " << i + 1 << "'s Name\n";
		std::cin.ignore();
		getline(std::cin, temp_name);
		std::cout << "Enter Player " << i + 1 << "'s Roll\n";
		std::cin >> temp_roll;


		for (int j = 0; j < amount_of_players; j++)
		{
			if (temp_roll == roll_storage[j])
			{
				temp_roll += 1;
			}
		}

		roll_storage[i] = temp_roll;
		DnDSorter[temp_roll] = temp_name;
	}
	
	std::list<int> list_rolls;

	for(int i = 0; i < amount_of_players; i++)
	{
		list_rolls.push_back(roll_storage[i]);
	}

	list_rolls.sort();

	std::cout << "\n\n*** Sorted List ***\n";

	outputMapList(list_rolls, DnDSorter);

	std::cout << "Output to text file? Yes/No\n";
	std::cin >> output_ans;

	if (output_ans[0] == 'Y' || output_ans[0] == 'y')
	{
		std::string filename = "";

		std::cout << "Enter desired name of output text file. Do not include an extenstion, the program will handle that.\n";
		std::cin >> filename;
		filename += ".txt";

		file_output.open(filename);

		file_output << "*** D&D Initiative Sorter Output ***\n";

		while (!list_rolls.empty())
		{
			file_output << "Character : " << DnDSorter[list_rolls.back()] << "\t Roll : " << list_rolls.back() << std::endl;
			list_rolls.pop_back();
		}
	}
	
	std::cout << "\nQuestions? Comments? Concerns? Contact Saleen_af on Reddit!\n";

	system("pause");
}


/*
map<int, string> DnDSorter;

DnDSorter[1] = "Tom";
DnDSorter[2] = "Max";
DnDSorter[3] = "John";
DnDSorter[4] = "Jorn";
DnDSorter[5] = "";
*/