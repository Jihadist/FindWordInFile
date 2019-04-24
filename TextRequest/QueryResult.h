#pragma once

class QueryResult
{
	friend std::ostream & print(std::ostream & os, const QueryResult &qr);
public:
	using line_no = std::vector<std::string > ::size_type;
	QueryResult(std::string s, 
		std::shared_ptr<std::set<line_no>> a, 
		std::shared_ptr<std::vector<std::string>> f)
	:request_(std::move(s)),lines_(std::move(a)),file_(std::move(f)){}
private:
	std::string request_;
	std::shared_ptr<std::set<line_no>> lines_;
	std::shared_ptr<std::vector<std::string>> file_;
};
