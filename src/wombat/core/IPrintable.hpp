#ifndef HAVE_CORE_IPRINTABLE_H
#define HAVE_CORE_IPRINTABLE_H

#include <string>

class IPrintable
{
	public:
		virtual ~IPrintable(){};
		virtual std::string string(){return std::to_string((long unsigned int)(void*)this);};
};

std::string toString(IPrintable printable)
{
	return printable.string();
}

template <class T>
std::string toString(T obj)
{
	return std::to_string(obj);
}

#endif
