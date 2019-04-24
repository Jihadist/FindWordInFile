#pragma once

#include "QueryResult.h"

class QueryResult;

class TextQuery
{
public:
	TextQuery(std::ifstream& basic_ifstream);
	QueryResult query(const std::string & s) const;

	using line_no = std::vector<std::string > ::size_type;

private:
	// вектор строк входного файла
	std::shared_ptr< std::vector<std::string>> lines_;
	// карта ассоциаций каждого слова в файле со строкой
	std::map<std::string, std::shared_ptr<std::set<line_no>>> map_;
};
