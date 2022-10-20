#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>
#include <regex>
#include <set>
#include <sstream>
#include <string>

struct q
{
	int s;
	int y;

	bool operator==(const q& a) const
	{
		return (a.s == s && a.y == y);
	}

	bool operator<(const q& a) const
	{
		if (a.s == s) return a.y > y;
		return a.s > s;
	}
};

using table = std::vector<std::vector<q>>;


std::string get_q(const q& cell, const std::set<q>& all_q)
{
	int count = 0;
	for (auto item : all_q)
	{
		if (cell == item)
		{
			return "q" + std::to_string(count) + " ";
		}
		count++;
	}
	return "- ";
}

int main()
{
	std::cout << "Enter the input file: ";
	std::string file_name;
	std::cin >> file_name;

	std::ifstream input_file;

	input_file.open(file_name);
	if (!input_file.is_open())
	{
		std::cout << "Failed to open '" << file_name << "' for reading\n";
		return 0;
	}

	std::cout << "Enter the output file: ";
	std::cin >> file_name;
	std::ofstream output_file;
	output_file.open(file_name);
	if (!output_file.is_open())
	{
		std::cout << "Failed to open '" << file_name << "' for writing\n";
		return 0;
	}

	int rows_count;
	int columns_count;

	input_file >> columns_count;
	input_file >> rows_count;

	std::getline(input_file, file_name);

	table mile_table;
	std::set<q> all_q;
	for (int i = 0; i < columns_count; ++i)
	{
		std::string line;
		std::getline(input_file, line);
		line.erase(remove(line.begin(), line.end(), ','), line.end());
		line.erase(remove(line.begin(), line.end(), 'S'), line.end());
		line.erase(remove(line.begin(), line.end(), 'Y'), line.end());
		line = std::regex_replace(line, std::regex("-"), "-1");
		std::istringstream stream_line(line);
		std::vector<q> row;
		for (int j = 0; j < rows_count; ++j)
		{
			q cell{};
			stream_line >> cell.s >> cell.y;
			row.push_back(cell);
			if (cell.s != -1 && cell.y != -1)
			{
				all_q.insert(cell);
			}
		}
		mile_table.push_back(row);
	}

	for (auto cell : all_q)
	{
		output_file << "Y" << cell.y << " ";
		for (int i = 0; i < rows_count; ++i)
		{
			output_file << get_q(mile_table[cell.s][i], all_q);
		}
		output_file << std::endl;
	}
}
