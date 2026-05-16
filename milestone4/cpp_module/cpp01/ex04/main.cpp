#include <iostream>
#include <fstream>
#include <string>

std::string readStrFile(std::string fname)
{
	std::ifstream	f(fname.c_str());
	std::string		res = "";
	
	if (f.is_open())
	{
		std::string	line;
		while (std::getline(f, line))
		{
			res += line + '\n';
		}
		if (!res.empty())
			res.erase(res.length() - 1);
		f.close();
		return (res);
	}
	else
	{
		throw std::runtime_error("Error: unable to open file");
	}
}

void putStrFile(std::string s, std::string fname)
{
	std::ofstream	of((fname + ".replace").c_str());

	if (of.is_open())
	{
		of << s;
		of.close();
	}
	else
	{
		std::cerr << "Error: unable to open file" << std::endl;
	}
}

std::string convertText(std::string cntnt, std::string crack, std::string stikr)
{
	std::string	reslt = "";
	size_t		l = 0;
	size_t		r = 0;

	while (true)
	{
		r = cntnt.find(crack, l);
		if (r == std::string::npos)
			break ;
		reslt += cntnt.substr(l, r - l);
		reslt += stikr;
		l = r + crack.length();
	}
	reslt += cntnt.substr(l);
	return (reslt);
}

int main(int argc, char **argv)
{
	if (argc != 4) {
		std::cout << "Error: invalid no. of arg";
		return (1);
	}
	std::string fname = argv[1];
	std::string crack = argv[2];
	std::string stikr = argv[3];
	std::string cntnt;
	try {
		cntnt = readStrFile(fname);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return (-1);
	}
	std::string reslt = "";
	if (crack.empty()) return (2);
	if (cntnt == "") {
		putStrFile(reslt, fname);
		return (3);
	}
	reslt = convertText(cntnt, crack, stikr);
	putStrFile(reslt, fname);
	return (0);
}
