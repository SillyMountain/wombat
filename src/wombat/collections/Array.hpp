#ifndef HAVE_COLLECTIONS_ARRAY_H
#define HAVE_COLLECTIONS_ARRAY_H

#include <wombat/collections/ICollection.hpp>

template <class T>
class Array : public ICollection<T>
{
	private:
		wsize n;
		T *data;

	public:

		Array()
		{
			this->n = 0;
			this->data = NULL;
		}

		// Implementations from ICollection
		wsize size() override
		{
			return this->n;
		}

		wbool add(T item) override
		{
			++this->n;
			this->data = (T*) realloc(this->data, this->n * sizeof(T));
			this->data[this->n - 1] = item;
		}

		wbool contains(T item) override
		{
			for(wsize i = 0; i < this->n; ++i)
			{
				if(this->data[i] == item)
				{
					return true;
				}
			}
			return false;
		}

		wbool remove(wsize at) override
		{
			T *newdata = (T*) malloc((this->n - 1) * sizeof(T));
			wsize iter = 0;
			for(wsize i = 0; i < this->n; i++)
			{
				if(i != at)
				{
					newdata[iter] = this->data[i];
					++iter;
				}
			}
			free(this->data);
			this->data = newdata;
		}

		T get(wsize at) override
		{
			return this->data[at];
		}
};

#endif
