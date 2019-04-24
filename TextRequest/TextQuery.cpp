#include "pch.h"
#include "TextQuery.h"


TextQuery::TextQuery(std::ifstream & basic_ifstream) : lines_(new std::vector<std::string>)
{
	std::string temp;
	while (std::getline(basic_ifstream, temp))
	{
		lines_->push_back(temp);
		auto n = lines_->size()-1;
		std::istringstream  line(temp);
		std::cout << temp<<"\n";
		std::string word;
		std::cout << "size" << lines_->size();
		while (line >> word)
		{
			auto &t = map_[word];
			if (!t)
				t.reset(new std::set < line_no>);
			t->insert(n);
		}
	}
}

QueryResult TextQuery::query(const std::string & s) const
{
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);

	auto const location = map_.find(s);
	if (location==map_.end())
		return QueryResult(s, nodata, lines_);
	return QueryResult(s, location->second, lines_);
}
