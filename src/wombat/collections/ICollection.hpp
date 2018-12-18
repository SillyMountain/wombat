#ifndef HAVE_COLLECTIONS_ICOLLECTION_H
#define HAVE_COLLECTIONS_ICOLLECTION_H

#include <wombat/core/types.hpp>
#include <wombat/core/IPrintable.hpp>

template <class T>
class ICollection: public IPrintable
{
	public:
		virtual ~ICollection(){};

		virtual wsize 	size()=0;
		virtual wbool 	add(T)=0;
		virtual wbool 	contains(T)=0;
		virtual wbool 	remove(wsize)=0;
		virtual T 	  	get(wsize)=0;

		virtual std::string string()
		{
			std::string ret = "[";
			for(wsize i = 0; i < this->size(); i++)
			{
				ret += toString(this->get(i));
				if(i < this->size() - 1)
				{
					ret += ", ";
				}
			}
			ret += "]";
			return ret;
		}
};

#endif //HAVE_COLLECTIONS_ICOLLECTION_H
